//
// Main.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 14:26:00 2017 Tom Jeammet
// Last update Sat Oct 28 16:19:56 2017 Tom Jeammet
//

#include "Main.hpp"

void					launch(std::fstream &makefile, std::vector<std::string> &file)
{
  std::vector<std::string>		lines;
  std::string				tmp;
  Parser				parser;

  while (std::getline(makefile, tmp))
    lines.push_back(tmp);
  parser.parse(lines);
  if (file.empty())
    {
      createMatrix(parser, parser.getFiles());
      std::cout << std::endl;
      printRelations(parser.getFiles(), parser.getDepends(), parser.getExe());
    }
  else
    {
      
    }
}

void					checks(int ac, char **av)
{
  std::vector<std::string>		lines;
  std::fstream				makefile;
  std::fstream				test;
  int					i;

  if (ac < 2)
    throw (Err("Usage:\n\t./303make Makefile [file]"));
  makefile.open(av[1]);
  if (makefile.fail())
    throw (Err("Error: no such file"));
  if (ac != 2 && ac != 3)
    throw (Err("Usage:\n\t./303make Makefile [file]"));
  else
    {
      if (ac > 2)
	{
	  for (i = 2; i < ac; i++)
	    {
	      test.open(av[i]);
	      lines.push_back(av[i]);
	    }
	}
      launch(makefile, lines);
    }
}

int					main(int ac, char **av)
{
    try
      {
	checks(ac, av);
      }
    catch (Err &err)
      {
	err.print_msg();
	return (84);
      }
    return (0);
}
