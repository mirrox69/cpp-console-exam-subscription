#include <iostream>
#include <iomanip>

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
        cout << "***** Итоги сессии *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод читателя **********/
            cout << "Студент: ";
            // вывод фамилии
            cout << subscriptions[i]->student.last_name << " ";
            // вывод первой буквы имени
            cout << subscriptions[i]->student.first_name << " ";
            // вывод первой буквы отчества
            cout << subscriptions[i]->student.middle_name << "";
            cout << '\n';
            cout << "Дата экзамена : ";
            cout << setfill('0') << subscriptions[i]->examdate.year << '-';
            // вывод месяца
            cout << setw(2) << setfill('0') << subscriptions[i]->examdate.month << '-';
            // вывод числа
            cout << setw(2) << setfill('0') << subscriptions[i]->examdate.day;
            cout << '\n';
            /********** вывод книги **********/
            cout << "Оценка и дисциплина : ";
            // вывод фамилии автора
            cout << subscriptions[i]->mark << " ";
            // вывод первой буквы имени автора
            cout << '"' << subscriptions[i]->title << '"';
            cout << '\n';
            /********** вывод даты выдачи **********/
            // вывод года
            /********** вывод даты возврата **********/
            // вывод года
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