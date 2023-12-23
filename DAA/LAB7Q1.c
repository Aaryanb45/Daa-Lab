// Insertion Sort for words ;-;

#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j,k;
    char temp[30];
    printf("Enter number of words to be sorted : ");
    scanf("%d",&n);
    char arr[n][30];
    for(i=0;i<n;i++)
    {
        printf("Enter %d : ",i+1);
        scanf("%s", arr[i]);
    }
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if (strcmp(arr[i], arr[j]) <= 0)
            {
                break;
            }
        }
        if (i-j>1)
        {
            for(k=i;k>j+1;k--)
            {
                // temp=arr[k];
                strcpy(temp,arr[k]);
                // arr[k]=arr[k-1];
                strcpy(arr[k],arr[k-1]);
                // arr[k-1]=temp;
                strcpy(arr[k-1],temp);
                printf("IN");
            }
        }
    }
    printf("\nSorted list is : ");
    for(i=0;i<n;i++)
    {
        printf("%s ",arr[i]);
    }
    return 0;
}