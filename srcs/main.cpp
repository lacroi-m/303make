//
// main.cpp for  in /home/ze/303make
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Oct 23 16:10:47 2017 ze
// Last update Mon Oct 23 17:48:07 2017 ze
//

#include "Main.hpp"

int	print_err(std::string str)
{
  std::cerr << str << std::endl;
  return (84);
}

void	launch(std::ifstream file)
{
  (void)file;
  /*size_t x = 0;
    
  
    while (file)
    std::cout << file << std::endl; x++;
    std::cout << x << std::cout;*/
}


bool	check_file(std::string path)
{
  std::fstream	file;
  
  if (file.open(path))
    return (false);
  
  launch(file);
}

int main(int ac, char **av)
{
  if (ac == 1)
    return (print_err("Usage:\n./303make Makefile [file]..."));
  
  if (check_file == false)
    return (print_err("File must exist and be a Makefile"));
  return (0);
}
