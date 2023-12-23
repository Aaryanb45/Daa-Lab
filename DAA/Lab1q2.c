// lab-1 Q2) Input – Two strings made of characters
// Output – Find out if the smaller string exists in the larger one. If yes, how many times?
#include<stdio.h>
#include<string.h>

 int substringCompare(const char *str1, int i, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (i + len2 > len1)
        return -1;  // Substring is out of bounds
    
    return strncmp(str1 + i, str2, len2);
}

int main(){
    char lstr[100];
    char sstr[100];
    printf("Enter larger string- ");
    scanf("%[^\n]s", lstr);
    getchar();
    printf("Larger string is: %s", lstr);
    printf("\nEnter smaller string- ");
    scanf("%[^\n]s", sstr);
    printf("Smaller string is: %s \n", sstr);
    
    int smallerLength = strlen(sstr);
    int largerLength = strlen(lstr);
    int count=0;
    for (int i = 0; i <= largerLength - smallerLength; i++) {
        if (substringCompare(lstr, i, sstr) == 0) {
            count++;
        }
    }
printf("The smaller string '%s' occurs %d times in the larger string '%s'.\n", sstr, count, lstr);

    return 0;
}