#include "insert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;



// Прототип функции сортировки
typedef void (*SortFunc)(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*));

// Прототип функции сравнения
typedef int (*CompareFunc)(const exam_subscription*, const exam_subscription*);

// Функции сортировки

// 1. Сортировка вставками
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

// 2. Сортировка слиянием
void merge(exam_subscription** array, int left, int mid, int right, int (*cmp)(const exam_subscription*, const exam_subscription*));
void merge_sort_recursive(exam_subscription** array, int left, int right, int (*cmp)(const exam_subscription*, const exam_subscription*));
void merge_sort(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*)) {
    merge_sort_recursive(array, 0, size - 1, cmp);
}

void merge(exam_subscription** array, int left, int mid, int right, int (*cmp)(const exam_subscription*, const exam_subscription*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Временные массивы указателей
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

// Функции сравнения

// a. По фамилии студента по алфавиту
int compare_last_name(const exam_subscription* a, const exam_subscription* b) {
    return strcmp(a->student.last_name, b->student.last_name);
}

// b. По названию предмета по алфавиту и при равенстве — по убыванию оценки
int compare_title_mark(const exam_subscription* a, const exam_subscription* b) {
    int title_cmp = strcmp(a->title, b->title);
    if (title_cmp != 0)
        return title_cmp; // по названию предмета по возрастанию
    // при равенстве — по убыванию оценки
    return b->mark - a->mark;
}

// Массив указателей на функции сортировки
SortFunc sort_methods[] = { insertion_sort /*[0]*/, merge_sort /*[1]*/ };

// Массив указателей на функции сравнения
CompareFunc compare_methods[] = { compare_last_name /*[0]*/, compare_title_mark /*[1]*/ };

// Функция для демонстрации выбора метода и критерия сортировки
void perform_sort(exam_subscription** data_array, int size) {
    cout << "Выберите метод сортировки:\n";
    cout << "0 - Вставками\n";
    cout << "1 - Слиянием\n";

    int method_choice;
    cin >> method_choice;

    if (method_choice < 0 || method_choice>1) {
        cout << "Некорректный выбор метода.\n";
        return;
    }

    cout << "Выберите критерий сортировки:\n";
    cout << "0 - По фамилии студента\n";
    cout << "1 - По названию предмета и оценке\n";

    int criterion_choice;
    cin >> criterion_choice;

    if (criterion_choice < 0 || criterion_choice>1) {
        cout << "Некорректный выбор критерия.\n";
        return;
    }

    SortFunc sort_func = sort_methods[method_choice];
    CompareFunc cmp_func = compare_methods[criterion_choice];

    // Вызов через указатель
    sort_func(data_array, size, cmp_func);

    cout << "Данные отсортированы.\n";
}



