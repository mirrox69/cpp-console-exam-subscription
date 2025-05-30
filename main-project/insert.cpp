#include "insert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;



// �������� ������� ����������
typedef void (*SortFunc)(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*));

// �������� ������� ���������
typedef int (*CompareFunc)(const exam_subscription*, const exam_subscription*);

// ������� ����������

// 1. ���������� ���������
void insertion_sort(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*)) {
    for (int i = 1; i < size; i++) {
        exam_subscription* key = array[i];
        int j = i - 1;
        while (j >= 0 && cmp(array[j], key) > 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// 2. ���������� ��������
void merge(exam_subscription** array, int left, int mid, int right, int (*cmp)(const exam_subscription*, const exam_subscription*));
void merge_sort_recursive(exam_subscription** array, int left, int right, int (*cmp)(const exam_subscription*, const exam_subscription*));
void merge_sort(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*)) {
    merge_sort_recursive(array, 0, size - 1, cmp);
}

void merge(exam_subscription** array, int left, int mid, int right, int (*cmp)(const exam_subscription*, const exam_subscription*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ��������� ������� ����������
    exam_subscription** L = new exam_subscription*[n1];
    exam_subscription** R = new exam_subscription * [n2];

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j]) <= 0) {
            array[k++] = L[i++];
        }
        else {
            array[k++] = R[j++];
        }
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort_recursive(exam_subscription** array, int left, int right, int (*cmp)(const exam_subscription*, const exam_subscription*)) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort_recursive(array, left, mid, cmp);
        merge_sort_recursive(array, mid + 1, right, cmp);
        merge(array, left, mid, right, cmp);
    }
}

// ������� ���������

// a. �� ������� �������� �� ��������
int compare_last_name(const exam_subscription* a, const exam_subscription* b) {
    return strcmp(a->student.last_name, b->student.last_name);
}

// b. �� �������� �������� �� �������� � ��� ��������� � �� �������� ������
int compare_title_mark(const exam_subscription* a, const exam_subscription* b) {
    int title_cmp = strcmp(a->title, b->title);
    if (title_cmp != 0)
        return title_cmp; // �� �������� �������� �� �����������
    // ��� ��������� � �� �������� ������
    return b->mark - a->mark;
}

// ������ ���������� �� ������� ����������
SortFunc sort_methods[] = { insertion_sort /*[0]*/, merge_sort /*[1]*/ };

// ������ ���������� �� ������� ���������
CompareFunc compare_methods[] = { compare_last_name /*[0]*/, compare_title_mark /*[1]*/ };

// ������� ��� ������������ ������ ������ � �������� ����������
void perform_sort(exam_subscription** data_array, int size) {
    cout << "�������� ����� ����������:\n";
    cout << "0 - ���������\n";
    cout << "1 - ��������\n";

    int method_choice;
    cin >> method_choice;

    if (method_choice < 0 || method_choice>1) {
        cout << "������������ ����� ������.\n";
        return;
    }

    cout << "�������� �������� ����������:\n";
    cout << "0 - �� ������� ��������\n";
    cout << "1 - �� �������� �������� � ������\n";

    int criterion_choice;
    cin >> criterion_choice;

    if (criterion_choice < 0 || criterion_choice>1) {
        cout << "������������ ����� ��������.\n";
        return;
    }

    SortFunc sort_func = sort_methods[method_choice];
    CompareFunc cmp_func = compare_methods[criterion_choice];

    // ����� ����� ���������
    sort_func(data_array, size, cmp_func);

    cout << "������ �������������.\n";
}



