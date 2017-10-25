//
// main.cpp for  in /home/ze/303make
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Oct 23 16:10:47 2017 ze
// Last update Wed Oct 25 16:29:29 2017 ze
//

#include "Main.hpp"

void	launchit(std::fstream &makefile, std::vector<std::string > &files)
{
  std::vector<std::string>	lines;
  std::string			tmp;

  if (files.empty())
    std::cout << "There are no extra files to check" << std::endl;
  
  while (std::getline(makefile, tmp))
    lines.push_back(tmp);
}

void	check_file(int ac, char **av)
{
  std::fstream			makefile;
  std::fstream			test;
  std::vector<std::string>	files;

  if (ac == 1)
    throw (Err("Usage:\n\t./303make Makefile [file1] [file2] [...]"));
  makefile.open(av[1]);
  if (makefile.fail())
    throw (Err("File must exist !"));
  if (ac > 2)
    for (int	i = 2; i < ac; i++){
      test.open(av[i]);
      if (test.fail())
	throw (Err("File " + (std::string)av[i] + " doesnt exist !"));
      files.push_back(av[i]);}
  launchit(makefile, files);
}

int main(int ac, char **av)
{
    try {
      check_file(ac, av);
    }
    catch (Err &err)
      {
	err.print_msg();
	return (84);
      }
    return (0);
}
