////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Study Tracker App
// File        :  StudyTracker.java
// Description :  Implements a Console (CUI) + GUI based application to log, summarize,
//                and export daily study activities.
// Author      :  Ishwari Pravin Jadhav
// Date        :  28/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////

import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.time.LocalDate;
import java.io.*;
import java.time.format.DateTimeFormatter;

//////////////////////////////////////////////////////////////////////////////////////
//
// Class       : StudyLog
// Description : Represents an individual study record containing date, subject,
//               duration, and description of the study session.
// Author      : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////
class StudyLog
{
    public LocalDate Date;
    public String Subject;
    public double Duration;
    public String Description;

    //////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	StudyLog
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   LocalDate A,String B,double C,String D
    //	Description             :   This is Constructor of class StudyLog.
    //	Returns					:   None
    //
    /////////////////////////////////////////////////////////////////////////////////////////
    public StudyLog(LocalDate A,String B,double C,String D)
    {
        this.Date = A;
        this.Subject = B;
        this.Duration = C;
        this.Description = D;
    }

    @Override
    public String toString()
    {
        return Date+" | "+Subject+" | "+Duration+" | "+Description;
    }

    public LocalDate getDate()
    {
        return Date;
    }

    public String getSubject()
    {
        return Subject;
    }

    public double getDuration()
    {
        return Duration;
    }

