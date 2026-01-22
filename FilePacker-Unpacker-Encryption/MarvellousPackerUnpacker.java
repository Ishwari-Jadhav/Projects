////////////////////////////////////////////////////////////////////////////////
// 
// Project     :  File Packer-Unpacker
// File        :  MarvellousPackerUnpacker.java
// Description :  Implements a CUI + GUI based file packing and unpacking 
//                system with directory traversal. 
// Author      :  Ishwari Pravin Jadhav
// Date        :  21/07/2025
//
////////////////////////////////////////////////////////////////////////////////

import java.util.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;

//////////////////////////////////////////////////////////////////////////////////
// 
// Class       :  MarvellousPacker
// Description :  Implements packing functionality.
// Author      :  Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////
class MarvellousPacker
{
    private String PackName;                     // Name of the packed file
    private String DirName;                      // Name of directory to pack

    ////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	MarvellousPacker
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String A,String B
    //	Description             :   This is Constructor of class MarvellousPacker.
    //	Returns					:   None
    //
    ////////////////////////////////////////////////////////////////////////////////////
    public MarvellousPacker(String A,String B)
    {
        this.PackName = A;
        this.DirName = B;
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	PackingActivity
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Packs all files from the given directory into the 
    //                              specified packed file.
    //	Returns					:   void
    //
    ////////////////////////////////////////////////////////////////////////////////////
    public void PackingActivity()
    {
        try
        {
            System.out.println("-----------------------------------------------------------------");
            System.out.println("-------------------Marvellous Packer UnPacker--------------------");
            System.out.println("-----------------------------------------------------------------");
            System.out.println("-------------------Packing Activity------------------------------");
            System.out.println("-----------------------------------------------------------------");

            int i = 0,j = 0,iRet = 0,iCountFile = 0;
            
            File fobj = new File(DirName);
 
            //check the existence of directory
            if((fobj.exists()) && (fobj.isDirectory()))
            {
                System.out.println(DirName+" is successfully opened");

                File PackObj = new File(PackName);

                //create the pack file
                boolean bRet = PackObj.createNewFile();

                if(bRet == false)
                {
                    System.out.println("Unable to create pack file");
                    return;
                }

                System.out.println("Packed files gets successfully created with name : "+PackName);

                //Retrive all files from directory
                File Arr[] = fobj.listFiles();

                //Packed file object
                FileOutputStream foobj = new FileOutputStream(PackObj);

                //buffer for read and write activity
                byte Buffer[] = new byte[1024];

                String Header = null;

                //directory traversal
                for(i = 0;i < Arr.length;i++)
                {
                    Header = Arr[i].getName() +" "+ Arr[i].length();

                    //loop to form 100 bytes header
                    for(j = Header.length();j < 100;j++)
                    {
                        Header = Header + " ";
                    }

                    //write header into packed files
                    foobj.write(Header.getBytes());

                    //open file from directory for reading
                    FileInputStream fiobj = new FileInputStream(Arr[i]);

                    //write contents into packed files
                    while((iRet = fiobj.read(Buffer)) != -1)
                    {
                        
                        foobj.write(Buffer,0,iRet);
                        System.out.println("File name scanned : "+Arr[i].getName());
                        System.out.println("File size read is : "+iRet);
                    }
                    fiobj.close();
                    iCountFile++;
                }
                System.out.println("Packing Activity Done");

                System.out.println("-------------------------------------------------------------");
                System.out.println("------------Statistical Report-------------------------------");
                System.out.println("-------------------------------------------------------------");

                System.out.println("Total files Packed : "+iCountFile);

                System.out.println("-------------------------------------------------------------");
                System.out.println("-------------Thank you for using our Application-------------");
                System.out.println("-------------------------------------------------------------");

            }
            else
            {
                System.out.println("There is no such Directory");
            }
        }
        catch(Exception eobj)
        {
            System.out.println("Error: "+eobj.getMessage());
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
/// 
// Class       :  MarvellousUnpacker
// Description :  Implements unpacking functionality.
// Author      :  Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////
class MarvellousUnpacker
{
    private String PackName;                       // Name of packed file

    ////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	MarvellousUnpacker
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String A
    //	Description             :   This is Constructor of class MarvellousUnpacker.
    //	Returns					:   None
    //
    ////////////////////////////////////////////////////////////////////////////////////
    public MarvellousUnpacker(String A)
    {
        this.PackName = A;
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	UnpackingActivity
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Unpacks files from the packed file into current 
    //                              directory.
    //	Returns					:   void
    //
    ////////////////////////////////////////////////////////////////////////////////////
    public void UnpackingActivity()
    {
        try
        {
            System.out.println("-----------------------------------------------------------------");
            System.out.println("-------------------Marvellous Packer UnPacker--------------------");
            System.out.println("-----------------------------------------------------------------");
            System.out.println("-----------------UnPacking Activity------------------------------");
            System.out.println("-----------------------------------------------------------------");

            String Header = null;
            File fobjnew = null;

            int FileSize = 0,iRet = 0,iCountFile = 0;
        
            File fobj = new File(PackName);

            //if packed file is not present
            if(! fobj.exists())
            {
                System.out.println("Unable to access file");
                return;
            }
            System.out.println("Packed File gets successfully opened");

            FileInputStream fiobj = new FileInputStream(fobj);

            //buffer to read the header
            byte HeaderBuffer[] = new byte[100];

            //scan the packed file to extract the files from it
            while((iRet = fiobj.read(HeaderBuffer,0,100)) != -1)
            {
                //convert byte array to string
                Header = new String(HeaderBuffer);

                Header = Header.trim();

                //Tokenize the header into 2 parts
                String Tokens[] = Header.split(" ");

                fobjnew = new File(Tokens[0]);

                //create new file to extract
                fobjnew.createNewFile();

                FileSize = Integer.parseInt(Tokens[1]);

                //create new buffer to store files data
                byte Buffer[] = new byte[FileSize];

                FileOutputStream foobj = new FileOutputStream(fobjnew);

                //read the data from packed file
                fiobj.read(Buffer,0,FileSize);

                //write the data into extracted file
                foobj.write(Buffer,0,FileSize);

                System.out.println("File unpacked with name: "+Tokens[0]+"having size "+FileSize);

                iCountFile++;

                foobj.close();
                
            }
                System.out.println("-------------------------------------------------------------");
                System.out.println("------------Statistical Report-------------------------------");
                System.out.println("-------------------------------------------------------------");

                System.out.println("Total Number of files unpacked : "+iCountFile);

                System.out.println("-------------------------------------------------------------");
                System.out.println("-------------Thank you for using our Application-------------");
                System.out.println("-------------------------------------------------------------");
            
                fiobj.close();
        }
        catch(Exception eobj)
        {
            System.out.println("Error: "+eobj.getMessage());
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
/// 
// Class       :  MarvellousPACKER (GUI)
// Description :  GUI for packing files.
// Author      :  Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////
class MarvellousPACKER implements ActionListener
{
    public JFrame frameobj;
    public JButton buttonobj;
    public JTextField text1obj;
    public JTextField text2obj;
    public JLabel Folderlabel,Filelabel,Resultlabel; 

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	MarvellousPACKER (GUI)
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String Title,int width,int height
    //	Description             :   This is Constructor of class MarvellousPACKER (GUI).
    //	Returns					:   None
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public MarvellousPACKER(String Title,int width,int height)
    {
        frameobj = new JFrame();

        Folderlabel= new JLabel("Folder Name");
        Folderlabel.setBounds(50,50,100,30);

        text1obj = new JTextField();
        text1obj.setBounds(150,50,150,30);

        Filelabel = new JLabel("File Name");
        Filelabel.setBounds(50,100,100,30);

        text2obj = new JTextField();
        text2obj.setBounds(150,100,150,30);

        buttonobj = new JButton("PACK");
        buttonobj.setBounds(150,170,100,30);

        Resultlabel = new JLabel("");
        Resultlabel.setBounds(150,210,250,30);

        frameobj.add(buttonobj);
        frameobj.add(text1obj);
        frameobj.add(text2obj);
        frameobj.add(Folderlabel);
        frameobj.add(Filelabel);
        frameobj.add(Resultlabel);

        buttonobj.addActionListener(this);
        frameobj.setLayout(null);

        frameobj.setTitle(Title);
        frameobj.setSize(width,height);
        frameobj.setVisible(true);
        frameobj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	actionPerformed
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   ActionEvent aboj
    //	Description             :   Event handler for GUI button click.
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void actionPerformed(ActionEvent aboj)
    {
        String foldername = text1obj.getText();
        String filename = text2obj.getText();

        if(foldername.isEmpty() || filename.isEmpty())
        {
            Resultlabel.setText("Please enter folder and file names!");
            return;
        }

        try
        {
            MarvellousPacker pobj = new MarvellousPacker(filename, foldername);
            pobj.PackingActivity();
            Resultlabel.setText("Packing Successful!");

            String ans = JOptionPane.showInputDialog("Do you want to encrypt the packed file? (yes/no)");
            if(ans != null && ans.equalsIgnoreCase("yes"))
            {
                String keyStr = JOptionPane.showInputDialog("Enter encryption key (integer):");
                if(keyStr != null)
                {
                    int key = Integer.parseInt(keyStr);
                    MarvellousEncryptDecrypt.encryptFile(filename, filename + "_enc", key);
                    JOptionPane.showMessageDialog(frameobj, "Encryption completed! Encrypted file: " + filename + "_enc");
                }
            }
        }
        catch(Exception e)
        {
            Resultlabel.setText("Error during packing!");
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
/// 
// Class       :  MarvellousUNPACKER (GUI)
// Description :  GUI for unpacking files.
// Author      :  Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////
class MarvellousUNPACKER implements ActionListener
{
    public JFrame frameobj;
    public JButton buttonobj;
    public JTextField textobj;
    public JLabel Filelabel,Resultlabel; 

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	MarvellousUNPACKER (GUI)
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String Title,int width,int height
    //	Description             :   This is Constructor of class MarvellousUNPACKER (GUI).
    //	Returns					:   None
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public MarvellousUNPACKER(String Title,int width,int height)
    {
        frameobj = new JFrame();

        Filelabel = new JLabel("File Name");
        Filelabel.setBounds(50,80,100,30);

        textobj = new JTextField();
        textobj.setBounds(150,80,150,30);

        buttonobj = new JButton("UNPACK");
        buttonobj.setBounds(150,150,100,30);

        Resultlabel = new JLabel("");
        Resultlabel.setBounds(150,200,250,30);

        frameobj.add(buttonobj);
        frameobj.add(textobj);
        frameobj.add(Filelabel);
        frameobj.add(Resultlabel);

        buttonobj.addActionListener(this);
        frameobj.setLayout(null);

        frameobj.setTitle(Title);
        frameobj.setSize(width,height);
        frameobj.setVisible(true);
        frameobj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	actionPerformed
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   ActionEvent aboj
    //	Description             :   Event handler for GUI button click.
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void actionPerformed(ActionEvent aboj)
    {
        String filename = textobj.getText();

        if(filename.isEmpty())
        {
            Resultlabel.setText("Please enter file name!");
            return;
        }

        try
        {
            MarvellousUnpacker uobj = new MarvellousUnpacker(filename);
            uobj.UnpackingActivity();
            Resultlabel.setText("Unpacking Successful!");

            String ans = JOptionPane.showInputDialog("Do you want to decrypt a file? (yes/no)");
            if(ans != null && ans.equalsIgnoreCase("yes"))
            {
                String encName = JOptionPane.showInputDialog("Enter encrypted file name:");
                String keyStr = JOptionPane.showInputDialog("Enter decryption key (integer):");
                if(encName != null && keyStr != null)
                {
                    int key = Integer.parseInt(keyStr);
                    MarvellousEncryptDecrypt.decryptFile(encName, "Decrypted_" + encName, key);
                    JOptionPane.showMessageDialog(frameobj, "Decryption completed! Decrypted file: Decrypted_" + encName);
                }
            }
        }
        catch(Exception e)
        {
            Resultlabel.setText("Error during unpacking!");
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
//
// Class       :  MarvellousGUILauncher
// Description :  Provides a simple GUI to launch either the Packer or Unpacker
//                interface.
// Author      :  Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////
class MarvellousGUILauncher implements ActionListener
{
    private JFrame frame;
    private JButton packerButton, unpackerButton, exitButton;
    private JLabel titleLabel;

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	MarvellousGUILauncher
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String Title,int width,int height
    //	Description             :   This is Constructor of class MarvellousGUILauncher.
    //	Returns					:   None
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public MarvellousGUILauncher(String title, int width, int height)
    {
        frame = new JFrame(title);

        titleLabel = new JLabel("Marvellous Packer-Unpacker GUI Mode", SwingConstants.CENTER);
        titleLabel.setBounds(20, 20, 360, 30);

        packerButton = new JButton("Open Packer GUI");
        packerButton.setBounds(100, 80, 200, 30);

        unpackerButton = new JButton("Open Unpacker GUI");
        unpackerButton.setBounds(100, 130, 200, 30);

        exitButton = new JButton("Exit");
        exitButton.setBounds(100, 180, 200, 30);

        frame.add(titleLabel);
        frame.add(packerButton);
        frame.add(unpackerButton);
        frame.add(exitButton);

        packerButton.addActionListener(this);
        unpackerButton.addActionListener(this);
        exitButton.addActionListener(this);

        frame.setLayout(null);
        frame.setSize(width, height);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	actionPerformed
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   ActionEvent e
    //	Description             :   Handles button clicks to open Packer or Unpacker GUI.
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource() == packerButton)
        {
            new MarvellousPACKER("Marvellous Packer", 400, 300);
        }
        else if(e.getSource() == unpackerButton)
        {
            new MarvellousUNPACKER("Marvellous Unpacker", 400, 300);
        }
        else if(e.getSource() == exitButton)
        {
            frame.dispose();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
// 
// Class       :  MarvellousEncryptDecrypt
// Description :  Implements Caesar Cipher based encryption and decryption for files.
// Author      :  Ishwari Pravin Jadhav
//
///////////////////////////////////////////////////////////////////////////////////////
class MarvellousEncryptDecrypt
{
    public static void encryptFile(String src, String dest, int key)
    {
        try (FileInputStream fi = new FileInputStream(src);
             FileOutputStream fo = new FileOutputStream(dest))
        {
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = fi.read(buffer)) != -1)
            {
                for (int i = 0; i < bytesRead; i++)
                {
                    buffer[i] = (byte)((buffer[i] + key) % 256);
                }
                fo.write(buffer, 0, bytesRead);
            }
            System.out.println("Encryption completed for: " + src);
        }
        catch (Exception e)
        {
            System.out.println("Error during encryption: " + e.getMessage());
        }
    }

    public static void decryptFile(String src, String dest, int key)
    {
        try (FileInputStream fi = new FileInputStream(src);
             FileOutputStream fo = new FileOutputStream(dest))
        {
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = fi.read(buffer)) != -1)
            {
                for (int i = 0; i < bytesRead; i++)
                {
                    buffer[i] = (byte)((buffer[i] - key) % 256);
                }
                fo.write(buffer, 0, bytesRead);
            }
            System.out.println("Decryption completed for: " + src);
        }
        catch (Exception e)
        {
            System.out.println("Error during decryption: " + e.getMessage());
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
//
// Class       :  MarvellousPackerUnpacker
// Description :  Main driver class with CUI + GUI options.
// Author      :  Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////
class MarvellousPackerUnpacker
{
    ////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	main
    //	Method Date			    :	21/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String A[]
    //	Description             :   Main entry point.Provides menu for CUI or GUI operation
    //	Returns					:   void
    //
    ////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        int choice = 0;

        while(true) 
        {
            System.out.println("\n--------------------------------------------------------------------------------");
            System.out.println("\n--------------------- Marvellous Packer-Unpacker System ------------------------");
            System.out.println("\n--------------------------------------------------------------------------------");
            System.out.println("1. Packing Files from Directory");
            System.out.println("2. Unpacking Files from Packed File");
            System.out.println("3. Open GUI Mode Only");
            System.out.println("4. Exit");
            System.out.print("Enter your choice : ");

            if(sobj.hasNextInt()) 
            {
                choice = sobj.nextInt();
                sobj.nextLine();
            }
            else 
            {
                System.out.println("Invalid input.Please enter a correct choice.");
                sobj.nextLine();
                continue;
            }

            if(choice == 1) 
            {
                System.out.println("\n---------------------------- PACKING PROCESS ------------------------------");

                System.out.print("Enter the name of the directory to pack : ");
                String DirName = sobj.nextLine();

                System.out.print("Enter the name of the packed file to create : ");
                String PackName = sobj.nextLine();

                try
                {
                    MarvellousPacker mobj = new MarvellousPacker(PackName, DirName);
                    mobj.PackingActivity();

                    System.out.println("\nPacking completed successfully!");

                    System.out.print("Do you want to encrypt the packed file? (yes/no): ");
                    String ans = sobj.nextLine();
                    if(ans.equalsIgnoreCase("yes"))
                    {
                        System.out.print("Enter encryption key (integer): ");
                        int key = sobj.nextInt();
                        sobj.nextLine();
                        MarvellousEncryptDecrypt.encryptFile(PackName, PackName + "_enc", key);
                        System.out.println("Encrypted file created: " + PackName + "_enc");
                    }
                }
                catch(Exception e)
                {
                    System.out.println("Error during packing: "+e.getMessage());
                }
            } 
            else if(choice == 2) 
            {
                System.out.println("\n--------------------------- UNPACKING PROCESS -----------------------------");

                System.out.print("Enter the name of the packed file to unpack : ");
                String PackName = sobj.nextLine();

                try
                {
                    MarvellousUnpacker mobj = new MarvellousUnpacker(PackName);
                    mobj.UnpackingActivity();

                    System.out.println("\nUnpacking completed successfully!");

                    System.out.print("Do you want to decrypt a file? (yes/no): ");
                    String ans = sobj.nextLine();
                    if(ans.equalsIgnoreCase("yes"))
                    {
                        System.out.print("Enter encrypted file name: ");
                        String encName = sobj.nextLine();
                        System.out.print("Enter decryption key (integer): ");
                        int key = sobj.nextInt();
                        sobj.nextLine();
                        MarvellousEncryptDecrypt.decryptFile(encName, "Decrypted_" + encName, key);
                        System.out.println("Decrypted file created: Decrypted_" + encName);
                    }
                }
                catch(Exception e)
                {
                    System.out.println("Error during unpacking: "+e.getMessage());
                }
            } 
            else if(choice == 3)
            {
                System.out.println("\n--------------------------- GUI MODE -----------------------------");

                System.out.println("Launching GUI Mode Launcher...");
                new MarvellousGUILauncher("Marvellous GUI Mode", 400, 300);
            }
            else if(choice == 4) 
            {
                System.out.println("----------------------------------------------------------");
                System.out.println("Thank you for using Marvellous PackerUnpacker Application.");
                System.out.println("----------------------------------------------------------");
                break;
            } 
            else 
            {
                System.out.println("Invalid choice.Please select option 1, 2 or 3.");
            }
        }
        sobj.close();
    }
}