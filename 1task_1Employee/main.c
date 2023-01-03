#include <assign.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FILE_SIZE 1024

int  display_task();
int  display_employee();

char temporary_data[FILE_SIZE];
char stored_line_data[FILE_SIZE];

void display_employee_searched_word();
void display_emp_task();
int  word_string(char word[],char string[]);
void store();

int  line_position = 1,line_search = 0;
int  file_length;int countIndex = 0;

char file_array_e[20][256];
char file_array_t[20][256];
char file_array_ta[20][256];

FILE *file_ptr_emp,*file_ptr_task,*file_ptr_assign,*file_replace_ptr;

char word_of_employee[50],word_of_task[50];
char stored_e_data[50];
char store_emp[50];
char store_task[50];
char tempContent[FILE_SIZE];

struct employee_details emp_store[2];
struct create_task     task_store[2];

int main()
{
    printf("Inside the main function\n");
    display_employee_searched_word();                                                  //function calling
    return 0;
}

int display_employee()
{
    char store_The_Value[100];
    file_ptr_emp = fopen("employee.csv","r");
    int i =0,j=0;
    printf("Inside the display function function \n");
    while(fgets(store_The_Value,200,file_ptr_emp))                                   //reads each line from the file
    {
        for(j=0;store_The_Value[j]!='\0';j++)
            file_array_e[i][j] = store_The_Value[j];
        printf("%s",file_array_e[i]);
        i++;
    }
    fclose(file_ptr_emp);
    return i;
}
int display_task()
{
    char store_The_Value[200];
    file_ptr_emp = fopen("task.csv","r");
    int i =0,j=0;
    printf("\n\nInside the display function function \n");
    while(fgets(store_The_Value,200,file_ptr_emp))                                 //reads each line from the file
    {
        for(j=0;store_The_Value[j]!='\0';j++)
            file_array_t[i][j] = store_The_Value[j];
        printf("%s",file_array_t[i]);
        i++;
    }
    fclose(file_ptr_emp);
    return i;
}
void display_employee_searched_word()
{
    int a,i;
    printf("Inside the display_searched_data function\n");
    file_length = display_employee();
    printf("\nEnter the employee name to display all the details \n");
    fflush(stdin);
    gets(word_of_employee);
    for(a=0;a<file_length;a++)
    {
        if(word_string(file_array_e[a],word_of_employee))
        {
            printf("%s\n",file_array_e[a]);
            strcpy(stored_e_data,file_array_e[a]);
            printf("%s word is  present in the string\n",word_of_employee);
            strcpy(store_emp,word_of_employee);
        }
        else
        {
            continue;
            printf("%s word is not present in the string\n",word_of_employee);
        }
    }
    printf("Inside the display_task_searched_data function\n");
    file_length = display_task();
    printf("\nEnter the task id to display all the details \n");
    fflush(stdin);
    gets(word_of_task);
    for(a=0;a<file_length;a++)
    {
        if(word_string(file_array_t[a],word_of_task))
        {
            printf("%s\n",file_array_t[a]);
            printf("%s word is  present in the string\n",word_of_task);
            strcpy(store_task,word_of_task);
            store();
            break;
        }
        else
        {
            continue;
            printf("%s word is not present in the string\n",word_of_task);
        }
    }
    file_ptr_assign=fopen("assign_data.txt","a");
    if(file_ptr_assign == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }
    for(i=0;i<1;i++)
    {
        strcpy(emp_store[i].task_obj.task_id,store_task);

        printf("emp_store[i].task_obj.task_id       %s\n",emp_store[i].task_obj.task_id);

        strcat(emp_store[i].task_obj.task_id,",");
        strcat(emp_store[i].task_obj.task_id ,stored_e_data);

       /* printf("**** %s\n",emp_store[i].task_obj.task_id);
        fprintf(file_ptr_assign,"%s\n",emp_store[i].task_obj.task_id);*/

    }

}
int word_string(char string[100],char word[100])
{
    int i=0, j, n, m;
    n = strlen(string);
    m = strlen(word);
    if (m > n)
    {
        printf("inside if condition  word length greater than string length");
        return 0;
    }
    while (i < n)
    {
        j = 0;
        while (i<n && j<m && string[i]==word[j])
        {
            ++i;
            ++j;
        }
        if (( i==n || string[i]==' ' || string[i]==',') && j==m)
        {
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
void store()
{
    int i;
    file_ptr_assign=fopen("assign_data.txt","a");
    if(file_ptr_assign == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }
    for(i=0;i<1;i++)
    {
        strcpy(emp_store[i].task_obj.task_id,store_task);

        //printf("emp_store[i].task_obj.task_id       %s\n",emp_store[i].task_obj.task_id);

        strcat(emp_store[i].task_obj.task_id,",");
        strcat(emp_store[i].task_obj.task_id ,stored_e_data);

        printf("** %s\n",emp_store[i].task_obj.task_id);
        fprintf(file_ptr_assign,"%s\n",emp_store[i].task_obj.task_id);

    }

}
