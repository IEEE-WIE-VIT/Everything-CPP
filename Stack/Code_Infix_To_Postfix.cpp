// C++ program to convert an expression from infix to postfix

#include<iostream>
#include<string>
#define MAX 20
using namespace std;

// Initializing the top pointer as -1
int top=-1;

//Creating a stack array of 20 elements
char stack[20];

// If stack is full, then display "Overflow", else insert in the stack
void push(char x)
{
    if(top==MAX-1)
    {
        cout<<"Overflow";
    }
   
    else
    {
        top++;
        stack[top]=x;
    }
}

// If stack is empty, then display "Underflow", else delete from the stack
char pop()
{
    char ch;
    if(top==-1)
    {
        cout<<"Underflow";
    }
    else
    {
        ch=stack[top];
        stack[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
//A function to check the precedence of the given operator. Higher value means higher precedence
int priority (char z)
{
    switch (z)
    {
        case '+':
        case '-':
            return(1);
         
        case '*':
        case '/':
            return(2);
            
        case '$':
            return(3);
    }
    return 0;
}

string convert(string exp1)
{
    int i=0;
    string exp2 = "";   
    while(exp1[i]!='\0')
    {       
        if(exp1[i]>='a' && exp1[i]<='z'|| exp1[i]>='A'&& exp1[i]<='Z')          
        {
            exp2.insert(exp2.end(),exp1[i]);
            i++;
        }  
        
        //If the scanned character is an ‘(‘, push it to the stack
        else if(exp1[i]=='(' || exp1[i]=='{'  || exp1[i]=='[')
        {
            push(exp1[i]);
            i++;
        }     
        
        //If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered
        else if(exp1[i]==')' || exp1[i]=='}'  || exp1[i]==']')
        {
            if(exp1[i]==')')
            {
                while(stack[top]!='(')
                {               exp2.insert(exp2.end(),pop());
                }
                pop();
                i++;
            }
            if(exp1[i]==']')
            {
                while(stack[top]!='[')
                {
                    exp2.insert(exp2.end(),pop());
                }
                pop();
                i++;
            }
 
            if(exp1[i]=='}')
            {
                while(stack[top]!='{')
                {
                    exp2.insert(exp2.end(),pop());
                }
                pop();
                i++;
            }
        }
        else            
        {
            if(top==-1)
            {
                push(exp1[i]);
                i++;
            }
            
            //An operator is encountered
            else if( priority(exp1[i]) <= priority(stack[top])) {
                exp2.insert(exp2.end(),pop());
               
                while(priority(stack[top]) == priority(exp1[i])){
                    exp2.insert(exp2.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(exp1[i]);
                i++;
            }
            else if(priority(exp1[i]) > priority(stack[top])) {
                push(exp1[i]);
                i++;
            }
        }
    }
    
     // pop all the operators from the stack
    while(top!=-1)
    {
        exp2.insert(exp2.end(),pop());
    }
    cout<<"The  Postfix Expression : "<<exp2; 
    return exp2;
}

//Main function of the program
int main()
{
    int cont;
    string infix, postfix;
    
    //Ask the user for the input of the Expression
    cout<<"\nEnter the Expression : "; 
    cin>>infix;
    
    postfix = convert(infix);
    return 0;
}
