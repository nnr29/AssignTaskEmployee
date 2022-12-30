#ifndef ASSIGN_H
#define ASSIGN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct employee_details
{
    char employee_name[60];
    char employee_id[10];
    char employee_ph[10];
    struct create_task *task_obj;
}emp;
struct create_task
{
    char task_id[15];
    //char task_current_time_date[30];
    char task_status[30];
    char task_assignee_name[30];
};
#endif // ASSIGN_H
