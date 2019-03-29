                                        ENGG1340 Computer Programming 
                                          Group Project (Group No. 27)
                                          Employee Management System

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

7.	User defined attributes (User inputs as to what attribute to be introduced type of attribute (int, str, bool))
Ask for inputs for each employee.

8. Another function of this program, which will be discussed before implementing, is the verification step, in which we will aim to assign each employee with a unique id , either a number or a combination of alphabets and numbers, which will let them enter the editing stage of the program. This serves as a security feature for the database, which in many ways is needed in the present world

9.	Exit (getting out of the while loop when a particular button is pressed)

10. Implement a master switch, which will allow the user to delete the entire database and allows him/her to start the database anew. 

Scope of the Project and the Problem Setting
THe above program has various applications, especially in organizations where efficient systems to manage data of the employees does not exist. Given the fact that even small scale companies can generate tremondous amounts of data, such a system will come in handy to these organizations. The data of the employees can be stored in txt files, which can be easily worked upon by this program. We are giving all the basic functionalities which are needed in the real world, such as data manipulation and sorting. In addition, there are some coding techniques, given in Extra notes, which we will try and implement, so that it makes the entire system more efficient and also user friendly. This program can be made use of small companies, which lack the capital or resources, to implement bigger databases, such that it makes their tasks easier. With a few more modifications, it can be implemented in relatively larger organizations. The aim is to keep the interface simply to understand and work upon.  


EXTRA NOTES:
Procedure of modification – 
How to modify the string (String operator) – 
1. Index the Entire employee directory
2. Select the particular employee you want to modify
3. Use (find) function to find what you need to modify ( you get back the index)
4. We also aim to make use of the 'struct' functionality of C++, which will be a far easier and effiecient way of entering employee credentials. Struct will also make it possible to make 'pin-point' edits, as each credential will have its own unique name. 
