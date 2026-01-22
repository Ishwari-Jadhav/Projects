# 📊 Study Tracker App
> The Marvellous Study Tracker App is a console-based Java application designed to help students systematically log, track, summarize, and export their study activities. 
It allows users to maintain daily study records, view summaries grouped by date or subject, and export all logs into a CSV file for offline reference. 
This project demonstrates practical usage of Java Collections, File I/O, and Object-Oriented Design in a real-world, utility-driven application.

---

## 📖 Project Overview

### Technologies Used
- Language: Java
- Packages & APIs:
  • `java.util.*` → Data structures (ArrayList, TreeMap), user input via Scanner
  • `java.time.LocalDate` → Auto-captures current date for study logs
  • `java.io.*` → File handling and CSV export
  • `javax.swing.*`, `java.awt.*`, `java.awt.event.*` → GUI components

### Project Flow
1. Launch the application → Main Menu displayed.
2. Choice 1 : Insert new study log → User provides subject, duration, description → Date auto-generated.
3. Choice 2 : Display all study logs stored in memory.
4. Choice 3 : Display summary grouped by date (total hours per day).
5. Choice 4 : Display summary grouped by subject (total hours per subject).
6. Choice 5 : Export all study logs to `MarvellousStudy.csv`.
7. Choice 6 : Exit application.

### Classes & Responsibilities
- StudyLog
  • Represents a single study session
  • Attributes: LocalDate date, String subject, double duration, String description
  • Methods: Constructor, getters, toString()

- Study_Tracker
  • Manages all logs in memory
  • Attributes: ArrayList<StudyLog> database
  • Methods: InsertLog(), DisplayLog(), SummaryByDate(), SummaryBySubject(), ExportCSV(), plus GUI equivalents

- StudyTracker / StudyTrackerGUI
  • Main entry points for Console (CUI) or GUI modes
  • Handles user interaction and calls Study_Tracker methods

---

## 📁 Folder Structure
```
StudyTrackerApp/
│
├─ StudyTracker.java
└─ README.md
```

---

## 🧩 Features
- Insert Study Log :
  • Record study sessions with date (auto-generated), subject, duration, and description. 

- Display Logs :
  • View all study logs currently stored in memory. 

- Summary by Date :
  • Calculate & display total study hours grouped by date. 

- Summary by Subject :
  • Calculate & display total study hours grouped by subject. 

- Export to CSV :
  • Export all study logs into a CSV file (MarvellousStudy.csv) for offline tracking.

- User-Friendly Console Menu :
  • Menu-driven interface with switch-case navigation for ease of use.
    
---

## 🧠 Learning Objectives 
- Practice Java Object-Oriented Programming (OOP) principles.
- Implement generic collection management with ArrayList and TreeMap.
- Work with LocalDate for automatic timestamping of entries.
- Perform file operations and CSV export using Java I/O.
- Develop both console and GUI-based Java applications.

---

## ⚙️ How to Run

### Compilation
```bash
javac StudyTracker.java
```

### Execution
```bash
# Console Mode
java StudyTracker

# GUI Mode
java StudyTracker
# Choose option 2 in the menu for GUI interface
```

---

## 🧪 Example Usage
Below are sample interactions demonstrating both Console and GUI workflows :

- CUI Mode
```
-----------------------------------------------------------------------------------
---------------- Welcome to Marvellous Study Tracker Application ------------------
-----------------------------------------------------------------------------------
Select mode:
1 : Console Mode (CUI)
2 : GUI Mode
Enter your choice: 1
-----------------------------------------------------------------------------------
Please select the appropriate option
1 : Insert new Study Log into Database
2 : View All Study Log
3 : Summary of Study Log by Date
4 : Summary of Study Log by Subject
5 : Export Study Log to CSV file
6 : Exit the application
Enter your choice: 1

Please provide name of subject: Java
Enter the time period of your study in hours: 2
Provide description: Practiced OOP concepts
StudyLog gets stored successfully

Enter your choice: 2
-----------------------------------------------------------------------------------
-----------------------All Study Logs-----------------------
2025-10-25 | Java | 2.0 | Practiced OOP concepts
-----------------------------------------------------------------------------------

Enter your choice: 3
------------------Summary By Date--------------------------
Date : 2025-10-25 Total Study 2.0
-----------------------------------------------------------------------------------

Enter your choice: 4
------------------Summary By Subject-----------------------
Subject : Java Total Study 2.0
-----------------------------------------------------------------------------------

Enter your choice: 5
Log exported successfully to MarvellousStudy.csv
-----------------------------------------------------------------------------------
```

- GUI Mode
```
- Launch the app and select GUI Mode.
- Click Insert new Study Log, enter:
  • Subject: Java
  • Duration: 2
  • Description: Practiced OOP concepts
- Click View All Study Log → Displays logs in the text area.
- Click Summary by Date / Summary by Subject → Shows totals grouped by date/subject.
- Click Export CSV → Saves MarvellousStudy.csv to the current directory.
- Click Exit → Closes the application.
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Study Tracker App
// File        :  StudyTracker.java
// Description :  Implements a Console (CUI) + GUI based application to log, summarize,
//                and export daily study activities.
// Author      :  Ishwari Pravin Jadhav
// Date        :  28/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
Study Tracker App — Java Project
2025
```

---

## 🔖 Tags
Java, OOP, Collections, ArrayList, TreeMap, LocalDate, FileHandling, CSV, GUI, Swing, ConsoleApp, StudyTracker, Logging, SummaryReports.

---

> 💡 *Study Tracker App :  A Java project for logging, summarizing, and exporting study sessions, with both console and GUI interfaces.*