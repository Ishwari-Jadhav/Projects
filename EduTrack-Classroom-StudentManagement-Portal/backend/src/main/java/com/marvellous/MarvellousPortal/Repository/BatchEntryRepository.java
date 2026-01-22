//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  BatchEntryRepository.java
// Description :  Repository interface extending MongoRepository to provide CRUD operations
//                for BatchEntry documents stored in MongoDB.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

package com.marvellous.MarvellousPortal.Repository;

import com.marvellous.MarvellousPortal.Entity.BatchEntry;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface BatchEntryRepository extends MongoRepository<BatchEntry, String> {
    // using default MongoRepository methods with String id (batchId)
}
