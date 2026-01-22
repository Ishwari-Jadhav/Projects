//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  BatchEntry.java
// Description :  Entity class representing a batch record in MongoDB, containing batch
//                details such as batch ID, name, trainer, schedule, fees, and list of students.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

package com.marvellous.MarvellousPortal.Entity;

import lombok.Data;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

import java.util.ArrayList;
import java.util.List;

@Document(collection = "BatchDetails")
@Data
public class BatchEntry {
    // use batchId as primary id (string like "B101")
    @Id
    private String batchId;

    private String batchName;
    private String trainer;
    private String schedule;
    private int fees;

    private List<Student> students = new ArrayList<>();
}
