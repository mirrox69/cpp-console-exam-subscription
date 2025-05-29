#include <iostream>

using namespace std;

#include "exam_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №8. Итоги сессии\n";
    cout << "Автор: Иван Мирончик\n\n";
    exam_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->student.last_name << ' ';
            cout << subscriptions[i]->student.first_name << ' ';
            cout << subscriptions[i]->student.middle_name << ' ';
            cout << subscriptions[i]->examdate.day << ' ';
            cout << subscriptions[i]->examdate.month << ' ';
            cout << subscriptions[i]->examdate.year << ' ';
            cout << subscriptions[i]->mark << ' ';
            cout << subscriptions[i]->title << ' ';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}