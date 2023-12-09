#include "car_list.h"


// Function to add a new car to the linked list
void add_car(struct CarNode **head, struct Car car)
{

    // If the linked list is empty, create a new node for the head
    if (*head == NULL)
    {
        *head = malloc(sizeof(struct CarNode));
        (*head)->car = car;
        (*head)->next = NULL;
    }
    else
    {
        // If the linked list is not empty, traverse to the end
        struct CarNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Add a new node at the end of the linked list
        current->next = malloc(sizeof(struct CarNode));
        current->next->car = car;
        current->next->next = NULL;
    }
}

// Function to free memory allocated for the linked list
void free_list(struct CarNode *head)
{
    struct CarNode *current = head;
    while (current != NULL)
    {
        struct CarNode *next = current->next;
        free(current);// Free the current node
        current = next;// Move to the next node
    }
}

// Function to print the entire linked list of cars
void print_list(struct CarNode *head)
{
    struct CarNode *temp = head;

    while(temp != NULL)
    {
        print_car(temp->car);// Print details of each car
        temp = temp->next;// Move to the next node
    }
}

// Function to print details of a single car
void print_car(struct Car car)
{
    printf("|  Model Name: %s\n", car.model_name);
    printf("|  Production: %u\n", car.production);
    printf("|  Country: %s\n", car.country);
    printf("|  Year: %u\n", car.year);
    printf("|  Price: %u\n", car.price);
    printf("|  Quantity: %u\n", car.quantity);
    printf("|  Manufacturer: %s\n", car.manufacturer);
    printf("------------------------------\n");
}