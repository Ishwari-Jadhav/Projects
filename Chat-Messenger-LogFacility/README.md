# 💬 Chat Messenger with Log Facility
> This project is a Java-based client-server chat application that enables real-time text-based communication between users using Java Socket Programming. Along with providing basic chat functionality, it also maintains a log file that records all conversation details in a periodic fashion for future reference.The application is platform and architecture independent, running on any system with a Java Runtime Environment (JRE).

---

## 📖 Project Overview
The Chat Messenger is a console-based client–server communication system built using Java sockets.
It allows real-time text messaging between two machines (or terminals on the same machine) and stores the entire conversation in a log file with timestamps.

- This project helps understand:

  • How client–server communication works
  • Using sockets to send and receive messages
  • Input/Output stream handling
  • Real-time message exchange
  • Logging mechanism using file I/O
  • Loop control and connection termination

The project forms a strong foundation for understanding Java networking concepts.

---

## 📁 Folder Structure
```
Chat Messenger with Log Facility/
│
├── ServerChat.java
├── ClientChat.java
├── README.md
```

---

## 🧩 Features
- Client-Server Communication
  • Uses Java TCP sockets for communication between the client and the server.

- Real-Time Chat
  • Enables instant text-based messaging between connected peers.

- Chat Log Maintenance
  • Logs all chat history with timestamps into a file.
  • Provides periodic logging for organized record-keeping.

- Cross-Platform
  • Runs seamlessly across different operating systems and architectures.

- Lightweight & Extensible
  • Can be extended to support group chat, file sharing, or encryption.

---

## 🧠 Learning Objectives 
- Practical knowledge of Java Socket Programming (TCP/IP).
- Hands-on experience with network programming concepts (client-server).
- Implementation of logging mechanisms in applications.
- Understanding of platform-independent communication in Java.
- Foundation for building scalable chat/messaging applications.

---

## ⚙️ How to Run

### Compilation
```bash
javac ServerChat.java ClientChat.java
```

### Execution
- Start the Server (Terminal 1)
```bash
java ServerChat
```

- Start the Client (Terminal 2)
```bash
java ClientChat
```

- Now begin chatting!

- The client can exit anytime using:
```bash
end
```

---

## 🧪 Example Usage
Below is a sample interaction with the Chat Messenger using the console menu :

```
------------------------------------ Server ------------------------------------
Marvellous server is waiting at port number 5100
Marvellous server successfully connected with the client
------ Chat Started ------
Client says: hello
Enter the message for client :
hi
------ Chat Ended ------


------------------------------------ Client ------------------------------------
Marvellous Client is successfully connected with server
________________________________________________
Marvellous Chat Messenger is ready to use
Type 'end' to exit the chat.
________________________________________________
You: hello
Server: hi
You: end
Chat ended. Client disconnected.
Automatically generated log file:

ChatLog_2025-11-20.txt
----------------------------------------------
[10:45:02] Client says: hello
[10:45:05] Server says: hi
----------------------------------------------
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Chat Messenger with Log Facility
// File        :  ServerChat.java / ClientChat.java
// Description :  This project demonstrates socket-based two-way communication between a 
//                client and a server along with logging of the chat session into a text file 
//                with timestamps.
// Author      :  Ishwari Pravin Jadhav
// Date        :  20/05/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
Chat Messenger with Log Facility - Java Project
2025
```

---

## 🔖 Tags
Java, SocketProgramming, ClientServer, Networking, ChatApplication, Logging, FileHandling, RealTimeCommunication, ConsoleApp,LogicBuilding.

---

> 💡 *Chat Messenger with Log Facility : A simple real-time client–server communication system with auto-generated chat logs, built using Java sockets.*