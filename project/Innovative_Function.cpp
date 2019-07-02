#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
void killswitch(){
  cout << "Please respond with a choice" << endl;
  cout << "Yes or No?" << endl;
  string agreement;
  cin >> agreement;
  if (agreement == "Yes"){
    remove("test1.txt");
    cout << "You have successfully deleted the employee database" << endl;
    cout << "Have a nice day" << endl;

  }
  else
    cout << "Make up your mind next time and try again " << endl;

}

int main()
{
  cout <<setw(10)<<"Enter your passcode" << endl;
  string x;
  cin >> x;
  if (x=="pass"){
    killswitch();
  }
  else
    cout << "access denied" << endl;
  return 0;

}
