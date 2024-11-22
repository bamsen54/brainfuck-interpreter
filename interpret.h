
#pragma once

#include <iostream>
#include <vector>
#include "util.h"

#define NUMBER_OF_CELLS 30

unsigned char cells[NUMBER_OF_CELLS];

inline void init_cells() {

    for(int cell_number = 0; cell_number < NUMBER_OF_CELLS; cell_number++)
        cells[cell_number] = 0;
}

inline void print_cells() {

    std::cout << "[ ";

    for(int e: cells)
        std::cout << e << " ";

    std::cout << "]\n";
}

unsigned int data_pointer        = 0; // pointer to cell
unsigned int instruction_pointer = 0; // pointer to char in program

void print_cell(const std::string& program);
void take_input(const std::string& program);
void go_to_next_cell(const std::string& program);
void go_to_previous_cell(const std::string& program);
void add_to_cell(const std::string& program);
void subtract_from_cell(const std::string& program);
void open_bracket(const std::string& program);
void close_bracket(const std::string& program);

inline void interpret(const std::string& program, bool reset_instruction_pointer_to_zero = false) {

    while(instruction_pointer < program.size()) {

        const char instruction = program[instruction_pointer];

        switch (instruction) {

            case '.':
                print_cell(program);
                break;
            case ',':
                take_input(program);
                break;
            case '>':
                go_to_next_cell(program);
                break;
            case '<':
                go_to_previous_cell(program);
                break;
            case '+':
                add_to_cell(program);
                break;
            case '-':
                subtract_from_cell(program);
                break;
            case '[':
                open_bracket(program);
                break;
            case ']':
                close_bracket(program);
                break;
            default:
                instruction_pointer++;
        }
    }

    if(reset_instruction_pointer_to_zero)
        instruction_pointer = 0;
}

// takes input from user and sets the current cell to that value

void print_cell(const std::string& program) {

    std::cout << cells[data_pointer];
    instruction_pointer++;
}

void take_input(const std::string& program) {

    int input;

    std::cout << "Enter 0-255: ";
    std::cin >> input;
    
    cells[data_pointer] = (int) input;

    std::cout << "\n";

    instruction_pointer++;
}

void go_to_next_cell(const std::string& program) {

    data_pointer = (data_pointer + 1) % NUMBER_OF_CELLS;
            
    instruction_pointer++;
}

void go_to_previous_cell(const std::string& program) {

    data_pointer --;

    if(data_pointer == - 1)
        data_pointer = NUMBER_OF_CELLS - 1;

    instruction_pointer++;
}

void add_to_cell(const std::string& program) {

    cells[data_pointer]++;

    instruction_pointer++;
}

void subtract_from_cell(const std::string& program) {

    cells[data_pointer]--;

    instruction_pointer++;
}

void open_bracket(const std::string& program) {

    if(cells[data_pointer] == 0) {

        int jump_to = find_next_matching_bracket(program, instruction_pointer) + 1;

        instruction_pointer = jump_to;
    }

    else {
        instruction_pointer++;
    }
}

void close_bracket(const std::string& program) {

    if(cells[data_pointer] == 0)
        instruction_pointer++;

    else {

        int jump_to = find_previous_matching_bracket(program, instruction_pointer) + 1;
        
        instruction_pointer = jump_to;
    }
}