//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Chat Messenger with Log Facility
// File        :  ServerChat.java
// Description :  Server-side application for bidirectional chat communication with a client.
//                Logs all chat messages (client + server) into a text file.
// Author      :  Ishwari Pravin Jadhav
// Date        :  20/05/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.io.*;
import java.net.*;
import java.time.LocalDate;
import java.time.LocalTime;

class ServerChat
{
    public static void main(String A[]) throws Exception
    {
        ServerSocket ssobj = new ServerSocket(5100);
        System.out.println("Marvellous server is waiting at port number 5100");

        Socket sobj = ssobj.accept();
        System.out.println("Marvellous server successfully connected with the client");

        PrintStream pobj = new PrintStream(sobj.getOutputStream());
        BufferedReader bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
        BufferedReader bobj2 = new BufferedReader(new InputStreamReader(System.in));

        String fileName = "ChatLog_" + LocalDate.now() + ".txt";
        FileWriter fwobj = new FileWriter(fileName, true);

        String str1, str2;

        System.out.println("------ Chat Started ------");

        while (true)
        {
            str1 = bobj1.readLine();
            if (str1 == null) break;

            System.out.println("Client says: " + str1);
            fwobj.write("[" + LocalTime.now().withNano(0) + "] Client says: " + str1 + "\n");

            System.out.println("Enter the message for client : ");
            str2 = bobj2.readLine();
            pobj.println(str2);

            fwobj.write("[" + LocalTime.now().withNano(0) + "] Server says: " + str2 + "\n");
            fwobj.flush();
        }

        System.out.println("------ Chat Ended ------");

        fwobj.close();
        sobj.close();
        ssobj.close();
    }
}