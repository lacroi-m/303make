//
// Depend.hpp for  in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 13:42:44 2017 Tom Jeammet
// Last update Sun Oct 29 15:56:56 2017 Tom Jeammet
//

#ifndef __DEPEND_HPP__
# define __DEPEND_HPP__

# include <vector>
# include <string>
# include <sstream>

class				Depend
{
private:
  std::string                   name;
  std::vector<std::string>	files;
  std::vector<std::string>	lines;

public:
  //Ctor
  Depend(void);
  //Dtor
  ~Depend(void);
  //Member
  void				add_files(std::string);
  void				add_line(std::string);
  std::string			getLine(void);
  //Getter
  std::string                   getName(void);
  std::vector<std::string>      getFiles(void);
  std::vector<std::string>	getLines(void);
  //Setter
  void                          setName(std::string &);
  void                          setFiles(std::vector<std::string> &);
  void				setLines(std::vector<std::string> &);
};

#endif /* ! __DEPEND_HPP__ */
