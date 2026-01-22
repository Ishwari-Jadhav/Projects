//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Project     : Blogging Application
// File        : ViewBlogServlet.java
// Description : Servlet to handle viewing all blog posts from the database. 
// Author      : Ishwari Pravin Jadhav
// Date        : 14/11/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

package com.blog;

import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class ViewBlogsServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {

        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        out.println("<html><body>");
        out.println("<h2 style='text-align:center;'>All Blog Posts</h2>");
        out.println("<div style='width:80%; margin:0 auto;'>");

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DBConnection.getConnection(); // or DriverManager.getConnection(...)
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM blog ORDER BY id");

            while (rs.next()) {
                out.println("<div style='border:1px solid #d3d2d2ff; padding:10px; margin:10px;'>");
                out.println("<h3>" + rs.getString("title") + "</h3>");
                out.println("<p><b>Author:</b> " + rs.getString("author") + "</p>");
                out.println("<p>" + rs.getString("content") + "</p>");
                out.println("</div>");
            }

            rs.close();
            stmt.close();
            // do not close shared connection if DBConnection reuses it; follow your implementation
        } catch (Exception e) {
            out.println("<p style='color:red;'>Error: " + e.getMessage() + "</p>");
            e.printStackTrace(out);
        }

        out.println("</div>");
        out.println("<div style='text-align:center; margin-top:20px;'><a href='index.html'><button>Back to Home</button></a></div>");
        out.println("</body></html>");
    }
}