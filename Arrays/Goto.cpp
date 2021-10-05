#include <iostream>  
using namespace std;  
int main()  
{  
fail:    
         cout<<"You can't continue further!\n";    
      cout<<"Enter your age:\n";    
      int marks;  
      cin>>marks;  
      if (marks< 50){    
              goto fail;    
      }    
      else    
      {    
              cout<<"Congrats! You can continue further!";     
      }         
}  
