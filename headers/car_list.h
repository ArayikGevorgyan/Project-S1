#ifndef CAR_LIST_H
#define CAR_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*These lines include necessary standard C libraries such as stdio.h, stdlib.h, and stdint.h,
 which provide functionalities for input/output, memory allocation, and standard integer types respectively.*/

struct Car
{
    char model_name[20];
    uint32_t production;
    char country[20];
    uint16_t year;
    uint32_t price;
    uint32_t quantity;
    char manufacturer[20];
};
/*Defines a structure Car that represents the properties of a car:
 model name, production quantity, country, year, price, quantity available, and manufacturer.*/

struct CarNode
{
    struct Car car;
    struct CarNode *next;
};
/*Defines a structure CarNode that represents a node in a linked list.
It contains a Car structure to hold car details and a pointer next to the next node in the linked list.*/


void add_car(struct CarNode **head, struct Car car);
void free_list(struct CarNode *head);

void print_car(struct Car car);
void print_list(struct CarNode *head);
/*Function prototypes for operations on the linked list, such as adding a new car to the list, 
freeing memory occupied by the list, and functions to print individual cars and the entire linked list.*/

#endif //CAR_LIST_H