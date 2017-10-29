//
// Compile.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Sun Oct 29 15:33:33 2017 Tom Jeammet
// Last update Sun Oct 29 16:41:56 2017 Tom Jeammet
//

#include "Compile.hpp"

void					print_exeLine(std::vector<Depend> depends, std::string exe)
{
  std::vector<Depend>::iterator         it;
  Depend				dp;

  for (it = depends.begin(); it != depends.end(); it++)
    {
      dp = *it;
      if ((exe.compare(dp.getName())) == 0)
	std::cout << dp.getLine() << std::endl;
    }
}

bool					is_in_files(std::vector<std::string> files, std::string file)
{
  std::vector<std::string>::iterator	it;
  std::string				tmp;

  for (it = files.begin(); it != files.end(); it++)
    {
      tmp = *it;
      if ((tmp.compare(file)) == 0)
	return (true);
    }
  return (false);
}

void					printCompiles(Parser parser, std::string file)
{
  std::vector<Depend>::iterator		it;
  std::vector<Depend>			depends;
  std::string				compile;
  std::string				exe;
  Depend				dp;

  if ((file.compare(parser.getExe())) != 0)
    {
      depends = parser.getDepends();
      for (it = depends.begin(); it != depends.end(); it++)
	{
	  dp = *it;
	  if (is_in_files(dp.getFiles(), file))
	    {
	      exe = parser.getExe();
	      if ((exe.compare(dp.getName())) != 0)
		{
		  std::cout << dp.getLine() << std::endl;
		  printCompiles(parser, dp.getName());
		}
	    }
	}
    }
}
