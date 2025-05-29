#include "filter.h"
#include <cstring>
#include <iostream>

exam_subscription** filter(exam_subscription* array[], int size, bool (*check)(exam_subscription* element), int& result_size)
{
	exam_subscription** result = new exam_subscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_exam_subscription_by_author(exam_subscription* element)
{
	return strcmp(element->title, "история беларуси") == 0;
}

bool check_exam_subscription_by_mark(exam_subscription* element)
{
	return element->mark > 7;
}

