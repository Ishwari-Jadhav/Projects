# 🔒 Secure File Transfer System (SFTS).
> A Windows-based simulation project that demonstrates the concept of cryptography and system-level programming using the Win32 SDK. 
The project implements Caesar Cipher and XOR Cipher for encryption/decryption and performs file handling via Windows system calls instead of standard C library functions. 
The cryptographic logic is modularized into a Dynamic Link Library (DLL), making the functionality reusable by multiple client  applications. 
This project showcases low-level programming, system calls, and DLL development in a practical and secure context.

---

## 📖 Project Overview
The Secure File Transfer System (SFTS) is a Windows-based application that encrypts and decrypts files using custom algorithms.  
It is divided into two modules — Server (DLL) and Client.  
The Server module (`ServerSFTS.dll`) contains reusable encryption logic, while the Client module (`ClientSFTS.cpp`) dynamically loads the DLL at runtime to securely process text files.

The project demonstrates:
- Modular software design using DLLs.
- Practical implementation of classical cryptographic algorithms.
- Secure and efficient file handling using Win32 APIs.

---

## 📁 Folder Structure
```
Secure File Transfer System/
│
├─ ServerSFTS.cpp
├─ ClientSFTS.cpp
└─ README.md
```

---

## 🧩 Features
- File-based Encryption & Decryption
  • Supports secure encryption/decryption of text files.

- Multiple Algorithms Implemented
  • Caesar Cipher (character shift-based substitution) 
  • XOR Cipher (bitwise XOR with user-defined key) 

- System-Level File Handling
  • Uses Win32 SDK APIs (CreateFile, ReadFile, WriteFile, CloseHandle) instead of high-level C functions. 

- DLL Integration
  • Exported reusable functions through a custom DLL. 
  • Client applications dynamically load and use encryption/decryption services. 

- Low-Level Programming Practice
  • Worked extensively with pointers, buffers, and string processing. 
  • Strengthened debugging skills with Visual Studio and Windows tools.
    
---

## 🧠 Learning Objectives 
- Proficiency in C programming and Win32 SDK system programming. 
- Experience in DLL creation, exporting/importing functions, and client integration. 
- Strong understanding of Windows API for file I/O and process handling. 
- Practical knowledge of cryptographic techniques (Caesar & XOR cipher). 
- Hands-on with modular project development and secure file transfer concepts.

---

## ⚙️ How to Run

### Compilation & Setup
```bash
1. Open Visual Studio → Create a new DLL Project named ServerSFTS.
   • Add ServerSFTS.cpp → Build to generate ServerSFTS.dll.

2. Create another Console Project named ClientSFTS.
   • Add ClientSFTS.cpp and place the generated ServerSFTS.dll in the same folder as ClientSFTS.exe.

3. Add a sample input file:
   • Create Input.txt in the same directory as ClientSFTS.exe.

4. Build both projects (DLL and Client) in Visual Studio.
```

### Execution
```bash
1. Run ClientSFTS.exe
2. The client dynamically loads ServerSFTS.dll and performs encryption on Input.txt.
3. The encrypted output is written to Output.txt.
4. For decryption, modify the client code to call Decrypt_Ceasor_Cipher or Decrypt_XOR_Cipher similarly.
```

---

## 🧪 Example Usage
Below is a simulated console output showing the workflow of the Secure File Transfer System:

```
---------------------------------------------------------
-------- Secure File Transfer System (SFTS) ------------
---------------------------------------------------------
Attempting to load ServerSFTS.dll...
DLL loaded successfully

Encrypting file: Input.txt using Caesar Cipher
Encryption complete
Encrypted output stored as: Output.txt

Decrypting file: Output.txt using Caesar Cipher
Decryption complete
Restored original file as: Decrypted_Input.txt

DLL unloaded successfully
---------------------------------------------------------
Input.txt             → Original file
Output.txt            → Encrypted file (Caesar Cipher)
Decrypted_Input.txt   → Restored original file
---------------------------------------------------------
Thank you for using Secure File Transfer System (SFTS)
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Secure File Transfer System (SFTS)
// File        :  ClientSFTS.cpp / ServerSFTS.cpp
// Description :  Implements encryption and decryption functionalities using Caesar and XOR
//                ciphers. The logic is modularized into a DLL for secure file transfer.
// Author      :  Ishwari Pravin Jadhav
// Date        :  12/09/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
Secure File Transfer System (SFTS) — C++ Project
2025
```

---

## 🔖 Tags
C++, Cryptography, CaesarCipher, XORCipher, DLL, Win32, SystemProgramming, FileHandling, DynamicLinkLibrary, ModularDesign, LogicBuilding.

---

> 💡 *Secure File Transfer System (SFTS) :  A modular C++ project demonstrating cryptography, system programming, and dynamic DLL integration for secure file handling on Windows.*