    public String getDescription()
    {
        return Description;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
//
// Class       : Study_Tracker
// Description : Core class implementing all data management operations such as
//               insertion, display, summary (by date & subject), and export to CSV.
//               It provides separate methods for both Console (CUI) and GUI modes.
// Author      : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////
class Study_Tracker
{
    //Data structure to hold the data about study
    private ArrayList <StudyLog> Database = new ArrayList <StudyLog> ();

    // --------------------------------- Console Methods -------------------------------------

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	InsertLog
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Accepts study details from the user and stores them 
    //                              in the database.
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void InsertLog()
    {
        Scanner ScannerObj = new Scanner(System.in);

        System.out.println("-----------------------------------------------------------------------------------");
        System.out.println("--------------------Please enter the valid details of your study-------------------");
        System.out.println("-----------------------------------------------------------------------------------");

        LocalDate Dateobj = LocalDate.now();

        System.out.println("Please provide name of subject like C/C++/Java/OS/DS : ");
        String sub = ScannerObj.nextLine();

        System.out.println("Enter the time period of your study in hours : ");
        double dur = ScannerObj.nextDouble();
        ScannerObj.nextLine();

        System.out.println("Please provide the description about the study for future reference : ");
        String desc = ScannerObj.nextLine();

        StudyLog StudyObj = new StudyLog(Dateobj,sub,dur,desc);

        Database.add(StudyObj);

        System.out.println("StudyLog gets stored succesfully");
        System.out.println("-----------------------------------------------------------------------------------");
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	DisplayLog
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Displays all study records stored in the database.
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void DisplayLog()
    {
        System.out.println("-----------------------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to display as Database is empty");
            System.out.println("-----------------------------------------------------------------------------------");
            return;
        }

        System.out.println("-----------------------------------------------------------------------------------");
        System.out.println("-----------------------Log report from Marvellous Study Tracker--------------------");
        System.out.println("-----------------------------------------------------------------------------------");

        for(StudyLog sobj : Database)
        {
            System.out.println(sobj);
        }
        System.out.println("-----------------------------------------------------------------------------------");
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	ExportCSV
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Exports all study records to a CSV file named 
    //                              "MarvellousStudy.csv".
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void ExportCSV()
    {
        if(Database.isEmpty())
        {
            System.out.println("Nothing to export as Database is empty");
            System.out.println("-----------------------------------------------------------------------------------");
            return;
        }

        String Filename = "MarvellousStudy.csv";

        try(FileWriter fwobj = new FileWriter(Filename))
        {
            //write CSV header
            fwobj.write("Date,Subject,Duration,Description\n");

            //Travel database
            for(StudyLog sobj : Database)
            {
                //write each record in CSV
                fwobj.write(sobj.getDate() + ","+
                            sobj.getSubject().replace(","," ")+ ","+
                            sobj.getDuration() + ","+
                            sobj.getDescription().replace(","," ") + "\n"
                           );

            }
            System.out.println("Log created Succesfully");
        }
        catch(Exception eobj)
        {
            System.out.println("Exception occured while creating the CSV");
            System.out.println("Report this issue to Marvellous Infosystem");
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	SummaryByDate
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Generates and displays a summary of total study time 
    //                              grouped by date.
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void SummaryByDate()
    {
        System.out.println("-----------------------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to display as Database is empty");
            System.out.println("-----------------------------------------------------------------------------------");
            return;
        }

        System.out.println("-----------------------------------------------------------------------------------");
        System.out.println("------------------Summary By Date from Marvellous Study Tracker--------------------");
        System.out.println("-----------------------------------------------------------------------------------");

        TreeMap <LocalDate,Double> tobj = new TreeMap <LocalDate,Double> ();

        LocalDate lobj = null;
        double d,old;

        for(StudyLog sobj : Database)
        {
            lobj = sobj.getDate();
            d = sobj.getDuration();

            if(tobj.containsKey(lobj))
            {
                old = tobj.get(lobj);
                tobj.put(lobj,d+old);
            }
            else
            {
                tobj.put(lobj,d);
            }
        }
        //Display the details as per date
        for(LocalDate ldobj : tobj.keySet())
        {
            System.out.println("Date : "+ldobj+" Total Study "+tobj.get(ldobj));
        }

        System.out.println("-----------------------------------------------------------------------------------");
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	SummaryBySubject
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Generates and displays a summary of total study time 
    //                              grouped by subject.
    //	Returns					:   void
    //
    //////////////////////////////////////////////////////////////////////////////////////
    public void SummaryBySubject()
    {
        System.out.println("-----------------------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to display as Database is empty");
            System.out.println("-----------------------------------------------------------------------------------");
            return;
        }

        System.out.println("-----------------------------------------------------------------------------------");
        System.out.println("------------------Summary By subject from Marvellous Study Tracker--------------------");
        System.out.println("-----------------------------------------------------------------------------------");

        TreeMap <String,Double> tobj = new TreeMap <String,Double> ();

        String s;
        double d,old;

        for(StudyLog sobj : Database)
        {
            s = sobj.getSubject();
            d = sobj.getDuration();

            if(tobj.containsKey(s))
            {
                old = tobj.get(s);
                tobj.put(s,d+old);
            }
            else
            {
                tobj.put(s,d);
            }
        }
        //Display the details as per subject
        for(String str : tobj.keySet())
        {
            System.out.println("Subject : "+str+" Total Study "+tobj.get(str));
        }

        System.out.println("-----------------------------------------------------------------------------------");
    }

    // --------------------------------- GUI Methods --------------------------------------------

    //////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	InsertLogGUI
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String sub, double dur, String desc
    //	Description             :   Adds a new study record received from the GUI interface.
    //	Returns					:   void
    //
    /////////////////////////////////////////////////////////////////////////////////////////
    public void InsertLogGUI(String sub, double dur, String desc)
    {
        StudyLog StudyObj = new StudyLog(LocalDate.now(), sub, dur, desc);
        Database.add(StudyObj);
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	DisplayLogGUI
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Returns all study logs as a formatted string for GUI 
    //                              display.
    //	Returns					:   String
    //
    /////////////////////////////////////////////////////////////////////////////////////////
    public String DisplayLogGUI()
    {
        if(Database.isEmpty())
        {
            return "Nothing to display. Database is empty.";
        }

        StringBuilder sb = new StringBuilder();
        for(StudyLog sobj : Database)
        {
            sb.append(sobj).append("\n");
        }
        return sb.toString();
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	SummaryByDateGUI
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Returns a formatted summary of study durations grouped 
    //                              by date.
    //	Returns					:   String
    //
    /////////////////////////////////////////////////////////////////////////////////////////
    public String SummaryByDateGUI()
    {
        if(Database.isEmpty())
        {
            return "Nothing to display. Database is empty.";
        }

        TreeMap<LocalDate, Double> map = new TreeMap<>();
        for(StudyLog s : Database)
        {
            map.put(s.getDate(), map.getOrDefault(s.getDate(), 0.0) + s.getDuration());
        }
        StringBuilder sb = new StringBuilder();
        for(LocalDate d : map.keySet())
        {
            sb.append("Date: ").append(d).append(" | Total Study: ").append(map.get(d)).append("\n");
        }
        return sb.toString();
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	SummaryBySubjectGUI
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Returns a formatted summary of study durations grouped 
    //                              by subject.
    //	Returns					:   String
    //
    /////////////////////////////////////////////////////////////////////////////////////////
    public String SummaryBySubjectGUI()
    {
        if(Database.isEmpty()) 
        {
            return "Nothing to display. Database is empty.";
        }

        TreeMap<String, Double> map = new TreeMap<>();
        for(StudyLog s : Database)
        {
            map.put(s.getSubject(), map.getOrDefault(s.getSubject(), 0.0) + s.getDuration());
        }
        StringBuilder sb = new StringBuilder();
        for(String sub : map.keySet())
        {
            sb.append("Subject: ").append(sub).append(" | Total Study: ").append(map.get(sub)).append("\n");
        }
        return sb.toString();
    }
}

//////////////////////////////////////////////////////////////////////////////////////
//
// Class       : StudyTrackerGUI
// Description : Implements the GUI-based version of Study Tracker using Swing
//               components. Provides buttons for all study operations and uses
//               dialogs for data input.
// Author      : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////
class StudyTrackerGUI
{
    private Study_Tracker tracker = new Study_Tracker();

    //////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	StudyTrackerGUI
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   This is Constructor of class StudyTrackerGUI.
    //	Returns					:   None
    //
    /////////////////////////////////////////////////////////////////////////////////////////
    public StudyTrackerGUI()
    {
        JFrame frame = new JFrame("Marvellous Study Tracker");
        frame.setSize(600, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(7, 1, 5, 5));         // menu buttons

        JButton addButton = new JButton("1 : Insert new Study Log");
        JButton viewButton = new JButton("2 : View All Study Log");
        JButton summaryDateButton = new JButton("3 : Summary by Date");
        JButton summarySubjectButton = new JButton("4 : Summary by Subject");
        JButton exportButton = new JButton("5 : Export CSV");
        JButton exitButton = new JButton("6 : Exit");

        frame.add(addButton);
        frame.add(viewButton);
        frame.add(summaryDateButton);
        frame.add(summarySubjectButton);
        frame.add(exportButton);
        frame.add(exitButton);

        JTextArea outputArea = new JTextArea();
        outputArea.setEditable(false);
        frame.add(new JScrollPane(outputArea));

        // ---------------- Button actions ----------------
        addButton.addActionListener(e -> insertLogDialog());
        viewButton.addActionListener(e -> outputArea.setText(tracker.DisplayLogGUI()));
        summaryDateButton.addActionListener(e -> outputArea.setText(tracker.SummaryByDateGUI()));
        summarySubjectButton.addActionListener(e -> outputArea.setText(tracker.SummaryBySubjectGUI()));
        exportButton.addActionListener(e ->
        {
            tracker.ExportCSV();
            JOptionPane.showMessageDialog(frame, "CSV Exported Successfully");
        });
        exitButton.addActionListener(e -> frame.dispose());

        frame.setVisible(true);
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	insertLogDialog
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Opens an input dialog to accept new study log details 
    //                              from user.
    //	Returns					:   void
    //
    /////////////////////////////////////////////////////////////////////////////////////////
    private void insertLogDialog()
    {
        JTextField subjectField = new JTextField();
        JTextField durationField = new JTextField();
        JTextArea descArea = new JTextArea(5, 20);
        JScrollPane scrollPane = new JScrollPane(descArea);

        Object[] message = 
        {
            "Subject:", subjectField,
            "Duration (hours):", durationField,
            "Description:", scrollPane
        };

        int option = JOptionPane.showConfirmDialog(null, message, "Add Study Log", JOptionPane.OK_CANCEL_OPTION);
        if(option == JOptionPane.OK_OPTION)
        {
            try
            {
                String sub = subjectField.getText();
                double dur = Double.parseDouble(durationField.getText());
                String desc = descArea.getText();
                tracker.InsertLogGUI(sub, dur, desc);
                JOptionPane.showMessageDialog(null, "Study Log Added Successfully");
            }
            catch(Exception ex)
            {
                JOptionPane.showMessageDialog(null, "Invalid input. Please try again.");
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////
//
// Class         : StudyTracker
// Description   : Allows user to select Console or GUI mode for interacting with the 
//                 Study Tracker.
// Author        : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////
class StudyTracker
{
    ////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	main
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   String A[]
    //	Description             :   Main entry point,allowing the user to choose between
    //                              Console (CUI) and GUI modes.
    //	Returns					:   void
    //
    ////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("-----------------------------------------------------------------------------------");
        System.out.println("---------------- Welcome to Marvellous Study Tracker Application ------------------");
        System.out.println("-----------------------------------------------------------------------------------");
        System.out.println("Select mode:");
        System.out.println("1 : Console Mode (CUI)");
        System.out.println("2 : GUI Mode");

        System.out.print("Enter your choice: ");
        int choice = sobj.nextInt();

        if(choice == 1)
        {
            // Console menu
            StudyTrackerCUI();
        }
        else if(choice == 2)
        {
            // Open GUI menu
            SwingUtilities.invokeLater(() -> new StudyTrackerGUI());
        }
        else
        {
            System.out.println("Invalid option. Exiting...");
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////
    //
    //	Method Name			    :	StudyTrackerCUI
    //	Method Date			    :	28/07/2025
    //	Method Author			:	Ishwari Pravin Jadhav
    //	Parameters				:   None
    //	Description             :   Provides menu-driven console interface for managing 
    //                              study logs.
    //	Returns					:   void
    //
    ////////////////////////////////////////////////////////////////////////////////////////
    private static void StudyTrackerCUI()
    {
        Study_Tracker stobj = new Study_Tracker();

        Scanner ScannerObj = new Scanner(System.in);

        int iChoice = 0;

        do
        {
            System.out.println("-----------------------------------------------------------------------------------");
            System.out.println("Please select the appropriate option");
            System.out.println("1 : Insert new Study Log into Datbase");
            System.out.println("2 : View All Study Log");
            System.out.println("3 : Summary of Study Log by Date");
            System.out.println("4 : Summary of Study Log by Subject");
            System.out.println("5 : Export Study Log to CSV file");
            System.out.println("6 : Exit the application");

            System.out.print("Enter your choice: ");
            iChoice = ScannerObj.nextInt();

            switch(iChoice)
            {
                    case 1:                              //Insert new Study Log into Datbase
                        stobj.InsertLog();
                        break;

                    case 2:                             //View All Study Log
                        stobj.DisplayLog();
                        break;

                    case 3:                             //Summary of Study Log by Date
                        stobj.SummaryByDate();
                        break;

                    case 4:                             //Summary of Study Log by Subject
                        stobj.SummaryBySubject();
                        break;

                    case 5:                             //Export Study Log to CSV file
                        stobj.ExportCSV();
                        break;

                    case 6:                             //Exit the application

                        System.out.println("-----------------------------------------------------------------------------------");
                        System.out.println("Thank you for using Marvellous Study Log apllication");
                        System.out.println("-----------------------------------------------------------------------------------");
                        break;

                    default:
                        System.out.println("Please enter the valid option");  
            }
        }while(iChoice != 6);
    } 
}