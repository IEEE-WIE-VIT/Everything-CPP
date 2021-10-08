#include<bits/stdc++.h>
using namespace std;
int main() {
   vector<int> v;
   vector<int>::iterator it;
   int c, item;
   while (1) {
      cout<<"1.Size of the Vector"<<endl;
      cout<<"2.Insert Element at the End"<<endl;
      cout<<"3.Insert Element at the Front"<<endl;
      cout<<"4.Delete Element at the End"<<endl;
      cout<<"5.Delete Element at the Front"<<endl;
      cout<<"6.Front Element at Vector"<<endl;
      cout<<"7.Last Element at Vector"<<endl;
      cout<<"8.Display Vector"<<endl;
      cout<<"9.Sort Vector"<<endl;
      cout<<"10.Exit"<<endl;
      cout<<"Enter your Choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Size of the Vector: "<<v.size()<<endl;
         break;
         case 2:
            cout<<"Enter value to be inserted at the end: ";
            cin>>item;
            v.push_back(item);
         break;
         case 3:
            cout<<"Enter value to be inserted at the front: ";
            cin>>item;
            v.insert(v.begin(),item);
         break;
         case 4:
            item = v.back();
            v.pop_back();
            cout<<"Element "<<item<<" deleted"<<endl;
         break;
         case 5:
            item = v.front();
            v.erase(v.begin());
            cout<<"Element "<<item<<" deleted"<<endl;
         break;
         case 6:
            cout<<"Front Element of the Vector: ";
            cout<<v.front()<<endl;
         break;
         case 7:
            cout<<"Back Element of the Vector: ";
            cout<<v.back()<<endl;
         break;
         case 8:
            cout<<"Elements of Vector: ";
            for (it = v.begin(); it != v.end(); it++)
               cout<<*it<<" ";
            cout<<endl;
         break;
         case 9:
            sort(v.begin(),v.end());
         break;
         case 10:
            exit(1);
         break;
         default:
            cout<<"Wrong Choice"<<endl;
      }
   }
   return 0;
}
  
