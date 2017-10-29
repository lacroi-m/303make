//
// Parser.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 15:10:08 2017 Tom Jeammet
// Last update Sun Oct 29 15:30:17 2017 Tom Jeammet
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
void					Parser::sortDepends(void)
{
  std::vector<std::string>::iterator	jt;
  std::vector<Depend>::iterator		it;
  std::vector<std::string>		names;
  std::vector<Depend>			depends;
  std::vector<Depend>			final;
  std::string				name;
  Depend				tmp;


  depends = getDepends();
  for (it = depends.begin(); it != depends.end(); it++)
    {
      tmp = *it;
      name = tmp.getName();
      names.push_back(name);
    }
  std::sort(names.begin(), names.end());
  for (jt = names.begin(); jt != names.end(); jt++)
    {
      name = *jt;
      for (it = depends.begin(); it != depends.end(); it++)
	{
	  tmp = *it;
	  if (((tmp.getName()).compare(name)) == 0)
	    final.push_back(tmp);
	}
    }
  setDepends(final);
}

void					Parser::completeFiles(void)
{
  std::vector<std::string>		files;
  std::string				exe;

  files = getFiles();
  exe = getExe();
  files.push_back(exe);
  std::sort(files.begin(), files.end());
  setFiles(files);
}

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

void					Parser::addToFiles(Depend dp)
{
  std::vector<std::string>::iterator	it;
  std::vector<std::string>		dpf;
  std::string				tmp;

  dpf = dp.getFiles();
  for (it = dpf.begin(); it != dpf.end(); it++)
    {
      tmp = *it;
      if (!isInVector(files, tmp))
	files.push_back(tmp);
    }
}

Depend					Parser::parseFiles(Depend dp, std::string line, int pos)
{
  std::vector<std::string>		tab;
  std::size_t				found;
  std::string				name;

  name = line.substr(0, pos);
  line = line.substr(pos + 3);
  if ((found = name.find('.')) == std::string::npos)
    setExe(name);
  else
    {
      if (!isInVector(files, name))
	files.push_back(name);
    }
  dp.setName(name);
  dp.add_files(line);
  addToFiles(dp);
  return (dp);
}

Depend					Parser::addCompile(Depend dp, std::string line)
{
  dp.add_line(line);
  depends.push_back(dp);
  return (dp);
}

void					Parser::parse(std::vector<std::string> tab)
{
  std::vector<std::string>::iterator    it;
  std::string				tmp;
  std::size_t                           found;
  Depend				dp;

  for (it = tab.begin(); it != tab.end(); it++)
    {
      tmp = *it;
      if ((tmp.compare("\n")) != 0)
        {
          if ((found = tmp.find(':')) != std::string::npos)
	    dp = parseFiles(dp, tmp, found);
          else
	    dp = addCompile(dp, tmp);
        }
    }
  completeFiles();
  sortDepends();
}

//Getter
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
