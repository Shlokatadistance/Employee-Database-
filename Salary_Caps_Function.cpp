#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void Salary_Caps()
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

int main()
{
 Salary_Caps();
 return 0;
}
