//
// exception.hpp for  in /home/jeamme_t/Workplace/abstractVM_2016/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Jul 20 22:09:00 2017 Tom Jeammet
// Last update Wed Sep 20 00:14:08 2017 Tom Jeammet
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
  //Setter
  void					set_msg(std::string);
  //Getter
  std::string				get_msg(void);
  //Member
  void					print_msg(void);
};

#endif /* ! __EXCEPTION_HPP__ */
