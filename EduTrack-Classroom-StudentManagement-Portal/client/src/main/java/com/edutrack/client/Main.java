//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  Main.java
// Description :  Java-based console frontend application that interacts with the backend
//                REST APIs to manage batches and students. Implements a menu-driven UI
//                with HTTP client requests and JSON processing.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

package com.edutrack.client;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;
import java.net.URI;
import java.net.http.*;
import java.time.Duration;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

    private static final String BASE_URL = "http://localhost:8080";
    private static final HttpClient http = HttpClient.newBuilder()
            .connectTimeout(Duration.ofSeconds(10))
            .build();
    private static final ObjectMapper mapper = new ObjectMapper();
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        while (true) {
            System.out.println("\n===== EduTrack Portal =====");
            System.out.println("1. Create New Batch");
            System.out.println("2. View All Batches");
            System.out.println("3. Update Batch");
            System.out.println("4. Delete Batch");
            System.out.println("5. Add Student to Batch");
            System.out.println("6. View Students in a Batch");
            System.out.println("7. Exit");
            System.out.print("Enter Choice: ");

            String choice = scanner.nextLine().trim();

            switch (choice) {
                case "1": createBatch(); break;
                case "2": viewAllBatches(); break;
                case "3": updateBatch(); break;
                case "4": deleteBatch(); break;
                case "5": addStudentToBatch(); break;
                case "6": viewStudentsInBatch(); break;
                case "7":
                    System.out.println("Thank you for using EduTrack!");
                    return;
                default:
                    System.out.println("Invalid choice, try again.");
            }
        }
    }

    private static void createBatch() throws IOException, InterruptedException {
        System.out.print("Batch ID (e.g. B101): ");
        String batchId = scanner.nextLine().trim();

        System.out.print("Batch Name: ");
        String name = scanner.nextLine().trim();

        System.out.print("Trainer: ");
        String trainer = scanner.nextLine().trim();

        System.out.print("Schedule: ");
        String schedule = scanner.nextLine().trim();

        System.out.print("Fees (number): ");
        int fees = Integer.parseInt(scanner.nextLine().trim());

        Map<String, Object> body = Map.of(
                "batchId", batchId,
                "batchName", name,
                "trainer", trainer,
                "schedule", schedule,
                "fees", fees
        );

        String json = mapper.writeValueAsString(body);

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(BASE_URL + "/batches"))
                .header("Content-Type", "application/json")
                .POST(HttpRequest.BodyPublishers.ofString(json))
                .build();

        HttpResponse<String> response = http.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println("Status: " + response.statusCode());
        System.out.println(response.body());
    }

    private static void viewAllBatches() throws IOException, InterruptedException {
        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(BASE_URL + "/batches"))
                .GET()
                .build();

        HttpResponse<String> response = http.send(request, HttpResponse.BodyHandlers.ofString());
        if (response.statusCode() == 200) {
            List<Map<String, Object>> batches = mapper.readValue(response.body(), new TypeReference<>() {});
            System.out.println("\n=== All Batches ===");
            batches.forEach(System.out::println);
        } else {
            System.out.println("Failed: " + response.statusCode());
        }
    }

    private static void updateBatch() throws IOException, InterruptedException {
        System.out.print("Batch ID to Update (e.g. B101): ");
        String batchId = scanner.nextLine().trim();

        System.out.print("New Batch Name (leave blank to keep): ");
        String name = scanner.nextLine().trim();

        System.out.print("New Trainer (leave blank to keep): ");
        String trainer = scanner.nextLine().trim();

        System.out.print("New Schedule (leave blank to keep): ");
        String schedule = scanner.nextLine().trim();

        System.out.print("New Fees (0 to keep): ");
        String feesStr = scanner.nextLine().trim();
        int fees = feesStr.isEmpty() ? 0 : Integer.parseInt(feesStr);

        Map<String, Object> body = Map.of(
                "batchName", name.isEmpty() ? null : name,
                "trainer", trainer.isEmpty() ? null : trainer,
                "schedule", schedule.isEmpty() ? null : schedule,
                "fees", fees
        );

        String json = mapper.writeValueAsString(body);

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(BASE_URL + "/batches/" + batchId))
                .header("Content-Type", "application/json")
                .PUT(HttpRequest.BodyPublishers.ofString(json))
                .build();

        HttpResponse<String> response = http.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println("Status: " + response.statusCode());
        System.out.println(response.body());
    }

    private static void deleteBatch() throws IOException, InterruptedException {
        System.out.print("Batch ID to Delete (e.g. B101): ");
        String batchId = scanner.nextLine().trim();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(BASE_URL + "/batches/" + batchId))
                .DELETE()
                .build();

        HttpResponse<String> response = http.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println("Status: " + response.statusCode());
    }

    private static void addStudentToBatch() throws IOException, InterruptedException {
        System.out.print("Batch ID (e.g. B101): ");
        String batchId = scanner.nextLine().trim();

        System.out.print("Student Name: ");
        String name = scanner.nextLine().trim();

        System.out.print("Contact: ");
        String contact = scanner.nextLine().trim();

        Map<String, Object> body = Map.of(
                "name", name,
                "contact", contact
        );

        String json = mapper.writeValueAsString(body);

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(BASE_URL + "/batches/" + batchId + "/student"))
                .header("Content-Type", "application/json")
                .POST(HttpRequest.BodyPublishers.ofString(json))
                .build();

        HttpResponse<String> response = http.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println("Status: " + response.statusCode());
        System.out.println(response.body());
    }

    private static void viewStudentsInBatch() throws IOException, InterruptedException {
        System.out.print("Batch ID (e.g. B101): ");
        String batchId = scanner.nextLine().trim();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(BASE_URL + "/batches/" + batchId + "/students"))
                .GET()
                .build();

        HttpResponse<String> response = http.send(request, HttpResponse.BodyHandlers.ofString());
        if (response.statusCode() == 200) {
            List<Map<String, Object>> students = mapper.readValue(response.body(), new TypeReference<>() {});
            System.out.println("\n=== Students in Batch ===");
            students.forEach(System.out::println);
        } else {
            System.out.println("Failed: " + response.statusCode());
        }
    }
}
