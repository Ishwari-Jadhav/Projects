//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  BatchEntryService.java
// Description :  Contains the business logic for creating batches, updating details,
//                managing students, and interacting with MongoDB through the repository layer.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

package com.marvellous.MarvellousPortal.service;

import com.marvellous.MarvellousPortal.Entity.BatchEntry;
import com.marvellous.MarvellousPortal.Entity.Student;
import com.marvellous.MarvellousPortal.Repository.BatchEntryRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class BatchEntryService {

    @Autowired
    private BatchEntryRepository batchEntryRepository;

    // CREATE or UPDATE (save)
    public BatchEntry saveEntry(BatchEntry batchEntry) {
        return batchEntryRepository.save(batchEntry);
    }

    // GET ALL
    public List<BatchEntry> getAll() {
        return batchEntryRepository.findAll();
    }

    // FIND BY batchId (String)
    public Optional<BatchEntry> findById(String batchId) {
        return batchEntryRepository.findById(batchId);
    }

    // DELETE BY batchId
    public void deleteById(String batchId) {
        batchEntryRepository.deleteById(batchId);
    }

    // ADD STUDENT
    public boolean addStudent(String batchId, Student student) {
        Optional<BatchEntry> maybe = batchEntryRepository.findById(batchId);
        if (maybe.isPresent()) {
            BatchEntry batch = maybe.get();
            batch.getStudents().add(student);
            batchEntryRepository.save(batch);
            return true;
        }
        return false;
    }

    // GET STUDENTS
    public List<Student> getStudents(String batchId) {
        Optional<BatchEntry> maybe = batchEntryRepository.findById(batchId);
        return maybe.map(BatchEntry::getStudents).orElse(null);
    }
}
