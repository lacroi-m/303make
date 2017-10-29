//
// Depend.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 13:52:59 2017 Tom Jeammet
// Last update Sun Oct 29 15:58:51 2017 Tom Jeammet
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
void					Depend::add_files(std::string line)
{
  std::vector<std::string>		tab;
  std::stringstream                     ss(line);
  std::string                           tmp;
  
  while (std::getline(ss, tmp, ' '))
    {
      if ((tmp.compare("")) != 0)
	tab.push_back(tmp);
    }
  setFiles(tab);
}

void					Depend::add_line(std::string line)
{
  std::vector<std::string>		tab;

  tab.push_back(line);
  setLines(tab);
}

std::string				Depend::getLine(void)
{
  std::vector<std::string>::iterator	it;
  std::vector<std::string>		tab;

  tab = getLines();
  it = tab.begin();
  return (*it);
}

//Getter
std::string				Depend::getName(void)
{
  return (this->name);
}

std::vector<std::string>		Depend::getFiles(void)
{
  return (this->files);
}

std::vector<std::string>                Depend::getLines(void)
{
  return (this->lines);
}

//Setter
void					Depend::setName(std::string &_name)
{
  this->name = _name;
}

void					Depend::setFiles(std::vector<std::string> &_files)
{
  this->files = _files;
}

void                                    Depend::setLines(std::vector<std::string> &_lines)
{
  this->lines = _lines;
}
