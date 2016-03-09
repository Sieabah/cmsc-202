#include <iostream>
using namespace std;

class Wonky{
public:
  Wonky();
  const char Munge(const char letter) const;
  ~Wonky();
private:
  char *a_ptr;
};

int main(){
  Wonky *w;
  w = new Wonky;
  char num1 = 'A';
  endl(cout << w->Munge(num1));
  delete w;
  return 0;
}

Wonky::Wonky(){
  a_ptr = new char[0];
}

const char Wonky::Munge(const char letter) const
{
 a_ptr[0] = letter + 5;
 return a_ptr[0];
}

Wonky::~Wonky(){
  delete a_ptr;
  a_ptr = NULL;
}