//
// Parser.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 15:10:08 2017 Tom Jeammet
// Last update Fri Oct 27 15:09:12 2017 Tom Jeammet
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

void					Parser::parseLine(std::string &line, int pos)
{
  std::vector<std::string>::iterator    it;
  std::vector<std::string>              words;
  std::string                           first;
  std::string                           tmp;
  std::size_t				found;
  Depend				dp;

  first = line.substr(0, pos);
  line = line.substr(pos + 3);
  std::stringstream                     ss(line);
  while (std::getline(ss, tmp, ' '))
    {
      if ((tmp.compare("")) != 0)
        words.push_back(tmp);
    }
  if ((found = first.find('.')) == std::string::npos)
    setExe(first);
  else
    {
      if (!isInVector(files, first))
        files.push_back(first);
    }
  for (it = words.begin(); it != words.end(); it++)
    {
      tmp = *it;
      if (!isInVector(files, tmp))
        files.push_back(tmp);
    }
  dp.setName(first);
  dp.setFiles(words);
  depends.push_back(dp);
}

void					Parser::parse(std::vector<std::string> &tab)
{
  std::vector<std::string>::iterator    it;
  std::string				tmp;
  std::size_t                           found;

  for (it = tab.begin(); it != tab.end(); it++)
    {
      tmp = *it;
      if ((tmp.compare("\n")) != 0)
        {
          if ((found = tmp.find(':')) != std::string::npos)
	    parseLine(*it, found);
          else
	    lines.push_back(*it);
        }
    }
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

std::vector<Depend>			Parser::getDepends(void)
{
  return (this->depends);
}

std::string				Parser::getExe(void)
{
  return (this->exe);
}

//Setter
void					Parser::setLines(std::vector<std::string> &_lines)
{
  this->lines = _lines;
}

void					Parser::setFiles(std::vector<std::string> &_files)
{
  this->files = _files;
}

void					Parser::setDepends(std::vector<Depend> &_depends)
{
  this->depends = _depends;
}

void					Parser::setExe(std::string &_exe)
{
  this->exe = _exe;
}
