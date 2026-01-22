<%@ page import="java.sql.*, com.blog.DBConnection" %>
<!DOCTYPE html>
<html>
<head>
    <title>View Blogs - APCOER Insights Blog</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f4f1fa;
            text-align: center;
            padding: 50px 0;
            margin: 0;
        }
        h2 {
            color: #6a1b9a;
            margin-bottom: 30px;
        }
        .blog-card {
            background: #fff;
            padding: 20px;
            margin: 20px auto;
            border-radius: 10px;
            box-shadow: 0 4px 10px rgba(0,0,0,0.2);
            width: 60%;
            text-align: left;
        }
        .blog-card h3 { color: #6a1b9a; margin-bottom: 10px; }
        .blog-card p { font-size: 16px; margin: 5px 0; }
        .back-btn {
            display: inline-block;
            text-decoration: none;
            color: #fff;
            background-color: #6a1b9a;
            padding: 10px 20px;
            border-radius: 8px;
            font-size: 16px;
            margin-top: 20px;
            transition: 0.3s;
        }
        .back-btn:hover { background-color: #8e24aa; }
    </style>
</head>
<body>
    <h2>All Blog Posts</h2>
    <%
        Connection conn = DBConnection.getConnection();
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT * FROM blog ORDER BY id ASC");

        while(rs.next()) {
            int blogId = rs.getInt("id");
    %>
        <div class="blog-card">
            <h3>ID <%= blogId %>: <%= rs.getString("title") %></h3>
            <p><b>Author:</b> <%= rs.getString("author") %></p>
            <p><%= rs.getString("content") %></p>
        </div>
    <%
        }
    %>
    <a href="index.html" class="back-btn">Back to Home</a>
</body>
</html>
