#include <stdio.h>
#include <time.h>                                                            // Preprocessor Directive to display the current date and time
#include "login_details_data.h"                                             //  Header file to structure and the their data members
#include <string.h>
#define FILE_SIZE 1024
#define numberOfEmp 10
int number_of_employees,number_of_tasks,file_length,countIndex=0,line_search=0;         //  Integer Global variables

struct employee_details employee_store_data[numberOfEmp];
struct create_task store_task_data[numberOfEmp];

void create_Administration_Access();
void stored_user_password( struct login_credential login_ptr2);          //Function to access the stored user name and password
int stored_word(char subWord2[20]);

void admin_Sign_Up_Fill_Details(struct login_credential *login_ptr);    //Function to sign up login credentials
void admin_Sign_In(struct login_credential *);                         //Function to sign in login credentials

void employee_option();
void employee_Fill_In_Details();
void employee_choice();

void employee_edit_text_csv();
void employee_edit_details_text();
void edit_employee_csv();
void employee_save_details();

void Save_Employee_Text();
void Save_Employee_CSV();
void Save_Employee_Object();

void replace_word_employee_task_csv();

void task_option();
void task_fill_in_details();
void task_edit_save_display_details();

FILE *admin_save,*employee_save,*employee_task_fptr,*task_save;
char filearray[20][256],temporary_data[FILE_SIZE];
int main()
{
    create_Administration_Access();
    return 0;
}
void create_Administration_Access()                                      //entering user name and password and not storing it
{
    struct login_credential *login_ptr;
    int loginOption;
    login_ptr=(struct login_credential*)malloc(sizeof (struct login_credential));
    printf("Welcome to Administration Access \n");
    enum login
    {
        STORED_USER_PASSWORD=1,
        SIGNUP_OPTION,
        EXIT_OPTION,
    };
    do
    {
        printf("\nEnter 1 to Sign In\n");
        printf("Enter 2 Sign up to this account \n");
        printf("Enter 3 to exit from this page\n");
        printf("Choose any menu :");
        scanf("%d", &loginOption);
        switch (loginOption)
        {

        case STORED_USER_PASSWORD:
        {
            printf("sign in to continue\n");
            stored_user_password(*login_ptr);
            break;
        }
        case SIGNUP_OPTION:
        {
            printf("sign up to contiue in switch case\n");
            admin_Sign_Up_Fill_Details(login_ptr);
            break;
        }
        case EXIT_OPTION:
        {
            printf("Exit from the login page\n");
            exit(1);
        }
        default:
        {
            printf("The above mentioned conditions were not satisfied so in default case \n");
            exit(1);
        }
        }
    } while (1);
}

