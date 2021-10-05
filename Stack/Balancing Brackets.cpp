
#include <iostream>
using namespace std;
bool areBracketsBalanced(string expr)
{
	stack<char> s;
	char x;

	
	for (int i = 0; i < expr.length(); i++)// Traversing the Expression
	{
		if (expr[i] == '(' || expr[i] == '['
			|| expr[i] == '{')
		{
			
			s.push(expr[i]);// Push the element in the stack
			continue;
		}

		
		if (s.empty())
			return false;

		switch (expr[i]) {
		case ')':
			
			
			x = s.top();// Store the top element in a
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			
			x = s.top();// Store the top element in b
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			
			x = s.top();// Store the top element in c
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}

	
	return (s.empty());// Check Empty Stack
}

int main()
{
	string expr = "{()}[]";

	
	if (areBracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}
