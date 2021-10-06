// C++ implementation of the HRRN Scheduling
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
class process {
public:
	pid_t p_no = 0;
	time_t start_AT = 0, AT = 0,
		BT_left = 0, BT = 0, temp_BT = 0,
		CT = 0, TAT = 0, WT = 0, RT = 0;
	int priority = 0;

	// Function for completion time
	void set_CT(time_t time)
	{
		CT = time;
		set_TAT();
		set_WT();
	}

	// Function for Turn Around Time
	void set_TAT()
	{
		TAT = CT - start_AT;
	}

	// Function for Waiting Time
	void set_WT()
	{
		WT = TAT - BT;
	}
	void P_set()
	{
		start_AT = AT;
		BT_left = BT;
	}
	void set_RT(time_t time)
	{
		RT = time - start_AT;
	}

	// Overload operator '<' w.r.t arrival
	// time because arrival time is the
	// first priority even greater than
	// priority of process and priority_queue
	// pops out the greatest value first
	// so we need to replace '<' with '>' inorder
	// to pop out smallest value
	friend bool operator<(const process& a, const process& b)
	{
		return a.AT > b.AT;
	}
};

// Function to implement pop_index()
process pop_index(priority_queue<process>* main_queue,
				int index)
{
	priority_queue<process> rm_index;
	int i;
	process p;

	switch (index) {
	case 0:
		p = (*main_queue).top();
		(*main_queue).pop();
		break;
	default:
		for (i = 0; i < index; i++) {
			rm_index.push((*main_queue).top());
			(*main_queue).pop();
		}
		p = (*main_queue).top();
		(*main_queue).pop();

		while (!(*main_queue).empty()) {
			rm_index.push((*main_queue).top());
			(*main_queue).pop();
		}
		(*main_queue) = rm_index;
		break;
	}
	return p;
}

// Function to implement maximum Response Ratio
// index w.r.t clock limit for arrival time
int max_response_ratio_index(priority_queue<process> ready_queue,
							time_t limit)
{
	int index, i = 0;
	double response_ratio = 0, max = 0;

	while (!ready_queue.empty()
		&& ready_queue.top().AT <= limit) {
		response_ratio = ((double)(limit - ready_queue.top().AT) + ready_queue.top().BT_left) / ready_queue.top().BT_left;
		if (response_ratio > max) {
			max = response_ratio;
			index = i;
		}
		i++;
		ready_queue.pop();
	}

	return index;
}

// Function to implement HRRN Scheduling
priority_queue<process> HRRN_run(priority_queue<process> ready_queue,
								queue<process>* gantt)
{
	priority_queue<process> completion_queue;
	process p;
	time_t clock = 0;

	while (!ready_queue.empty()) {
		while (clock < ready_queue.top().AT) {
			p.temp_BT++;
			clock++;
		}
		if (p.temp_BT > 0) {
			p.p_no = -1;
			p.CT = clock;
			(*gantt).push(p);
		}
		p = pop_index(&ready_queue,
					max_response_ratio_index(ready_queue,
											clock));
		p.set_RT(clock);

		while (p.BT_left > 0) {
			p.temp_BT++;
			p.BT_left--;
			clock++;
		}
		p.set_CT(clock);
		(*gantt).push(p);
		p.temp_BT = 0;

		completion_queue.push(p);
	}
	return completion_queue;
}

// Set data on the basis of given table
priority_queue<process> set_sample_data()
{
	priority_queue<process> ready_queue;
	process temp;
	temp.AT = 0;
	temp.BT = 4;
	temp.priority = 2;
	temp.p_no = 1;
	temp.P_set();
	ready_queue.push(temp);
	temp.AT = 1;
	temp.BT = 2;
	temp.priority = 4;
	temp.p_no = 2;
	temp.P_set();
	ready_queue.push(temp);
	temp.AT = 2;
	temp.BT = 3;
	temp.priority = 6;
	temp.p_no = 3;
	temp.P_set();
	ready_queue.push(temp);
	temp.AT = 3;
	temp.BT = 5;
	temp.priority = 10;
	temp.p_no = 4;
	temp.P_set();
	ready_queue.push(temp);
	temp.AT = 4;
	temp.BT = 1;
	temp.priority = 8;
	temp.p_no = 5;
	temp.P_set();
	ready_queue.push(temp);
	temp.AT = 5;
	temp.BT = 4;
	temp.priority = 12;
	temp.p_no = 6;
	temp.P_set();
	ready_queue.push(temp);
	temp.AT = 6;
	temp.BT = 6;
	temp.priority = 9;
	temp.p_no = 7;
	temp.P_set();
	ready_queue.push(temp);
	return ready_queue;
}

// Function to get total Waiting Time
double get_total_WT(priority_queue<process> processes)
{
	double total = 0;
	while (!processes.empty()) {
		total += processes.top().WT;
		processes.pop();
	}
	return total;
}

// Function to get total Turn Around Time
double get_total_TAT(priority_queue<process> processes)
{
	double total = 0;
	while (!processes.empty()) {
		total += processes.top().TAT;
		processes.pop();
	}
	return total;
}

// Function to get total Completion Time
double get_total_CT(priority_queue<process> processes)
{
	double total = 0;
	while (!processes.empty()) {
		total += processes.top().CT;
		processes.pop();
	}
	return total;
}

