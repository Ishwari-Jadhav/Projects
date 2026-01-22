# 🎓 EduTrack – Classroom & Student Management Portal
> A console-based Java Frontend Client + Spring Boot Backend + MongoDB (NoSQL) project that manages batches, trainers, schedules, and student enrollment.
This system provides a practical understanding of REST APIs, JSON data handling, backend service layers, and menu-driven frontend communication.

---

## 📖 Project Overview
EduTrack Portal is a complete educational management system developed using:

 • Backend: Java, Spring Boot, MongoDB
 • Frontend: Java-based console client
 • Architecture: REST API + JSON + NoSQL database

- The EduTrack Portal is a full-stack Java-based web + client application designed to manage and streamline academic activities. 
- The portal provides CRUD operations for managing batches along with detailed student records in each batch. 
- It leverages Spring Boot for building a RESTful backend, MongoDB for scalable data storage, and a Java client application for user interaction. 
- The system simplifies batch creation, student management, and record updates, making it a centralized classroom management solution.

---

## 📁 Folder Structure
```
EduTrack – Classroom & Student Management Portal/
│
├── backend/
│   ├── src/main/java/com/marvellous/MarvellousPortal/
│   │     ├── controller/
│   │     ├── service/
│   │     ├── repository/
│   │     └── entity/
│   ├── pom.xml
│
├── client/
│   ├── src/main/java/com/edutrack/client/Main.java
│   ├── pom.xml
│
└── README.md
```

---

## 🧩 Features
- Batch Management
  • Create, update, delete, and view batches. 
  • Store details such as batch name, schedule, duration, and trainer info. 

- Student Records
  • Maintain student details (name, contact, enrollment date, assigned batch). 
  • Link students dynamically with their respective batch. 

- CRUD Operations
  • REST APIs for Create, Read, Update, Delete functionalities. 

- Database Integration
  • Uses MongoDB for flexible and scalable data storage.

- Client-Side Application
  • Java-based client with user-friendly menu to interact with backend APIs. 

- Scalable & Modular Design
  • Built on Spring Boot architecture,allowing easy integration with future features (attendance, performance tracking, fee management).  

---

## 🧠 Learning Objectives
- Hands-on experience with Spring Boot framework for backend development. 
- Practical understanding of MongoDB and NoSQL data modeling. 
- Exposure to REST API design and client-server architecture. 
- Strong application of full-stack Java development. 
- Experience in modular project design suitable for real-world systems.

---

## ⚙️ How to Run

### Backend (Spring Boot)
Navigate to backend folder:
```bash
cd backend
mvn spring-boot:run
```
Backend starts at:
```bash
http://localhost:8080
```
OR run directly via IntelliJ.

### Frontend (Java Client)
Navigate to client folder:
```bash
cd client
javac Main.java
java Main
```
OR run directly via IntelliJ.

---

## 🧪 Example Usage
Below is a sample interaction with the EduTrack-Portal using the console menu :

```
===== EduTrack Portal =====
1. Create New Batch
2. View All Batches
3. Update Batch
4. Delete Batch
5. Add Student to Batch
6. View Students in a Batch
7. Exit
Enter Choice: 1

Batch ID: B101
Batch Name: Java Full Stack
Trainer: Piyush Sir
Schedule: Mon-Wed-Fri 10am
Fees: 12000
Status: 201 CREATED

--------------------------------------

Enter Choice: 5
Batch ID: B101
Student Name: Ishwari
Contact: 9876543210
Status: 200 OK
Student added successfully

--------------------------------------

Enter Choice: 6
Batch ID: B101
=== Students in Batch ===
{name=Ishwari, contact=9876543210, enrollmentDate=2025-11-18}
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  Main.java / Controllers / Services
// Description :  A complete academic batch & student management system using Java console 
//                frontend, Spring Boot backend, and MongoDB NoSQL database.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
EduTrack – Classroom & Student Management Portal - Java Project
2025
```

---

## 🔖 Tags
Java, SpringBoot, MongoDB, RESTAPI, CRUD, ConsoleApplication, NoSQL, JSON, MenuDriven, EduTrack, StudentManagement, BatchManagement, LogicBuilding.

---

> 💡 *EduTrack – Classroom & Student Management Portal : A fully functional batch & student management system using a Java console client, REST APIs, and MongoDB.*