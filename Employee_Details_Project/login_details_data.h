#ifndef LOGIN_DETAILS_DATA_H
#define LOGIN_DETAILS_DATA_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct login_credential
{
    char stored_username[10];
    char stored_userpassword[10];

    char username_signup[10];
    char userpassword_signup[10];

    char save_username[10];
    char save_userpassword[10];

    char username_signin[10];
    char userpassword_signin[10];


};
struct employee_details
{
    char employee_name[60];
    char employee_id[10];
    char employee_email_id[60];
    char employee_phone_number[60];
    char employee_address[160];
    struct create_task *task_obj;
};
struct create_task
{
    char task_id[15];
    char task_current_time_date[30];
    char task_status[30];
    char task_assignee_name[30];
};


#endif // LOGIN_DETAILS_DATA_H
