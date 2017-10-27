//
// Depend.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 13:52:59 2017 Tom Jeammet
// Last update Fri Oct 27 15:01:07 2017 Tom Jeammet
//

#include "Depend.hpp"

//Ctor
Depend::Depend(void)
{

}
//Dtor
Depend::~Depend(void)
{

}

//Member


//Getter
std::string                   Depend::getName(void)
{
  return (this->name);
}

std::vector<std::string>      Depend::getFiles(void)
{
  return (this->files);
}

//Setter
void                          Depend::setName(std::string &_name)
{
  this->name = _name;
}

void                          Depend::setFiles(std::vector<std::string> &_files)
{
  this->files = _files;
}
