//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Project     : Blogging Application
// File        : BlogServlet.java
// Description : Servlet to handle adding new blog posts to the database using JDBC.
// Author      : Ishwari Pravin Jadhav
// Date        : 14/11/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

package com.blog;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

// Map this servlet to /addblog
@WebServlet("/addblog")
public class BlogServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    // Handles GET requests
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Redirect to the add blog form
        response.sendRedirect("addblog.html");
    }

    // Handles POST requests (form submission)
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Get form data
        String title = request.getParameter("title");
        String author = request.getParameter("author");
        String content = request.getParameter("content");

        try {
            // Get database connection
            Connection conn = DBConnection.getConnection();

            // Prepare SQL insert
            String sql = "INSERT INTO blog(title, author, content) VALUES (?, ?, ?)";
            PreparedStatement pst = conn.prepareStatement(sql);
            pst.setString(1, title);
            pst.setString(2, author);
            pst.setString(3, content);

            // Execute insert
            int rows = pst.executeUpdate();
            if (rows > 0) {
                response.sendRedirect("success.jsp"); // Redirect to success page
            } else {
                response.sendRedirect("error.jsp"); // Redirect to error page
            }

            // Close resources
            pst.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
            response.sendRedirect("error.jsp");
        }
    }
}
