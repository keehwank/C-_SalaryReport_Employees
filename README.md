# C-_SalaryReport_Employees
Write a program to allow the user to:
1. Create two classes. Employuee and Departments
   The Department class will have: DepartmentID, Departmentname, DepartmentHeadName.
   The Employee class will have employeeID, employeename, employeesalary, employeeage, employeeDepartmentID.
   Both of the above classes should have appropriate constructors, accessor methods.
2. Create two arrays. One for Employee with the size 5 and another one for Department with the size 3.

Your program should display a menu for the user to do the following:
1. Create Department: Collect all information about a department. Make sure the department ID does not already exist
   in the array containing Department objects. If it does not, then insert the Department object into the array. When
   the array is full, display the error message to the user "Teh array is full, you can not add any more departments"
2. Create Employee: Collect all information about an Employee. Make sure the Employee ID does not already exist in the
   array containing Employee objects. If it does not, then insert the Employee object into the array. Also make sure that 
   the DepartmentID that the employee belongs also exists. If it does not, then display error message.
   When the array is full, display the error message to the user "The array is full, you can not add any mor Employees"
3. Write the data to the file. When the user selects this option, dump the information in each array into a separate file.
4. Retrieve data from the file: When user selects this option, open each file, load the data from the file into the appropriate 
   array.
5. Display Report: When user selects this option, go through arrays and display the total salary paid for each
   department. The report should display the department name and the total salary of all employees in that department.
