# 💾 Customized Database Management System (DBMS).
> This project is a Customized implementation of a Database Management System (DBMS) built entirely in Java. It simulates core SQL
operations such as SELECT, INSERT, UPDATE, DELETE, ORDER BY, and table management — all in a console-based environment without using an
actual database engine. The project provides a practical understanding of data handling, sorting, filtering, and file-based persistence.

---

## 📖 Project Overview
The Marvellous DBMS is a console-based simulation of a relational database.
It allows users to perform operations such as inserting, updating, deleting, querying, sorting, grouping, and taking backups of employee records — all in memory and serialized files for persistence.

- This project is designed to enhance understanding of:
  • Data storage and retrieval techniques.
  • SQL query simulation and operations.
  • Sorting, filtering, and aggregation of data.
  • File-based backup and restore.
  • Basic database design principles.

---

## 📁 Folder Structure
```
Customized Database Management System/
│
├── EmployeeDBMS.java
├── README.md
```

---

## 🧩 Features
- SQL-like Operations :
  Supports SELECT, INSERT, UPDATE, DELETE, ORDER BY, GROUP BY, COUNT, SUM, AVG, MIN, MAX.

- Table Management :
  • Create, truncate, and drop employee table.
  • Add or drop columns dynamically (e.g., EmpEmail).

- Sorting & Filtering :
  • Multiple sorting options (ascending/descending by ID, Name, Age, Address, Salary).
  • Conditional filtering (like WHERE EmpName LIKE 'A%', '%t', '%it%').

- Backup & Restore :
  Save and restore the database state using serialization.

- Console-based Menu :
  Interactive menu-driven interface for performing all database operations.

- File-based Persistence :
  Data can be saved into .ser file and restored later.
    
---

## 🧠 Learning Objectives 
- Understand basic DBMS concepts and SQL operations.
- Implement CRUD operations programmatically in Java.
- Learn sorting, searching, and filtering techniques on objects.
- Gain experience with Java collections (ArrayList, Collections.sort).
- Practice file I/O and object serialization for data persistence.
- Build a menu-driven console application with robust input handling.

---

## ⚙️ How to Run

### Compilation
```bash
javac EmployeeDBMS.java
```

### Execution
```bash
java EmployeeDBMS
```

---

## 🧪 Example Usage
Below is a sample interaction with the Marvellous DBMS using the console menu :

```
--------------------------------------------------------------------------------------
---------------------------------- Marvellous DBMS -----------------------------------
--------------------------------------------------------------------------------------
1 : INSERT INTO employee
2 : SELECT * from employee
3 : SELECT * FROM employee WHERE EmpID = 
...
45 : TERMINATE THE DBMS
--------------------------------------------------------------------------------------
Please Select the desired operation on the database

Enter the data that you want to insert:
Enter the name of employee : John
Enter the age of employee : 28
Enter the address of employee : Mumbai
Enter the salary of employee : 50000
Record inserted successfully

Select * from employee:
EmpID: 1, Name: John, Age: 28, Address: Mumbai, Salary: 50000

SELECT * FROM employee WHERE EmpName LIKE 'A%':
There is no such record

ORDER BY EmpSalary DESC:
Records sorted by EmpSalary in Descending Order
EmpID: 1, Name: John, Age: 28, Address: Mumbai, Salary: 50000

Take a BACKUP of table:
Database gets successfully stored into secondary storage

TERMINATE THE DBMS
Thank you for using Marvellous DBMS
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
//////////////////////////////////////////////////////////////////////////////////////////////
// 
// Project     :  Customized Database Management System (DBMS)
// File        :  EmployeeDBMS.java
// Description :  This project simulates a lightweight, file-based DBMS for managing employee 
//                records with auto-generated IDs, CRUD operations, and persistent storage 
//                using Java serialization.
// Author      :  Ishwari Pravin Jadhav
// Date        :  22/09/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
Customized Database Management System (DBMS) — Java Project
2025
```

---

## 🔖 Tags
Java, DBMS, CRUD, SQLSimulation, ObjectOrientedProgramming, FileHandling, Serialization, MenuDriven, Sorting, Filtering, Aggregation, LogicBuilding.

---

> 💡 *Customized Database Management System (DBMS) : A fully functional simulation of database operations demonstrating sorting, filtering, aggregation, and backup/restore in Java.*