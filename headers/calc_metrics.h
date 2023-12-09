#ifndef CALC_METRICS_H
#define CALC_METRICS_H

#include "car_list.h"

#include <stdio.h>

void calc_metrics(struct CarNode *head,
                  struct Car *most_profitable_release,
                  struct Car *least_profitable_release,
                  struct Car *most_profitable_all_time,
                  struct Car *least_profitable_all_time,
                  struct Car *most_sold,
                  struct Car *least_sold);
/*

This line declares a function calc_metrics that is responsible for calculating 
various metrics related to car data. It takes a pointer to the head of a linked list of cars 
and pointers to Car structures representing different metrics such as most/least profitable releases, 
most/least profitable of all time, most/least sold, etc. 

*/


#endif //CALC_METRICS_H