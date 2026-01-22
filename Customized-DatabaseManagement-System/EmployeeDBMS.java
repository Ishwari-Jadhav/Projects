////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project :     Customized Database Management System (DBMS).
// File    :     EmployeeDBMS.java
// Description : This project simulates a lightweight, file-based DBMS for managing employee 
//               records with auto-generated IDs, CRUD operations, and persistent storage 
//               using Java serialization.
// Author  :     Ishwari Pravin Jadhav
// Date    :     22/09/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////

import java.util.*;
import java.io.*;

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Class :       Employee
// Description : Defines an employee with unique auto-generated ID, name, age, address,salary, 
//               and optional email. Implements Serializable for easy object persistence.
//
//////////////////////////////////////////////////////////////////////////////////////////////
class Employee implements Serializable
{
    public int EmpID;
    public String EmpName;
    public int EmpAge;
    public String EmpAddress;
    public int EmpSalary;
    public String EmpEmail;

    private static int Counter;

    static
    {
        Counter = 1;
    }
    public Employee(String B,int C,String D,int E)
    {
        this.EmpID = Counter++;
        this.EmpName = B;
        this.EmpAge = C;
        this.EmpAddress = D;
        this.EmpSalary = E;
        this.EmpEmail = null;
    }

    public void DisplayInformation()
    {
        System.out.println(
            "ID : "+this.EmpID+
            " Name : "+this.EmpName+
            " Age : "+this.EmpAge+
            " Address : "+this.EmpAddress+
            " Salary : "+this.EmpSalary+
            (this.EmpEmail != null ? " Email: " +this.EmpEmail : "")
        );
    }

