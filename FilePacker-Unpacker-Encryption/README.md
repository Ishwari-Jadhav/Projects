# 📦 File Packer-Unpacker
> This project is a Java-based file utility tool that provides functionality for packing multiple files into a single archive and
unpacking them back with all metadata preserved.
To enhance security, the packed file is encrypted, and only authorized users can decrypt & extract the data. 
The project also features a Graphical User Interface (GUI) for user-friendly interaction.

---

## 📖 Project Overview
The File Packer-Unpacker project is a hybrid Console + GUI Java application designed to simplify file storage and transfer.
It recursively traverses directories, packs selected files into one compressed output file, and can later unpack them to restore the original structure.

- This project helps understand key programming concepts such as:
  • File I/O (Input/Output Stream operations)
  • Directory traversal and recursion
  • Header-based file storage
  • Exception handling and stream management
  • GUI integration with Swing

---

## 📁 Folder Structure
```
File Packer-Unpacker/
│
├── MarvellousPackerUnpacker.java
├── README.md
```

---

## 🧩 Features
- File Packing
  • Combines multiple regular files into a single archive file. 
  • Stores metadata (file name, size, timestamp) along with file content. 

- File Unpacking
  • Extracts individual files from the packed archive. 
  • Restores all original metadata and file structure. 

- Data Security
  • Built-in encryption and decryption to protect packed files.

- Graphical User Interface (GUI)
  • User-friendly GUI built in Java (Swing).
  • Provides simple options for selecting files, encrypting, packing, and unpacking.

- Cross-platform
  • Runs seamlessly on any system with a Java Runtime Environment (JRE).
    
---

## 🧠 Learning Objectives 
- Practical experience with Java I/O Streams and File Handling APIs. 
- Implementation of metadata management during file operations. 
- Strong understanding of encryption/decryption techniques in Java. 
- Hands-on experience with GUI development (Swing). 
- Insight into archiving and compression utilities (similar to ZIP/TAR).

---

## ⚙️ How to Run

### Compilation
```bash
javac MarvellousPackerUnpacker.java
```

### Execution
```bash
java MarvellousPackerUnpacker
```

---

## 🧪 Example Usage
Below is a sample console interaction with the Marvellous Packer-Unpacker :

- CUI Mode
```
---------------------------------------------------------
---------- Marvellous Packer-Unpacker Utility ------------
---------------------------------------------------------
1 : Pack files
2 : Unpack files
3 : Exit
---------------------------------------------------------
Enter your choice :
1
Enter folder name to pack : D:\Marvellous\Test
Enter name of packed file : AllFiles.pack
Packing process initiated...
File packed successfully.

---------------------------------------------------------
Enter your choice :
2
Enter name of packed file : AllFiles.pack
Enter destination folder to unpack : D:\Marvellous\Output
Unpacking process initiated...
Files successfully unpacked.
---------------------------------------------------------
Thank you for using Marvellous Packer-Unpacker!
```

- GUI Mode
```
[GUI Window Opens]
---------------------------------------------------------
Select Option:
[1] Pack Files
[2] Unpack Files

> Choose "Pack Files"
> Browse Source Folder: D:\Marvellous\Test
> Enter Output File Name: AllFiles.pack
> Click "Start Packing"

Packing Completed Successfully!
---------------------------------------------------------
Similarly, use "Unpack Files" to restore data.
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
////////////////////////////////////////////////////////////////////////////////
// 
// Project     :  File Packer-Unpacker
// File        :  MarvellousPackerUnpacker.java
// Description :  Implements a CUI + GUI based file packing and unpacking 
//                system with directory traversal. 
// Author      :  Ishwari Pravin Jadhav
// Date        :  21/07/2025
//
////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
File Packer-Unpacker — Java Project
2025
```

---

## 🔖 Tags
Java, FileHandling, DirectoryTraversal, PackerUnpacker, GUI, CUI, Streams, ExceptionHandling, LogicBuilding, FileIO, Swing, Serialization.

---

> 💡 *File Packer-Unpacker :  A practical Java project demonstrating efficient file packing and unpacking through CUI and GUI interfaces.*