#ifndef LOGIN_DETAILS_DATA_H
#define LOGIN_DETAILS_DATA_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>                                                            // Preprocessor Directive to display the current date and time

#define FILE_SIZE 1024


struct login_credential
{
    char username[10];
    char password[10];

    char username_signin[10];
    char userpassword_signin[10];
};
struct create_task
{
    char task_id[15];
    char task_current_time_date[30];
    char task_status[30];
    char task_assignee_name[30];
};
struct employee_details
{
    char employee_name[60];
    char employee_id[10];
    char employee_email_id[60];
    char employee_phone_number[60];
    char employee_address[160];
    struct create_task task_obj[10];
};

#endif // LOGIN_DETAILS_DATA_H
