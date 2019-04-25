// Draft Porject with Two functions
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

void Deleting_Employee ()
{
  // Text File Employee.txt
  string id;
  cout<< "Enter the ID of the Employee to be deleted: ";
  cin>>id;

  ifstream fin;
  string my_line;

  fin.open("Employee.txt");
  int mylen=id.length();

  ofstream fout;
  fout.open("New_Employee.txt");

  while (getline(fin, my_line))
  {
    if (my_line.substr(0,mylen)!=id){
      fout<< my_line<< '\n';
    }
  }

  fout.close();
  fin.close();
  int isRemoved= remove("Employee.txt");
  int isRenamed= rename("New_Employee.txt", "Employee.txt");
}

int main()
{
  Adding_Employee();
  Deleting_Employee();
  return 0;
}
