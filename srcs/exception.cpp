#include "exception.hpp"

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
