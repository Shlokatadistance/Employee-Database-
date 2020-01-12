#include <iostream>
#include "Employee."
using namespace std;

void Employee::Salary_Caps()
{
  int lower_range, upper_range;
  cout<< "Enter the Lower Range of the Salary Caps: ";
  cin>> lower_range;
  cout<< endl;

  cout<< "Enter the Upper Range of the Salary Caps: ";
  cin>> upper_range;
  cout<< endl;

  string my_line, str_salary;
  int my_salary, str_length, index;
  ifstream fin;
  fin.open("Employee.txt");

  cout<< "Employees with salary between "<< lower_range<< " and "<< upper_range<<" are: "<<endl;

  while (getline(fin, my_line)){
    str_length=my_line.length();
    str_salary=my_line.substr(str_length-6, str_length);
    istringstream(str_salary)>> my_salary;// error in this

    if (my_salary<upper_range && my_salary> lower_range){
      index=my_line.find(" ", 11);
      cout<< my_line.substr(11, index)<< endl;
    }
  }
  fin.close();
}



void Employee::Add_Attributes()
{
  string my_line, attr_name, type, user_input="";
  ifstream fin;
  fin.open("Employee.txt");

  ofstream fout;
  fout.open("New_Employee.txt");

  cout<< "Enter the name of the attribute: ";
  cin >> attr_name;
  cout<< endl;

  cout<< "Press 1. To initialize all values to 0 "<< endl;
  cout<< "Press 2. To input values separately for each employee "<< endl;

  cin >> type;
  cout<< endl;

  if (type=="1"){
    while (getline(fin, my_line))
    {
      fout<< my_line<<'\t'<< 0 << '\n';
    }
  }

  else if (type=="2"){
    while (getline(fin, my_line))
    {
      cin>> user_input;
      fout<< my_line<< '\t' <<user_input << '\n';
    }
  }

  fout.close();
  fin.close();
  int isRemoved= remove("Employee.txt");
  int isRenamed= rename("New_Employee.txt", "Employee.txt");
}



void Employee::Add_Employee()
{
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



void Employee::Deleting_Employee()
{
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

void Employee::Add_Attributes()
{
  cout<< "Hurray! Salary Caps function is working."<< endl;
}

void Employee::Add_Attributes()
{
  cout<< "Hurray! Salary Caps function is working."<< endl;
}
