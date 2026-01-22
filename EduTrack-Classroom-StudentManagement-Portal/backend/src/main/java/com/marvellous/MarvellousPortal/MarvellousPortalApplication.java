//////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  EduTrack – Classroom & Student Management Portal
// File        :  MarvellousPortalApplication.java
// Description :  Entry point of the Spring Boot backend application that initializes all
//                components including controllers, services, repositories and REST APIs.
// Author      :  Ishwari Pravin Jadhav
// Date        :  08/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////


package com.marvellous.MarvellousPortal;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class MarvellousPortalApplication
{

	public static void main(String[] args)
	{
		SpringApplication.run(MarvellousPortalApplication.class, args);
	}

}
