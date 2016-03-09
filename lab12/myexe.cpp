#include <iostream>
#include <exception>

using namespace std;

/*
  class NegativeStack: public exception
  {
  public:
  virtual const char* what() const throw()
  {
  return "Cannot create a negative size stack";
  }
  } NegStack;

  class FullStack: public exception
  {
  public:
  virtual const char* what() const throw()
  {
  return "Push to full stack";
  }
  } fullStack;

  class EmptyStack: public exception
  {
  public:
  virtual const char* what() const throw()
  {
  return "Pop from empty stack";
  }
  } emptyStack;
*/

class InvalidSize
{
public:
  InvalidSize(string str)
  {
    m_str = str;
  }
  void GetMessage()
  {
    cerr << m_str << endl;
  }
private:
  string m_str;
};

class eFullStack
{
public:
  eFullStack(string str)
  {
    m_str = str;
  }
  void GetMessage()
  {
    cerr << m_str << endl;
  }
private:
  string m_str;
};

class eEmptyStack
{
public:
  eEmptyStack(string str)
  {
    m_str = str;
  }
  void GetMessage()
  {
    cerr << m_str << endl;
  }
private:
  string m_str;
};
