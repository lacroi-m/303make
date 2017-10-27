//
// Exception.cpp for  in /home/kopiz/Workplace/MATHS/303make/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Oct 27 14:31:02 2017 Tom Jeammet
// Last update Fri Oct 27 14:31:06 2017 Tom Jeammet
//

#include "Exception.hpp"

//Ctor
Err::Err(std::string msg)
{
  this->set_msg(msg);
}

//Dtor
Err::~Err(void) throw ()
{
  
}

//Setter
void					Err::set_msg(std::string msg)
{
  this->_msg = msg;
}

//Getter
std::string				Err::get_msg(void)
{
  return (this->_msg);
}

//Member
void					Err::print_msg(void)
{
  if (this->_msg != "")
    std::cerr << this->_msg << std::endl;
}
