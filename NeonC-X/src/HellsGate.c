//HellsGate.c

#include <Windows.h>
#include "includes/structs.h"

/*--------------------------------------------------------------------
  VX Tables
  For example, NtAllocateVirtualMemory would be represented
  as VX_TABLE_ENTRY NtAllocateVirtualMemory.
--------------------------------------------------------------------*/
typedef struct _VX_TABLE_ENTRY {
    PVOID   pAddress;
    DWORD64 dwHash;
    WORD    wSystemCall;
} VX_TABLE_ENTRY, * PVX_TABLE_ENTRY;

typedef struct _VX_TABLE { //each member will be of type VX_TABLE_ENTRY
    VX_TABLE_ENTRY NtAllocateVirtualMemory;
    VX_TABLE_ENTRY NtProtectVirtualMemory;
    VX_TABLE_ENTRY NtCreateThreadEx;
    VX_TABLE_ENTRY NtWaitForSingleObject;
    // Add more syscalls as needed
} VX_TABLE, * PVX_TABLE;

BOOL GetImageExportDirectory(PVOID pModuleBase, PIMAGE_EXPORT_DIRECTORY* ppImageExportDirectory) {
    // Get DOS header
    PIMAGE_DOS_HEADER pImageDosHeader = (PIMAGE_DOS_HEADER)pModuleBase;
    if (pImageDosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        return FALSE;
    } 
    return 1;
};
