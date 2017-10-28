//
// Relations.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Sat Oct 28 13:34:43 2017 Tom Jeammet
// Last update Sat Oct 28 16:17:48 2017 Tom Jeammet
//

#include "Relations.hpp"

bool					containFile(Depend dp, std::string name)
{
  std::vector<std::string>::iterator	it;
  std::vector<std::string>		files;
  std::string				tmp;

  files = dp.getFiles();
  for (it = files.begin(); it != files.end(); it++)
    {
      tmp = *it;
      if ((tmp.compare(name)) == 0)
	return (true);
    }
  return (false);
}

void					searchInFiles(std::vector<Depend> depends, Depend depend, std::string name, std::string dependN, std::string exe)
{
  std::vector<std::string>::iterator	it;
  std::vector<std::string>		files;
  std::string				tmp;

  files = depend.getFiles();
  for (it = files.begin(); it != files.end(); it++)
    {
      tmp = *it;
      if ((tmp.compare(name)) == 0)
	{
	  if ((dependN.compare(exe)) != 0)
	    searchInDepends(depends, dependN, exe);
	  else
	    std::cout << exe << std::endl;
	}
    }
}

void					searchInDepends(std::vector<Depend> depends, std::string name, std::string exe)
{
  std::vector<Depend>::iterator		it;
  std::string				dependN;
  Depend				tmp;

  for (it = depends.begin(); it != depends.end(); it++)
    {
      tmp = *it;
      if (containFile(tmp, name))
	{
	  std::cout << name << " -> ";
	  dependN = tmp.getName();
	  searchInFiles(depends, tmp, name, dependN, exe);
	}
    }
}

void					printRelations(std::vector<std::string> files, std::vector<Depend> depends, std::string exe)
{
  std::vector<std::string>::iterator	it;
  std::string				tmp;

  for (it = files.begin(); it != files.end(); it++)
    {
      tmp = *it;
      if ((tmp.compare(exe)) != 0)
	searchInDepends(depends, tmp, exe);
    }
}
