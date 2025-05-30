#ifndef FILTER_H
#define FILTER_H

#include "exam_subscription.h"

exam_subscription** filter(exam_subscription* array[], int size, bool (*check)(exam_subscription* element), int& result_size);

/*
  <function_name>:
              ,
          true,
    ,

:
    array       -
    size        -
    check       -    .

                   ,
    result_data - ,    - ,



          ,
     (     true)
*/


bool check_exam_subscription_by_author(exam_subscription* element);

/*
  check_book_subscription_by_author:
      - ,

:
    element -   ,


    true,           ,  false
*/


bool check_exam_subscription_by_mark(exam_subscription* element);

/*
  check_book_subscription_by_date:
      - ,           2021-

:
    element -   ,


    true,           2021- ,  false
*/

#endif

