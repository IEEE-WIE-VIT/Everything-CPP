#include <iostream>
#include<conio.h>

using namespace std;

int main() {
   
   int sales[12];
   int i;
   cout << "Read User Input into Array\n";

   for (i = 0; i < 12; i++) {
      
      cout << "Enter Value for Position " << i << " : ";
      cin >> sales[i];
   }

   cout << "\n User Input\n";
   for (i = 0; i < 12; i++) {
      
      cout << "Position : " << i << " , Sales Value : " << sales[i] << " \n";
   }

   getch();
}
