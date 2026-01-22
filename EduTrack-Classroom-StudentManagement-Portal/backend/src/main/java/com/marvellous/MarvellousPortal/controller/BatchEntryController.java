//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  BatchEntryController.java
// Description :  Handles all REST API endpoints for managing batches and enrolling students.
//                Accepts client requests, performs validations, and communicates with
//                the service layer for CRUD operations.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

package com.marvellous.MarvellousPortal.controller;

import com.marvellous.MarvellousPortal.Entity.BatchEntry;
import com.marvellous.MarvellousPortal.Entity.Student;
import com.marvellous.MarvellousPortal.service.BatchEntryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/batches")
@CrossOrigin
public class BatchEntryController {

    @Autowired
    private BatchEntryService batchEntryService;

    // GET ALL BATCHES
    @GetMapping
    public ResponseEntity<Object> getAll() {
        List<BatchEntry> allData = batchEntryService.getAll();
        return new ResponseEntity<>(allData, HttpStatus.OK);
    }

    // CREATE BATCH
    @PostMapping
    public ResponseEntity<Object> createEntry(@RequestBody BatchEntry myentry) {
        try {
            if (myentry.getBatchId() == null || myentry.getBatchId().isBlank()) {
                return new ResponseEntity<>("batchId is required (e.g. B101)", HttpStatus.BAD_REQUEST);
            }

            BatchEntry saved = batchEntryService.saveEntry(myentry);
            return new ResponseEntity<>(saved, HttpStatus.CREATED);

        } catch (Exception e) {
            return new ResponseEntity<>("Error: " + e.getMessage(), HttpStatus.BAD_REQUEST);
        }
    }

    // GET BY ID
    @GetMapping("/{batchId}")
    public ResponseEntity<Object> getBatchById(@PathVariable String batchId) {
        return batchEntryService.findById(batchId)
                .<ResponseEntity<Object>>map(batch -> new ResponseEntity<>(batch, HttpStatus.OK))
                .orElseGet(() -> new ResponseEntity<>("Batch Not Found", HttpStatus.NOT_FOUND));
    }

    // UPDATE BATCH
    @PutMapping("/{batchId}")
    public ResponseEntity<Object> updateEntryById(
            @PathVariable String batchId,
            @RequestBody BatchEntry myentry) {

        return batchEntryService.findById(batchId)
                .<ResponseEntity<Object>>map(old -> {

                    if (myentry.getBatchName() != null) old.setBatchName(myentry.getBatchName());
                    if (myentry.getTrainer() != null) old.setTrainer(myentry.getTrainer());
                    if (myentry.getSchedule() != null) old.setSchedule(myentry.getSchedule());
                    if (myentry.getFees() != 0) old.setFees(myentry.getFees());

                    BatchEntry updated = batchEntryService.saveEntry(old);
                    return new ResponseEntity<>(updated, HttpStatus.OK);

                })
                .orElseGet(() -> new ResponseEntity<>("Batch Not Found", HttpStatus.NOT_FOUND));
    }

    // DELETE BATCH
    @DeleteMapping("/{batchId}")
    public ResponseEntity<Object> deleteEntryById(@PathVariable String batchId) {
        batchEntryService.deleteById(batchId);
        return new ResponseEntity<>("Batch Deleted", HttpStatus.NO_CONTENT);
    }

    // ADD STUDENT
    @PostMapping("/{batchId}/student")
    public ResponseEntity<Object> addStudentToBatch(
            @PathVariable String batchId,
            @RequestBody Student student) {

        if (student.getEnrollmentDate() == null || student.getEnrollmentDate().isBlank()) {
            student.setEnrollmentDate(java.time.LocalDate.now().toString());
        }

        boolean success = batchEntryService.addStudent(batchId, student);

        if (success)
            return new ResponseEntity<>("Student added successfully", HttpStatus.OK);
        else
            return new ResponseEntity<>("Batch Not Found", HttpStatus.NOT_FOUND);
    }

    // GET STUDENTS IN A BATCH
    @GetMapping("/{batchId}/students")
    public ResponseEntity<Object> getStudents(@PathVariable String batchId) {
        List<Student> students = batchEntryService.getStudents(batchId);

        if (students != null)
            return new ResponseEntity<>(students, HttpStatus.OK);

        return new ResponseEntity<>("Batch Not Found", HttpStatus.NOT_FOUND);
    }
}
