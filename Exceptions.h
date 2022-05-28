#include <exception>
#include <string>
#include "DirectConnection.h"
#include "enums.h"
#include "City.h"
struct MyException : public std::exception
{
   std::string msg;
   MyException(std::string m) : msg(m) {}
//    ~MyException() throw () {} // Updated
   const char* what() const throw() { return msg.c_str(); }
};

struct dcAlreadyAddedError : public std::exception
{
   std::string msg;
   unsigned int dcnt_id;

   dcAlreadyAddedError(std::string m,unsigned int id) : msg(m), dcnt_id(id){}
   dcAlreadyAddedError(std::string m) : msg(m){}
   const char* what() const throw() { return msg.c_str(); }
   unsigned int what_direct_connection_id()const{return dcnt_id;}

};

struct StationTypeError : public std::exception
{
   std::string msg;
   std::string passed_type;
   StationTypeError(std::string m, std::string pt):msg(m), passed_type(pt){}
      StationTypeError(std::string m):msg(m){}
   const char* what() const throw() { return msg.c_str(); }
   std::string what_passed_type() const {return passed_type;}


};

struct CityNotFoundException : public std::exception
{
   std::string msg;
   City passed_city;
   CityNotFoundException(std::string m,City const& ct):msg(m), passed_city(ct){}
   CityNotFoundException(std::string m):msg(m){}
   const char* what() const throw() { return msg.c_str(); }
   City what_passed_city() const {return passed_city;}
};

struct DCNotFoundException : public std::exception
{
   std::string msg;
   City CA;
   City CB;
  DCNotFoundException(std::string m):msg(m){}
  DCNotFoundException(std::string m, City const& CtA, City const& CtB):msg(m), CA(CtA), CB(CtB){}
   const char* what() const throw() { return msg.c_str(); }
   City what_PlaceA() const{return CA;}
   City what_PlaceB() const{return CB;}
};