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
//  Description:    It holds the information
//                  to boot the Opersting System
//
////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};


////////////////////////////////////////////////////
//
//      Structure Name:  SuperBlock
//      Description:     Holds the information
//                       of complete File System
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
//  Structure Name:   File Table
//  Description:      It holds the information
//                    of opened files
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
//  Structure Name:  UAREA
//  Description:     It holds the information of process
//
//////////////////////////////////////////////////////////

struct UAREA
{
    //char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};



//////////////////////////////////////////////////////////
//
//  Structure Name:  save
//  Description:     Saves the file to the Secondary Storage
//
//////////////////////////////////////////////////////////

struct save
{
    char FileName[20];
    int INodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
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
   // strcpy(uareaobj.ProcessName,"Myexe");
    int i=0; 

    for(i = 0 ; i<MAXOPENFILES ; i++)
    {
        uareaobj.UFDT[i] = NULL;
    }
    printf("CVFS : UAREA Gets Initialise Succesffully!\n");
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
    printf("\nCVFS : Super Block Gets Initialise Succesffully!\n");
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
    for(i=1 ; i<=MAXINODE ; i++)
    {
        newn = (PINODE)malloc(sizeof(INODE));  

        strcpy(newn->FileName,"\0");
        newn->INodeNumber=i;
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
    
    printf("\nCVFS : DILB gets created succesfully!\n");
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
    strcpy(bootobj.Information,"\nBooting Process of CVFS is Completed\n");
    printf("%s\n",bootobj.Information);

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
    printf("\n------ CVFS Help Page-------");
    printf("\n------------------------------------\n");
    
    printf("man :   it is udes to display Manual page\n");
    printf("clear:  used to clear terminal screen\n");
    printf("creat:  used to create new regular file\n");
    printf("open:   used to open regular file\n");
    printf("close:  used to close regular file\n");
    printf("write:  used to write data into the file\n");
    printf("read:   used to read the data from file\n");
    printf("stat:   used to display statistical information of file\n");
    printf("unlink: used to delete the file\n");
    printf("lseek:  used to Change the file offset\n");

    printf("exit:   used to terminate CVFS\n");
       
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

void ManPageDisplay(char Name[])
{
    if( strcmp(Name,"exit") == 0)
    {
        printf("About: Used to Terminate the Project \n");
        printf("Usage: exit \n");
    }
    else if(strcmp(Name,"ls")==0)
    {
        printf("About: Used to list all files from Current Directory\n");
        printf("Usage: ls \n");
        
    }
    else if(strcmp(Name,"clear")==0)
    {
        printf("About: Used to clear the terminal");
        printf("Usage: clear\n");
    }
    else if(strcmp(Name,"creat")==0)
    {
        printf("About: Used to create new File");
        printf("Usage: creat file_name Permission\n");

        printf("FileName: Name of that File we want ot create\n");
        printf("Permission: Permission of the New File\n");

        printf("Permission: 1 -> Read\n");
        printf("Permission: 2-> Write\n");
        printf("Permission: 3-> Read + Write\n");
    }
    else if(strcmp(Name,"unlink")==0)
    {
        printf("About: Used to delete existing File\n");
        printf("Usage: unlink_file_name\n");
        printf("File Name: Name of file that we want to delete\n");
    }
    else if(strcmp(Name,"stat")==0)
    {
        printf("About: Used to get information of file\n");
        printf("Usage: stat file_name\n");
        printf("File Name: Name of file whose information should be fetch\n");
    }
    else if(strcmp(Name,"lseek")==0)
    {
        printf("About: Used to change file descriptor\n");
        printf("Usage: lseek fd number of bytes to read");
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

   if(IsFileExist(Name) == true)
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
   for(i=3 ; i<MAXINODE ; i++)
   {
        if(uareaobj.UFDT[i] == NULL)
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

   // Copy the New file Name into Filename of Inode
   strcpy(uareaobj.UFDT[i]->ptrinode->FileName,Name);

   //Set its FileSize to MAXFILESIZE (macro)
   uareaobj.UFDT[i]->ptrinode->FileSize = MAXFILESIZE;

   //set ActualFileSize to 0
   uareaobj.UFDT[i]->ptrinode->ActualFileSize = 0;

   //Set Filetype to REGULARFILES (macro)
   uareaobj.UFDT[i]->ptrinode->FileType = REGULARFILE;

   // Increment its Reference Count
   uareaobj.UFDT[i]->ptrinode->ReferenceCount = 1;
   
   //Set value of permission to Permission 
   uareaobj.UFDT[i]->ptrinode->Permission = permission;

   //Allocate Memory for Files Data (Data Block)
   uareaobj.UFDT[i]->ptrinode->Buffer = (char *)malloc(MAXFILESIZE);
   
    superobj.FreeInodes--;
   
    return i;
}


/////////////////////////////////////////////////////////////
//
//      Function Name:  LsFile()
//      Description:    Used to display names of all files
//      Input:          None
//      Output:         None
//      Author:         Rohan Shilimkar
//      Date:           1/08/2026
//  
/////////////////////////////////////////////////////////////

void LsFile()
{
    PINODE temp = head;

    printf("-----------------------------------------------------\n");
    printf("\n-------- CVFS Files Information---------\n");
    printf("\n---------------------------------------------------\n");

    
    if(superobj.TotalInodes == superobj.FreeInodes)
    {
        printf("\nNo Files in Directory!\n");
    }
   
    while(temp!=NULL)
    {
        if(temp->FileType !=0 )
        {
            printf("\n%s\n",temp->FileName);
        }
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////
//
//      Function Name:  LsFile_All()
//      Description:    Used to display all details of all files
//      Input:          None
//      Output:         None
//      Author:         Rohan Shilimkar
//      Date:           2/08/2026
//  
/////////////////////////////////////////////////////////////

void LsFile_All()
{
    PINODE temp = head;
    
    printf("\n-----------------------------------------------------\n");
    printf("\n-------- CVFS Files Information---------\n");
    printf("\n---------------------------------------------------\n");
    
    
    if(superobj.TotalInodes == superobj.FreeInodes)
    {
        printf("\nNo Files in Directory!\n");
    }
    
    while(temp!=NULL)
    {
        if(temp->FileType !=0 )
        {
            printf("\n%s  %d  %d\n",temp->FileName,temp->INodeNumber,temp->ActualFileSize);
        }
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////
//
//      Function Name:  stat_file()
//      Description:    Used to display all details of specific file
//      Input:          File Name
//      Output:         Exit Status Of Function
//      Author:         Rohan Shilimkar
//      Date:           2/08/2026
//  
/////////////////////////////////////////////////////////////

int stat_file(char Name[])
{
    PINODE temp = head;
    int Permission = 0;
    int Type = 0;
    
    if(IsFileExist(Name) == false)
    {
        return ERR_FILE_NOT_EXIST;
    }
    
    while(temp != NULL)
    {
        if(strcmp(temp->FileName,Name)==0)
        {
            
            printf("\n-----------------------------------------------------\n");
            printf("\n--------Statistical Information of File------------\n");
            printf("\n---------------------------------------------------\n");
            
            printf("\nFile Name: %s",temp->FileName);
            printf("\nInode Number: %d",temp->INodeNumber);
            printf("\nFile Size: %d",temp->FileSize);
            printf("\nActual File Size: %d",temp->ActualFileSize);
            printf("\nReference Count: %d",temp->ReferenceCount);
            
            Permission= temp->Permission;
            if(Permission == READ)
            {
                printf("\nFile Permission: Read Only\n");
            }
            else if(Permission == WRITE)
            {
                printf("\nFile Permission: Write\n");
            }
            else if(Permission == READ + WRITE)
            {
                printf("\nFile Permission:Read + Write\n");
                
            }
            
            Type = temp->FileType;
            
            if(Type == REGULARFILE)
            {
                printf("\nFile Type : Regular File");
            }
            else if(Type == SPECIALFILE)
            {
                printf("\nFile Type: Special File");
            }
            
            break;
        }
        temp = temp->next;
    }
    
    return EXECUTE_SUCCESS;   
    
}

/////////////////////////////////////////////////////////////
//
//      Function Name:  unlink_file()
//      Description:    Used to Delete the Specific File
//      Input:          File Name
//      Output:         Exit Status Of Function
//      Author:         Rohan Shilimkar
//      Date:           2/08/2026
//  
/////////////////////////////////////////////////////////////

int unlink_file(char Name[])
{
    int i=0;

    if(IsFileExist(Name)==false)
    {
        return ERR_FILE_NOT_EXIST;
    }

    for(i=0;i<MAXOPENFILES;i++)
    {
        if(uareaobj.UFDT[i]!=NULL)
        {
            if(strcmp(uareaobj.UFDT[i]->ptrinode->FileName,Name)==0)
            {
                //Deallocate memory of Buffer
                free(uareaobj.UFDT[i]->ptrinode->Buffer);
                uareaobj.UFDT[i]->ptrinode->Buffer = NULL;


                strcpy(uareaobj.UFDT[i]->ptrinode->FileName,"\0");

                uareaobj.UFDT[i]->ptrinode->FileSize = 0;
                uareaobj.UFDT[i]->ptrinode->ActualFileSize = 0;
                uareaobj.UFDT[i]->ptrinode->FileType = 0;
                uareaobj.UFDT[i]->ptrinode->Permission = 0;
                uareaobj.UFDT[i]->ptrinode->ReferenceCount = 0;

                //Deallocate File Table
                free(uareaobj.UFDT[i]);
                uareaobj.UFDT[i] = NULL;

                superobj.FreeInodes++;
                break;  //imp
            }

        }//end of if

    }//End of For

    return EXECUTE_SUCCESS;

}//End of Function



/////////////////////////////////////////////////////////////
//
//      Function Name:  write_file()
//      Description:    Used to write the data into Specific File
//      Input:          File Descriptor 
//                      data what we want to write size of data
//      Output:         Number of bytes Succesfully return
//      Author:         Rohan Shilimkar
//      Date:           2/08/2026
//  
/////////////////////////////////////////////////////////////

int write_file(int fd,char *data,int size)
{
     int offset = 0,iRet=0;
    printf("File descriptor %d\n",fd);
    printf("Data that we want to write: %s\n",data);
    printf("Size: %d\n",size);


    //If fd is Invalid
    if(fd < 0 || fd > MAXOPENFILES)
    {
        return ERR_INVALID_PARAMETER;
    }


    //if writing permission is not there
    if(uareaobj.UFDT[fd]->ptrinode->Permission < WRITE)
    {
        return ERR_PERMISSION_DENIED;
    }


    //Check the space is there or not
    if((MAXFILESIZE - uareaobj.UFDT[fd]->WriteOffset) < size)
    {
        return ERR_INSUFFICENT_SPACE;
    }

    //Actual Data Writting
    strncpy(uareaobj.UFDT[fd]->ptrinode->Buffer + uareaobj.UFDT[fd]->WriteOffset,data,size);

    //Update the Write Offset
    uareaobj.UFDT[fd]->WriteOffset = uareaobj.UFDT[fd]->WriteOffset + size;

    //Update Actual File Size
    uareaobj.UFDT[fd]->ptrinode->ActualFileSize = uareaobj.UFDT[fd]->ptrinode->ActualFileSize + size ;

    return size;

}


/////////////////////////////////////////////////////////////
//
//      Function Name:  read_file()
//      Description:    Used to read the data from Specific File
//      Input:          File Descriptor address of empty Buffer 
//                         size of data
//      Output:         Number of bytes Succesfully return
//      Author:         Rohan Shilimkar
//      Date:           2/08/2026
//  
/////////////////////////////////////////////////////////////

int read_file(int fd, char* data,int size)
{
    
    if(fd < 0 || fd > MAXOPENFILES)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(size < 0)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(uareaobj.UFDT[fd] == NULL)
    {
        return ERR_FILE_NOT_EXIST;
    }

    if(uareaobj.UFDT[fd]->ptrinode->Permission < READ)
    {
        return ERR_PERMISSION_DENIED;
    }

    if((MAXFILESIZE -  uareaobj.UFDT[fd]->ReadOffset) < size)
    {
        return ERR_INSUFFICENT_DATA;
    }

    strncpy(data,uareaobj.UFDT[fd]->ptrinode->Buffer + uareaobj.UFDT[fd]->ReadOffset,size);

    uareaobj.UFDT[fd]->ReadOffset = uareaobj.UFDT[fd]->ReadOffset + size;

    data[size] = '\0';

    return size;
}

/////////////////////////////////////////////////////////////
//
//      Function Name:  lseek_file()
//      Description:    Used to read the data
//      Input:          File Descriptor address of empty Buffer 
//                      Origin
//      Output:         Number of bytes Succesfully return
//      Author:         Rohan Shilimkar
//      Date:           2/08/2026
//  
/////////////////////////////////////////////////////////////


int lseek_file(int fd,int seek)
{
    int iRet = 0;

    if(fd < 0 || fd > MAXOPENFILES)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(seek < 0)
    {
        return ERR_INVALID_PARAMETER;
    }
    
    if(uareaobj.UFDT[fd] == NULL)
    {
        return ERR_FILE_NOT_EXIST;
    }

    
    uareaobj.UFDT[fd]->ReadOffset = uareaobj.UFDT[fd]->ReadOffset + seek;
    uareaobj.UFDT[fd]->WriteOffset = uareaobj.UFDT[fd]->WriteOffset + seek;
 
    return EXECUTE_SUCCESS;
}


void save()
{
   
    PINODE temp = head;

    struct save sobj;

    ḍḍ = 

}


/////////////////////////////////////////////////////////////
//
//      Entry Point Function Of The CVFS Project
//
////////////////////////////////////////////////////////////

int main()
{
    StartAuxillaryDataInitialisation();

    char* EmptyBuffer = NULL;

    //Input Command
    char str[80] = {'\0'};

    //Tokenise command
    char Command[5][20]= {{'\0'}};
    int iRet = 0,iCount = 0,size=0;

    //Data for write system call
    char InputBuffer[MAXFILESIZE] = {'\0'};

    printf("-----------------------------------------------------\n");
    printf("\n------------ CVFS started Sucessfully--------------\n");
    printf("\n---------------------------------------------------\n");
    
    //Infinite Listening Shell
    while(1)
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\n CVFS : >");
        fgets(str,sizeof(str),stdin);

        iCount = sscanf(str,"%s %s %s %s %s",Command[0],Command[1],Command[2],Command[3],Command[4]);

        fflush(stdin);

        if(iCount == 1)
        {
            // CVFS : > exit
            if(strcmp(Command[0],"exit")==0)
            {
                printf("\nThank You for using CVFS\n");
                printf("\nDeallocating all resources of  CVFS\n");;
                break;
            }
            // CVFS : > help
            else if(strcmp(Command[0],"help")==0)
            {
                DisplayHelp();
            }
            // CVFS : > clear
            else if(strcmp(Command[0],"clear")==0)
            {
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif

            }
            // CVFS:> ls
            else if(strcmp(Command[0],"ls")==0)
            {
                   LsFile();
            }
            else
            {
                printf("\nCommand Not Found\n");
                printf("\nPlease refer help Option to get more Information\n");
                printf("\nPlease refer Manual page of command using man\n");
        
            }
        }
        else if(iCount == 2)
        {
            // CVFS : > man open
            if(strcmp(Command[0],"man")== 0)
            {
                ManPageDisplay(Command[1]);
            }
            // CVFS : > ls -a
            else if((strcmp(Command[0],"ls")== 0) && (strcmp(Command[1],"-a")==0))
            {
                LsFile_All();
            }
            // CVFS : > stat Ganesh.txt(FileName)
            else if((strcmp(Command[0],"stat")== 0))
            {
                iRet = stat_file(Command[1]);

                if(iRet == ERR_FILE_NOT_EXIST)
                {
                    printf("\nError: File Not Exist\n");
                }
                
            }
            //  CVFS : > write 3
            else if(strcmp(Command[0],"write") == 0)
            {
                printf("Enter the data that you want to write into the file\n");

                fgets(InputBuffer,MAXFILESIZE,stdin);

                size = strlen(InputBuffer);

                iRet = write_file(atoi(Command[1]), InputBuffer, size-1);

                if(iRet == ERR_INVALID_PARAMETER)
                {
                    printf("Error : Invalid parameters\n");

                    printf("Please refer man page for more information\n");
                }
                else if(iRet == ERR_FILE_NOT_EXIST)
                {
                    printf("Error : File not exist\n");
                }
                else if(iRet == ERR_PERMISSION_DENIED)
                {
                    printf("Error : There is no perission to write the data\n");
                }
                else if(iRet == ERR_INSUFFICENT_SPACE)
                {
                    printf("Error : There is no space to write the data\n");
                }
                else 
                {
                    printf("%d bytes gets succesfully written into the file\n",iRet);
                }
        
            }
            //CVFS: >  unlink Ganesh.txt
            else if((strcmp(Command[0],"unlink")== 0))
            {
                iRet = unlink_file(Command[1]);

                if(iRet == ERR_FILE_NOT_EXIST)
                {
                    printf("\nError: File Not Exist\n");
                }
                else if(iRet == EXECUTE_SUCCESS)
                {
                    printf("\nFile Deleted Sucuessfully\n");
                }
                
            }
            // CVFS:> open filename
            else if(strcmp(Command[0],"open")==0)
            {
                

            }            
            else
            {
                printf("\nCommand Not Found\n");
                printf("\nPlease refer help Option to get more Information\n");
                printf("\nPlease refer Manual page of command using man\n");
            }
            
        }
        else if(iCount == 3)
        {
            // CVFS : > creat Ganesh.txt 3
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
            // CVFS : > read 3 10
            else if(strcmp(Command[0],"read")==0)
            {
                EmptyBuffer = (char *)malloc(atoi(Command[2]));

               iRet =  read_file(atoi(Command[1]),EmptyBuffer,atoi(Command[2]));

               if(iRet == ERR_INVALID_PARAMETER)
               {
                printf("Invalid ");
               }
               else if(iRet == ERR_FILE_NOT_EXIST)
               {
                printf("Not exist");
               }
               else if(iRet == ERR_INSUFFICENT_DATA)
               {
                    printf("Insufficent data");
               }
               else if(iRet == ERR_PERMISSION_DENIED)
               {
                    printf("No permission");
               }
               else
               {
                printf("Read operation is Successfull\n");
                printf("Data from file is :\n");
                printf("%s\n",EmptyBuffer);
                free(EmptyBuffer);
               }
            }
            //CVFS:> lseek fd bytes
            else if((strcmp(Command[0],"lseek")==0))
            {

                iRet = lseek_file(atoi(Command[1]),atoi(Command[2]));

                if(iRet == ERR_INVALID_PARAMETER)
                {
                    printf("Error invalid parameter");
                    printf("Refer man Page");
                }
                else
                {
                    printf("Command Executed Successfully!");
                }
            }   
            else
            {
            printf("\nCommand Not Found\n");
            printf("\nPlease refer help Option to get more Information\n");
            printf("\nPlease refer Manual page of command using man\n");
            }
                    
            
        }
        else
        {
            printf("\nCommand Not Found\n");
            printf("\nPlease refer help Option to get more Information\n");
            printf("\nPlease refer Manual page of command using man\n");
        }
    
    }// End Of While

    return 0;

}// End Of Main 
