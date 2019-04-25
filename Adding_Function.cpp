// Adding an Employee Function
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Adding_Employee ()
{
  // Text File Employee.txt
  string name, role, id;
  char address[100];
  int age;
  double salary;
  cout<< "Enter New Employee's Name: ";
  cin>> name;
  cout<< "Enter New Employee's ID: ";
  cin>> id;
  cout<< "Enter New Employee's Age: ";
  cin>> age;
  cout<< "Enter New Employee's Address: ";
  cin>> address;
  cout<< "Enter New Employee's Salary: ";
  cin>> salary;
  cout<< "Enter New Employee's Role: ";
  cin>> role;

  ofstream fout;
  fout.open("Employee.txt", ios::app);

  if (fout.fail()) {
		cout << "Error in file opening!" << endl;
    exit(1);
  }
  fout<< id<<" "<<name<<" "<<age<<" "<<role<<" "<<salary<<" "<<address<<'\n';
  fout.close();
}

int main()
{
  Adding_Employee();
  return 0;
}
