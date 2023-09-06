#include<stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int limit;
    printf("Enter number of max words: \n");
    scanf("%d",&limit);
    char str[limit][50], temp[50];
    printf("\nEnter %d words: \n",limit);

    for(i=0; i<limit; ++i)
        scanf("%s[^/n]",str[i]);

    
    for(i=0; i<limit -1; ++i)
        for(j=i+1; j<limit ; ++j)
        
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        

    printf("\nIn lexicographical order: \n");
    for(i=0; i<limit; ++i)
    {
        puts(str[i]);
    }

    return 0;
}