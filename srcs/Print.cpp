//
// Print.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 14:36:30 2017 Tom Jeammet
// Last update Sat Oct 28 15:42:36 2017 Tom Jeammet
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
  std::string				file;
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
    }
}
