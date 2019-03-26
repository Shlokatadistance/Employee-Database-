                          ENGG1340 (Computer Programming 2)
                            Group Project (Group No 27)
                              Staff Management System
Members: 
Sinha Shlok (UID: 3035554256) and Shandilya Eeshaanee (UID: 3035552234)

Student Tutor: Mehra Tejasvi

Steps to follow in the project
1.	To input all the data, we use arrays. Sorting can be done either on id or alphabetically. 
2.	After giving in an input of employee details, display an option on the screen to show final employee list.
3.	Array manipulation for carrying out the required tasks.

Project Plan:
Menu--> execute as per user requirement--> Output/ edit as per requirement

Menu Options (Use the switch function in a while loop for iteration):
1.	To display the list of employees’ data (display another menu as to what to display all the options could also be selected)
a)	ID
b)	Role
c)	Age
d)	Salary
e)	Address
Execution: use <fstream> to read the text files. The way the program shall store data is by making use of a text file to store all the credentials of the employees.

2.	To search for a particular employee (this function will display all the details of the particular employee)
-	We shall use <fstream> to access the text file by reading it and then print out the details

3.	To add an employee (to ask for all the details about the existing attributes and append the details into the text file)
-	We shall use <fstream> to access the text file by writing it.

4.	Remove the employee (to remove a specific row, we shall replicate all the data into a new file except the one to be removed and then delete the previous file and rename the existing one)
-	To make a new file and use <fstream> when required

5.	Modify employee data (to edit a particular attribute of the employee in the text file)
A menu shows up with the following attribute to be modified:
a)	ID
b)	Role
c)	Age
d)	Salary
e)	Address

6.	Salary caps (Input the range of the salary output the list of employees who earn within that range)
-	data sorted in terms of salary

7.	User defined attributes (User inputs as to what attribute to be introduced type of attribute (int, str, bool))
Ask for inputs for each employee

8.	Exit (getting out of the while loop when a particular button is pressed)


EXTRA NOTES:
Procedure of modification – 
How to modify the string (String operator) – 
1. Index the Entire employee directory
2. Select the particular employee you want to modify
3. Use (find) function to find what you need to modify ( you get back the index)
