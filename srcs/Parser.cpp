//
// Parser.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 15:10:08 2017 Tom Jeammet
// Last update Thu Oct 26 15:14:53 2017 Tom Jeammet
//

#include "Parser.hpp"

//Ctor
Parser::Parser(void)
{

}

//Dtor
Parser::~Parser(void)
{

}

//Member
bool                                    Parser::isInVector(std::vector<std::string> &tab, std::string &str)
{
  std::vector<std::string>::iterator    it;
  std::string				tmp;

  for (it = tab.begin(); it != tab.end(); it++)
    {
      tmp = *it;
      if ((tmp.compare(str)) == 0)
        return (true);
    }
  return (false);
}

void					Parser::parseLine(std::string line, int pos)
{
  std::vector<std::string>::iterator    it;
  std::vector<std::string>              lines;
  std::string                           first;
  std::string                           tmp;

  first = line.substr(0, pos);
  line = line.substr(pos);
  std::stringstream                     ss(line);
  while (std::getline(ss, tmp, ' '))
    {
      if ((tmp.compare("")) != 0)
        lines.push_back(tmp);
    }
  if (first.find('.') == std::string::npos)
    this->exe = first;
  else
    {
      if (!isInVector(this->files, first))
        this->files.push_back(first);
    }
  for (it = files.begin(); it != files.end(); it++)
    {
      if (!isInVector(this->files, *it))
        this->files.push_back(*it);
    }
}

void                     Parser::parseit(std::vector<std::string> &lines)
{
  std::vector<std::string>::iterator    it;
  std::vector<std::string>              files;
  std::string				tmp;
  std::size_t                           found;

  for (it = lines.begin(); it != lines.begin(); it++)
    {
      tmp = *it;
      if ((tmp.compare("\n")) != 0)
        {
          if ((found = tmp.find(':')) != std::string::npos)
            {
              parseLine(*it, found);
            }
          else
            {
	      this->lines.push_back(*it);
            }
        }
    }
  std::cout << "lines : " << std::endl;
  print_stab(lines);
  std::cout << "files : " << std::endl;
  print_stab(files);
  std::cout << "exe : " << std::endl;
  std::cout << exe << std::endl;
}

void					Parser::print_stab(std::vector<std::string> tab)
{
  std::vector<std::string>::iterator	it;

  for (it = tab.begin(); it != tab.end(); it++)
    {
      std::cout << *it << std::endl;
    }
  std::cout << std::endl;
}

//Getter
std::vector<std::string>		Parser::getLines(void)
{
  return (this->lines);
}

std::vector<std::string>		Parser::getFiles(void)
{
  return (this->files);
}

std::string				Parser::getExe(void)
{
  return (this->exe);
}

//Setter
void					Parser::setLines(std::vector<std::string> _lines)
{
  this->lines = _lines;
}

void					Parser::setFiles(std::vector<std::string> _files)
{
  this->files = _files;
}

void					Parser::setExe(std::string _exe)
{
  this->exe = _exe;
}
