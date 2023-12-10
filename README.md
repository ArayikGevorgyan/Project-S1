# Electric Car Analysis

This C program analyzes data related to electric cars from a CSV file, calculating metrics such as profitability, sales, and model performance. It utilizes linked lists to store and manage the car data, along with functions for reading CSV files, computing metrics, and printing results.

## Prerequisites

- This program is written in C and requires a C compiler for execution.
- CMake (minimum version 3.26) is required to build the project.



## Getting Started

    **Run the Program:**
    ```
    mkdir build && cd build
    cmake ..
    cmake --build . -j${nproc}
    ./EV_Statistic ../Project.csv
    
    ```

## Functionality

- `csv_reader.h` contains functions to read data from a CSV file and populate a linked list of car structures.
- `car_list.h` manages linked lists for storing car data.
- `calc_metrics.h` computes various metrics like profitability, sales, etc., based on the stored car data.

## Usage

- The program expects a CSV file with electric car data in a specific format.
- Upon execution, it reads the data, calculates metrics, and prints the most and least profitable releases, all-time profitability, most and least sold models, etc.

## File Structure

- `main.c`: Entry point of the program, utilizes functions from other files to perform analysis.
- `csv_reader.c`: Implements functions for reading CSV files.
- `car_list.c`: Manages linked lists to store car data.
- `calc_metrics.c`: Calculates various metrics based on the stored data.

## Contributing

Contributions to enhance the program's functionality, optimize code, or improve documentation are welcome! Feel free to create pull requests.




