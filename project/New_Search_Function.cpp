#include <iostream>
#include <fstream>
using namespace std;

void Edit_Existing ()
{
  string emp_name;
  cout<< "Enter the Employee name whose data is to be editted: ";
  cin>> emp_name;
  cout<< endl;
  int my_length;
  string role, salary, age, id, gender, myline;

  ifstream fin;
  fin.open("data.txt");

  ofstream fout;
  fout.open("my_data.txt");

  while (getline(fin, myline))
  {
    my_length=myline.find('\t');
    if (emp_name==myline.substr(0, my_length))
    {
      cout<< "Enter Employee's ID: ";
      cin>> id;
      cout<< "Enter Employee's Age: ";
      cin>> age;
      cout<< "Enter Employee's Gender: ";
      cin>> gender;
      cout<< "Enter Employee's Salary: ";
      cin>> salary;
      cout<< "Enter Employee's Role: ";
      cin>> role;
      fout<< emp_name<< '\t'<< id<<'\t'<< age <<'\t'<< role << '\t' << gender <<'\t'<< salary<< endl; //the new set of data
    }
    else
    {
      fout<<myline<<endl;
    }
  }
  int isRemoved= remove("data.txt");
  int isRenamed= rename("my_data.txt", "data.txt");
}

int main(){
  Edit_Existing();
  return 0;
}
