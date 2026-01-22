# 💾 Customized Virtual File System (CVFS)
> This project is a Customized implementation of a Virtual File System (VFS) that simulates the core functionality of the Linux file
system. It is built entirely in C++, with its own custom shell to interact with the virtual environment. The project provides a practical
understanding of system calls, file handling, memory management, and OS internals.

---

## 📖 Project Overview
The Customized Virtual File System (CVFS) is a console-based simulation of a real file system.
It allows users to perform operations such as create, read, write, append, copy, rename, delete, and list files — all in a virtual environment without using actual disk I/O.

- This project is designed to enhance understanding of:
  • File handling and memory management.
  • Inode and file descriptor structures.
  • Command interpretation (custom shell).
  • Error and permission handling.
  • Operating system file management principles.

---

## 📁 Folder Structure
```
Customized Virtual File System/
│
├── CVFS.cpp
├── README.md  
```

---

## 🧩 Features
- Custom Shell Interface : 
  Provides Linux-like commands for file operations (create, open, read, write, delete, ls, etc).

- System Call Simulation : 
  Implements core Linux file system calls (open, read, write, lseek, close, rm, etc).

- File System Data Structures : 
  • Incore Inode Table
  • File Table
  • UAREA (User Area)
  • User File Descriptor Table

- Platform Independent :
  Allows system-level file handling functionalities of Linux to be used on any operating system platform.

- Database-like Functionality :
  Provides a customised database management layer with structured file handling.
    
---

## 🧠 Learning Objectives 
- Deep understanding of Linux File System internals. 
- Practical knowledge of data structures used in OS (inode, file tables, UAREA). 
- Strong grasp of system programming in C++. 
- Hands-on with shell design & command interpreter. 
- Application of low-level logic building for OS-like environments.

---

## ⚙️ How to Run

### Compilation
```bash
g++ CVFS.cpp -o CVFS
```

### Execution
```bash
./CVFS      # On Linux / Mac
CVFS.exe    # On Windows
```

---

## 🧪 Example Usage
Below is a sample interaction with the Customized Virtual File System (CVFS) using its custom shell interface:

```
-------------------------------------------------------------
----------- Marvellous CVFS Started Successfully ------------
-------------------------------------------------------------

Marvellous CVFS > create Demo.txt 3
File is successfully created with FD : 0

Marvellous CVFS > write 0
Please enter the data that you want to write into the file :
Hello Marvellous!

15 bytes successfully written into the file.

Marvellous CVFS > read 0 15
Read operation is successful
Data from file is : Hello Marvellous!

Marvellous CVFS > append 0
Please enter the data you want to append :
This is CVFS simulation.
27 bytes appended successfully

Marvellous CVFS > ls
---------------------------------------------------------------
File Name        Inode Number      File Size      Permission
---------------------------------------------------------------
Demo.txt         1                 42 Bytes       Read & Write
---------------------------------------------------------------

Marvellous CVFS > unlink Demo.txt
Unlink Operation performed successfully

Marvellous CVFS > exit
Thank you for using Marvellous CVFS
Deallocating all resources...
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
////////////////////////////////////////////////////////////////////////////////////
// 
// Project     :  Customized Virtual File System (CVFS)
// File        :  CVFS.cpp
// Description :  Implementation of a command-line based virtual file system 
//                supporting multiple file operations and in-memory management.
// Author      :  Ishwari Pravin Jadhav
// Date        :  10/08/2025
//
////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
Customized Virtual File System (CVFS) — C++ Project
2025
```

---

## 🔖 Tags
C++, FileSystem, VirtualFileSystem, OperatingSystemConcepts, Inode, FileHandling, LogicBuilding, CLI, ShellSimulation, ErrorHandling.

---

> 💡 *Customized Virtual File System (CVFS): A virtual implementation of core file system concepts, demonstrating efficient command processing, memory management, and logical design in C++.*