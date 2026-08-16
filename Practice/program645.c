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

#define MAXINODE 5
#define MAXFILESIZE 50
#define MAXOPENFILES 5

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
    struct Inode* next;
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
//      Function Name:  InitialiseUAREA
//      Description:    Used to Initialise Uarea
//      Author:         Rohan Shilimkar
//      Date:           31/07/2026
//  
/////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName,"Myexe");
    int i=0;

    for(i = 0 ; i<MAXFILESIZE ; i++)
    {
        uareaobj.UFDT[i] = NULL;
    }
    printf("CVFS : UAREA Gets Initialise Succesffully!");
}

/////////////////////////////////////////////////////////////
//
//      Function Name:  InitialiseSuperBlock
//      Description:    Used to Initialise Super Block
//      Author:         Rohan Shilimkar
//      Date:           31/07/2026
//  
/////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;
    printf("\nCVFS : Super Block Gets Initialise Succesffully!");
}


/////////////////////////////////////////////////////////////
//
//      Function Name:  CreateDILB()
//      Description:    Used to create LinkedList of INODES
//      Author:         Rohan Shilimkar
//      Date:           31/07/2026
//  
/////////////////////////////////////////////////////////////

void CreateDILB()
{
    PINODE temp = NULL;
    PINODE newn = NULL;
    int i=0;
    
    temp = head;
    for(i=1;i<=MAXINODE;i++)
    {
        newn = (PINODE)malloc(sizeof(INODE));
        
        newn->INodeNumber=i;
        strcpy(newn->FileName,"\0");
        newn->FileSize=0;      
        newn->FileType=0;      
        newn->ActualFileSize=0;
        newn->ReferenceCount=0;      
        newn->Permission=0;
        newn->Buffer=NULL;

        if(temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp->next;
        }
    }
    
    printf("\nCVFS : Super Block Gets Created Succesffully!");
  
}

/////////////////////////////////////////////////////////////
//
//      Function Name:  StartAuxillaryDataInitialisation()
//      Description:    Use to call all such functions
//                      which are used to initialise auxillary data
//      Author:         Rohan Shilimkar
//      Date:           31/07/2026
//  
/////////////////////////////////////////////////////////////

void StartAuxillaryDataInitialisation()
{
    strcpy(bootobj.Information,"Booting Process of CVFS is Completed\n");
    printf("%s",bootobj.Information);
    InitialiseUAREA();
    InitialiseSuperBlock();
    
    CreateDILB();

}



/////////////////////////////////////////////////////////////
//
//      Function Name:  DisplayHelp
//      Description:    Used to Display help to user of project
//      Author:         Rohan Shilimkar
//      Date:           1/08/2026
//  
/////////////////////////////////////////////////////////////

void DisplayHelp()
{
    
    printf("--------------------------------------\n");
    printf("\n------Marvellous CVFS Help Page-------");
    printf("\n------------------------------------\n");
    
    printf("man : it is udes to display Manual page\n");
    printf("clear: used to clear terminal screen\n");
    printf("creat: used to create new regular file\n");
    printf("open: used to open regular file\n");
    printf("close: used to close regular file\n");
    printf("write: used to write data into the file\n");
    printf("read: used to read the data from file\n");
    printf("stat: used to display statistical information of file\n");
    printf("unlink: used to delete the file\n");
    printf("exit: used to terminate Marvellous CVFS\n");
    
    
    printf("\n----------------------------------------\n");
}

/////////////////////////////////////////////////////////////
//
//      Function Name:  ManPageDisplay()
//      Description:    Used to Display Man Page of specific Command
//      Input:          Name of Command
//      Author:         Rohan Shilimkar
//      Date:           1/08/2026
//  
/////////////////////////////////////////////////////////////

void  ManPageDisplay(char Name[])
{
    if( strcmp(Name,"exit") == 0)
    {
        printf("About:Used to Terminate the Project \n");
        printf("Usage: exit \n");
    }
    else if(strcmp(Name,"ls")==0)
    {
        printf("About:Used to list all files from Current Directory\n");
        printf("Usage: ls \n");
        
    }
    else if(strcmp(Name,"clear")==0)
    {
        printf("About:Used to clear the terminaln");
        printf("Usage: clear\n");
    }
    else
    {
        printf("No Manual Entry Found for %s\n",Name);
    }
    
    
}
/////////////////////////////////////////////////////////////
//
//      Function Name:  IsFileExist()
//      Description:    Used to Check whether 
//                      file is present or not
//      Input:          Name of File 
//      Output:         true if present
//                      false if not present
//      Author:         Rohan Shilimkar
//      Date:           1/08/2026
//  
/////////////////////////////////////////////////////////////

bool IsFileExist(
                char Name[]             //Name of File
                )
{
    PINODE temp = head;
    bool bFlag = false;

   while(temp!=NULL)
   {
    if(strcmp(temp->FileName,Name)==0)
    {
        bFlag = true;
        break;
    }
    temp = temp->next;
   }

   return bFlag;

}


/////////////////////////////////////////////////////////////
//
//      Function Name:  CreateFile()
//      Description:    Used to create a new File
//      Input:          Name of File and Permissions
//      Output:         File Descriptor
//      Author:         Rohan Shilimkar
//      Date:           1/08/2026
//  
/////////////////////////////////////////////////////////////


