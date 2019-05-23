//This program is for creating departments and employees to report the total salary paid for each department.
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


class Departments           //designing the class named Departments
{
    private:
        int departmentID;
        string departmentName;
        string departmentHeadName;
       
    public:
    
        Departments()    //Constructor
        {    departmentID = 0;
             departmentName = "NotDefined";
             departmentHeadName = "Anonymous";
        }        
            
        void setDepartmentID(int depID)        
        {    departmentID = depID;
        }
        
        void setDepartmentName_HeadDepartment()
        {    
             cout << "Department Name : ";
             cin >> departmentName;
             
             cout << "Head of Department : ";
             cin >> departmentHeadName;
        }
        
        int getDepartmentID()
        {    return departmentID; 
        }
        
        string getDepartmentName()
        {    return departmentName;
        }
        
        string getDepartmentHeadName()
        {    return departmentHeadName;
        }
};

class Employee         //designing the class named Employee
{
 private:
    int employeeID;
    string employeeName;
    int employeeSalary;
    int employeeAge;
    int employeeDepartmentID;
    
    
 public:
 
    Employee()      //Constructor 
    {   
        employeeID = 0;
        employeeName = "Anonymous";
        employeeSalary = 0;
        employeeAge = 0;
        employeeDepartmentID = 0;
    }
    
    void setEmployeeID(int empID)
    {   employeeID = empID;
    }

    void setEmployeeDepData(int empDepData)
    {   employeeDepartmentID = empDepData;
    }

    void setEmployeeOtherData()
    {
        cout << "Employee Name :";
        cin >> employeeName;
        
        cout << "Salary: $";
        cin >> employeeSalary;
        
        cout << "Age : ";
        cin >> employeeAge;
    }
    
    int getEmployeeID()
    {    return employeeID;
    }
    
     string getEmployeeName()
    {    return employeeName;
    }
    
     int getEmployeeSalary()
    {    return employeeSalary;
    }
    
     int getEmployeeAge()
    {    return employeeAge;
    }
    
     int getEmployeeDepartmentID()
    {    return employeeDepartmentID;
    }
};

void displayMenu()    //the function of display menu
{
    cout << "1. Create Department" << endl;
    cout << "2. Create Employee" << endl;
    cout << "3. Write Out Data File" << endl;
    cout << "4. Read In Data File" << endl;
    cout << "5. Display Salary Report" << endl;
    cout << "6. -- Quit -- " << endl;
}


