#ifndef CSV_READER_H
#define CSV_READER_H

#include "car_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void read_car_list(struct CarNode **head, char *filename);
/*This line declares a function read_car_list responsible for 
reading data from a CSV file and populating a linked list of cars. 
It takes a pointer to a pointer to the head of the linked list (struct CarNode **head)
and a filename (the CSV file) as input parameters.*/


int read_string(int fd, char *buf);
int read_number(int fd, uint32_t *number);

int skip_line(int fd);

#endif //CSV_READER_H