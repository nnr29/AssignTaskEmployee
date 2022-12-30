#include <assign.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int display();
void display_searched_word();
int word_string(char word[200],char string[200]);
int line_position = 1,line_search = 0;
int file_length;
char file_array[20][256];
int main()
{
    printf("Inside the main function *****************\n");
    display_searched_word();             //function calling
    return 0;
}
int display()
{
    char store_The_Value[100];
    FILE *fp;
    fp = fopen("task_list.csv","r");
    int i =0,j=0;
    printf("Inside the display function function ******************\n");
    while(fgets(store_The_Value,100,fp))//reads each line from the file
    {
        for(j=0;store_The_Value[j]!='\0';j++)
            file_array[i][j] = store_The_Value[j];
        printf("%s",file_array[i]);
        i++;
    }
    fclose(fp);
    printf("\n%d Lines in file\n",i);
    return i;
}
void display_searched_word()
{
    char word[200];
    int a;
    printf("Inside the display_searched_data function ************\n");
    file_length=display();
    printf("\n\nThe file_length is %d\n",file_length);
    printf("\n\n\nEnter the word to search in the string \n");
    fflush(stdin);
    gets(word);
    for(a=0;a<file_length;a++)
    {
        if(word_string(file_array[a],word))
        {
            printf("%s\n",file_array[a]);
            printf("%s word is  present in the string\n",word);
            break;
        }
        else
        {
            continue;
            printf("%s word is not present in the string\n",word);
            //break; //break statement is used so that word is not present in the statement executes only once
        }
    }
}
int word_string(char string[200],char word[200])
{
    int i=0, j, n, m;
    n = strlen(string);
    m = strlen(word);
    //printf("Inside the word_string function ***********\n");
  // printf("string length  %d\t  word length  %d\n",n,m);

    if (m > n)
    {
        printf("inside if condition  word length greater than string length");
        return 0;
    }
    while (i < n)
    {
        // printf("Inside i<n");
        j = 0;
        while (i<n && j<m && string[i]==word[j])
        {
//             printf("\nsearching %c    original %c",word[j],string[i]);
//             printf("\nstring i    %d  %d",i,n);
//             printf("\nword   j    %d  %d",j,m);
            ++i;
            ++j;
        }
        if (( i==n || string[i]==' ' || string[i]==',') && j==m)
        {
            printf("\nj %d  word m %d",j,m);
            return 1;
        }
        while (i<n && string[i] != ' ')
        {
            ++i;
        }
        ++i;
    }
    return 0;
}














