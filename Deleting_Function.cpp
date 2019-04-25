// Adding an Employee Function
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

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
  Deleting_Employee();
  return 0;
}
