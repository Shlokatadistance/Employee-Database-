#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;
void editexisting(){
  char name[50];
  char id[5];
  int age;
  char role[10];
  int salary;
  char gender[8];

  char checker[5];
  cout<<"\nEnter employee id: ";
  cin>>checker;
  cout << "enter new name" << endl;
  char newname[50];
  cin >> newname;
  cout << "Enter new id" << endl;
  char newid[5];
  cin >> newid;
  cout << "Enter new age" << endl;
  int newage;
  cin >> newage;
  cout << "Enter new role" << endl;
  char newrole[10];
  cin >> newrole;
  cout << "Enter new salary"<< endl;
  int newsalary;
  cin >> newsalary;
  cout << "Enter new gender" << endl;
  char newgender[8];
  cin >> newgender;

  FILE *file, *tempfile;
  file= fopen("data.txt", "r");
  tempfile= fopen("temp.txt", "w");
  while(fscanf(file, "%s %s %d %s %d %s", &name[0], &id[0] , &age, &role[0], &salary, &gender[0])!=EOF){

    if(strcmp(checker, id)==0)
      fprintf(tempfile, "%s %s %d %s %d %s \n", newname, newid, newage, newrole, newsalary, newgender);
    else
      fprintf(tempfile, "%s %s %d %s %d %s \n", name, id, age, role, salary, gender );
    }
    fclose(file);
    fclose(tempfile);
    int isRemoved= remove("data.txt");
    int isRenamed= rename("temp.txt", "data.txt");

}

int main(){
  char name[50];
  char id[5];
  int age;
  char role[10];
  int salary;
  char gender[8];
  editexisting();
}