int main()
{
    int numEmployee = 5;
    int numDepartments = 3;
    int tempDepartmentID, tempEmployeeID, tempEmpDepID, i = 0, e = 0, depIndex, empIndex = 0, k=0, j;
    
    int fromFileDepID[numDepartments], fromFileEmpID[numEmployee], fromFileEmpSalary[numEmployee], fromFileEmpAge[numEmployee], fromFileEmpDeppartID[numEmployee];
    string fromFileDepName[numDepartments], fromFileDepHeadName[numDepartments], fromFileEmpName[numEmployee];
    
    int totalSalary[numDepartments];
    
    char charSelection;
    
    
    Employee employee[numEmployee];             //declaring an employee object of class Employee
    Departments departments[numDepartments];    //declaring a departments object of class Departments
    ofstream outputFile;                        
    ifstream inputFile;
    
    do
    {
       displayMenu();    //calling the displayMenu function
    
       cout << "Please make a selection : ";
       cin >> charSelection;
       if (charSelection <= '0' || charSelection > '7')      //validating the variable of charSelection
       {   cout << "Please enter a valid choice (1 - 6): ";
           cin >> charSelection;
       }
    
       switch(charSelection)
       {
           case '1': while (i < numDepartments)       //finding if this array is full using while loop
                     {   if (departments[i].getDepartmentID() != 0)   
                              i++;
                         else  break;   
                     }     
                  
                     if (i == numDepartments)         //in case the array is full
                        cout << endl << "The array is full, you can not add any more Departments." << endl;   
                        
                     else            //in case the array is not full
                     {
                         cout << "Please Enter Department Details:" << endl;
                         cout << "Department ID : ";
                         cin >> tempDepartmentID;
                      
                         for (depIndex=0; depIndex < numDepartments; depIndex++)   //finding if the departmentID is unique
                         {   if (tempDepartmentID == departments[depIndex].getDepartmentID() )   //in case the departmentID is not unique
                             {    cout << "Value must be unique!" << endl;
                                  break;
                             }
                         }                     
                         
                         if (depIndex == numDepartments)   //in case the departmentID is unique
                         {    for (int j=0; j < numDepartments; j++)     
                              {    if (departments[j].getDepartmentID() == 0 )
                                   {      departments[j].setDepartmentID(tempDepartmentID);
                                          departments[j].setDepartmentName_HeadDepartment();
                                          break;
                                    }
                              }
                         }      
                         else
                            break;   // escaping switch statement because the departmentID is not unique
                     }    
                     
                     break;
                  
           case '2': while (e < numEmployee)       //finding if this array is full using while loop
                     {   if (employee[e].getEmployeeID() != 0)
                              e++;
                         else  break;   
                     } 
                  
                     if (e == numEmployee)    //in case the array is full
                        cout << "The array is full, you can not add any more Employees." << endl;
                        
                     else       //in case the array is not full
                     {
                         cout << "Please Enter Employee Details:" << endl;
                         cout << "Employee ID : ";
                         cin >> tempEmployeeID;
                      
                         for (empIndex=0; empIndex < numEmployee; empIndex++)   //finding if the employeeID is unique 
                         {   if (tempEmployeeID == employee[empIndex].getEmployeeID() )   //in case the employeeID is not unique  
                             {    cout << "Value must be unique!" << endl;
                                  break;
                             }
                         }                     
                         
                         if (empIndex == numEmployee)   //in case the employeeID is unique
                         {       
                              for (j=0; j < numEmployee; j++)   
                              {   if (employee[j].getEmployeeID() == 0 )
                                  {      employee[j].setEmployeeID(tempEmployeeID);
                                         employee[j].setEmployeeOtherData();
                                         break;
                                  }        
                              }
                         }
                         else
                            break;   //escaping switch statement because the employeeID is not unique
                         
                         cout << "Department ID : ";
                         cin >> tempEmpDepID;
                         
                         do                //validating employee's Department ID using while loop
                         {  
                              for (k=0; k < numDepartments; k++)   
                              {   if (tempEmpDepID == departments[k].getDepartmentID() )  //in case the department ID of an employee is valid
                                  {       employee[j].setEmployeeDepData(tempEmpDepID);
                                          break;
                                  }
                              }    
                             
                              if (tempEmpDepID == departments[k].getDepartmentID())  //escaping do..while loop because the department ID of an employee is valid
                                    break;
                             
                              else              //if (k == numDepartments)   //in case the department ID of an employee is not valid
                              {   cout << "Please enter a valid department ID: ";
                                  cin >> tempEmpDepID;
                              }
                         }while (k == numDepartments);
                                    
                     }
                     
                     break;
            
           case '3': outputFile.open("department.dat");     //Opening the output file named "department.dat"
                     for (int outFileIndex = 0; outFileIndex < numDepartments; outFileIndex++)    //writing the data to the file using for loop
                     {
                          outputFile << departments[outFileIndex].getDepartmentID() << endl;
                          outputFile << departments[outFileIndex].getDepartmentName() << endl;
                          outputFile << departments[outFileIndex].getDepartmentHeadName() << endl;
                     }          
                     outputFile.close();    //Closing the file
                     
                     outputFile.open("employee.dat");      //Opening the output file named "employee.dat"
                     for (int outFileIndex = 0; outFileIndex < numEmployee; outFileIndex++)       //writing the data to the file using for loop
                     {      
                          outputFile << employee[outFileIndex].getEmployeeID() << endl;
                          outputFile << employee[outFileIndex].getEmployeeName() << endl;
                          outputFile << employee[outFileIndex].getEmployeeSalary() << endl;
                          outputFile << employee[outFileIndex].getEmployeeAge() << endl;
                          outputFile << employee[outFileIndex].getEmployeeDepartmentID() << endl;
                     }      
                     outputFile.close();        //Closing the file
                     
                     break;
                     
           case '4': inputFile.open("department.dat");        //Opening the input file named "department.dat"
                     for (int inFileIndex = 0; inFileIndex < numDepartments; inFileIndex++)     //Retrieving data from the file using array and for loop
                     {
                          inputFile >> fromFileDepID[inFileIndex];  
                          inputFile >> fromFileDepName[inFileIndex];  
                          inputFile >> fromFileDepHeadName[inFileIndex];  
                     }      
                     inputFile.close();         //Closing the file
                     
                     inputFile.open("employee.dat");           //Opening the input file named "employee.dat"
                     for (int inFileIndex = 0; inFileIndex < numEmployee; inFileIndex++)      //Retrieving data from the file using array and for loop
                     {
                         inputFile >> fromFileEmpID[inFileIndex];  
                         inputFile >> fromFileEmpName[inFileIndex];  
                         inputFile >> fromFileEmpSalary[inFileIndex];   
                         inputFile >> fromFileEmpAge[inFileIndex];  
                         inputFile >> fromFileEmpDeppartID[inFileIndex];  
                     }         
                     inputFile.close();        //Closing the file
         
                     break;
                     
           case '5': for (int p=0;  p < numDepartments; p++)         //Calculating the total salary for each department
                     {
                         totalSalary[p] = 0;
                         for (int m=0; m < numEmployee; m++)
                         {
                             if (departments[p].getDepartmentID() == employee[m].getEmployeeDepartmentID())
                                 totalSalary[p] += employee[m].getEmployeeSalary();
                         }
                     }
                     
                     //Start to display report
                     
                     cout << endl << "Salary Report By Department" << endl;
                     for (int n=0; n < numDepartments; n++)
                     {
                         cout << endl;
                         cout << left << setw(13) << "Dept" << ": " << departments[n].getDepartmentName() << endl;
                         cout << left << setw(13) << "Total Salary" << ": $" << totalSalary[n] << endl;
                     }    
                         
                     break;
          
       }
    
 
    }while (charSelection != '6');
    
    cout << "Thank you, goodbye.";
 
return 0;
}