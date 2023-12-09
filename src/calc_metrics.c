#include "calc_metrics.h"

void calc_metrics(struct CarNode *head,
                  struct Car *most_profitable_release,
                  struct Car *least_profitable_release,
                  struct Car *most_profitable_all_time,
                  struct Car *least_profitable_all_time,
                  struct Car *most_sold,
                  struct Car *least_sold)
{
// Initialize variables to track maximum and minimum profit/sales
    uint32_t max_profit_release = 0;
    uint32_t min_profit_release = UINT32_MAX;
    uint32_t max_profit_all_time = 0;
    uint32_t min_profit_all_time = UINT32_MAX;
    uint32_t max_sold = 0;
    uint32_t min_sold = UINT32_MAX;

// Pointer to traverse the linked list
    struct CarNode *current = head;


// Loop through the linked list to calculate metrics
    while(current != NULL)
    {
        // Calculate profit for the current release and all-time profit
        uint32_t profit_release = current->car.price * current->car.quantity;
        uint32_t profit_all_time = current->car.price * current->car.production;

        // Update metrics for most/least profitable releases based on current data
        if(profit_release > max_profit_release)
        {
            max_profit_release = profit_release;
            *most_profitable_release = current->car;
        }

        if(profit_release < min_profit_release)
        {
            min_profit_release = profit_release;
            *least_profitable_release = current->car;
        }
        // Update metrics for most/least profitable all-time based on current data
        if(profit_all_time > max_profit_all_time)
        {
            max_profit_all_time = profit_all_time;
            *most_profitable_all_time = current->car;
        }

        if(profit_all_time < min_profit_all_time)
        {
            min_profit_all_time = profit_all_time;
            *least_profitable_all_time = current->car;
        }
        // Update metrics for most/least sold based on current data
        if(current->car.quantity > max_sold)
        {
            max_sold = current->car.quantity;
            *most_sold = current->car;
        }

        if(current->car.quantity < min_sold)
        {
            min_sold = current->car.quantity;
            *least_sold = current->car;
        }
        // Move to the next node in the linked list
        current = current->next;
    }
}