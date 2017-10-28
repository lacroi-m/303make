//
// Matrix.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 15:18:20 2017 Tom Jeammet
// Last update Sat Oct 28 15:02:18 2017 Tom Jeammet
//

#include "Matrix.hpp"

void					printZeros(std::vector<std::string> &files)
{
  std::vector<std::string>::iterator	it;
  int					i;

  i = 0;
  for (it = files.begin(); it != files.end(); it++)
    {
      std::cout << "0";
      if (i < ((int)files.size() - 1))
	std::cout << " ";
      i = i + 1;
    }
}

void					checkFiles(std::vector<std::string> &files, std::vector<std::string> depends)
{
  std::vector<std::string>::iterator	it;
  std::vector<std::string>::iterator	jt;
  std::string				tmp;
  std::string				tmp2;
  int					printed;
  int					i;

  i = 0;
  for (it = files.begin(); it != files.end(); it++)
    {
      printed = 0;
      tmp = *it;
      for (jt = depends.begin(); jt != depends.end(); jt++)
	{
	  tmp2 = *jt;
	  if ((tmp2.compare(tmp)) == 0)
	    {
	      std::cout << "1";
	      printed = 1;
	    }
	}
      if (printed == 0)
	std::cout << "0";
      if (i < ((int)files.size() - 1))
	std::cout << " ";
      i = i + 1;
    }  
}

int					checkDepend(std::vector<std::string> &files, std::vector<Depend> &depends, std::string name)
{
  std::vector<Depend>::iterator		it;
  Depend				tmp;

  for (it = depends.begin(); it != depends.end(); it++)
    {
      tmp = *it;
      if ((name.compare(tmp.getName())) == 0)
	{
	  checkFiles(files, tmp.getFiles());
	  return (0);
	}
    }
  printZeros(files);
  return (0);
}

void					printMatrix(std::vector<std::string> &files, std::vector<Depend> &depends)
{
  std::vector<std::string>::iterator	it;
  std::string				tmp;

  for (it = files.begin(); it != files.end(); it++)
    {
      tmp = *it;
      std::cout << "[";
      checkDepend(files, depends, tmp);
      std::cout << "]" << std::endl;
    }
}

void                                    createMatrix(Parser &parser, std::vector<std::string> files)
{
  std::vector<Depend>                   depends;

  depends = parser.getDepends();
  printMatrix(files, depends);
}
