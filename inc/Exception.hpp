//
// Exception.hpp for $ in /home/kopiz/Workplace/MATHS/303make/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 14:27:11 2017 Tom Jeammet
// Last update Fri Oct 27 14:27:15 2017 Tom Jeammet
//

#ifndef __EXCEPTION_HPP__
# define __EXCEPTION_HPP__

# include <iostream>
# include <string>
# include <exception>

class					Err : public std::exception
{
private:
  std::string				_msg;

public:
  //Ctor
  Err(std::string);
  //Dtor
  ~Err(void) throw ();
  //Member
  void					print_msg(void);
  //Setter
  void					set_msg(std::string);
  //Getter
  std::string				get_msg(void);
};

#endif /* ! __EXCEPTION_HPP__ */
