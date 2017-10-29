//
// Compile.hpp for  in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Sun Oct 29 15:32:43 2017 Tom Jeammet
// Last update Sun Oct 29 16:53:18 2017 Tom Jeammet
//

#ifndef __COMPILE_HPP__
# define __COMPILE_HPP__

# include <vector>
# include <string>
# include <iostream>

# include "Depend.hpp"
# include "Parser.hpp"

void                                    print_exeLine(std::vector<Depend>, std::string);
bool                                    is_in_files(std::vector<std::string>, std::string);
void					printCompiles(Parser, std::string);

#endif /* ! __COMPILE_HPP__ */
