#include "login_details_data.h"                                                                                             //  Header file to structure and the their data members
int stored_word(char sub[]);
void stored_user_password();

void employee_option();

void admin_Sign_Up_Fill_Details();                                                                                       // Function to sign up
void admin_Sign_In(struct login_credential *);                                                                          // Function to sign in
void employee_Fill_In_Details();                                                                                       // Function to fill all the employee details

void employee_choice();

void employee_edit_details();
void employee_edit_details_text();
void edit_employee_csv();


void employee_save_details();

void Save_Employee_Text();                                                                                             // Save the Employee details as text file format
void Save_Employee_CSV();                                                                                             //  Save the Employee details as csv file format
void Save_Employee_Object();                                                                                         //   Save 1 structure employee details as 1 object in the csv file format

int task_display();

void task_option();

void task_fill_in_details();                                                                                         //   Function to fill all the task details
void task_edit_save_display_details();
void task_edit_text_csv();

void task_save_details();

void Save_Task_Text();                                                                                              // Save the Task details as text file format
void Save_Task_CSV();                                                                                              //  Save the Task details as csv file format
void Save_Task_Object();                                                                                          //   Save 1 structure task details as 1 object in the csv file format

void replace_word_employee_csv();                                                                               // Function to replace the stored word to new word  in employee details structure
void replace_word_task_csv();                                                                                  //  Function to replace the stored word to new word  in task details structure

void task_edit_details_text();
void edit_task_csv();

void assign_the_task_employee();                                                                             // Assign one task to one employee  and save the data in one file
int word_string(char string[100],char word[100]);                                                           // Function to find the word in the present in the file

void store_assign_task();
void replace_status();                                                                                       // Function to replace the status after it is assigned
void assign_multiple_task_employee();                                                                       // Assign multiple task to one employee and save the data in one file
void store_assign_multiple_task();

void completereport();
void signout_project();
int number_of_employees,number_of_tasks,file_length,line_search=0,countIndex=0;

FILE *admin_save,*employee_fptr,*employee_save,*task_save,*task_fptr,*employee_task_fptr,*assign_task_emp;  // FILE pointer

char temporary_data[FILE_SIZE],filearray[20][256];
char word_of_employee[200],word_of_task[100];
char file_array_e[40][256],file_array_t[40][256],file_array_ta[40][256];
char store_emp[20],store_task[20],stored_e_data[20];

