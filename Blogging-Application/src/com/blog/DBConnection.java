//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Project     : Blogging Application
// File        : DBConnection.java
// Description : Utility class to establish a JDBC connection to the MariaDB database.
// Author      : Ishwari Pravin Jadhav
// Date        : 14/11/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

package com.blog;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {
    private static Connection connection = null;

    public static Connection getConnection() {
        try {
            // If connection is null OR closed, create a new one
            if (connection == null || connection.isClosed()) {
                Class.forName("com.mysql.cj.jdbc.Driver");
                connection = DriverManager.getConnection(
                        "jdbc:mysql://localhost:3306/blogdb",
                        "root",
                        "" // replace with your password if any
                );
                System.out.println("Database connected successfully!");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return connection;
    }
}