int CreateFile(
                char Name[],        //Name of File
                int permission      // File Permission
              )
{
    PINODE temp = head;
    int i=0;

    if((superobj.FreeInodes)==0)
    {
        return ERR_NO_INODES;
    }
    
    // Permission value is wrong
    // Permission = 1 read
    // Permission = 2 write
    // Permission = 3 read + write

    if(permission < 1 || permission > 3 )
    {
        return ERR_INVALID_PARAMETER;
    }

   if(IsFileExist(Name)==true)
   {
        return ERR_FILE_ALREADY_EXIST;
   }
   
   //Search for empty inode

   while(temp != NULL)
   {
    if(temp->FileType == 0)
    {
        break;
    }
        temp = temp->next;
   }

   // Rare Case
   if(temp == NULL)
   {
        return ERR_INVALID_PARAMETER;
   }

   // Search Empty UFDT entry

   //Reserve first 3 fd
   for(i=3;i<MAXINODE;i++)
   {
        if(uareaobj.UFDT[i]== NULL)
        {
            break;
        }
   }
   if(i == MAXOPENFILES)
   {
        return ERR_MAX_FILES_OPEN;
   }

   //Allocate memory for file table
   uareaobj.UFDT[i] = (PFILETABLE)malloc(sizeof(FILETABLE));

   ///Initialise FileTable
   uareaobj.UFDT[i]->ReadOffset = 0;
   uareaobj.UFDT[i]->WriteOffset = 0;
   uareaobj.UFDT[i]->Mode = permission;


   // Connect File table with inode

   uareaobj.UFDT[i]->ptrinode = temp;

   // Initialise all members of iNode

   //
   strcpy(uareaobj.UFDT[i]->ptrinode->FileName,Name);

   //
   uareaobj.UFDT[i]->ptrinode->FileSize = MAXFILESIZE;

   //
   uareaobj.UFDT[i]->ptrinode->ActualFileSize = 0;

   //
   uareaobj.UFDT[i]->ptrinode->FileType = REGULARFILE;

   //
   uareaobj.UFDT[i]->ptrinode->ReferenceCount = 1;
   //
   
   uareaobj.UFDT[i]->ptrinode->Permission = permission;

   //Allocate Memory for Files Data (Data Block)
   uareaobj.UFDT[i]->ptrinode->Buffer = (char *)malloc(MAXFILESIZE);

   superobj.FreeInodes--;
   
    return i;

}


/////////////////////////////////////////////////////////////
//
//      Entry Point Function Of The CVFS Project
//
////////////////////////////////////////////////////////////

int main()
{
    StartAuxillaryDataInitialisation();

    char str[80] = {'\0'};
    char Command[5][20]= {{'\0'}};
    int iRet = 0,iCount = 0;

    printf("-----------------------------------------------------\n");
    printf("\n--------Marvellous CVFS started Sucessfully---------\n");
    printf("\n---------------------------------------------------\n");
    
    //Infinite Listening Shell
    while(1)
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\nMarvellous CVFS : >");
        fgets(str,sizeof(str),stdin);

        iCount = sscanf(str,"%s %s %s %s %s",Command[0],Command[1],Command[2],Command[3],Command[4]);

        fflush(stdin);
    

        if(iCount == 1)
        {
            //Marvellous CVFS : > exit
            if(strcmp(Command[0],"exit")==0)
            {
                printf("\nThank You for using Marvellous CVFS\n");
                printf("Deallocating all resources of Marvellous CVFS\n");;
                break;
            }
            //Marvellous CVFS : > help
            else if(strcmp(Command[0],"help")==0)
            {
                DisplayHelp();
            }
            //Marvellous CVFS : > clear
            else if(strcmp(Command[0],"clear")==0)
            {
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif    

            }
            else
            {
                printf("Command Not Found");
                printf("Please refer help Option to get more Information\n");
                printf("Please refer Manual page of command using man\n");
        
            }
        }
        else if(iCount == 2)
        {
            //Marvellous CVFS : > man open
            if(strcmp(Command[0],"man")== 0)
            {
                ManPageDisplay(Command[1]);
            }
            else
            {
                printf("Command Not Found");
                printf("Please refer help Option to get more Information\n");
                printf("Please refer Manual page of command using man\n");
            }

        }
        else if(iCount == 3)
        {
            //Marvellous CVFS : > creat Ganesh.txt 3
            if(strcmp(Command[0],"creat")==0)
            {
                iRet = CreateFile(Command[1],atoi(Command[2]));

                if(iRet == ERR_NO_INODES )
                {
                    printf("Error: Unable to create new file\n");
                    printf("Because no free inode\n");
                }
                else if(iRet == ERR_INVALID_PARAMETER)
                {
                    printf("Error: Unable to create new file\n");
                    printf("Because parameters of command are invalid\n");
                    printf("Please use man Page to get actual parameters\n");
                }
                else if(iRet == ERR_FILE_ALREADY_EXIST)
                {
                    printf("Error: Unable to create new file\n");
                    printf("Because File name is already Present\n");
                    printf("Please use ls command to check names of all files\n");
                }
                else if(iRet == ERR_MAX_FILES_OPEN)
                {
                    printf("Error: Unable to create new file\n");
                    printf("Because the UFDT is full\n");
                    printf("Please close some opened files\n");
                }
                else
                {
                    printf("File Created Successfully with fd: %d",iRet);
                }
            }
        }
        else if(iCount == 4)
        {

        }
        else
        {
            printf("Command Not Found");
            printf("Please refer help Option to get more Information\n");
            printf("Please refer Manual page of command using man\n");
        }

    }// End Of While

    return 0;

}// End Of Main