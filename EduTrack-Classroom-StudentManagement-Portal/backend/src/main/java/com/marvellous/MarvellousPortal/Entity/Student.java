//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  Student.java
// Description :  Entity class representing student information embedded inside a batch
//                document, including name, contact details, and enrollment date.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

package com.marvellous.MarvellousPortal.Entity;

import lombok.Data;

@Data
public class Student {
    private String name;
    private String contact;
    private String enrollmentDate;
}
