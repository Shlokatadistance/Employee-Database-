#include <iostream>
//#include "Employee.h"
#include <iomanip>
#include <string.h>
#include <fstream>
#include<sstream>


using namespace std;

void Salary_Caps()
{
  //Salary caps (Input the range of the salary and output the list of employees who earn within that range)
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



void Add_Attributes()
{
  // User defined attributes (User inputs as to what attribute to be introduced type of attribute (int, str, bool)) Ask for inputs for each employee
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



void Add_Employee()
{
  // To add an employee (to ask for all the details about the existing attributes and append the details into the text file)
  char name[50], role[10], id[5],gender[8];
  char address[100];
  int age;
  int salary;
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
  cout <<"Enter New Employee's Gender: ";
  cin >> gender;

  ofstream fout;
  fout.open("Employee.txt", ios::app);

  if (fout.fail()) {
		cout << "Error in file opening!" << endl;
    exit(1);
  }
  fout<< id<<" "<<name<<" "<<age<<" "<<role<<" "<<salary<<" "<<address<<'\n';
  fout.close();
}



void Deleting_Employee()
{
  //Remove the employee (to remove a specific row, we shall replicate all the data into a new file except the one to be removed and then delete the previous file and rename the existing one)
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



void Searching_Function()
{
  // Searchign for functions with specified data
  char checker[5] ;
    cin >> checker;
    ifstream fin;
    fin.open("data.txt");
    if (fin.fail())
    {
      cout << "The file cannot be opened!" << endl;
      exit(1);
    }
    else
      cout<<"File working"<<endl;
      char name[50],id[5],role[10],gender[8];
      int age,salary;


    while (fin >> name >> id >> age >> role >> salary >> gender){
      if (strcmp(id,checker)==0){
        cout << setw(12) <<"Name :" << name << endl;
        cout << setw(12) <<"ID : "<< id << endl;
        cout << setw(12) <<"Age :" << age << endl;
        cout <<setw(12) <<"role :" << role << endl;
        cout <<setw(12) <<"Salary :"<< salary << endl;
        cout << setw(12) <<"Gender :" << gender << endl;
      }

    }
    fin.close();
  }

void Display_All_Data()
{
  char name[50];
  char id[5];
  int age;
  char role[10];
  int salary;
  char gender[8];

  char ch;
    cin >> ch;
    string hello;
    if (ch == 'y'){
      ifstream fin;
      fin.open("data.txt");
      if (fin.fail())
      {
        cout << "The file cannot be opened!" << endl;
        exit(1);
      }
      else
        cout<<"File working"<<endl;


      while (fin >> name >> id >> age >> role >> salary >> gender){
        cout << name <<"  " << id << " " << age << " " << role << endl;

      }

      fin.close();
    }
}



void Options()
{
  cout << "Welcome to the Employee Management system" << endl;
    cout << "-----------------------------------------" << endl;
    cout << " Please select your option" << endl;
    cout << "1. List of all Employees" << endl;
    cout << "2. Search for a particular Employee" << endl;
    cout << "3. Add an employee" << endl;
    cout << "4. Edit the details of an employee" << endl;
    cout << "5. Delete an employee" << endl;
    cout << "6. Generate the salary caps" << endl;
    cout << "7. Define an attribute" << endl;

    cout << "Please enter your choice" << endl;
    int choice ;
    cin >> choice;
    int continuation=0;
    while (continuation==0)
    {
      switch (choice) {
                      case 1:
                          Display_All_Data();
                      case 2:
                          Searching_Function();
                      case 3:
                          Add_Employee();
                      /*case 4:
                          addsomenewEmployee();
                          break;*/
                      case 5:
                          Deleting_Employee();
                      case 6:
                          Salary_Caps();
                      case 7:
                          Add_Attributes();
                      default:
                          cout<<"\n Make a choice you imbecile \n";
                          break;
                  }
          cout<< "Do you want to continue?";
          cout<< "Press 0. To Exit";
          cout<< "Press 1. To Continue";
          cin>> continuation;
          cout<< endl;
          }
    }
int main(){
  char name[50];
  char id[5];
  int age;
  char role[10];
  int salary;
  char gender[8];
  Options();
  return 0;
}
