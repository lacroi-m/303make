//
// Parser.hpp for  in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Oct 26 14:38:46 2017 Tom Jeammet
// Last update Sat Oct 28 15:24:50 2017 Tom Jeammet
//

#ifndef __PARSER_HPP__
# define __PARSER_HPP__

# include <string>
# include <vector>
# include <sstream>
# include <algorithm>

# include "Depend.hpp"

class					Parser
{
private:
  std::vector<std::string>		lines;
  std::vector<std::string>		files;
  std::vector<Depend>			depends;
  std::string				exe;

public:
  //Ctor
  Parser(void);
  //Dtor
  ~Parser(void);
  //Member
  void					sortDepends(void);
  void					completeFiles(void);
  bool					isInVector(std::vector<std::string> &, std::string &);
  void					parseLine(std::string &, int);
  void					parse(std::vector<std::string>);
  //Getter
  std::vector<std::string>		getLines(void);
  std::vector<std::string>		getFiles(void);
  std::vector<Depend>			getDepends(void);
  std::string				getExe(void);
  //Setter
  void					setLines(std::vector<std::string> &);
  void					setFiles(std::vector<std::string> &);
  void					setDepends(std::vector<Depend> &);
  void					setExe(std::string &);
};

#endif /* ! __PARSER_HPP__ */
