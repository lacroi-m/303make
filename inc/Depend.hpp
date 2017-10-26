//
// Depend.hpp for  in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 13:42:44 2017 Tom Jeammet
// Last update Thu Oct 26 15:08:31 2017 Tom Jeammet
//

#include "Main.hpp"

class				Depend
{
private:
  std::string                   name;
  std::vector<std::string>	lines;
  std::vector<std::string>      files;

public:
  //Ctor
  Depend(void);
  //Dtor
  ~Depend(void);
  //Member
  //Getter
  std::string                   getName(void);
  std::vector<std::string>      getLines(void);
  std::vector<std::string>      getFiles(void);
  //Setter
  void                          setName(std::string);
  void                          setLines(std::vector<std::string>);
  void                          setFiles(std::vector<std::string>);

};
