//
// Main.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 14:26:00 2017 Tom Jeammet
// Last update Sun Oct 29 16:54:01 2017 Tom Jeammet
//

#include "Main.hpp"

int					launch(std::fstream &makefile, std::string file, int ac)
{
  std::vector<std::string>		lines;
  std::string				tmp;
  Parser				parser;

  while (std::getline(makefile, tmp))
    lines.push_back(tmp);
  parser.parse(lines);
  if (ac == 2)
    {
      createMatrix(parser, parser.getFiles());
      std::cout << std::endl;
      printRelations(parser.getFiles(), parser.getDepends(), parser.getExe());
    }
  else
    {
      if (!is_in_files(parser.getFiles(), file))
	return (84);
      else
	{
	  printCompiles(parser, file);
	  if (file.compare(parser.getExe()) == 0)
	    std::cout << std::endl;
	  else
	    print_exeLine(parser.getDepends(), parser.getExe());
	}
    }
  return (0);
}

int					checks(int ac, char **av)
{
  std::vector<std::string>		lines;
  std::fstream				makefile;
  std::fstream				test;
  int					ret;

  if (ac < 2)
    throw (Err("Usage:\n\t./303make Makefile [file]"));
  makefile.open(av[1]);
  if (makefile.fail())
    throw (Err("Error: no such file"));
  if (ac != 2 && ac != 3)
    throw (Err("Usage:\n\t./303make Makefile [file]"));
  else
    {
      if (ac == 2)
	launch(makefile, "", ac);
      if (ac == 3)
	{
	  test.open(av[2]);
	  if ((ret = launch(makefile, av[2], ac)) == 84)
	    return (ret);
	}
    }
  return (0);
}

int					main(int ac, char **av)
{
  int					ret;
  
    try
      {
	if ((ret = checks(ac, av)) == 84)
	  return (84);
      }
    catch (Err &err)
      {
	err.print_msg();
	return (84);
      }
    return (0);
}
