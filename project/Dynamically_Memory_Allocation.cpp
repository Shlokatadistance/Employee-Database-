#include <iostream>
#include <string>
#include <fstream>
#include <utility>
using namespace std;

void sortArray(string *nameholder, int length)
{
	cout<< "Sort Array function is being printed"<< endl;
	for (int a = 0; a < length-1; ++a)
	{
		int c = a;
		for (int b = a + 1; b < length; ++b)
		{
			if (nameholder[b] < nameholder[c])
				c = b;
		}
		swap(nameholder[a], nameholder[c]);
	}
}
int main()
{
  cout << "How many names would you like to enter? ";
	int length;
	cin >> length;
  ifstream fin;
  fin.open("test1.txt");

	if (fin.fail()){
    cout << "This file has errors" << endl;
    exit(1);
  }
  else
  cout << "The file works" << endl;

	int count = 0;
  string name;
  /*while (fin>>name){
    cout << name<<"\n";
    count++;
  }*/

  string *nameholder = new string[length];
	fin>>name;
  int count1 = 0;
	for (int i =0;i<length;++i){
		getline(fin,name);
		nameholder[i] = name;
		cout << name << endl;

	}
  //while (getline(fin, name)){
			//nameholder[count1]=name.substr(0, 10);
			//cout<< nameholder[count1]<< endl;
			//count1++;

		//}
		//swap(length,count1);





 sortArray(nameholder, length);
 cout << "\nHere is your sorted list:\n";
 for (int i = 0; i < length; ++i)
		cout << ": " << nameholder[i] << '\n';
 delete[] nameholder;
 return 0;
}