// Function to get total Response Time
double get_total_RT(priority_queue<process> processes)
{
	double total = 0;
	while (!processes.empty()) {
		total += processes.top().RT;
		processes.pop();
	}
	return total;
}

// Function to display main queue
void disp(priority_queue<process> main_queue, bool high)
{
	int i = 0, temp, size = main_queue.size();
	priority_queue<process> tempq = main_queue;
	double temp1;
	cout << "+-------------+--------------";
	cout << "+------------+-----------------";
	cout << "+-----------------+--------------+---------------+";
	if (high == true)
		cout << "----------+" << endl;
	else
		cout << endl;
	cout << "| Process No. | Arrival Time ";
	cout << "| Burst Time | Completion Time ";
	cout << "| Turnaround Time | Waiting Time | Response Time |";
	if (high == true)
		cout << " Priority |" << endl;
	else
		cout << endl;
	cout << "+-------------+--------------";
	cout << "+------------+-----------------";
	cout << "+-----------------+--------------+---------------+";
	if (high == true)
		cout << "----------+" << endl;
	else
		cout << endl;
	while (!main_queue.empty()) {
		temp = to_string(main_queue.top().p_no).length();
		cout << '|' << string(6 - temp / 2 - temp % 2, ' ')
			<< main_queue.top().p_no << string(7 - temp / 2, ' ');
		temp = to_string(main_queue.top().start_AT).length();
		cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
			<< main_queue.top().start_AT << string(7 - temp / 2, ' ');
		temp = to_string(main_queue.top().BT).length();
		cout << '|' << string(6 - temp / 2 - temp % 2, ' ')
			<< main_queue.top().BT << string(6 - temp / 2, ' ');
		temp = to_string(main_queue.top().CT).length();
		cout << '|' << string(8 - temp / 2 - temp % 2, ' ')
			<< main_queue.top().CT << string(9 - temp / 2, ' ');
		temp = to_string(main_queue.top().TAT).length();
		cout << '|' << string(8 - temp / 2 - temp % 2, ' ')
			<< main_queue.top().TAT << string(9 - temp / 2, ' ');
		temp = to_string(main_queue.top().WT).length();
		cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
			<< main_queue.top().WT << string(7 - temp / 2, ' ');
		temp = to_string(main_queue.top().RT).length();
		cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
			<< main_queue.top().RT << string(8 - temp / 2, ' ');
		if (high == true) {
			temp = to_string(main_queue.top().priority).length();
			cout << '|' << string(5 - temp / 2 - temp % 2, ' ')
				<< main_queue.top().priority << string(5 - temp / 2, ' ');
		}
		cout << "|\n";
		main_queue.pop();
	}
	cout << "+-------------+--------------";
	cout << "+------------+-----------------";
	cout << "+-----------------+--------------+---------------+";
	if (high == true)
		cout << "----------+";
	cout << endl;
	temp1 = get_total_CT(tempq);
	cout << "\nTotal completion time :- " << temp1 << endl;
	cout << "Average completion time :- " << temp1 / size << endl;
	temp1 = get_total_TAT(tempq);
	cout << "\nTotal turnaround time :- " << temp1 << endl;
	cout << "Average turnaround time :- " << temp1 / size << endl;
	temp1 = get_total_WT(tempq);
	cout << "\nTotal waiting time :- " << temp1 << endl;
	cout << "Average waiting time :- " << temp1 / size << endl;
	temp1 = get_total_RT(tempq);
	cout << "\nTotal response time :- " << temp1 << endl;
	cout << "Average response time :- " << temp1 / size << endl;
}

// Function to display Gantt Chart
void disp_gantt_chart(queue<process> gantt)
{
	int temp, prev = 0;
	queue<process> spaces = gantt;
	cout << "\n\nGantt Chart (IS indicates ideal state) :- \n\n+";
	while (!spaces.empty()) {
		cout << string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_BT, '-') << "+";
		spaces.pop();
	}
	cout << "\n|";
	spaces = gantt;
	while (!spaces.empty()) {
		cout << string(spaces.front().temp_BT, ' ');
		if (spaces.front().p_no == -1)
			cout << "IS" << string(spaces.front().temp_BT, ' ') << '|';
		else
			cout << "P" << spaces.front().p_no
				<< string(spaces.front().temp_BT, ' ') << '|';
		spaces.pop();
	}
	spaces = gantt;
	cout << "\n+";
	while (!spaces.empty()) {
		cout << string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_BT, '-')
			<< "+";
		spaces.pop();
	}
	spaces = gantt;
	cout << "\n0";
	while (!spaces.empty()) {
		temp = to_string(spaces.front().CT).length();
		cout << string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_BT - temp / 2 - prev, ' ')
			<< spaces.front().CT;
		prev = temp / 2 - temp % 2 == 0;
		spaces.pop();
	}
	cout << "\n\n";
}

// Driver Code
int main()
{
	// Initialise Ready and Completion Queue
	priority_queue<process> ready_queue, completion_queue;

	// queue for Gantt Chart
	queue<process> gantt;
	ready_queue = set_sample_data();

	// Function call to find completion data
	completion_queue = HRRN_run(ready_queue, &gantt);

	// Display Completion Queue
	disp(completion_queue, false);

	// Display Gantt Chart
	disp_gantt_chart(gantt);
	return 0;
}
