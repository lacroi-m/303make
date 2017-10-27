//
// Depend.hpp for  in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 13:42:44 2017 Tom Jeammet
// Last update Fri Oct 27 15:01:41 2017 Tom Jeammet
//

#ifndef __DEPEND_HPP__
# define __DEPEND_HPP__

# include <vector>
# include <string>

class				Depend
{
private:
  std::string                   name;
  std::vector<std::string>	files;

public:
  //Ctor
  Depend(void);
  //Dtor
  ~Depend(void);
  //Member
  //Getter
  std::string                   getName(void);
  std::vector<std::string>      getFiles(void);
  //Setter
  void                          setName(std::string &);
  void                          setFiles(std::vector<std::string> &);
};

#endif /* ! __DEPEND_HPP__ */
