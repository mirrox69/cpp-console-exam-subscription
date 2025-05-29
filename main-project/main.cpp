#include <iostream>
#include <iomanip>

using namespace std;

#include "exam_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �4. GIT\n";
    cout << "������� �8. ����� ������\n";
    cout << "�����: ���� ��������\n\n";
    exam_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** ����� ������ *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� �������� **********/
            cout << "�������: ";
            // ����� �������
            cout << subscriptions[i]->student.last_name << " ";
            // ����� ������ ����� �����
            cout << subscriptions[i]->student.first_name << " ";
            // ����� ������ ����� ��������
            cout << subscriptions[i]->student.middle_name << "";
            cout << '\n';
            cout << "���� �������� : ";
            cout << setfill('0') << subscriptions[i]->examdate.year << '-';
            // ����� ������
            cout << setw(2) << setfill('0') << subscriptions[i]->examdate.month << '-';
            // ����� �����
            cout << setw(2) << setfill('0') << subscriptions[i]->examdate.day;
            cout << '\n';
            /********** ����� ����� **********/
            cout << "������ � ���������� : ";
            // ����� ������� ������
            cout << subscriptions[i]->mark << " ";
            // ����� ������ ����� ����� ������
            cout << '"' << subscriptions[i]->title << '"';
            cout << '\n';
            /********** ����� ���� ������ **********/
            // ����� ����
            /********** ����� ���� �������� **********/
            // ����� ����
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