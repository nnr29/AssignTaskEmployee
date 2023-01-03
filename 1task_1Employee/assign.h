#ifndef ASSIGN_H
#define ASSIGN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct create_task
{
    char task_id[20];
    char task_status[20];
    char task_assignee_name[30];
};

struct employee_details
{
    char employee_name[10];
    char employee_id[10];
    char employee_ph[10];
    struct create_task task_obj;
}emp;
#endif // ASSIGN_H

