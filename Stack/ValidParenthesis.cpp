//Checking for balanced brackets using CPP
#include <bits/stdc++.h>
using namespace std;


int ValidParenthesis(string expression) {
	stack<char> stack;
	char x;

	// Iterating over the given expression
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '(' || expression[i] == '['
			|| expression[i] == '{') {
			// Push the element in the stack
			stack.push(expression[i]);
			continue;
		}

		/* If incoming bracket is not opening bracket, then it must be closing. So stack cannot be empty here.*/
		if (stack.empty())
			return -1;

		if (expression[i] == ')') {
		   // Store the top element in a
			x = stack.top();
			stack.pop();
			if (x == '{' || x == '[')
				return -1;
			break;
		}

		if (expression[i] == '}') {
		    // Store the top element in b
			x = stack.top();
			stack.pop();
			if (x == '(' || x == '[')
				return -1;
			break;
			
		}

    	if (expression[i] == ']') {
    	    // Store the top element in c
			x = stack.top();
			stack.pop();
			if (x == '(' || x == '{')
				return -1;
			break;
    	}
    	
	}
	

	// Checking for Empty Stack
	return 1;
}

// Driver code
int main()
{
	string expr = "[{[]}]";

	// Function call
	if (ValidParenthesis(expr) != -1)
		cout << "The expression is Balanced";
	else
		cout << "The expression is Not Balanced";
	return 0;
}
//This code is contributed by Tisha
