#include <vector>
#include <iostream>
#include <exception>
#include "myexe.cpp"

using namespace std;

template <class T>
class IntStack
{
public:
  // MaxSize should be an unsigned int, but for the sake of example...
  IntStack(int MaxSize) throw(InvalidSize)
  {
    if(MaxSize < 0)
      throw InvalidSize("Cannot create a negative size stack");

    data.resize(MaxSize);
    cur_index = 0;
			
  }

  void push(T new_data) throw(eFullStack)
  {
    if(cur_index == data.size())
      throw eFullStack("Push to full stack");

    data.at(cur_index) = new_data;
    cur_index++;
  } 

  T pop() throw(eEmptyStack)
  {

    if(cur_index == 0)
      throw eEmptyStack("Pop from empty stack");

    cur_index--;
    return data.at(cur_index);

  }

private:
  vector<T> data;
  unsigned int cur_index;
};

int main()
{
  cout << "c_test\n";
  try
    {
      // Testing Constructor
      IntStack<int> c_test(-10);
	
      c_test.push(3);
      c_test.push(4);
      c_test.pop();
      c_test.pop();
    }
  catch (InvalidSize& e)
    {
      e.GetMessage();
    }
  cout << "\nPush_test\n";
	
	
  // Testing push
  try
    {
      IntStack<int> push_test(5);
	
      for(unsigned int i = 0; i < 7; i++) {
	push_test.push(i);
      }
    }
  catch(eFullStack& e)
    {
      e.GetMessage();
    }
	
  cout << "\nPop_test\n";
  // Testing pop
	
  try
    {
      IntStack<int> pop_test(2);
	
      pop_test.push(1);
      pop_test.push(2);
      pop_test.pop();
      pop_test.pop();
      pop_test.pop();
    }
  catch(eEmptyStack& e)
    {
      e.GetMessage();
    }
  cout << "\nExtraCredit\n";
  //  Extra Credit
  //*
  IntStack<char> x(3);
  x.push('c');
  x.pop();
  //*/
	
  cout << "\nCompleted!" << endl;
}
