//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Chat Messenger with Log Facility
// File        :  ClientChat.java
// Description :  Client-side application that connects to the chat server using TCP sockets
//                and exchanges messages in real time.
// Author      :  Ishwari Pravin Jadhav
// Date        :  20/05/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.io.*;
import java.net.*;

class ClientChat
{
    public static void main(String A[]) throws Exception
    {
        System.out.println("Client is ready to connect with server");

        Socket sobj = new Socket("localhost", 5100);
        System.out.println("Marvellous Client is successfully connected with server");

        PrintStream pobj = new PrintStream(sobj.getOutputStream());
        BufferedReader bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
        BufferedReader bobj2 = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("________________________________________________");
        System.out.println("Marvellous Chat Messenger is ready to use");
        System.out.println("Type 'end' to exit the chat.");
        System.out.println("________________________________________________");

        String str1, str2;

        System.out.print("You: ");

        while (!(str1 = bobj2.readLine()).equals("end"))
        {
            pobj.println(str1);

            str2 = bobj1.readLine();
            System.out.println("Server: " + str2);

            System.out.print("You: ");
        }

        sobj.close();
        System.out.println("Chat ended. Client disconnected.");
    }
}