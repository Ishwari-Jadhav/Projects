//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Project     :  Secure File Transfer System (SFTS)
// File        :  ServerSFTS.cpp
// Description :  Implements encryption and decryption functionalities using Caesar and XOR
//                ciphers. The functions are exported as DLL functions to be accessed by the
//                client application during secure file transfer.
// Author      :  Ishwari Pravin Jadhav
// Date        :  12/09/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>

using namespace std;

#define MAX_SIZE 1024

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	Encrypt_Ceasor_Cipher
//	Function Date	:	12/09/2025
//	Function Author	:	Ishwari Pravin Jadhav
//	Parameters		:	char* Src, char* Dest, int Key
//	Description		:	Encrypts file data using Caesar Cipher technique and stores the
//						encrypted content into destination file.
//	Returns			:	None
//
//////////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) void Encrypt_Ceasor_Cipher(char* Src, char* Dest, int Key)
{
    int fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1) { printf("Unable to open source file: %s\n", Src); return; }

    int fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, _S_IREAD | _S_IWRITE);
    if (fdDest == -1) { printf("Unable to create destination file: %s\n", Dest); _close(fdSrc); return; }

    char Buffer[MAX_SIZE];
    int iRet;
    while ((iRet = _read(fdSrc, Buffer, MAX_SIZE)) > 0)
    {
        for (int i = 0; i < iRet; i++)
            Buffer[i] = (unsigned char)(Buffer[i] + Key);
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	Decrypt_Ceasor_Cipher
//	Function Date	:	12/09/2025
//	Function Author	:	Ishwari Pravin Jadhav
//	Parameters		:	char* Src, char* Dest, int Key
//	Description		:	Decrypts a Caesar Cipher-encrypted file and restores original content.
//	Returns			:	None
//
//////////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) void Decrypt_Ceasor_Cipher(char* Src, char* Dest, int Key)
{
    int fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1) { printf("Unable to open source file: %s\n", Src); return; }

    int fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, _S_IREAD | _S_IWRITE);
    if (fdDest == -1) { printf("Unable to create destination file: %s\n", Dest); _close(fdSrc); return; }

    char Buffer[MAX_SIZE];
    int iRet;
    while ((iRet = _read(fdSrc, Buffer, MAX_SIZE)) > 0)
    {
        for (int i = 0; i < iRet; i++)
            Buffer[i] = (unsigned char)(Buffer[i] - Key);
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	Encrypt_XOR_Cipher
//	Function Date	:	12/09/2025
//	Function Author	:	Ishwari Pravin Jadhav
//	Parameters		:	char* Src, char* Dest, char Key
//	Description		:	Encrypts a file using XOR Cipher and writes the encrypted content
//						into the destination file.
//	Returns			:	None
//
//////////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) void Encrypt_XOR_Cipher(char* Src, char* Dest, char Key)
{
    int fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1) { printf("Unable to open source file: %s\n", Src); return; }

    int fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, _S_IREAD | _S_IWRITE);
    if (fdDest == -1) { printf("Unable to create destination file: %s\n", Dest); _close(fdSrc); return; }

    char Buffer[MAX_SIZE];
    int iRet;
    while ((iRet = _read(fdSrc, Buffer, MAX_SIZE)) > 0)
    {
        for (int i = 0; i < iRet; i++)
            Buffer[i] = Buffer[i] ^ Key;
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	Decrypt_XOR_Cipher
//	Function Date	:	12/09/2025
//	Function Author	:	Ishwari Pravin Jadhav
//	Parameters		:	char* Src, char* Dest, char Key
//	Description		:	Decrypts a XOR Cipher-encrypted file and restores the original content.
//	Returns			:	None
//
//////////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) void Decrypt_XOR_Cipher(char* Src, char* Dest, char Key)
{
    int fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1) { printf("Unable to open source file: %s\n", Src); return; }

    int fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, _S_IREAD | _S_IWRITE);
    if (fdDest == -1) { printf("Unable to create destination file: %s\n", Dest); _close(fdSrc); return; }

    char Buffer[MAX_SIZE];
    int iRet;
    while ((iRet = _read(fdSrc, Buffer, MAX_SIZE)) > 0)
    {
        for (int i = 0; i < iRet; i++)
            Buffer[i] = Buffer[i] ^ Key;
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}