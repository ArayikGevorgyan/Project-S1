#include "csv_reader.h"

int skip_line(int fd)
{
    char symbol = 'a';
    ssize_t read_bytes;

    while((read_bytes = read(fd, &symbol, 1)) > 0)
    {
        if (symbol == '\n')
        {
            break;
        }

    }

    // Handling errors or reaching end-of-file
    if (read_bytes == -1)
    {
        perror("read");
        exit(1);
    }
    else if (read_bytes == 0)
    {
        return -1;// Indicates end-of-file
    }

    return 0;// Successfully skipped line
}

int read_string(int fd, char *buf)
{
    char symbol = 'a';
    uint8_t i = 0;
    ssize_t read_bytes;


    // Loop to read characters until encountering ',', '\n', or reaching the limit of 19 characters
    while((read_bytes = read(fd, &symbol, 1)) > 0)
    {
        if (symbol == ',' || symbol == '\n' || i == 19)
        {
            break;
        }
        else if (symbol == '\r')
        {
            read_bytes = read(fd, &symbol, 1);
            break;
        }
        buf[i++] = symbol;
    }

    if (read_bytes == -1)
    {
        perror("read");
        exit(1);
    }
    else if (read_bytes == 0)
    {
        return -1;
    }

    return 0;
}

int read_number(int fd, uint32_t *number)
{
    char symbol = 'a';
    ssize_t read_bytes;

    while((read_bytes = read(fd, &symbol, 1)) > 0)
    {
        if (symbol == ',' || symbol == '\n')
        {
            break;
        }
        else if (symbol == '\r')
        {
            read_bytes = read(fd, &symbol, 1);
            break;
        }
        *number = *number * 10 + (symbol - '0');
    }

    if (read_bytes == -1)
    {
        perror("read");
        exit(1);
    }
    else if (read_bytes == 0)
    {
        return -1;
    }

    return 0;
}

void read_car_list(struct CarNode **head, char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    skip_line(fd);

    struct Car car;

    for (;;)
    {
        car = (struct Car) {0};

        if (read_string(fd, car.model_name) == -1)
        {
            break;
        }

        if (read_number(fd, &car.production) == -1)
        {
            break;
        }

        if (read_string(fd, car.country) == -1)
        {
            break;
        }

        if (read_number(fd, (uint32_t *) &car.year) == -1)
        {
            break;
        }

        if (read_number(fd, &car.price) == -1)
        {
            break;
        }

        if (read_number(fd, &car.quantity) == -1)
        {
            break;
        }

        if (read_string(fd, car.manufacturer) == -1)
        {
            add_car(head, car);
            break;
        }

        add_car(head, car);
    }

    if (close(fd) == -1)
    {
        perror("close");
        exit(1);
    }
}