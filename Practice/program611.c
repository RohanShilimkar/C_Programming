/////////////////////////////////////////////////////////////
//
//      Header Files Inclusion
//
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>

/////////////////////////////////////////////////////////////
//
//      User-Defined Macros
//
////////////////////////////////////////////////////////////

#define MAXFILESIZE 50
#define MAXOPENFILES 10

#define READ 1
#define WRITE 2
#define EXCUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0
#define REGULARFILE 1
#define SPECIALFILE 2


/////////////////////////////////////////////////////////////
//
//       UserDefined  Macros for Error   
//
////////////////////////////////////////////////////////////

#define ERR_INVALID_PARAMETER -1

#define ERR_NO_INODES -2

#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4

#define ERR_PERMISSION_DENIED -5

#define ERR_INSUFFICENT_SPACE -6
#define ERR_INSUFFICENT_DATA -7

#define ERR_MAX_FILES_OPEN -8


////////////////////////////////////////////////////
//
//  Structure Name: BootBlock
//  Description:  It holds the information
//                toboot the Opersting System
//
////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

////////////////////////////////////////////////////
//
//      Structure Name: SuperBlock
//      Description: Holds the information
//                  of complete File System
// 
////////////////////////////////////////////////////


struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};


///////////////////////////////////////////////////////
//
//  Structure Name: Inode
//  Description: It holds the information of file
//
//////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int INodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    char* Buffer;
    struct inode* next;
};
typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

//////////////////////////////////////////////////////////
//
//  Structure Name: File Table
//  Description: It holds the information of opened files
//
//////////////////////////////////////////////////////////

#pragma pack(1)
struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode; 
};

typedef struct FileTable FILETABLE;
typedef struct FileTable* PFILETABLE; 


//////////////////////////////////////////////////////////
//
//  Structure Name: UAREA
//  Description: It holds the information of process
//
//////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};
/////////////////////////////////////////////////////////////
//
//     Gloabl Varibles Used in Project      
//
/////////////////////////////////////////////////////////////

struct BootBlock bootobj;
struct SuperBlock superobj;
struct UAREA uareaobj;

PINODE head = NULL;

/////////////////////////////////////////////////////////////
//
//      Entry Point Function Of The CVFS Project
//
////////////////////////////////////////////////////////////

int main()
{

    return 0;
}