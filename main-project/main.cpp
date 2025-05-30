#include <iostream>
#include <iomanip>

using namespace std;

#include "exam_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "insert.h" 
void output(exam_subscription* subscriptions) {
    
    
        /********** вывод читателя **********/
        cout << "Студент: ";
        // вывод фамилии
        cout << subscriptions->student.last_name << " ";

        // вывод первой буквы имени
        cout << subscriptions->student.first_name << " ";
        // вывод первой буквы отчества
        cout << subscriptions->student.middle_name << "";
        cout << '\n';
        cout << "Дата экзамена : ";
        cout << setfill('0') << subscriptions->examdate.year << '-';
        // вывод месяца
        cout << setw(2) << setfill('0') << subscriptions->examdate.month << '-';
        // вывод числа
        cout << setw(2) << setfill('0') << subscriptions->examdate.day;
        cout << '\n';
        /********** вывод книги **********/
        cout << "Оценка и дисциплина : ";
        // вывод фамилии автора
        cout << subscriptions->mark << " ";
        // вывод первой буквы имени автора
        cout << '"' << subscriptions->title << '"';
        cout << '\n';
        /********** вывод даты выдачи **********/
        // вывод года
        /********** вывод даты возврата **********/
        // вывод года
        cout << '\n';
    
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №8. Итоги сессии\n";
    cout << "Автор: Иван Мирончик\n";
    cout << "Группа: 24ПИ\n";
    exam_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt" , subscriptions , size);
        int option = 1;
        int methodChoice = 2;
        int criterionChoice = 2;
        int filterChoice = 2;
        bool (*check_function)(exam_subscription*) = NULL;
        while (option != 2) {
            cout << "Выберите опцию\n"
                << "0 - Фильтрация\n"
                << "1 - Сортировка\n"
                << "2 - Выход\n";
            cin >> option;
            switch (option) {
            case 0:
                cout << "Выберите критерий фильтрации\n"
                    << "0 - Дисциплина история беларуси\n"
                    << "1 - Оценка выше 7\n";
                cin >> filterChoice;
                break;
            case 1:
                cout << "Выберите метод сортировки\n"
                    << "0 - Сортировка вставками\n"
                    << "1 - Сортировка слиянием\n";
                cin >> methodChoice;
                cout << "Выберите критерий сортировки\n"
                    << "0 - По возрастанию фамилии студента\n"
                    << "1 - По возрастанию названия дициплины\n";
                cin >> criterionChoice;
                break;
            case 2:

                break;
            default:
                option = 2;

            }
            switch (filterChoice) {
            case 0:
                check_function = check_exam_subscription_by_author;
                break;
            case 1:
                check_function = check_exam_subscription_by_mark;
                break;
            default:
                check_function = NULL;
            }
            if (check_function)
            {
                int new_size;
                exam_subscription** filtered = filter(subscriptions, size, check_function, new_size);
                for (int i = 0; i < new_size; i++)
                {
                    output(filtered[i]);
                }
                delete[] filtered;
            }
            if ((methodChoice == 0 || methodChoice == 1) && (criterionChoice == 0 || criterionChoice == 1)) {
                SortFunc sortFunc = sort_methods[methodChoice];
                CompareFunc cmpFunc = compare_methods[criterionChoice];
                
                sortFunc(subscriptions, size, cmpFunc);

                for (int i = 0; i < size; i++) {

                    output(subscriptions[i]);
                }
               
            }

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

}
