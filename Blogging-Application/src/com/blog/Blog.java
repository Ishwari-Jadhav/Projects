//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Project     : Blogging Application
// File        : Blog.java
// Description : This class represents a Blog entity with fields like id, title, content, 
//               author, and created_at. Used for storing blog data in the application.
// Author      : Ishwari Pravin Jadhav
// Date        : 14/11/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

package com.blog;

public class Blog
{
    private int id;
    private String title;
    private String content;
    private String author;

    // Constructor
    public Blog(String title, String content, String author)
    {
        this.title = title;
        this.content = content;
        this.author = author;
    }

    //Getters
    public String getTitle()
    {
        return title;
    }

    public String getContent()
    {
        return content;
    }

    public String getAuthor()
    {
        return author;
    }
}

//to compile : javac -cp "C:\apache-tomcat-9.0.111\apache-tomcat-9.0.111\lib\servlet-api.jar" -d "C:\apache-tomcat-9.0.111\\apache-tomcat-9.0.111\webapps\BlogApp\WEB-INF\classes" *.java