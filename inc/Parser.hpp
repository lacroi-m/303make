//
// Parser.hpp for  in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 14:38:46 2017 Tom Jeammet
// Last update Thu Oct 26 15:14:41 2017 Tom Jeammet
//

#include "Depend.hpp"

class					Parser
{
private:
  std::vector<std::string>		lines;
  std::vector<std::string>		files;
  std::string				exe;

public:
  //Ctor
  Parser(void);
  //Dtor
  ~Parser(void);
  //Member
  bool					isInVector(std::vector<std::string> &, std::string &);
  void					parseLine(std::string, int);
  void					parseit(std::vector<std::string> &);
  void					print_stab(std::vector<std::string>);
  //Getter
  std::vector<std::string>		getLines(void);
  std::vector<std::string>		getFiles(void);
  std::string				getExe(void);
  //Setter
  void					setLines(std::vector<std::string>);
  void					setFiles(std::vector<std::string>);
  void					setExe(std::string);
  
};
