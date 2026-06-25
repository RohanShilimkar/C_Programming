/* Algorithm

    Start
        Accept A number From User
        
        Display the Number of Factors in it
        
    Stop    



*/



/////////////////////////////////////////////////////
//      
//      Include Required Header Files
//
/////////////////////////////////////////////////////


#include<stdio.h>


/////////////////////////////////////////////////////////
//
//       Function Name : DisplayDigit
//       Input         : Integer     
//       Output        : Integer
//       Description   : Display's The Factors of Number
//       Author        : Rohan Rajan Shilimkar
//
/////////////////////////////////////////////////////////



void DisplayDigit(int iNo)
{
    int iDigit = 0;

    if(iNo<0)
    {
        iNo = -iNo; 
    }

    while(iNo>0)
    {
        iDigit = iNo % 10;
        printf("%d\n",iDigit);
        iNo = iNo / 10;

    }
}


///////////////////////////////////////////////////
//
//     Main Application 
//
///////////////////////////////////////////////////


int main()
{
    int iValue =0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    DisplayDigit(iValue);


    return 0;
}

/////////////////////////////////////////////////
//
//     Input : 2395
//     Output : 5,9,3,2
//
//     Input : -1018
//     Otput : 8,1,0,1
//
/////////////////////////////////////////////////
