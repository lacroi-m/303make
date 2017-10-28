//
// Relations.hpp for  in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Sat Oct 28 13:35:03 2017 Tom Jeammet
// Last update Sat Oct 28 14:29:30 2017 Tom Jeammet
//

#ifndef __RELATIONS_HPP__
# define __RELATIONS_HPP__

# include <vector>
# include <iostream>

# include "Depend.hpp"

void					searchInFiles(std::vector<Depend>, Depend, std::string, std::string);
void					searchInDepends(std::vector<Depend>, std::string, std::string);
void					printRelations(std::vector<std::string>, std::vector<Depend>, std::string);

#endif /* ! __RELATIONS_HPP__ */