int stored_word(char subWord2[20])
{
    char ch;
    char temp[30];
    int i = 0, countWord = 0,j=0;
    admin_save = fopen("admin_credentials.csv", "r");
    if (admin_save == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    while (!feof(admin_save))
    {
        ch = getc(admin_save);
        if (ch == 32 || ch == 46 || ch == 63 || ch == 44 || ch == 10)
        {
            temp[i] = '\0';
            if (strcmp(temp, subWord2)==0)
            {
                countWord++;
                return j;
            }
            if(ch == 10)
                j++;
            i = 0;
        }
        else
        {
            temp[i] = ch;
            i++;
        }
    }
    fclose(admin_save);
    return -1;
}
void stored_user_password( struct login_credential login_ptr2)
{
    char *pointer_delimiter;
    time_t time_sec;
    struct tm calender_time;                                                      //declare and assigning
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    printf("Enter the user name \n");
    pointer_delimiter = strtok (login_ptr2.stored_username,",");                      //delimiter to separate , . ? etc
    scanf("%s",login_ptr2.stored_username);
    printf("Enter the password \n");
    scanf("%s",login_ptr2.stored_userpassword);
    while (pointer_delimiter != NULL)
    {
        pointer_delimiter = strtok (NULL, ",");                                     // strtok function is used to extract the chracters
    }
    if(stored_word(login_ptr2.stored_username) == stored_word(login_ptr2.stored_userpassword)  && (stored_word(login_ptr2.stored_username) != -1))
    {
        printf("Sign In successful\n");
        printf("Current Time: %d:%d:%d\n", calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
        printf("Current Date: %d-%d-%d\n", calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        employee_option();
    }
    else
    {
        printf("The user name and password is incorrect \n");
        create_Administration_Access();
    }
}

void admin_Sign_Up_Fill_Details(struct login_credential *login_ptr)      //entering the user name and password
{                                                                       //and storing them in another character array
    time_t time_sec;
    struct tm calender_time;                                                      //declare and assigning
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    printf("Inside admin_Sign_Up_Fill_Details function  \n");
    printf("S I G N U P\n");
    printf("Enter the user name\n");
    scanf("%s",login_ptr->username_signup);

    printf("Enter the  password  \n");
    scanf("%s",login_ptr->userpassword_signup);
    printf("Sign up successful \n");

    printf("Current Time: %d:%d:%d\n", calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
    printf("Current Date: %d-%d-%d\n", calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);


    if((admin_save=fopen("admin_credentials.csv","a"))==NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    else
    {
        strcpy(login_ptr->save_username,login_ptr->username_signup);
        strcpy(login_ptr->save_userpassword,login_ptr->userpassword_signup);

        fprintf(admin_save,"%s,%s,%d:%d:%d, %d-%d-%d\n",login_ptr->save_username,login_ptr->save_userpassword,
         calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec,calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
    }
    fclose(admin_save);
    if((admin_save=fopen("admin_credentials.txt","a"))==NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    else
    {
        strcpy(login_ptr->save_username,login_ptr->username_signup);
        strcpy(login_ptr->save_userpassword,login_ptr->userpassword_signup);

        fprintf(admin_save,"User  %s\n",login_ptr->save_username);
        fprintf(admin_save,"Pass  %s\n",login_ptr->save_userpassword);
        fprintf(admin_save,"Time: %d:%d:%d\n", calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
        fprintf(admin_save,"Date: %d-%d-%d\n\n", calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
    }
    fclose(admin_save);
    admin_Sign_In(login_ptr);
}
void admin_Sign_In(struct login_credential *login_ptr)                 //entering the user name and password and
{                                                                     // comparing it with stored user name and password
    printf("Inside admin_Sign_In function \n");
    printf(" Administration  Login   Verification\n");

    printf("Enter the user name to sign in\n");
    scanf("%s",login_ptr->username_signin);

    printf("Enter the password to sign in \n");
    scanf("%s",login_ptr->userpassword_signin);

    if(strcmp(login_ptr->save_username,login_ptr->username_signin)==0)
    {
        printf("Login\t");
    }else
    {
        admin_Sign_Up_Fill_Details(login_ptr);
    }
    if(strcmp(login_ptr->save_userpassword,login_ptr->userpassword_signin)==0)
    {
        printf("\tsuccessful\n");
        employee_option();
    }
    else
    {
        admin_Sign_Up_Fill_Details(login_ptr);
        exit(1);
    }
}
void employee_option()
{
    int disp_add;
    enum display_add
    {
        ADD_EMPLOYEE_DETAILS=1,
        EXIT_OPT
    };

    printf("1.Enter 1 to add  new employee details\n");
    printf("2.Enter 2 to exit \n");
    scanf("%d",&disp_add);

    do{
        switch (disp_add)
        {
        case ADD_EMPLOYEE_DETAILS:
        {
            printf("Add employee details\n");
            employee_Fill_In_Details();
            break;
        }
        case EXIT_OPT:
        {
            printf("Exit from the function\n");
            exit(1);
            break;
        }
        default:
        {
            printf("The above mentioned conditions were not satisfied so in default case \n");
            exit(1);
        }
        }
    }while(1);
    employee_option();
}

void employee_display()                                            //dispalying all the employee details
{                                                                 // stored in the text files
    char display_data;
    printf("Inside employee_display function\n");
    employee_save=fopen("employee_details_save.txt","r");
    if(employee_save==NULL)
    {
        printf("Error while opening the file  \n");
        exit(1);
    }
    printf("inside the employee display function \n");
    while((display_data = fgetc(employee_save))!=EOF)
    {
        putchar(display_data);
    }
    //task_option();
}
void employee_Fill_In_Details()                                 //Filling the employee details
{
    struct employee_details *employee_ptr;
    int count = 1;
    printf("Inside employee_Fill_In_Details\n");
    printf(" EMPLOYEE DETAILS\n");
    printf("Enter the number of employee details that you want to enter\n");
    scanf("%d",&number_of_employees);
    for(int i=0;i<number_of_employees;i++)
    {
        employee_ptr = (struct employee_details*)malloc(sizeof (struct employee_details));
        printf("\nEmployee No. %i\n",count);

        printf("1.Enter the employee Full Name \n");
        fflush(stdin);
        gets(employee_ptr->employee_name);

        printf("2.Enter the employee id\n");
        scanf("%s",employee_ptr->employee_id);

        printf("3.Enter the employee email Address\n");
        scanf("%s",employee_ptr->employee_email_id);

        printf("4.Enter the employee phone number\n");
        scanf("%s",employee_ptr->employee_phone_number);

        printf("5.Enter the employee Address\n");
        fflush(stdin);
        gets(employee_ptr->employee_address);

        employee_store_data[i]=*employee_ptr;

        count ++;
    }
    employee_choice();
}
void employee_choice()                                           //if the user wants to save the employee details
{                                                               //edit the employee details and exit
    printf("Inside employee_choice function\n");
    int employee_option;
    enum employee_details
    {
        EDIT_EMPLOYEE_DATA=1,
        SAVE_EMPLOYEE_DATA,
        DISPLAY_EMPLOYEE_DETAILS
    };
    do{
        printf("\n1.Enter 1 to edit employee details \n2.Enter 2 to save employee details\n");
        printf("3.Enter 3 to display the previous employee details\n");
        scanf("%d",&employee_option);
        switch (employee_option)
        {
        case EDIT_EMPLOYEE_DATA:
        {
            printf("Edit the employee details \n");
            employee_edit_text_csv();
            break;
        }
        case SAVE_EMPLOYEE_DATA:
        {
            printf("Saving the employee details\n");
            employee_save_details();
            break;
        }
        case DISPLAY_EMPLOYEE_DETAILS:
        {
            printf("Display the previous employee details\n");
            employee_display();
            break;
        }
        default:
        {
            printf("The above mentioned conditions were not satisfied so in default case \n");
            exit(1);
        }
        }
    }while(1);
}
void employee_edit_text_csv()                                   //display the entered employee details in the terminal as
{                                                             // well as in the appending in the text file
    int save_option;
    enum employee_details
    {
        EDIT_EMPLOYEE_DATA_TEXT=1,
        EDIT_EMPLOYEE_DATA_CSV,
        EXIT_EMP_OPT
    };
    do{
        printf("\n1.Enter 1 to edit employee details as text file\n2.Enter to edit the employee details as csv file\n");
        printf("3.Enter 3 to exit from the program\n");
        scanf("%d",&save_option);
        switch (save_option)
        {
        case EDIT_EMPLOYEE_DATA_TEXT:
        {
            printf("Edit the employee details as text file\n");
            employee_edit_details_text();
            break;
        }
        case EDIT_EMPLOYEE_DATA_CSV:
        {
            printf("Edit the employee details as csv file\n");
            edit_employee_csv();
            break;
        }
        default:
        {
            printf("The above mentioned conditions were not satisfied so in default case \n");
            exit(1);
        }
        }
    }while(1);
}

void employee_edit_details_text()                                     //Edit the employee details and save
{                                                               //the data in the text files
    int  edit_option;
    char id[10];
    int  count = 0,i;
    printf("Enter the employee id\n");
    scanf("%s",id);
    for(i = 0;i < number_of_employees;i++)
    {
        int name_cmp = strcmp(employee_store_data[i].employee_id,id);
        if(name_cmp == 0)
            continue;
        else
        {
            count++;
        }
    }
    if(count >= i)
    {
        printf("This employee  id  does not exist \n");
        return;
    }
    struct employee_details ;
    printf("Inside employee_edit_details  function \n");
    printf("1.Enter 1 to edit the employee name\n2.Enter 2 to edit the employee identity number\n");
    printf("3.Enter 3 to edit the employee email id\n4.Enter 4 to edit the employee phone-number\n");
    printf("5.Enter 5 to edit the employee address\n6.Enter 6 to save employee details\n");
    printf("7.Enter 7 to exit from the loop\n");
    scanf("%d",&edit_option);

    enum edit_employee_details
    {
        EMPLOY_NAME = 1,
        EMPLOY_ID,
        EMPLOY_EMAIL,
        EMPLOY_PHONENUMBER,
        EMPLOY_ADDRESS,
        EMPLOY_SAVE_CHANGES
    };

    switch (edit_option)
    {
    case EMPLOY_NAME:
    {
        char *emp_name;
        int  count = 0,i;
        emp_name = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_employees;i++)
        {
            int name_cmp = strcmp(employee_store_data[i].employee_id,id);
            if(name_cmp == 0)
            {
                printf("Edit the employee name \n");
                fflush(stdin);
                gets(emp_name);
                strcpy(employee_store_data[i].employee_name,emp_name);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This employee  name  does not exist \n");
        employee_save_details();
    }
        break;
    case EMPLOY_ID:
    {
        int  count=0,i;
        for(i = 0;i<number_of_employees;i++)
        {
            int id_cmp = (employee_store_data[i].employee_id == id);
            if(id_cmp == 0)
            {
                printf("Edit the employee id \n");
                fflush(stdin);
                scanf("%s",id);
                strcpy(employee_store_data[i].employee_name,id);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This employee  id does not exist \n");
        employee_save_details();
    }
        break;
    case EMPLOY_EMAIL:
    {
        char *emp_email;
        int  count=0,i;
        emp_email = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_employees;i++)
        {
            int email_cmp = strcmp(employee_store_data[i].employee_id,id);
            if(email_cmp == 0)
            {
                printf("Edit the employee email \n");
                fflush(stdin);
                gets(emp_email);
                strcpy(employee_store_data[i].employee_name,emp_email);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This employee email id does not exist \n");
        employee_save_details();
        free(emp_email);
    }
        break;
    case EMPLOY_PHONENUMBER:
    {
        char *emp_ph_no;
        int  count=0,i;
        emp_ph_no = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_employees;i++)
        {
            int ph_no_cmp = strcmp(employee_store_data[i].employee_id,id);
            if(ph_no_cmp == 0)
            {
                printf("Edit the employee ph-number \n");
                fflush(stdin);
                gets(emp_ph_no);
                strcpy(employee_store_data[i].employee_name,emp_ph_no);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This employee phone number does not exist \n");
        employee_save_details();
        free(emp_ph_no);
    }
        break;
    case EMPLOY_ADDRESS:
    {
        char *emp_address;
        int  count = 0,i;
        emp_address = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_employees;i++)
        {
            int address_cmp = strcmp(employee_store_data[i].employee_id,id);
            if(address_cmp == 0)
            {
                printf("Edit the employee address \n");
                fflush(stdin);
                gets(emp_address);
                strcpy(employee_store_data[i].employee_name,emp_address);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This employee address does not exist \n");
        employee_save_details();
        free(emp_address);
    }
        break;
    case EMPLOY_SAVE_CHANGES:
    {
        printf("Save the employee  details without changing any details \n");
        employee_save_details();
        break;
    }
    default:
    {
        printf("The above mentioned conditions were not satisfied so in default case \n");
        exit(1);
    }
    }
    Save_Employee_Text();
}

void edit_employee_csv()
{
    char ch,*ptr,store[100];
    int choose;
    employee_task_fptr = fopen("edit_data.csv", "r");
    while (!feof(employee_task_fptr))
    {
        ch = fgetc(employee_task_fptr);
    }
    fclose(employee_task_fptr);
    do
    {
        printf("\nPress 1 to edit the employee_name\nPress 2 to edit the employee_id\n");
        printf("Press 3  to edit the employee_email\nPress 4 to edit the employee_phone_number\n");
        printf("Press 5  to edit the employee_address\nPress 6 to exit\n");
        printf("Choose any menu :");
        scanf("%d", &choose);
        enum edit_particular
        {
            EMPLOYEE_NAME_EDIT = 1,
            EMPLOYEE_ID_EDIT,
            EMPLOYEE_EMAIL_EDIT,
            EMPLOYEE_PHONE_EDIT,
            EMPLOYEE_ADDRESS_EDIT,
            EXIT
        };
        switch (choose)
        {
        case EMPLOYEE_NAME_EDIT:
            while (fgets(store,100,employee_task_fptr))
            {
                ptr=strtok(store,",");
            }
            replace_word_employee_task_csv();
            break;

        case EMPLOYEE_ID_EDIT:
            while (fgets(store,100,employee_task_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_task_csv();
            break;
        case EMPLOYEE_EMAIL_EDIT:
            while (fgets(store,100,employee_task_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_task_csv();
            break;
        case EMPLOYEE_PHONE_EDIT:
            while (fgets(store,100,employee_task_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_task_csv();
            break;
        case EMPLOYEE_ADDRESS_EDIT:
            while (fgets(store,100,employee_task_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_task_csv();
            break;
        case EXIT:
            printf("exit\n");
            exit(1);
        default:
            printf("Invalid menu try again\n");
            break;
        }
    } while (1);
}
void employee_save_details()                                   //display the entered employee details in the terminal as
{                                                             // well as in the appending in the text file
    int save_option;
    enum employee_details
    {
        SAVE_EMPLOYEE_DATA_TEXT=1,
        SAVE_EMPLOYEE_DATA_CSV,
        EMPLOYEE_OBJECT,
        EXIT_EMP_OPT
    };
    do{
        printf("\n1.Enter 1 to save employee details as text file\n2.Enter to save the employee details as csv file\n");
        printf("3.Enter 3 to employee details as object\n4.Enter 4 to exit from the program\n");
        scanf("%d",&save_option);
        switch (save_option)
        {
        case SAVE_EMPLOYEE_DATA_TEXT:
        {
            printf("Saving the employee details as text file\n");
            Save_Employee_Text();
            break;
        }
        case SAVE_EMPLOYEE_DATA_CSV:
        {
            printf("Saving the employee details as csv file\n");
            Save_Employee_CSV();
            break;
        }
        case EMPLOYEE_OBJECT:
        {
            printf("Saving the employee details as object\n");
            Save_Employee_Object();
            break;
        }
        case EXIT_EMP_OPT:
        {
            printf("Exit function is called\n");
            exit(1);
        }
        default:
        {
            printf("The above mentioned conditions were not satisfied so in default case \n");
            exit(1);
        }
        }
    }while(1);
}
void Save_Employee_Text()
{
    int  count = 1;
    printf("Inside employee_save_details function\n");
    if((employee_save = fopen("employee_details_save.txt","a")) == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    else
    {
        for(int i = 0;i < number_of_employees;i++)
        {
            printf("Emp_Name   \t%s\n",employee_store_data[i].employee_name);
            printf("Emp_Id     \t%s\n",employee_store_data[i].employee_id);
            printf("Emp_Email  \t%s\n",employee_store_data[i].employee_email_id);
            printf("Emp_Ph-no. \t%s\n",employee_store_data[i].employee_phone_number);
            printf("Emp_Address\t%s\n",employee_store_data[i].employee_address);
            count++;
            fprintf(employee_save,"\nEmp_Name  \t%s\n",employee_store_data[i].employee_name);
            fprintf(employee_save,"Emp_Id      \t%s\n",employee_store_data[i].employee_id);
            fprintf(employee_save,"Emp_Email   \t%s\n",employee_store_data[i].employee_email_id);
            fprintf(employee_save,"Emp_Ph-no.  \t%s\n",employee_store_data[i].employee_phone_number);
            fprintf(employee_save,"Emp_Address \t%s\n",employee_store_data[i].employee_address);
        }
        fclose(employee_save);
    }
    task_option();
}
void Save_Employee_CSV()
{
    int  count = 1;
    printf("Inside employee_save_details function\n");
    if((employee_save = fopen("employee_details_save.csv","a")) == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    else
    {
        for(int i = 0;i < number_of_employees;i++)
        {
            printf("%s,%s,%s,%s,%s\n",employee_store_data[i].employee_name,employee_store_data[i].employee_id,employee_store_data[i].employee_email_id,

                   employee_store_data[i].employee_phone_number,employee_store_data[i].employee_address);

            count++;

            fprintf(employee_save,"%s,%s,%s,%s,%s",employee_store_data[i].employee_name,employee_store_data[i].employee_id,employee_store_data[i].employee_email_id,

                    employee_store_data[i].employee_phone_number,employee_store_data[i].employee_address);
        }
        fclose(employee_save);
    }
    task_option();
}
void Save_Employee_Object()
{
    char store[100],*ptr,inp[10];
    printf("Inside the emp_details function\n");
    employee_save=fopen("employee_details_save.csv","r");
    int i = 0;
    if(employee_save==NULL)
    {
        printf("Error while opening the file\n");
        exit(1);
    }
    while (fgets(store,100,employee_save))
    {
       printf("%s",store);

        ptr=strtok(store,",");
        strcpy(employee_store_data[i].employee_name,ptr);
        printf("%s\n",employee_store_data[i].employee_name);

        ptr=strtok(NULL,",");
        strcpy(employee_store_data[i].employee_id,ptr);
        printf("%s\n",employee_store_data[i].employee_id);

        ptr=strtok(NULL,",");
        strcpy(employee_store_data[i].employee_email_id,ptr);
        printf("%s\n",employee_store_data[i].employee_email_id);

        ptr=strtok(NULL,",");
        strcpy(employee_store_data[i].employee_phone_number,ptr);
        printf("%s\n",employee_store_data[i].employee_phone_number);

        ptr=strtok(NULL,",");
        strcpy(employee_store_data[i].employee_address,ptr);
        printf("%s\n",employee_store_data[i].employee_address);
        i++;

    }
    printf("Enter the existing  Employee  Name\n");
    scanf("%s",inp);
    for(int i=0; i<number_of_employees; i++)
    {
        if(!strcmp(employee_store_data[i].employee_name , inp)){
            printf("Employee name    %s\n",employee_store_data[i].employee_name);
            printf("Employee id      %s\n",employee_store_data[i].employee_id);
            printf("Employee email   %s\n",employee_store_data[i].employee_email_id);
            printf("Employee phone   %s\n",employee_store_data[i].employee_phone_number);
            printf("Employee address %s\n",employee_store_data[i].employee_address);
        }
    }
    task_option();
}
void replace_word_employee_task_csv()
{
    char *entered_word, replace_word[20], temp[20], ch;
    int i = 0, countWord = 0, size, k;
    int a,b;
    entered_word = (char*)malloc(sizeof (char));                                    //dynamically allocating memory using malloc function
    employee_task_fptr = fopen("edit_data.csv","r");                                     //file opened in reading mode
    if (employee_task_fptr == NULL)
    {
        printf("file does not exist\n");
        exit(1);
    }                                            //Entering the line number to search
    for(a=1;a<=file_length;a++)
    {
        if(a==line_search)                                                       //comparing the stored line and entered line
        {
            for(b=0;filearray[a-1][b]!='\0';b++)
            {
                printf("%c",filearray[a-1][b]);
            }
        }
    }
    printf("\nEnter the word which you want to replace:  ");
    fflush(stdin);
    gets(entered_word);                                                        //Entering the existing word stored in files
    employee_task_fptr = fopen("edit_data.csv", "r");
    if (employee_task_fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(0);
    }
    while (!feof(employee_task_fptr))
    {
        ch = fgetc(employee_task_fptr);
        if (ch == 32 || ch == 46 || ch == 63 || ch == 44 || ch == 10)            //ASCII values  space==32, .==46, ?==63, ,==44, \n==10
        {
            temp[i] = '\0';
            if (!strcmp(temp, entered_word))
            {
                countWord++;
            }
            i = 0;
        }
        else
        {
            temp[i] = ch;
            i++;
        }
    }
    fclose(employee_task_fptr);
    if (countWord == 0)
    {
        printf("word is not found\n");
        return;
    }
    printf("Enter new word for replace: ");
    fflush(stdin);
    gets(replace_word);                                                           //Entering a new word to replace the word
    employee_task_fptr = fopen("edit_data.csv", "r");
    if (employee_task_fptr == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    while (!feof(employee_task_fptr))
    {
        ch = fgetc(employee_task_fptr);
        if (ch == 32 || ch == 46 || ch == 63 || ch == 44 || ch == 10)                //ASCII values  space==32, .==46, ?==63, ,==44, \n==10
        {
            temp[i] = '\0';
            if (!strcmp(temp, entered_word))                                        // string compare of entered word and temporary word
            {
                size = strlen(entered_word);                                        // String length of entered word
                countIndex=countIndex-size;
                for (int j = 0; replace_word[j] != '\0'; j++)
                {
                    temporary_data[countIndex] = replace_word[j];
                    countIndex++;
                }
                temporary_data[countIndex] = ch;
                countIndex++;
            }
            else
            {
                temporary_data[countIndex] = ch;
                countIndex++;
            }
            i = 0;
        }else
        {
            temp[i] = ch;
            temporary_data[countIndex]=ch;
            countIndex++;
            i++;
        }
    }
    fclose(employee_task_fptr);                                                              //file closed
    temporary_data[countIndex] = '\0';
    employee_task_fptr = fopen("edit_data.csv", "w");                                       // file opened in writing mode
    if (employee_task_fptr == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    for (k = 0; k < countIndex-1; k++)
    {
        fputc(temporary_data[k],employee_task_fptr);                                     // writing single character from the file
    }
    fclose(employee_task_fptr);

    if ((employee_task_fptr = fopen("edit_data.csv", "r")) == NULL)                     //file opened in reading mode
    {
        printf("Error in  opening the file \n");
        exit(0);
    }
    while (!feof(employee_task_fptr))
    {
        ch=fgetc(employee_task_fptr);
    }
    fclose(employee_task_fptr);
    countIndex=0;
}
void task_option()
{
    int disp_add;
    enum display_add
    {
        ADD_TASK_DETAILS=1,
        EXIT_OPT
    };

    printf("1.Enter 1 to add  new employee details\n");
    printf("2.Enter 2 to exit \n");
    scanf("%d",&disp_add);

    do{
        switch (disp_add)
        {
        case ADD_TASK_DETAILS:
        {
            printf("Add task details\n");
            task_fill_in_details();
            break;
        }
        case EXIT_OPT:
        {
            printf("Exit from the function\n");
            exit(1);
            break;
        }
        default:
        {
            printf("The above mentioned conditions were not satisfied so in default case \n");
            exit(1);
        }
        }
    }while(1);
    employee_option();
}
void task_display()                                            //dispalying all the employee details
{                                                                 // stored in the text files
    char display_data;
    printf("Inside task_display function\n");
    task_save=fopen("task_details_save.txt","r");
    if(task_save==NULL)
    {
        printf("Error while opening the file  \n");
        exit(1);
    }
    printf("inside the employee display function \n");
    while((display_data = fgetc(task_save))!=EOF)
    {
        putchar(display_data);
    }
}
void task_fill_in_details()
{
    struct create_task *task_ptr;
    int count_task = 1;
    printf("Inside the task_fill_in details function\n");
    printf("Enter the number of task details that you want to enter\n");
    scanf("%d",&number_of_tasks);
    for(int i=0;i<number_of_tasks;i++)
    {
        task_ptr = (struct create_task*)malloc(sizeof (struct create_task));
        printf("1. Enter the employee task id\n");
        fflush(stdin);
        gets(task_ptr->task_id);


        printf("2. Enter the current status of the employee \n");
        fflush(stdin);
        gets(task_ptr->task_status);

        printf("3. Enter the employee name of the assignee\n");
        fflush(stdin);
        gets(task_ptr->task_assignee_name);

        store_task_data[i]=*task_ptr;

        count_task++;
    }
    task_edit_save_display_details();

}
void task_edit_save_display_details()
{
    printf("Inside employee_choice function\n");
    int task_option;
    enum task_details
    {
        EDIT_TASK_DATA=1,
        SAVE_TASK_DATA,
        DISPLAY_TASK,
        EXIT_TASK_OPTION
    };
    do{
        printf("\n1.Enter 1 to edit task details \n2.Enter 2 to save task details\n");
        printf("3.Enter 3 to display task details\n4.Enter 4 to exit from task details\n");
        scanf("%d",&task_option);
        switch (task_option)
        {
        case EDIT_TASK_DATA:
        {
            printf("Edit the task details \n");
            //task_edit_details();
            break;
        }
        case SAVE_TASK_DATA:
        {
            printf("Saving the task details\n");
            //task_save_details();
            break;
        }
        case DISPLAY_TASK:
        {
            printf("Display the task details\n");
            task_display();
            break;
        }
        case EXIT_TASK_OPTION:
        {
            printf("Exit from the task details page \n");
            exit(1);
            break;
        }
        default:
        {
            printf("The above mentioned conditions were not satisfied so in default case \n");
            exit(1);
        }
        }
    }while(1);
}


