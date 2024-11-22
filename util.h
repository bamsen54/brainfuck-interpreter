#pragma once

#include <iostream>
#include <vector>
#include <string>


inline bool string_has_char(std::string str, const char chr) {

    for(const char c: str) {

        if(c == chr)
            return true;
    }

    return false;
}

inline unsigned int find_next_matching_bracket(const std::string& program, int instruction_pointer) {

    int running_total = 1;

    while(instruction_pointer < program.size()) {

        instruction_pointer++;

         if (program[instruction_pointer] == '[')
            running_total++;

        else if(program[instruction_pointer] == ']')
            running_total--;

        if(running_total == 0)
            return instruction_pointer;
    }

    return - 1;
}

inline unsigned int find_previous_matching_bracket(const std::string& program, int instruction_pointer) {

    int running_total = 1;

    while(instruction_pointer < program.size()) {

        instruction_pointer--;

         if (program[instruction_pointer] == ']')
            running_total++;

        else if(program[instruction_pointer] == '[')
            running_total--;

        if(running_total == 0)
            return instruction_pointer;
    }

    return - 1;
}

