#include <stdio.h>
#include <string.h>

void IntegerSort(int array[],int limit);
void MarksSort(float array[],int limit);
int main()
{

    int limit;
    printf("Enter the maximum number of students: ");
    scanf("%d",&limit);
    float marks[limit];
    char name[limit][256];
    char temp[256];
    int roll[limit];
    printf("Enter Name, Roll No and Marks : \n");
    for(int i = 0; i<limit; ++i){
        printf("Name %d: ",i+1);
        scanf("%s",name[i]);
        printf("Roll %d: ",i+1);
        scanf("%d",&roll[i]);
        printf("Marks %d: ",i+1);
        scanf("%f",&marks[i]);
    }
    
    //sorting
    printf("1. Sort by Name.\n2. Sort by Roll\n3. Sort by marks \n");
    int count;
    scanf("%d",&count);
    if(count==1)
    {
        for(int i=0; i<limit -1; ++i)
        for(int j=i+1; j<limit ; ++j)
        {
            if(strcmp(name[i], name[j])>0)
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    
        printf("\n The sorted Record is: \n");
        printf("Name\t\tRoll\t\tMarks \n");
        for(int i = 0; i<limit; i++)
        {
            printf("%s\t\t%d\t\t%f\n",name[i],roll[i],marks[i]);
        }

    }

    else if(count == 2)
    {
        IntegerSort(roll,limit);
        printf("\n The sorted Record is: \n");
        printf("Name\t\tRoll\t\tMarks \n");
        for(int i = 0; i<limit; i++)
        {
            printf("%s\t\t%d\t\t%f\n",name[i],roll[i],marks[i]);
        }
        
    }
    else if(count ==3)
    {
        MarksSort(marks,limit);
        printf("\n The sorted Record is: \n");
        printf("Name\t\tRoll\t\tMarks \n");
        for(int i = 0; i<limit; i++)
        {
            printf("%s\t\t%d\t\t%f\n",name[i],roll[i],marks[i]);
        }
    }
    else printf("\nWrong Input\n");
    
    return 0;
}




void IntegerSort(int array[],int limit)
{
    int temp = 0;
    for(int i = 0;i<limit-1; ++i)
    {
        for(int j = 0; j<limit-i-1; ++j)
        {
            if(array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void MarksSort(float array[],int limit)
{
    int temp = 0;
    for(int i = 0;i<limit-1; ++i)
    {
        for(int j = 0; j<limit-i-1; ++j)
        {
            if(array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