    public String toString()
    {
        return "ID : "+this.EmpID+
               " Name : "+this.EmpName+
               " Age : "+this.EmpAge+
               " Address : "+this.EmpAddress+
               " Salary : "+this.EmpSalary+
               (this.EmpEmail != null ? " Email: " +this.EmpEmail : "");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Class       : MarvellousDBMS
// Description : It implements a Lightweight employee DBMS with CRUD operations and
//               persistent storage.
//
//////////////////////////////////////////////////////////////////////////////////////////
class MarvellousDBMS implements Serializable
{
    private LinkedList<Employee> Table;

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			:	MarvellousDBMS
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   This is Constructor of class MarvellousDBMS.
    //	Returns				:   None
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public MarvellousDBMS()
    {
        System.out.println("MarvellousDBMS started succesfully...");
        Table = new LinkedList<Employee>();
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   INSERT INTO employee(1,"Amit",23,"Pune",21000)
    //	Method Name			:	InsertIntoTable
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   String name,int age,String address,int salary
    //	Description         :   Adds a new employee record to the table with auto-generated ID.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void InsertIntoTable(  String name,
                                  int age,
                                  String address,
                                  int salary
                               )
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        Employee eobj = new Employee(name,age,address,salary);

        Table.add(eobj);

        System.out.println("Marvellous DBMS : > New record inserted succesfully");
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * from employee
    //	Method Name			:	SelectStarFrom
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Displays all employee records from the table.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void SelectStarFrom()
    {
        System.out.println("--------------------------------------------------------------------------------------");
        System.out.println("---------------------------Data from the Employee table-------------------------------");
        System.out.println("--------------------------------------------------------------------------------------");

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            System.out.println(eref);
        }

        System.out.println("--------------------------------------------------------------------------------------");
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpID = 11
    //	Method Name			:	SelectSpecificID
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int id
    //	Description         :   Displays the employee record matching the given ID.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void SelectSpecificID(int id)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(eref.EmpID == id)
            {
                found = true;
                System.out.println(eref);
                break;
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpName = "Sagar"
    //	Method Name			:	SelectSpecificName
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   String name
    //	Description         :   Displays all employee records matching the given name.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void SelectSpecificName(String name)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(name.equals(eref.EmpName))
            {
                found = true;
                System.out.println(eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpAge = 22
    //	Method Name			:	SelectSpecificAge
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int age
    //	Description         :   Displays all employee records with the specified age.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void SelectSpecificAge(int age)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(eref.EmpAge == age)
            {
                found = true;
                System.out.println(eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpAddress = "Nashik"
    //	Method Name			:	SelectSpecificAddress
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   String name
    //	Description         :   Displays all employee records with the specified address.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void SelectSpecificAddress(String name)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(name.equals(eref.EmpAddress))
            {
                found = true;
                System.out.println(eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpSalary = 22000
    //	Method Name			:	SelectSpecificSalary
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int salary
    //	Description         :   Displays all employee records with the specified salary.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void SelectSpecificSalary(int salary)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(eref.EmpSalary == salary)
            {
                found = true;
                System.out.println(eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   DELETE FROM employee WHERE EmpId = 11
    //	Method Name			:	DeleteSpecificID
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int id
    //	Description         :   Deletes the employee record matching the given ID.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteSpecificID(int id)
    {
        boolean found = false;
        int index = 0;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(eref.EmpID == id)
            {
                found = true;
                break;
            }
            index++;
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
        else
        {
            Table.remove(index);
            System.out.println("Record succesfully deleted");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   DELETE FROM employee WHERE EmpName = "Sagar"
    //	Method Name			:	DeleteSpecificName
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   String name
    //	Description         :   Deletes all employee records matching the given name.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteSpecificName(String name)
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        boolean found = Table.removeIf(eref -> eref.EmpName.equals(name));
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
        else
        {
            System.out.println("Record succesfully deleted");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   DELETE FROM employee WHERE EmpAge = 22
    //	Method Name			:	DeleteSpecificAge
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int age
    //	Description         :   Deletes all employee records with the specified age.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteSpecificAge(int age)
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        boolean found = Table.removeIf(eref -> eref.EmpAge == age);
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
        else
        {
            System.out.println("Record succesfully deleted");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   DELETE FROM employee WHERE EmpAddress = "Pune"
    //	Method Name			:	DeleteSpecificAddress
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   String address
    //	Description         :   Deletes all employee records with the specified address.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteSpecificAddress(String address)
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        boolean found = Table.removeIf(eref -> eref.EmpAddress.equals(address));
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
        else
        {
            System.out.println("Record succesfully deleted");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   DELETE FROM employee WHERE EmpSalary = 22000
    //	Method Name			:	DeleteSpecificSalary
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int salary
    //	Description         :   Deletes all employee records with the specified salary.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteSpecificSalary(int salary)
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        boolean found = Table.removeIf(eref -> eref.EmpSalary == salary);
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
        else
        {
            System.out.println("Record succesfully deleted");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   UPDATE employee SET name = Sagar WHERE id = 2
    //	Method Name			:	UpdateByID
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int id,String newName
    //	Description         :   Updates the name of the employee record matching the given ID.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void UpdateByID(int id,String newName)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(eref.EmpID == id)
            {
                found = true;
                eref.EmpName = newName;
                System.out.println("Updated Record: "+eref);
                break;
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   UPDATE employee SET Salary = 30000 WHERE name = "Amit"
    //	Method Name			:	UpdateByName
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   String name,int newSalary
    //	Description         :   Updates the salary of all employee records with the specified name.
    //	Returns				:   void
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    public void UpdateByName(String name,int newSalary)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(name.equals(eref.EmpName))
            {
                found = true;
                eref.EmpSalary = newSalary;
                System.out.println("Updated Record: "+eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   UPDATE employee SET Salary = 30000 WHERE age = 22
    //	Method Name			:	UpdateByAge
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int age,int newSalary
    //	Description         :   Updates the salary of all employee records with the specified age.
    //	Returns				:   void
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    public void UpdateByAge(int age,int newSalary)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(eref.EmpAge == age)
            {
                found = true;
                eref.EmpSalary = newSalary;
                System.out.println("Updated Record: "+eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   UPDATE employee SET Name = "Amit" WHERE address = "Pune"
    //	Method Name			:	UpdateByAddress
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   String address,String newName
    //	Description         :   Updates the name of all employee records with the specified address.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////
    public void UpdateByAddress(String address,String newName)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(address.equals(eref.EmpAddress))
            {
                found = true;
                eref.EmpName = newName;
                System.out.println("Updated Record: "+eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   UPDATE employee SET salary = 23000 WHERE salary = 30000
    //	Method Name			:	UpdateBySalary
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   int salary,int newSalary
    //	Description         :   Updates the salary of all employee records with the specified 
    //                          current salary.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void UpdateBySalary(int salary,int newSalary)
    {
        boolean found = false;

        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for(Employee eref : Table)
        {
            if(eref.EmpSalary == salary)
            {
                found = true;
                eref.EmpSalary = newSalary;
                System.out.println("Updated Record: "+eref);
            }
        }
        
        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //  
    //  Operation           :   Take Backup of Table
    //  Method Name         :   TakeBackup
    //  Method Date         :   22/09/2025
    //  Method Author       :   Ishwari Pravin Jadhav
    //  Parameters          :   None
    //  Description         :   Saves the current database state to a file (MarvellousDBMS.ser).
    //  Returns             :   void
    //
    /////////////////////////////////////////////////////////////////////////////////////////////
    public void TakeBackup()
    {
        try
        {
            FileOutputStream fos = new FileOutputStream("MarvellousDBMS.ser");
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            oos.writeObject(this);
        }
        catch(Exception eobj)
        {
            System.out.println("Exception Occured...");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //  
    //  Operation           :   Restore Backup
    //  Method Name         :   RestoreBackup
    //  Method Date         :   22/09/2025
    //  Method Author       :   Ishwari Pravin Jadhav
    //  Parameters          :   String path
    //  Description         :   Restores database state from a backup file.
    //  Returns             :   MarvellousDBMS object or null if failure.
    //
    /////////////////////////////////////////////////////////////////////////////////////////////
    public static MarvellousDBMS RestoreBackup(String path)
    {
        try
        {
            MarvellousDBMS ret = null;

            FileInputStream fis = new FileInputStream(path);
            ObjectInputStream ois = new ObjectInputStream(fis);

            ret = (MarvellousDBMS) ois.readObject();
            return ret;
        }
        catch(Exception eobj)
        {
            System.out.println("Exception Occured...");
            return null;
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT COUNT(*) FROM employee
    //	Method Name			:	GetEmployeeCount
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Displays the total number of employee records in the table.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void GetEmployeeCount()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if(Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        System.out.println("Total number of records : "+Table.size());
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT MAX(EmpSalary) FROM employee
    //	Method Name			:	GetMaximumSalary
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Finds and displays the highest salary among employees.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void GetMaximumSalary()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if(Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        int maxSalary = Integer.MIN_VALUE;
        for(Employee eref : Table)
        {
            if(eref.EmpSalary > maxSalary)
            {
                maxSalary = eref.EmpSalary;
            }
        }
        System.out.println("Maximum salary is : "+maxSalary);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT MIN(EmpSalary) FROM employee
    //	Method Name			:	GetMinimumSalary
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Finds and displays the lowest salary among employees.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void GetMinimumSalary()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if(Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }
        
        int minSalary = Integer.MAX_VALUE;
        for(Employee eref : Table)
        {
            if(eref.EmpSalary < minSalary)
            {
                minSalary = eref.EmpSalary;
            }
        }
        System.out.println("Minimum salary is : "+minSalary);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT AVG(EmpSalary) FROM employee
    //	Method Name			:	GetAverageSalary
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Calculates and displays the average salary of all employees.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void GetAverageSalary()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if(Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        int sum = 0;
        for(Employee eref : Table)
        {
            sum = sum + eref.EmpSalary;
        }

        double avg = (double) sum / Table.size();
        System.out.println("Average salary is : "+avg);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT SUM(EmpSalary) FROM employee
    //	Method Name			:	GetSumOfSalary
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Calculates and displays the total sum of all employee salaries.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void GetSumOfSalary()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if(Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        int sum = 0;
        for(Employee eref : Table)
        {
            sum = sum + eref.EmpSalary;
        }

        System.out.println("Total salary is : "+sum);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT COUNT(*),EmpAddress FROM employee GROUP BY EmpAddress
    //	Method Name			:	GroupEmployeesByAddress
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Groups employees by address and displays the count per group.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void GroupEmployeesByAddress()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }
        
        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        HashMap<String, Integer> groupMap = new HashMap<>();

        for (Employee eref : Table)
        {
            if (groupMap.containsKey(eref.EmpAddress))
            {
                int count = groupMap.get(eref.EmpAddress);
                groupMap.put(eref.EmpAddress,count + 1);
            }
            else
            {
                groupMap.put(eref.EmpAddress,1);
            }
        }

        System.out.println("Employee count grouped by Address : ");
        for(Map.Entry<String,Integer> entry : groupMap.entrySet())
        {
            System.out.println(entry.getKey()+ " -> " +entry.getValue());
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpID ASC
    //	Method Name			:	OrderByIDAsc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by ID in ascending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByIDAsc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e1.EmpID, e2.EmpID));

        System.out.println("Records sorted by EmpID in Ascending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpName ASC
    //	Method Name			:	OrderByNameAsc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by name in ascending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByNameAsc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> (e1.EmpName).compareTo(e2.EmpName));

        System.out.println("Records sorted by EmpName in Ascending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpAge ASC
    //	Method Name			:	OrderByAgeAsc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by age in ascending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByAgeAsc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e1.EmpAge, e2.EmpAge));

        System.out.println("Records sorted by EmpAge in Ascending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpAddress ASC
    //	Method Name			:	OrderByAddressAsc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by address in ascending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByAddressAsc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> (e1.EmpAddress).compareTo(e2.EmpAddress));

        System.out.println("Records sorted by EmpAddress in Ascending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpSalary ASC
    //	Method Name			:	OrderBySalaryAsc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by salary in ascending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderBySalaryAsc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e1.EmpSalary, e2.EmpSalary));

        System.out.println("Records sorted by EmpSalary in Ascending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpID DESC
    //	Method Name			:	OrderByIDDesc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by ID in descending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByIDDesc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e2.EmpID,e1.EmpID));

        System.out.println("Records sorted by EmpID in Descending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpName DESC
    //	Method Name			:	OrderByNameDesc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by name in descending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByNameDesc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> (e2.EmpName).compareTo(e1.EmpName));

        System.out.println("Records sorted by EmpName in Descending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpAge DESC
    //	Method Name			:	OrderByAgeDesc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by age in descending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByAgeDesc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e2.EmpAge,e1.EmpAge));

        System.out.println("Records sorted by EmpAge in Descending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpAddress DESC
    //	Method Name			:	OrderByAddressDesc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by address in descending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByAddressDesc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> (e2.EmpAddress).compareTo(e1.EmpAddress));

        System.out.println("Records sorted by EmpAddress in Descending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpSalary DESC
    //	Method Name			:	OrderBySalaryDesc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts and displays employees by salary in descending order.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderBySalaryDesc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e2.EmpSalary,e1.EmpSalary));

        System.out.println("Records sorted by EmpSalary in Descending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpAddress ASC,EmpSalary DESC
    //	Method Name			:	OrderByAddressAscSalaryDesc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts employees first by address (asc) and then by salary (desc).
    //	Returns				:   void
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByAddressAscSalaryDesc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e2.EmpSalary,e1.EmpSalary));

        Collections.sort(Table,(e1, e2) -> (e1.EmpAddress).compareTo(e2.EmpAddress));

        System.out.println("Records sorted by EmpAddress in Ascending Order and by EmpSalary in Descending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpSalary DESC,EmpName ASC
    //	Method Name			:	OrderBySalaryDescNameAsc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts employees first by salary (desc) and then by name (asc).
    //	Returns				:   void
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderBySalaryDescNameAsc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> (e1.EmpName).compareTo(e2.EmpName));

        Collections.sort(Table,(e1, e2) -> Integer.compare(e2.EmpSalary,e1.EmpSalary));

        System.out.println("Records sorted by EmpSalary in Descending Order and by EmpName in Ascending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee ORDER BY EmpAge ASC,EmpSalary DESC
    //	Method Name			:	OrderByAgeAscSalaryDesc
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Sorts employees first by age (asc) and then by salary (desc).
    //	Returns				:   void
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    public void OrderByAgeAscSalaryDesc()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        Collections.sort(Table,(e1, e2) -> Integer.compare(e2.EmpSalary,e1.EmpSalary));

        Collections.sort(Table,(e1, e2) -> Integer.compare(e1.EmpAge, e2.EmpAge));

        System.out.println("Records sorted by EmpAge in Ascending Order and by EmpSalary in Descending Order");

        SelectStarFrom();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpName LIKE 'A%'
    //	Method Name			:	FindEmployeesNameStartsWithA
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Finds and displays employees whose names start with ‘A’.
    //	Returns				:   void
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    public void FindEmployeesNameStartsWithA()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        boolean found = false;

        for (Employee eref : Table)
        {
            if(eref.EmpName.startsWith("A"))
            {
                System.out.println("EmpID: "+eref.EmpID+", Name: "+eref.EmpName+ ", Age: "+eref.EmpAge+ ", Address: "+eref.EmpAddress+", Salary: "+eref.EmpSalary);
                found = true;
            }
        }

        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpName LIKE '%t'
    //	Method Name			:	FindEmployeesNameEndsWithT
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Finds and displays employees whose names end with ‘t’.
    //	Returns				:   void
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    public void FindEmployeesNameEndsWithT()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        boolean found = false;

        for (Employee eref : Table)
        {
            if(eref.EmpName.endsWith("t"))
            {
                System.out.println("EmpID: "+eref.EmpID+", Name: "+eref.EmpName+ ", Age: "+eref.EmpAge+ ", Address: "+eref.EmpAddress+", Salary: "+eref.EmpSalary);
                found = true;
            }
        }

        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   SELECT * FROM employee WHERE EmpName LIKE '%it%'
    //	Method Name			:	FindEmployeesNameContainsIt
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Finds and displays employees whose names contain ‘it’.
    //	Returns				:   void
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    public void FindEmployeesNameContainsIt()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        if (Table.isEmpty())
        {
            System.out.println("Table is empty");
            return;
        }

        boolean found = false;

        for (Employee eref : Table)
        {
            if(eref.EmpName.contains("it"))
            {
                System.out.println("EmpID: "+eref.EmpID+", Name: "+eref.EmpName+ ", Age: "+eref.EmpAge+ ", Address: "+eref.EmpAddress+", Salary: "+eref.EmpSalary);
                found = true;
            }
        }

        if(found == false)
        {
            System.out.println("There is no such record");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   ALTER TABLE employee ADD COLUMN EmpEmail VARCHAR(15)
    //	Method Name			:	AlterTableAddEmployeeEmail
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Adds the EmpEmail column to all employee records.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void AlterTableAddEmployeeEmail()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for (Employee eref : Table)
        {
            eref.EmpEmail = "";
        }

        System.out.println("Column 'EmpEmail' added to Employee table");
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   ALTER TABLE employee DROP COLUMN EmpEmail
    //	Method Name			:	AlterTableDropEmployeeEmail
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Removes the EmpEmail column from all employee records.
    //	Returns				:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    public void AlterTableDropEmployeeEmail()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        for (Employee eref : Table)
        {
            eref.EmpEmail = null;
        }

        System.out.println("Column 'EmpEmail' dropped from Employee table");
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   TRUNCATE TABLE employee
    //	Method Name			:	TruncateEmployeeTable
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Deletes all records but keeps the table structure unchanged.
    //	Returns				:   void
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    public void TruncateEmployeeTable()
    {
        if(Table == null)
        {
            System.out.println("Employee table does not exist so Operation cannot be done");
            return;
        }

        Table.clear();
        System.out.println("Employee table truncated & All records deleted,structure remains");
    }

    //////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Query               :   DROP TABLE employee
    //	Method Name			:	DropEmployeeTable
    //	Method Date			:	22/09/2025
    //	Method Author	    :	Ishwari Pravin Jadhav
    //	Parameters			:   None
    //	Description         :   Drops the Employee table and removes its structure.
    //	Returns				:   void
    //
    /////////////////////////////////////////////////////////////////////////////////////////////
    public void DropEmployeeTable()
    {
        Table = null;
        System.out.println("Employee table dropped & Table structure removed");
    }

} //End of MarvellousDBMS

class EmployeeDBMS
{
    public static void main(String A[])throws Exception
    {
        // Try to restore DBMS from backup file,otherwise create a new one
        MarvellousDBMS mobj = MarvellousDBMS.RestoreBackup("MarvellousDBMS.ser");

        if(mobj == null)
        {
            System.out.println("Unable to restore the backup");

            mobj = new MarvellousDBMS();
        }

        Scanner sobj = new Scanner(System.in);

        // Variable declarations for menu operations
        int iOption = 0;
        int age = 0;
        int salary = 0;
        int id = 0;

        String name = "";
        String address = "";

        System.out.println("--------------------------------------------------------------------------------------");
        System.out.println("---------------------------------- Marvellous DBMS -----------------------------------");
        System.out.println("--------------------------------------------------------------------------------------");

        // Display all available DBMS operations
        while(iOption != 45)
        {
            System.out.println("--------------------------------------------------------------------------------------");
            System.out.println("1 : INSERT INTO employee");
            System.out.println("2 : SELECT * from employee");
            System.out.println("3 : SELECT * FROM employee WHERE EmpID = ");
            System.out.println("4 : SELECT * FROM employee WHERE EmpName = ");
            System.out.println("5 : SELECT * FROM employee WHERE EmpAge = ");
            System.out.println("6 : SELECT * FROM employee WHERE EmpAddress = ");
            System.out.println("7 : SELECT * FROM employee WHERE EmpSalary = ");
            System.out.println("8 : DELETE  FROM employee WHERE EmpId = ");
            System.out.println("9 : DELETE  FROM employee WHERE EmpName = ");
            System.out.println("10 : DELETE  FROM employee WHERE EmpAge = ");
            System.out.println("11 : DELETE  FROM employee WHERE EmpAddress = ");
            System.out.println("12 : DELETE  FROM employee WHERE EmpSalary = ");
            System.out.println("13 : UPDATE  employee SET  EmpName = WHERE EmpId = ");
            System.out.println("14 : UPDATE  employee SET  EmpSalary = WHERE EmpName = ");
            System.out.println("15 : UPDATE  employee SET  EmpSalary = WHERE EmpAge = ");
            System.out.println("16 : UPDATE  employee SET  EmpName = WHERE EmpAddress = ");
            System.out.println("17 : UPDATE  employee SET  EmpSalary = WHERE EmpSalary = ");
            System.out.println("18 : Take a BACKUP of table");
            System.out.println("19 : SELECT COUNT(*) FROM employee");
            System.out.println("20 : SELECT MAX(EmpSalary) FROM employee");
            System.out.println("21 : SELECT MIN(EmpSalary) FROM employee");
            System.out.println("22 : SELECT AVG(EmpSalary) FROM employee");
            System.out.println("23 : SELECT SUM(EmpSalary) FROM employee");
            System.out.println("24 : SELECT COUNT(*),EmpAddress FROM employee GROUP BY EmpAddress");
            System.out.println("25 : SELECT * FROM employee ORDER BY EmpID ASC");
            System.out.println("26 : SELECT * FROM employee ORDER BY EmpName ASC");
            System.out.println("27 : SELECT * FROM employee ORDER BY EmpAge ASC");
            System.out.println("28 : SELECT * FROM employee ORDER BY EmpAddress ASC");
            System.out.println("29 : SELECT * FROM employee ORDER BY EmpSalary ASC");
            System.out.println("30 : SELECT * FROM employee ORDER BY EmpID DESC");
            System.out.println("31 : SELECT * FROM employee ORDER BY EmpName DESC");
            System.out.println("32 : SELECT * FROM employee ORDER BY EmpAge DESC");
            System.out.println("33 : SELECT * FROM employee ORDER BY EmpAddress DESC");
            System.out.println("34 : SELECT * FROM employee ORDER BY EmpSalary DESC");
            System.out.println("35 : SELECT * FROM employee ORDER BY EmpAddress ASC,EmpSalary DESC");
            System.out.println("36 : SELECT * FROM employee ORDER BY EmpSalary DESC,EmpName ASC");
            System.out.println("37 : SELECT * FROM employee ORDER BY EmpAge ASC,EmpSalary DESC");
            System.out.println("38 : SELECT * FROM employee WHERE EmpName LIKE 'A%'");
            System.out.println("39 : SELECT * FROM employee WHERE EmpName LIKE '%t'");
            System.out.println("40 : SELECT * FROM employee WHERE EmpName LIKE '%it%'");
            System.out.println("41 : ALTER TABLE employee ADD COLUMN EmpEmail VARCHAR(15)");
            System.out.println("42 : ALTER TABLE employee DROP COLUMN EmpEmail");
            System.out.println("43 : TRUNCATE TABLE employee");
            System.out.println("44 : DROP TABLE employee");
            System.out.println("45 : TERMINATE THE DBMS");
            System.out.println("--------------------------------------------------------------------------------------");


            System.out.println("Please Select the desired operation on the datatbase");
            iOption = sobj.nextInt();

            if(iOption == 1)
            {
                System.out.println("Please enter the data that you want to insert : ");

                sobj.nextLine();

                System.out.println("Enter the name of employee : ");
                name = sobj.nextLine();

                System.out.println("Enter the age of employee : ");
                age = sobj.nextInt();

                sobj.nextLine();

                System.out.println("Enter the address of employee : ");
                address = sobj.nextLine();

                System.out.println("Enter the salary of employee : ");
                salary = sobj.nextInt();

                mobj.InsertIntoTable(name,age,address,salary);
            }
            else if(iOption == 2)
            {
                mobj.SelectStarFrom();
            }
            else if(iOption == 3)
            {
                System.out.println("Enter the employee ID : ");
                id = sobj.nextInt();

                mobj.SelectSpecificID(id);
            }
            else if(iOption == 4)
            {
                sobj.nextLine();
                
                System.out.println("Enter the name of employee : ");
                name = sobj.nextLine();

                mobj.SelectSpecificName(name);
            }
            else if(iOption == 5)
            {   
                System.out.println("Enter the age of employee : ");
                age = sobj.nextInt();

                mobj.SelectSpecificAge(age);
            }
            else if(iOption == 6)
            {
                sobj.nextLine();
                
                System.out.println("Enter the address of employee : ");
                address = sobj.nextLine();

                mobj.SelectSpecificAddress(address);
            }
            else if(iOption == 7)
            {   
                System.out.println("Enter the salary of employee : ");
                salary = sobj.nextInt();

                mobj.SelectSpecificSalary(salary);
            }
            else if(iOption == 8)
            {
                System.out.println("Enter the employee ID : ");
                id = sobj.nextInt();

                mobj.DeleteSpecificID(id);
            }
            else if(iOption == 9)
            {
                sobj.nextLine();
                
                System.out.println("Enter the employee name : ");
                name = sobj.nextLine();

                mobj.DeleteSpecificName(name);
            }
            else if(iOption == 10)
            {
                System.out.println("Enter the employee age : ");
                age = sobj.nextInt();

                mobj.DeleteSpecificAge(age);
            }
            else if(iOption == 11)
            {
                sobj.nextLine();

                System.out.println("Enter the employee address : ");
                address = sobj.nextLine();

                mobj.DeleteSpecificAddress(address);
            }
            else if(iOption == 12)
            {
                System.out.println("Enter the employee salary : ");
                salary = sobj.nextInt();

                mobj.DeleteSpecificSalary(salary);
            }
            else if(iOption == 13)
            {
                System.out.println("Enter Employee ID to update : ");
                id = sobj.nextInt();

                sobj.nextLine();

                System.out.println("Enter the new name : ");
                String newName = sobj.nextLine();

                mobj.UpdateByID(id,newName);
            }
            else if(iOption == 14)
            {
                sobj.nextLine();

                System.out.println("Enter Employee name to update : ");
                name = sobj.nextLine();

                System.out.println("Enter the new salary : ");
                int newsalary = sobj.nextInt();

                mobj.UpdateByName(name,newsalary);
            }
            else if(iOption == 15)
            {
                System.out.println("Enter Employee age to update : ");
                age = sobj.nextInt();

                System.out.println("Enter the new salary : ");
                int newsalary = sobj.nextInt();

                mobj.UpdateByAge(age,newsalary);
            }
            else if(iOption == 16)
            {
                sobj.nextLine();

                System.out.println("Enter Employee address to update : ");
                address = sobj.nextLine();

                System.out.println("Enter the new name : ");
                String newname = sobj.nextLine();

                mobj.UpdateByAddress(address,newname);
            }
            else if(iOption == 17)
            {
                System.out.println("Enter Employee salary to update : ");
                salary = sobj.nextInt();

                System.out.println("Enter the new salary : ");
                int newsalary = sobj.nextInt();

                mobj.UpdateBySalary(salary,newsalary);
            }
            else if(iOption == 18)
            {
                mobj.TakeBackup();
                System.out.println("Database gets succesfully stored into secondary storage");
            }
            else if(iOption == 19)
            {
                mobj.GetEmployeeCount();
            }
            else if(iOption == 20)
            {
                mobj.GetMaximumSalary();
            }
            else if(iOption == 21)
            {
                mobj.GetMinimumSalary();
            }
            else if(iOption == 22)
            {
                mobj.GetAverageSalary();
            }
            else if(iOption == 23)
            {
                mobj.GetSumOfSalary();
            }
            else if(iOption == 24)
            {
                mobj.GroupEmployeesByAddress();
            }
            else if(iOption == 25)
            {
                mobj.OrderByIDAsc();
            }
            else if(iOption == 26)
            {
                mobj.OrderByNameAsc();
            }
            else if(iOption == 27)
            {
                mobj.OrderByAgeAsc();
            }
            else if(iOption == 28)
            {
                mobj.OrderByAddressAsc();
            }
            else if(iOption == 29)
            {
                mobj.OrderBySalaryAsc();
            }
            else if(iOption == 30)
            {
                mobj.OrderByIDDesc();
            }
            else if(iOption == 31)
            {
                mobj.OrderByNameDesc();
            }
            else if(iOption == 32)
            {
                mobj.OrderByAgeDesc();
            }
            else if(iOption == 33)
            {
                mobj.OrderByAddressDesc();
            }
            else if(iOption == 34)
            {
                mobj.OrderBySalaryDesc();
            }
            else if(iOption == 35)
            {
                mobj.OrderByAddressAscSalaryDesc();
            }
            else if(iOption == 36)
            {
                mobj.OrderBySalaryDescNameAsc();
            }
            else if(iOption == 37)
            {
                mobj.OrderByAgeAscSalaryDesc();
            }
            else if(iOption == 38)
            {
                mobj.FindEmployeesNameStartsWithA();
            }
            else if(iOption == 39)
            {
                mobj.FindEmployeesNameEndsWithT();
            }
            else if(iOption == 40)
            {
                mobj.FindEmployeesNameContainsIt();
            }
            else if(iOption == 41)
            {
                mobj.AlterTableAddEmployeeEmail();
            }
            else if(iOption == 42)
            {
                mobj.AlterTableDropEmployeeEmail();
            }
            else if(iOption == 43)
            {
                mobj.TruncateEmployeeTable();
            }
            else if(iOption == 44)
            {
                mobj.DropEmployeeTable();
            }
            else if(iOption == 45)
            {
                System.out.println("Thank you for using Marvellous DBMS");
                mobj = null;
                System.gc();
                break;
            }
        } //End of while
    } //End of main method
} //End of main class