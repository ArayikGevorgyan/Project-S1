#include "csv_reader.h"
#include "car_list.h"
#include "calc_metrics.h"


int main(int argc, char *argv[])
{

    // Checking if the program is provided with the necessary filename argument
    if(argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    // Checking if the provided filename is NULL
    if(argv[1] == NULL)
    {
        printf("Filename is NULL\n");
        exit(1);
    }

    // Initializing the linked list head
    struct CarNode *head = NULL;

    // Reading car data from the provided CSV file and populating the linked list
    read_car_list(&head, argv[1]);

    // Variables to store calculated metrics about car releases and sales
    struct Car most_profitable_release;
    struct Car least_profitable_release;
    struct Car most_profitable_all_time;
    struct Car least_profitable_all_time;
    struct Car most_sold;
    struct Car least_sold;

    // Calculating various metrics based on the car data in the linked list
    calc_metrics(head,
                 &most_profitable_release,
                 &least_profitable_release,
                 &most_profitable_all_time,
                 &least_profitable_all_time,
                 &most_sold,
                 &least_sold);

    printf("******************************\n");
    printf("*   Most profitable release  *\n");
    printf("******************************\n");
    print_car(most_profitable_release);
    printf("******************************\n");
    printf("*  Least profitable release  *\n");
    printf("******************************\n");
    print_car(least_profitable_release);
    printf("******************************\n");
    printf("*  Most profitable all time  *\n");
    printf("******************************\n");
    print_car(most_profitable_all_time);
    printf("*****************************\n");
    printf("* Least profitable all time *\n");
    printf("*****************************\n");
    print_car(least_profitable_all_time);
    printf("*****************************\n");
    printf("*         Most sold         *\n");
    printf("*****************************\n");
    print_car(most_sold);
    printf("*****************************\n");
    printf("*        Least sold         *\n");
    printf("*****************************\n");
    print_car(least_sold);


    // Freeing memory allocated for the linked list
    free_list(head);

    return 0;
}