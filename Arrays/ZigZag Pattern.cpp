/* 
## Question:
Add following functionalities to it :
Take input of number of rows and columns.
Print the following zigzag pattern.
Sample Input :
7 16
Sample Output :
1                       13 
  2                  12  14
    3              11        15
      4          10             16
        5      9
          6  8
            7
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int c,r,flag=1,i=0,j=0;
   cin>>r>>c;

   vector <vector<int>> pattern(r, vector <int> (c));
  //Block of code, prints the number with the help of variable 'k' & rest remains zero by default.
   for(int k=1;k<=c;k++){

       pattern[i][j]=k;
       if(i==0)
       flag=1;

       else if(i==(r-1))
       flag=0;

       //(Zero)-> False and (Non-Zero)->True
       if(flag) i++;
       else i--;

       j++;

   }
   //Replacing the '0' with " " (space) & printing the numbers of correct position. 
    for(int m = 1; m <= r; m++)
    {
        for(int n = 1; n <= c; n++)
        {
            if(pattern[m][n] == 0)
            cout<<" ";

            else 
            cout<<pattern[m][n];

        }
        cout<<"\n";
    }

    return 0;
}
