//
// Print.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 14:36:30 2017 Tom Jeammet
// Last update Fri Oct 27 14:36:31 2017 Tom Jeammet
//

#include "Print.hpp"

void                                    print_stab(std::vector<std::string> &tab)
{
  std::vector<std::string>::iterator    it;

  for (it = tab.begin(); it != tab.end(); it++)
    std::cout << *it << std::endl;
  std::cout << std::endl;
}
