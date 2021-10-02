//Static Data Members

/* A static member is shared by all objects of the class.
All static data is initialized to zero when the first object is created, if no other initialization is present.
We can't put it in the class definition but it can be initialized outside the class,
as done in the following example by redeclaring the static variable,
using the scope resolution operator :: to identify which class it belongs to.*/

#include <iostream>
using namespace std;

class Employee
{
    int id;
    static int count;

public:
    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is " << id << " and this is employee number " << count << endl;
    }
    static void getCount(void){
        // cout<<id; // throws an error
        cout<<"The value of count is "<<count<<endl;
    }
};      

// Count is the static data member of class Employee
int Employee::count; // Default value is 0

int main()
{
    Employee roy, lavesh, rohan;

    // roy.id = 1;
    // roy.count=1; // cannot do this as id and count are private

    roy.setData();
    roy.getData();
    Employee::getCount();

    lavesh.setData();
    lavesh.getData();
    Employee::getCount();

    rohan.setData();
    rohan.getData();
    Employee::getCount();

    return 0;
}
