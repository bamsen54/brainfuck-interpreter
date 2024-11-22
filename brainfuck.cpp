
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>

#include "interpret.h"
#include "util.h"

std::string program_unfiltered = "";
std::string program           = "";
std::string valid              = ".,+-<>[]";

int main(int argc, char** argv) {

    if(argc == 2) {

        std::ifstream t(argv[1]);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

        program_unfiltered = str;

        for(char c: str) {

            if(string_has_char(valid, c))
                program.push_back(c);
        }

        init_cells();

        interpret(program, false); 
    }

    // if no ore more than 2 files are entered, we go into repl mode
    else if(argc == 1) {
        std::cout << "repl\n\n";

        init_cells();

        while(true) {

            std::cout << "";
            
            std::string input;

            std::getline(std::cin, input);

            if(input == "exit")
                break;

            interpret(input, true);


            
            std::cout << "\n";
        }
    }

    
}