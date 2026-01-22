# 📝 Blogging Application – APCOER Insights Blog
> A Java-based web application for creating, viewing, and managing blog posts.
Designed for students and professionals to explore, share knowledge, and practice Java Servlets, JSP, and JDBC.

---

## 📖 Project Overview
The Blogging Application enables users to:

- Add new blog posts with title, content, and author information.
- View all existing blog posts in a clean, professional interface.
- Delete specific blog posts by ID.

The project demonstrates Java Servlet programming, JSP integration, JDBC database connectivity, and basic web application design principles.

---

## 📁 Folder Structure
```
Blogging Application/
│
├─ src/
│   └─ com/blog/
│       ├─ Blog.java
│       ├─ BlogServlet.java
│       ├─ DBConnection.java
│       ├─ DeleteBlogServlet.java
│       └─ ViewBlogServlet.java
│
├─ WebContent/
│   ├─ addblog.html
│   ├─ deleteblog.html
│   ├─ index.html
│   ├─ viewblog.jsp
│   ├─ success.jsp
│   └─ error.jsp
│  
├─ WebContent/WEB-INF/
│   ├─ web.xml
│
├─ Screenshots/
│   ├─ 1.home_page.png
│   ├─ 2.add_blog.png
│   ├─ 3.blog_added.png
│   ├─ 4.view_blog.png
│   ├─ 5.delete_blog.png
│   └─ 6.view_blog (after deletion).png
│
├─ .gitignore
│
└─ README.md
```

---

## 🧩 Features
- Add Blog : Create new blog posts with title, content, and author name.
- View Blogs : Display all blog posts with ID, title, author, and content.
- Delete Blog : Remove a blog post by specifying its ID.
- Sequential IDs : Blog IDs are automatically updated after deletion.
- Clean UI : Modern and user-friendly interface using HTML and CSS.
    
---

## 🧠 Learning Objectives 
- Understand Java Servlet and JSP programming for web applications.
- Learn JDBC database connectivity and CRUD operations.
- Implement a simple web application using Tomcat server.
- Understand session management and user interaction through web forms.
- Practice organizing code and resources in a professional project structure.

---

## ⚙️ How to Run

### 1. Setup Database
```bash
CREATE DATABASE blogdb;

USE blogdb;

CREATE TABLE blog (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    content TEXT NOT NULL,
    author VARCHAR(100) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

### 2. Configure JDBC
```bash
- Place mysql-connector-java-x.x.x.jar in WEB-INF/lib/ folder.
- Update DBConnection.java with correct database URL, username, and password.
```

### 3. Compile Java Code
```bash
cd src
javac -cp "C:\apache-tomcat-9.0.111\lib\servlet-api.jar" -d ../WebContent/WEB-INF/classes com/blog/*.java
```

### 4. Start Tomcat
```bash
cd C:\apache-tomcat-9.0.111\bin
startup.bat
```

### 5. Access Application
```bash
- Home page: http://localhost:8080/BlogApp/
- Add Blog: http://localhost:8080/BlogApp/addblog.html
- View Blogs: http://localhost:8080/BlogApp/viewblogs
- Delete Blog: http://localhost:8080/BlogApp/deleteblog.html
```

---

## 🧾 Screenshots

Screenshots attached are : 

- Home Page
- Add Blog Page
- View Blogs Page
- Delete Blog Page

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Project     : Blogging Application
// File        : [FileName].java
// Description : This file is part of a Java-based blogging application that allows users
//               to add, view, and delete blog posts. It demonstrates servlet, JSP, and 
//               JDBC integration with MariaDB.
// Author      : Ishwari Pravin Jadhav
// Date        : 14/11/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
Blogging Application – Java Web Project
2025
```

---

## 🔖 Tags
Java, Servlet, JSP, JDBC, MySQL, Web Application, CRUD, Blogging, HTML, Tomcat.

---

---

## © Copyright Notice
```
© 2025 Ishwari Jadhav
This project "Blogging Application" is my original work.  
For learning and interview purposes only.  
Do not copy, distribute, or reuse without permission.
```

---

> 💡 *Blogging Application – A Java web project demonstrating CRUD operations using Servlets, JSP, and JDBC with a clean, professional interface.*