//
// Print.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 14:36:30 2017 Tom Jeammet
// Last update Sun Oct 29 15:20:34 2017 Tom Jeammet
//

#include "Print.hpp"

void                                    print_stab(std::vector<std::string> tab)
{
  std::vector<std::string>::iterator    it;

  for (it = tab.begin(); it != tab.end(); it++)
    std::cout << *it << std::endl;
  std::cout << std::endl;
}

void					print_depends(std::vector<Depend> depends)
{
  std::vector<std::string>::iterator	jt;
  std::vector<Depend>::iterator		it;
  std::vector<std::string>		files;
  std::vector<std::string>		lines;
  std::string				file;
  std::string				line;
  Depend				tmp;

  for (it = depends.begin(); it != depends.end(); it++)
    {
      tmp = *it;
      std::cout << "NAME : " << tmp.getName() << std::endl;
      files = tmp.getFiles();
      std::cout << "FILES : " << std::endl;
      for (jt = files.begin(); jt != files.end(); jt++)
	{
	  file = *jt;
	  std::cout << file << std::endl;
	}
      lines = tmp.getLines();
      std::cout << "LINES : " << std::endl;
      for (jt = lines.begin(); jt != lines.end(); jt++)
	{
	  line = *jt;
	  std::cout << line << std::endl;
	}
      std::cout << std::endl;
    }
}
