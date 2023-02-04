# Windows System Programming

In this Repository I share some codes about windows APIs.

1. [MailSlot](/InterProcessCommiunication/MailSlot) : 
   Description : A mailslot is a mechanism for one-way interprocess communications (IPC). Applications can store messages in a mailslot. The owner of the mailslot can retrieve messages that are stored there. These messages are typically sent over a network to either a specified computer or to all computers in a specified domain. A domain is a group of workstations and servers that share a group name.

    We Implemented two codes , one of them write on share memory using MailSlot and another one Read Shared Memory.

    Thats like a online chat :)


2. [FileMapping](/InterProcessCommiunication/FileMapping/) :
    A memory-mapped file contains the contents of a file in virtual memory. This mapping between a file and memory space enables an application, including multiple processes, to modify the file by reading and writing directly to the memory. You can use managed code to access memory-mapped files in the same way that native Windows functions access memory-mapped files

    First run readMemory then Write :)