struct employee_details employee_store_data[20];                                                            // Array of structure of 20 employees details
struct create_task store_task_data[20];                                                                    //  Array of structure of 20 task details
int main()
{
    stored_user_password();
    return 0;
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
void stored_user_password()
{
    struct login_credential  *login_ptr;
    login_ptr=(struct login_credential*)malloc(sizeof (struct login_credential));
    char *pointer_delimiter;
    char stored_username[10],stored_pwd[10];
    time_t time_sec;
    struct tm calender_time;                                                                                   //declare and assigning
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    printf("Enter the user name \n");
    pointer_delimiter = strtok (stored_username,",");                                                        //delimiter to separate , . ? etc
    scanf("%s",stored_username);
    printf("Enter the password \n");
    scanf("%s",stored_pwd);
    while (pointer_delimiter != NULL)
    {
        pointer_delimiter = strtok (NULL,",");                                                             // strtok function is used to extract the chracters
    }
    if(stored_word(stored_pwd) == stored_word(stored_pwd)  && (stored_word(stored_pwd) != -1))
    {
        printf("Sign In successful\n");
        printf("Current Time: %d:%d:%d\n", calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
        printf("Current Date: %d-%d-%d\n", calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        employee_option();
    }
    else
    {
        printf("The user name and password is incorrect \n");
        admin_Sign_Up_Fill_Details();
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
}
void admin_Sign_Up_Fill_Details()                                                                                  //entering the user name and password
{                                                                                                                 //and storing them in another character array
    struct login_credential *login_ptr;
    login_ptr=(struct login_credential*)malloc(sizeof (struct login_credential));
    time_t time_sec;
    struct tm calender_time;                                                                                     //declare and assigning
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    printf("Inside admin_Sign_Up_Fill_Details function  \n");
    printf("S I G N U P\n");
    printf("Enter the user name\n");
    scanf("%s",login_ptr->username);

    printf("Enter the  password  \n");
    scanf("%s",login_ptr->password);
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
        fprintf(admin_save,"%s,%s,%d:%d:%d, %d-%d-%d\n",login_ptr->username,login_ptr->password,
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
        fprintf(admin_save,"User  %s\n",login_ptr->username);
        fprintf(admin_save,"Pass  %s\n",login_ptr->password);
        fprintf(admin_save,"Time: %d:%d:%d\n", calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
        fprintf(admin_save,"Date: %d-%d-%d\n\n", calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
    }
    fclose(admin_save);
    admin_Sign_In(login_ptr);
}
void admin_Sign_In(struct login_credential *login_ptr)                                                           //entering the user name and password and
{                                                                                                               // comparing it with stored user name and password
    printf("Inside admin_Sign_In function \n");
    printf(" Administration  Login   Verification\n");

    printf("Enter the user name to sign in\n");
    scanf("%s",login_ptr->username_signin);

    printf("Enter the password to sign in \n");
    scanf("%s",login_ptr->userpassword_signin);

    if(strcmp(login_ptr->username,login_ptr->username_signin)==0)
    {
        printf("Login\t");
    }else
    {
        admin_Sign_Up_Fill_Details();
    }
    if(strcmp(login_ptr->password,login_ptr->userpassword_signin)==0)
    {
        printf("\tsuccessful\n");
        employee_option();
    }
    else
    {
        admin_Sign_Up_Fill_Details();
        exit(1);
    }
}
void employee_Fill_In_Details()                                                                               //Filling the employee details
{
    int count = 1;
    printf("Inside employee_Fill_In_Details\n");
    printf(" EMPLOYEE DETAILS\n");
    printf("Enter the number of employee details that you want to enter\n");
    scanf("%d",&number_of_employees);
    for(int i=0;i<number_of_employees;i++)
    {
        printf("\nEmployee No. %i\n",count);

        printf("1.Enter the employee Full Name \n");
        fflush(stdin);
        gets(employee_store_data[i].employee_name);

        printf("2.Enter the employee id\n");
        scanf("%s",employee_store_data[i].employee_id);

        printf("3.Enter the employee email Address\n");
        scanf("%s",employee_store_data[i].employee_email_id);

        printf("4.Enter the employee phone number\n");
        scanf("%s",employee_store_data[i].employee_phone_number);

        printf("5.Enter the employee Address\n");
        fflush(stdin);
        gets(employee_store_data[i].employee_address);

        count ++;
    }
    employee_choice();
}
int employee_display()
{
    printf("Inside the display function function \n");
    employee_save = fopen("employee_details_save.csv","r");
    int i =0,j=0;
    while (!feof(employee_save))
    {
        char storeChar = fgetc(employee_save);
        if(storeChar == 10)
        {
            j=0;
            i++;
            printf("\n");
        }
        else{
            file_array_e[i][j] = storeChar;
            printf("%c",file_array_e[i][j]);
            j++;
        }
    }
    fclose(employee_save);
    return i;
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
            employee_edit_details();
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
void employee_edit_details()
{
    int employee_option;
    enum edit
    {
        EDIT_EMPLOYEE_TEXT=1,
        EDIT_EMPLOYEE_CSV
    };
    do{
        printf("\n1.Enter 1 to edit employee details as text \n2.Enter 2 to save employee details as csv\n");
        scanf("%d",&employee_option);
        switch (employee_option)
        {
        case EDIT_EMPLOYEE_TEXT:
        {
            printf("Edit the employee details as text format \n");
            employee_edit_details_text();
            break;
        }
        case EDIT_EMPLOYEE_CSV:
        {
            printf("Saving the employee details as csv format\n");
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
void employee_edit_details_text()                                                                           //Edit the employee details and save
{                                                                                                          //the data in the text files
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
    printf("Inside employee_edit_details  as text function \n");
    printf("1.Enter 1 to edit the employee name\n2.Enter 2 to edit the employee identity number\n");
    printf("3.Enter 3 to edit the employee email id\n4.Enter 4 to edit the employee phone-number\n");
    printf("5.Enter 5 to edit the employee address\n6.Enter 6 to save employee details as text\n");
    printf("7.Enter 7  to exit from the loop\n");
    scanf("%d",&edit_option);

    enum edit_employee_details
    {
        EMPLOY_NAME = 1,
        EMPLOY_ID,
        EMPLOY_EMAIL,
        EMPLOY_PHONENUMBER,
        EMPLOY_ADDRESS,
        EMPLOY_SAVE_CHANGES_TEXT,
        EMPLOYEE_EXIT
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
        free(emp_name);
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
                strcpy(employee_store_data[i].employee_id,id);
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
        int  count = 0,i;
        emp_email = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_employees;i++)
        {
            int email_cmp = strcmp(employee_store_data[i].employee_id,id);
            if(email_cmp == 0)
            {
                printf("Edit the employee email \n");
                fflush(stdin);
                gets(emp_email);
                strcpy(employee_store_data[i].employee_email_id,emp_email);
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
        int  count = 0,i;
        emp_ph_no = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_employees;i++)
        {
            int ph_no_cmp = strcmp(employee_store_data[i].employee_phone_number,id);
            if(ph_no_cmp == 0)
            {
                printf("Edit the employee phone number \n");
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
                strcpy(employee_store_data[i].employee_address,emp_address);
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
    case EMPLOY_SAVE_CHANGES_TEXT:
    {
        printf("Save the employee  details without changing any details as text file\n");
        Save_Employee_Text();
        break;
    }
    case EMPLOYEE_EXIT:
    {
        printf("Exit function is called\n");
        exit(1);
        break;
    }
    default:
    {
        printf("The above mentioned conditions were not satisfied so in default case \n");
        exit(1);
    }
    }
}
void edit_employee_csv()
{
    printf("Inside edit employee csv\n");
    char ch,*ptr,store[100];
    int choose;
    employee_fptr = fopen("employee_details_save.csv", "r");
    while (!feof(employee_fptr))
    {
        ch = fgetc(employee_fptr);
    }
    do
    {
        printf("\nPress 1 to edit the employee_name\nPress 2 to edit the employee_id\n");
        printf("Press 3 to edit the employee_email\nPress 4 to edit the employee_phone_number\n");
        printf("Press 5 to edit the employee_address\nPress 6 to save employee details as csv format\nPress 7 to exit");
        printf("Choose any menu :");
        scanf("%d", &choose);
        enum edit_particular
        {
            EMPLOYEE_NAME_EDIT = 1,
            EMPLOYEE_ID_EDIT,
            EMPLOYEE_EMAIL_EDIT,
            EMPLOYEE_PHONE_EDIT,
            EMPLOYEE_ADDRESS_EDIT,
            EMPLOYEE_SAVE_CSV,
            EXIT
        };
        switch (choose)
        {
        case EMPLOYEE_NAME_EDIT:
            while (fgets(store,100,employee_fptr))
            {
                ptr=strtok(store,",");
            }
            replace_word_employee_csv();
            break;

        case EMPLOYEE_ID_EDIT:
            while (fgets(store,100,employee_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_csv();
            break;
        case EMPLOYEE_EMAIL_EDIT:
            while (fgets(store,100,employee_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_csv();
            break;
        case EMPLOYEE_PHONE_EDIT:
            while (fgets(store,100,employee_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_csv();
            break;
        case EMPLOYEE_ADDRESS_EDIT:
            while (fgets(store,100,employee_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
            }
            replace_word_employee_csv();
            break;
        case EMPLOYEE_SAVE_CSV:
            printf("Save the employee details in the csv format\n");
            Save_Employee_CSV();
        case EXIT:
            printf("exit\n");
            exit(1);
        default:
            printf("Invalid menu try again\n");
            break;
        }
    } while (1);
    fclose(employee_fptr);
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
    printf("Inside employee_save_details text function\n");
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
    printf("Inside employee_save_details csv function\n");
    if((employee_save = fopen("employee_details_save.csv","a")) == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    else
    {
        for(int i = 0;i < number_of_employees;i++)
        {
            printf("\n%s,%s,%s,%s,%s\n",employee_store_data[i].employee_name,employee_store_data[i].employee_id,employee_store_data[i].employee_email_id,

                   employee_store_data[i].employee_phone_number,employee_store_data[i].employee_address);

            count++;

            fprintf(employee_save,"\n%s,%s,%s,%s,%s",employee_store_data[i].employee_name,employee_store_data[i].employee_id,employee_store_data[i].employee_email_id,

                    employee_store_data[i].employee_phone_number,employee_store_data[i].employee_address);
        }
        fclose(employee_save);
    }
    task_option();
}
void Save_Employee_Object()
{
    printf("Inside the emp_details as object function\n");
    char store[100],*ptr,inp[10];
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
int task_display()                                            //dispalying all the employee details
{                                                                 // stored in the text files
    printf("Inside the task display function\n");
    task_save = fopen("task_details_save.csv","r");
    int i = 0,j = 0;
    while (!feof(task_save))
    {
        char storeChar = fgetc(task_save);
        if(storeChar == 10){
            j=0;
            i++;
            printf("\n");
        }
        else{
            file_array_t[i][j] = storeChar;
            printf("%c",file_array_t[i][j]);
            j++;
        }
    }
    printf("\n");
    fclose(task_save);
    return i;
}
void task_option()
{
    printf("Inside the task option function\n");
    int disp_add;
    enum display_add
    {
        ADD_TASK_DETAILS=1,
        EXIT_OPT
    };

    printf("1.Enter 1 to add  new task details\n");
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
}
void task_fill_in_details()
{
    printf("Inside the task_fill_in details function\n");
    struct create_task *task_ptr;
    int count_task = 1;
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
            task_edit_text_csv();
            break;
        }
        case SAVE_TASK_DATA:
        {
            printf("Saving the task details\n");
            task_save_details();
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
void task_edit_text_csv()                                   //display the entered employee details in the terminal as
{                                                             // well as in the appending in the text file
    int save_option;
    enum task_details
    {
        EDIT_TASK_DATA_TEXT=1,
        EDIT_TASK_DATA_CSV,
        EXIT_TASK_OPT
    };
    do{
        printf("\n1.Enter 1 to edit task details as text file\n2.Enter to edit the task details as csv file\n");
        printf("3.Enter 3 to exit from the program\n");
        scanf("%d",&save_option);
        switch (save_option)
        {
        case EDIT_TASK_DATA_TEXT:
        {
            printf("Edit the task details as text file\n");
            task_edit_details_text()  ;
            break;
        }
        case EDIT_TASK_DATA_CSV:
        {
            printf("Edit the task details as csv file\n");
            edit_task_csv();
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
void task_save_details()                                       //display the entered employee details in the terminal as
{                                                             // well as in the appending in the text file
    int save_option;
    enum employee_details
    {
        SAVE_TASK_DATA_TEXT=1,
        SAVE_TASK_DATA_CSV,
        TASK_OBJECT,
        EXIT_TASK_OPT
    };
    do{
        printf("\n1.Enter 1 to save task details as text file\n2.Enter to save the task details as csv file\n");
        printf("3.Enter 3 to task details as object\n4.Enter 4 to exit from the program\n");
        scanf("%d",&save_option);
        switch (save_option)
        {
        case SAVE_TASK_DATA_TEXT:
        {
            printf("Saving the task details as text file\n");
            Save_Task_Text();
            break;
        }
        case SAVE_TASK_DATA_CSV:
        {
            printf("Saving the task details as csv file\n");
            Save_Task_CSV();
            break;
        }
        case TASK_OBJECT:
        {
            printf("Saving the task details as object\n");
            Save_Task_Object();
            break;
        }
        case EXIT_TASK_OPT:
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
void Save_Task_Text()
{
    printf("Inside the task save details function\n");
    int count = 1;
    time_t time_sec;
    struct tm calender_time;
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    if((task_save = fopen("task_details_save.txt","a")) == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    else
    {
        for(int i = 0;i < number_of_tasks;i++)
        {
            printf("Task id           \t%s\n",store_task_data[i].task_id);
            printf("Task status       \t%s\n",store_task_data[i].task_status);
            printf("Task assignee_name\t%s\n",store_task_data[i].task_assignee_name);
            printf("Time: %d:%d:%d\n", calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
            printf("Date: %d-%d-%d\n", calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
            count++;
            fprintf(task_save,"\nTask id          \t%s\n",store_task_data[i].task_id);
            fprintf(task_save,"Task status        \t%s\n",store_task_data[i].task_status);
            fprintf(task_save,"Task assignee_name \t%s\n",store_task_data[i].task_assignee_name);
            fprintf(task_save,"Time:              \t%d:%d:%d\n",calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
            fprintf(task_save,"Date:              \t%d-%d-%d\n\n",calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        }
        fclose(task_save);
    }
    assign_the_task_employee();

}
void Save_Task_CSV()
{
    printf("Inside the task save details function\n");
    int count = 1;
    time_t time_sec;
    struct tm calender_time;
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    if((task_save = fopen("task_details_save.csv","a")) == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    else
    {
        for(int i = 0;i < number_of_tasks;i++)
        {
            printf("\n%s,%s,%s,",store_task_data[i].task_id,store_task_data[i].task_status,store_task_data[i].task_assignee_name);
            printf("Time: %d:%d:%d,", calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec);
            printf("Date: %d-%d-%d\n", calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
            count++;
            fprintf(task_save,"%s,%s,%s,Time:%d:%d:%d,Date:%d-%d-%d\n",store_task_data[i].task_id,store_task_data[i].task_status,store_task_data[i].task_assignee_name,
                    calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec,calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        }
        fclose(task_save);
    }
    assign_the_task_employee();
}
void Save_Task_Object()
{
    printf("Inside the task details as object function\n");
    char store[100],*ptr,user_input[10];
    task_save=fopen("task_details_save.csv","r");
    int i = 0;
    if(task_save==NULL)
    {
        printf("Error while opening the file\n");
        exit(1);
    }
    while (fgets(store,100,task_save))
    {
        printf("%s",store);

        ptr=strtok(store,",");
        strcpy(store_task_data[i].task_id,ptr);
        printf("%s\n",store_task_data[i].task_id);

        ptr=strtok(NULL,",");
        strcpy(store_task_data[i].task_assignee_name,ptr);
        printf("%s\n",store_task_data[i].task_assignee_name);

        ptr=strtok(NULL,",");
        strcpy(store_task_data[i].task_current_time_date,ptr);
        printf("%s\n",store_task_data[i].task_current_time_date);


        ptr=strtok(NULL,",");
        strcpy(store_task_data[i].task_status,ptr);
        printf("%s\n",store_task_data[i].task_status);
        i++;

    }
    printf("Enter Task Id\n");
    scanf("%s",user_input);
    for(int i=0; i<number_of_tasks; i++)
    {
        if(!strcmp(employee_store_data[i].task_obj[i].task_id , user_input)){
            printf("Task Id            %s\n",store_task_data[i].task_id);
            printf("Task assignee name %s\n",store_task_data[i].task_assignee_name);
            printf("Task status        %s\n",store_task_data[i].task_status);

        }
    }
    assign_the_task_employee();
}
void replace_word_task_csv()
{
    printf("Inside  replace word task csv \n");
    char *entered_word, replace_word[20], temp[20], ch;
    int i = 0, countWord = 0, size, k;
    int a,b;
    entered_word = (char*)malloc(sizeof (char));                                    //dynamically allocating memory using malloc function
    task_fptr = fopen("task_details_save.csv","r");                                     //file opened in reading mode
    if (task_fptr == NULL)
    {
        printf("file does not exist\n");
        exit(1);
    }
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
    printf("\nEnter the word which you want to replace in csv:  ");
    fflush(stdin);
    gets(entered_word);                                                        //Entering the existing word stored in files
    task_fptr = fopen("task_details_save.csv", "r");
    if (task_fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(0);
    }
    while (!feof(task_fptr))
    {
        ch = fgetc(task_fptr);
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
    if (countWord == 0)
    {
        printf("word is not found\n");
        return;
    }
    printf("Enter new word for replace in csv: ");
    fflush(stdin);
    gets(replace_word);                                                           //Entering a new word to replace the word
    task_fptr = fopen("task_details_save.csv", "r");
    if (task_fptr == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    while (!feof(task_fptr))
    {
        ch = fgetc(task_fptr);
        if (ch == 32 || ch == 46 || ch == 63 || ch == 44 || ch == 10)                //ASCII values  space==32, .==46, ?==63, ,==44, \n==10
        {
            temp[i] = '\0';
            if (!strcmp(temp, entered_word))                                        // string compare of entered word and temporary word
            {
                size = strlen(entered_word);                                        // String length of entered word
                countIndex=countIndex-size;
                for (int j=0; replace_word[j]!='\0'; j++)
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
    fclose(task_fptr);                                                              //file closed
    temporary_data[countIndex] = '\0';
    task_fptr = fopen("task_details_save.csv", "w");                                       // file opened in writing mode
    if (task_fptr == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    for (k = 0; k < countIndex-1; k++)
    {
        fputc(temporary_data[k],task_fptr);                                     // writing single character from the file
    }
    fclose(task_fptr);

    if ((task_fptr = fopen("task_details_save.csv", "r")) == NULL)                            //file opened in reading mode
    {
        printf("Error in  opening the file \n");
        exit(0);
    }
    while (!feof(task_fptr))
    {
        ch=fgetc(task_fptr);
    }
    fclose(task_fptr);
    countIndex=0;
}
void replace_word_employee_csv()
{
    printf("Inside replace word employee csv\n");
    file_length = employee_display();
    char *entered_word, replace_word[20], temp[20], ch;
    int i = 0, countWord = 0, size, k;
    entered_word = (char*)malloc(sizeof (char));                                                 //dynamically allocating memory using malloc function
    employee_fptr = fopen("employee_details_save.csv","r");                                     //file opened in reading mode
    if (employee_fptr == NULL)
    {
        printf("file does not exist\n");
        exit(1);
    }
    printf("\nEnter the word which you want to replace in employee csv:  ");
    fflush(stdin);
    gets(entered_word);                                                                        //Entering the existing word stored in files
    employee_fptr = fopen("employee_details_save.csv", "r");
    if (employee_fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(0);
    }
    while (!feof(employee_fptr))
    {
        ch = fgetc(employee_fptr);
        if (ch == 32 || ch == 46 || ch == 63 || ch == 44 || ch == 10)                                //ASCII values  space==32, .==46, ?==63, ,==44, \n==10
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
    fclose(employee_fptr);
    if (countWord == 0)
    {
        printf("word is not found\n");
        return;
    }
    printf("Enter new word for replace in employee csv: ");
    fflush(stdin);
    gets(replace_word);                                                                                        //Entering a new word to replace the word
    employee_fptr = fopen("employee_details_save.csv", "r");
    if (employee_fptr == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    while (!feof(employee_fptr))
    {
        ch = fgetc(employee_fptr);
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
    fclose(employee_fptr);                                                                          //file closed
    temporary_data[countIndex] = '\0';
    employee_fptr = fopen("employee_details_save.csv", "w");                                       // file opened in writing mode
    if (employee_fptr == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    for (k = 0; k < countIndex-1; k++)
    {
        fprintf(employee_fptr,"%c",temporary_data[k]);
    }
    fclose(employee_fptr);

    if ((employee_fptr = fopen("employee_details_save.csv", "r")) == NULL)                     //file opened in reading mode
    {
        printf("Error in  opening the file \n");
        exit(0);
    }
    while (!feof(employee_fptr))
    {
        ch=fgetc(employee_fptr);
    }
    fclose(employee_fptr);
    countIndex=0;
}
void task_edit_details_text()
{
    printf("Inside task edit details text\n");
    int  edit_option;
    char id[10];
    int  count = 0,i;
    printf("Enter the task id\n");
    scanf("%s",id);
    for(i = 0;i < number_of_tasks;i++)
    {
        int name_cmp = strcmp(store_task_data[i].task_id,id);
        if(name_cmp == 0)
            continue;
        else
        {
            count++;
        }
    }
    if(count >= i)
    {
        printf("This task  id  does not exist \n");
        return;
    }
    printf("1.Enter 1 to edit the task id\n2.Enter 2 to edit the task status\n");
    printf("3.Enter 3 to edit task assignee name \n");

    scanf("%d",&edit_option);

    enum edit_task_details
    {
        TASK_ID = 1,
        TASK_ASSIGNEE_NAME,
        TASK_STATUS,
    };

    switch (edit_option)
    {
    case TASK_ID:
    {
        char *task_identity;
        int  count = 0,i;
        task_identity = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_tasks;i++)
        {
            int task_id_cmp = strcmp(store_task_data[i].task_id,id);
            if(task_id_cmp == 0)
            {
                printf("Edit the task id \n");
                fflush(stdin);
                gets(task_identity);
                strcpy(store_task_data[i].task_id,task_identity);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This Task id  does not exist \n");
        Save_Task_Text();
    }
        break;
    case TASK_ASSIGNEE_NAME:
    {
        int  count=0,i;
        for(i = 0;i<number_of_tasks;i++)
        {
            int id_cmp = (store_task_data[i].task_assignee_name == id);
            if(id_cmp == 0)
            {
                printf("Edit the task assignee name \n");
                fflush(stdin);
                scanf("%s",id);
                strcpy(store_task_data[i].task_assignee_name,id);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This employee  id does not exist \n");
        Save_Task_Text();
    }
        break;
    case TASK_STATUS:
    {
        char *task_status;
        int  count = 0,i;
        task_status = (char*)malloc(sizeof (char));
        for(i = 0;i < number_of_tasks;i++)
        {
            int email_cmp = strcmp(employee_store_data[i].employee_id,id);
            if(email_cmp == 0)
            {
                printf("Edit the task status \n");
                fflush(stdin);
                gets(task_status);
                strcpy(store_task_data[i].task_status,task_status);
            }
            else
            {
                count++;
            }
        }
        if(count >= i)
            printf("This status does not exist \n");
        Save_Task_Text();
        free(task_status);
    }
        break;

    default:
    {
        printf("The above mentioned conditions were not satisfied so in default case \n");
        exit(1);
    }
    }
}
void edit_task_csv()
{
    printf("Inside the edit task csv\n");
    char ch,*ptr,store[100];
    int choose;
    task_fptr = fopen("task_details_save.csv", "r");
    while (!feof(task_fptr))
    {
        ch = fgetc(task_fptr);
    }
    fclose(task_fptr);
    do
    {
        printf("\nPress 1 to edit the task_id\nPress 2 to edit the task assignee name\n");
        printf("Press 3  to edit the task_status\n");
        printf("Press 4 to the task details in the csv format\nPress 5 to exit\n");
        printf("Choose any menu :");
        scanf("%d", &choose);
        enum edit_particular
        {
            TASK_ID_EDIT = 1,
            TASK_ASSIGNEENAME_EDIT,
            TASK_STATUS_EDIT,
            TASK_SAVE_CSV,
            EXIT
        };
        switch (choose)
        {
        case TASK_ID_EDIT:
            while (fgets(store,100,task_fptr))
            {
                ptr=strtok(store,",");
            }
            replace_word_task_csv();
            break;

        case TASK_ASSIGNEENAME_EDIT:
            while (fgets(store,100,task_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
            }
            replace_word_task_csv();
            break;
        case TASK_STATUS_EDIT:
            while (fgets(store,100,task_fptr))
            {
                ptr=strtok(store,",");
                ptr=strtok(NULL,",");
                ptr=strtok(NULL,",");
            }
            replace_word_task_csv();
            break;
        case TASK_SAVE_CSV:
            printf("Save the task details in the csv format\n");
            Save_Task_CSV();
        case EXIT:
            printf("exit\n");
            exit(1);
        default:
            printf("Invalid menu try again\n");
            break;
        }
    } while (1);
}
void assign_the_task_employee()
{
    printf("\nInside the assign the task to employee\n");
    int a;
    file_length = employee_display();
    printf("\nEnter the employee name to display all the details \n");
    fflush(stdin);
    gets(word_of_employee);
    printf("After entering the employee name\n");
    for(a=0;a<file_length;a++)
    {
        if(word_string(file_array_e[a],word_of_employee))
        {
            printf("%s\n",file_array_e[a]);
            fflush(stdin);
            strcpy(stored_e_data,file_array_e[a]);
            break;
        }
        else
        {
            continue;
            printf("%s word is not present in the string\n",word_of_employee);
        }
    }
    file_length = task_display();
    printf("\nEnter the task id to display all the details \n");
    fflush(stdin);
    gets(word_of_task);
    for(a=0;a<file_length;a++)
    {
        if(word_string(file_array_t[a],word_of_task))
        {
            printf("%s word is  present in the string\n",word_of_task);
            strcpy(store_task,word_of_task);
            store_assign_task();
            break;
        }
        else
        {
            continue;
            printf("%s word is not present in the string\n",word_of_task);
        }
    }
    assign_task_emp=fopen("assign_data.csv","a");
    if(assign_task_emp == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }
    else
    {
        printf("");
    }
    fclose(assign_task_emp);
    assign_multiple_task_employee();
}
int word_string(char string[200],char word[200])
{
    int i=0, j, n, m;
    n = strlen(string);
    m = strlen(word);
    if (m > n)
    {
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
void store_assign_task()
{
    printf("\nInside the store assign task\n");
    int i;
    time_t time_sec;
    struct tm calender_time;                                                      //declare and assigning
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    employee_task_fptr=fopen("assign_data.csv","a");
    if(employee_task_fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }
    for(i=0;i<20;i++)
    {
        strcpy(employee_store_data[i].task_obj[i].task_id,store_task);

        strcat(employee_store_data[i].task_obj[i].task_id,",");
        strcat(employee_store_data[i].task_obj[i].task_id ,stored_e_data);


        printf("\n%s,Time %d:%d:%d,Date %d-%d-%d\n",
               employee_store_data[i].task_obj[i].task_id ,calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec,
               calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        printf("\nBefore the replace status function\n");

        fprintf(employee_task_fptr,"\n%s,Time %d:%d:%d,Date %d-%d-%d\n",
                employee_store_data[i].task_obj[i].task_id ,calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec,
                calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        replace_status();
        break;
    }

    fclose(employee_task_fptr);
}
void replace_status()
{
    printf("\nInside the replace status function\n");
    char word[50],*ptr;
    char linedata[100]="";
    char word_replace[10];
    int flag = 1;
    int a;
    file_length = task_display();
    assign_task_emp = fopen("task_details_save.csv", "r+");
    if (assign_task_emp == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    printf("Enter the task id to change the status  \n");
    fflush(stdin);
    gets(word);
    printf("word       %s\n",word);
    for(a=0;a<file_length;a++)
    {
        if(word_string(file_array_t[a],word))
        {
            printf("%s",file_array_t[a]);
            printf("%s word is  present in the string\n",word);

            ptr=strtok(file_array_t[a],",");
            strcat(linedata,ptr);
            printf("Enter the word to be replaced \n");
            scanf("%s",word_replace);
            strcat(linedata,",");
            strcat(linedata,word_replace);
            strcat(linedata,",");
            ptr=strtok(NULL,",");
            ptr=strtok(NULL,",");
            strcat(linedata,ptr);
            strcat(linedata,",");
            ptr=strtok(NULL,",");
            strcat(linedata,ptr);
            strcat(linedata,",");
            ptr=strtok(NULL,",");
            strcat(linedata,ptr);
            strcpy(file_array_t[a],linedata);
            flag = 0;
            break;
        }
    }
    for(a=0;a<file_length;a++)
    {
        printf("%s\n",file_array_t[a]);
        fprintf(assign_task_emp,"%s\n",file_array_t[a]);
    }
    if(flag)
        printf("%s word is not present in the string\n",word);
}
void assign_multiple_task_employee()
{
    int a,b;
    printf("\nInside the assign  multiple task employee\n");
    file_length = employee_display();
    printf("\nEnter the employee name to display all the details \n");
    fflush(stdin);
    gets(word_of_employee);
    for(a=0;a<file_length;a++)
    {
        if(word_string(file_array_e[a],word_of_employee))
        {
            printf("%s",file_array_e[a]);
            strcpy(stored_e_data,file_array_e[a]);
            printf("%s word is  present in the string\n",word_of_employee);
            strcpy(store_emp,word_of_employee);
            break;
        }
        else
        {
            continue;
            printf("%s word is not present in the string\n",word_of_employee);
        }
    }
    file_length = task_display();
    assign_task_emp=fopen("assign_data.csv","a");
    if(assign_task_emp== NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }

    printf("Enter the number of tasks to be assigned\n");
    scanf("%d",&number_of_tasks);

    for(a=0;a<number_of_tasks;a++)
    {
        printf("\nEnter the task id to display all the details \n");
        fflush(stdin);
        gets(word_of_task);

        for(b=0;b<file_length;b++)
        {
            if(word_string(file_array_t[b],word_of_task))
            {
                printf("%s\n",file_array_t[b]);
                printf("%s word is  present in the string\n",word_of_task);
                strcat(word_of_task,",");
                printf("%s",word_of_task);
                strcat(word_of_task,stored_e_data);


                strcpy(store_task,word_of_task);
                strcat(store_task,",");
                fprintf(assign_task_emp,"%s",word_of_task);
                store_assign_multiple_task();
            }
            else
            {
                continue;
                printf("%s word is not present in the string\n",word_of_task);
            }
        }
    }
    fclose(assign_task_emp);
}
void store_assign_multiple_task()
{
    printf("Inside the store assign multiple task\n");
    int i;
    time_t time_sec;
    struct tm calender_time;                                                      //declare and assigning
    time_sec = time(NULL);
    calender_time = *localtime(&time_sec);
    employee_task_fptr=fopen("assign_data.csv","a");
    if(employee_task_fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }

    for(i=0;i<number_of_tasks;i++)
    {
        printf("Inside the for loop\n");
        strcpy(employee_store_data[i].task_obj[i].task_id,store_task);
        printf("%s,Time %d:%d:%d,Date %d-%d-%d\n",
               employee_store_data[i].task_obj[i].task_id ,calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec,
               calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        fprintf(employee_task_fptr,"%s,Time %d:%d:%d,Date %d-%d-%d\n\n",employee_store_data[i].task_obj[i].task_id,
                calender_time.tm_hour, calender_time.tm_min, calender_time.tm_sec,
                calender_time.tm_mday, calender_time.tm_mon+1, calender_time.tm_year+1900);
        replace_status();
        break;
    }
    fclose(employee_task_fptr);
    signout_project();
}
void completereport()
{
    printf("Stored user name and password\n\n");
    admin_save = fopen("admin_credentials.csv", "r");
    if (admin_save == NULL)
    {
        printf("File is not open\n");
        exit(0);
    }
    char store1[100];
    while (fgets(store1,100,admin_save))
    {
        printf("%s",store1);
    }
    printf("\nStored Employee details in the the csv file format \n\n");
    if((employee_save = fopen("employee_details_save.csv","r")) == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    while (fgets(store1,100,employee_save))
    {
        printf("%s",store1);
    }
    printf("\nStored task fill in details in csv file  format\n\n");
    if((task_save = fopen("task_details_save.csv","r")) == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }
    while (fgets(store1,100,task_save))
    {
        printf("%s",store1);
    }
    employee_task_fptr=fopen("assign_data.csv","r");
    if(employee_task_fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }
    printf("\nStored list of assigned task \n\n");
    while (fgets(store1,100,employee_task_fptr))
    {
        printf("%s",store1);
    }
    fclose(admin_save);
    fclose(employee_save);
    fclose(task_save);
    fclose(employee_task_fptr);
}
void signout_project()
{
    struct login_credential *login_ptr;
    login_ptr=(struct login_credential*)malloc(sizeof (struct login_credential));
    int choose_opt;
    printf("Inside the sign out project function\n");
    do
    {
        printf("\nPress 1 to display the complete report\nPress 2 sign in function\n");
        printf("Press 3  to exit\n");
        printf("Choose any menu :");
        scanf("%d", &choose_opt);
        enum sign_out
        {
            DISPLAY_REPORT=1,
            SIGN_IN,
            EXIT
        };
        switch (choose_opt)
        {
        case DISPLAY_REPORT:
        {
            printf("Display the complete report of the project\n");
            completereport();
            break;
        }
        case SIGN_IN:
        {
            printf("Sign in function is called\n");
            stored_user_password();
            break;
        }
        case EXIT:
        {
            printf("Exit function is called\n");
            exit(1);
        }
        }
    }while(1);
}

