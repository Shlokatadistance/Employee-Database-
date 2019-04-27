#include <iostream>
#include "Employee.h"
#include <iomanip>
#include <string.h>
#include <fstream>
#include<sstream>
using namespace std;

void Employee:: Salary_Caps()
//This function takes in two ranges of salaries and outputs all the salaries within that range.
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
  fin.open("data.txt");

  cout<< "Employees with salary between "<< lower_range<< " and "<< upper_range<<" are: "<<endl;

  while (getline(fin, my_line)){
    str_length=my_line.length();
    str_salary=my_line.substr(str_length-6, str_length);
    istringstream(str_salary)>> my_salary;// error in this

    if (my_salary<upper_range && my_salary> lower_range){
      index=my_line.find('\t');
      cout<< my_line.substr(0, index)<< endl;
    }
  }
  fin.close();
}



void Employee:: Add_Attributes()
// This function allows the user to define an attribute and append it to the main data file. The attribute can be of string type.
{

  string my_line, attr_name, type, user_input="";
  ifstream fin;
  fin.open("data.txt");

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
      fout<< my_line<< '\t'<<user_input << '\n';
    }
  }

  fout.close();
  fin.close();
  int isRemoved= remove("data.txt");
  int isRenamed= rename("New_Employee.txt", "data.txt");
}



void Employee:: Add_Employee()
///This function enables the user to add an employee to the database and append the employee's credentials to the main data file
{

  char name[50], role[20],gender[8];
  string id;

  int age;
  int salary;
  cout<< "Enter New Employee's Name: ";
  cin>> name;
  cout<< "Enter New Employee's ID: ";
  cin>> id;
  cout<< "Enter New Employee's Age: ";
  cin>> age;
  cout<< "Enter New Employee's Salary: ";
  cin>> salary;
  cout<< "Enter New Employee's Role: ";
  cin>> role;
  cout <<"Enter New Employee's Gender: ";
  cin >> gender;

  ofstream fout;
  fout.open("data.txt", ios::app);

  if (fout.fail()) {
		cout << "Error in file opening!" << endl;
    exit(1);
  }
  fout<< name<<'\t'<<id<<'\t'<<age<<'\t'<<role<<'\t'<<gender<<'\t'<<salary<< endl;
  fout.close();
}



void Employee:: Deleting_Employee()
{
  // This function is just another name for 'firing' an employee.
  //Remove the employee (to remove a specific row, we shall replicate all the data into a new file except the one to be removed and then delete the previous file and rename the existing one)
  string id;
  cout<< "Enter the ID of the Employee to be deleted: ";
  cin>>id;

  ifstream fin;
  string my_line;

  fin.open("data.txt");
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
  int isRemoved= remove("data.txt");
  int isRenamed= rename("New_Employee.txt", "data.txt");
}
char s1[50];

void Employee:: showDetails(void)
//Displays all details according to Employee's id. The user types in an id and the program displays the employee's information.
//This function is using c style of input and reading. We chose this method because the streaming method was not able to output any information after the 'strcmp' part.
//The methods we are using the FILE pointer and using the scanf,fopen and fclose methods
//The printing of the name of the employee was an issue, for which we declared s1 as a global variable
{
            FILE *file;
            string s;
            char name[100];
            char id[10];
            int age;
            char role[20];
            int salary;
            char gender[8];
            char checkId[10];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;



            strcpy(s1, checkId);

            file= fopen("data.txt", "r");

            while(fscanf(file, "%s", &name[0])!=EOF)
            {
                char temp_name[50], temp_id[10];
                strcpy(temp_name, name);
                fscanf(file, "%s", &id[0]);
                strcpy(temp_id, id);


                fscanf(file, "%d", &age);
                fscanf(file, "%s", &role[0]);
                fscanf(file, "%s", &gender[0]);
                fscanf(file, "%d", &salary);

                if(!strcmp(s1,id))
                {
                  cout<<"\nName: "<<temp_name;
                  cout<<"\nId: "<<temp_id;
                  cout<<"\nAge: "<<age;
                  cout<<"\nRole: "<<role;
                  cout<<"\nGender: "<<gender;
                  cout<<"\nSalary: "<<salary;
                }
            }
            fclose(file);
        }


int main()
{
  Options();
  return 0;
}
