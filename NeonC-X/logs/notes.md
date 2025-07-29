We are currently working on walking the NTDLL file that is loaded into every process in order to find syscalls for windows api functions.


The Process Environment Block contains process-wide information including command line parameters, environment variables, 
and crucially, a linked list of all modules (DLLs and executables) loaded in the process.
This module list is what allows us to find NTDLL.dll without making any API calls.


