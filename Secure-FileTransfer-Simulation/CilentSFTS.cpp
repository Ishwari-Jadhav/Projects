//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Secure File Transfer System (SFTS)
// File        :  ClientSFTS.cpp
// Description :  Client-side program that dynamically loads the Server DLL at runtime to
//                perform file encryption using Caesar Cipher. Demonstrates DLL loading and
//                function pointer usage for secure file transfer operations.
// Author      :  Ishwari Pravin Jadhav
// Date        :  12/09/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include<windows.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	main
//	Function Date	:	12/09/2025
//	Function Author	:	Ishwari Pravin Jadhav
//	Parameters		:	None
//	Description		:	Main entry point of the client program. It dynamically loads the
//						Server DLL, retrieves the address of the encryption function, and
//						executes Caesar Cipher encryption on the given file.
//	Returns			:	int - Returns 0 on success, -1 on failure.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
typedef void (*FPTR)(char*, char*, int);
int main()
{
    HINSTANCE hdll = LoadLibrary(L"ServerSFTS.dll");

    if (hdll == NULL)
    {
        cout<< "Unable to load library\n";
        return -1;
    }
    FPTR fp = (FPTR)GetProcAddress(hdll,"Encrypt_Ceasor_Cipher");
    if (fp == NULL)
    {
        cout<< "Unable to get address of function\n";
        return -1;
    }
    fp((char*)"Input.txt",(char*)"Output.txt", 21);

    cout << "DLL loaded successfully\n";

    FreeLibrary(hdll);

    return 0;
}
