#ifndef EXAM_SORT_H
#define EXAM_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exam_subscription.h"


// Типы указателей на функции сортировки и сравнения
typedef void (*SortFunc)(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*));
typedef int (*CompareFunc)(const exam_subscription*, const exam_subscription*);

// Прототипы функций сортировки

// Вставками
void insertion_sort(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*));

// Слиянием
void merge_sort(exam_subscription** array, int size, int (*cmp)(const exam_subscription*, const exam_subscription*));
void merge_sort_recursive(exam_subscription** array, int left, int right, int (*cmp)(const exam_subscription*, const exam_subscription*));
void merge(exam_subscription** array, int left, int mid, int right, int (*cmp)(const exam_subscription*, const exam_subscription*));

// Прототипы функций сравнения

// По фамилии студента по алфавиту
int compare_last_name(const exam_subscription* a, const exam_subscription* b);

// По названию предмета по алфавиту и при равенстве — по убыванию оценки
int compare_title_mark(const exam_subscription* a, const exam_subscription* b);

// Массив указателей на функции сортировки и сравнения
extern SortFunc sort_methods[];
extern CompareFunc compare_methods[];

// Функция для выбора метода сортировки и выполнения сортировки
void perform_sort(exam_subscription** data_array, int size);

#endif // EXAM_SORT_H
