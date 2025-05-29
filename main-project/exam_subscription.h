#ifndef EXAM_SUBSCRIPTION_H
#define EXAM_SUBSCRIPTION_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct exam_subscription
{
    person student;
    date examdate;
    int mark;
    char title[MAX_STRING_SIZE];
};

#endif
