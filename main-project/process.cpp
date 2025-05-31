#include "processing.h"


// ��������, �������� �� ��� ����������
int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

// ���������� ���� � ������ ������
int daysInMonth(int month, int year) {
    static const int daysPerMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysPerMonth[month - 1];
}

// �������������� ���� � ���������� ���� � ������� �����
long dateToDays(exam_subscription* d) {
    long days = 0;
    // ������� ������ ����
    for (int y = 0; y < d->examdate.year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    // ��������� ��� �������� ����
    for (int m = 1; m < d->examdate.month; m++) {
        days += daysInMonth(m, d->examdate.year);
    }
    days += d->examdate.day;
    return days;
}
int process(exam_subscription* array[], int size)
{
    // ������������� min � max ���
    exam_subscription* minDate = array[0];
    exam_subscription* maxDate = array[0];

    for (int i = 1; i < size; i++) {
        // ��������� ��� ��� ������ �����������
        if (dateToDays(array[i]) < dateToDays(minDate))
            minDate = array[i];
        // ��������� ��� ��� ������ ������������
        if (dateToDays(array[i]) > dateToDays(maxDate))
            maxDate = array[i];
    }

    long diffDays = dateToDays(maxDate) - dateToDays(minDate);
    return diffDays;
}

