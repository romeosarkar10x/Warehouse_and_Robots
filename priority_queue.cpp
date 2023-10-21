#include <iostream>
#include <queue>
#include <ctime>

typedef unsigned int u_int;
class MyClass
{

public:
  MyClass() : xyz(rand()) { }
  class compare
  {
  public:
    bool operator()(MyClass ca, MyClass cb)
    {
      return ca.xyz > cb.xyz;
    }
  };
  
private:
  friend std::ostream& operator<<(std::ostream& _o, MyClass _object);
  u_int xyz;
};

std::ostream& operator<<(std::ostream& _o, MyClass _object)
{
  _o << "[" << _object.xyz << "]";
  return _o;
}

int main()
{
  srand(time(nullptr) + clock());

  std::priority_queue<MyClass, std::vector<MyClass>, MyClass::compare> q;
  for(u_int u = 0; u < 10; u++)
  {
    q.push(MyClass());
  }

  while(!q.empty())
  {
    std::cout << q.top() << " ";
    q.pop();
  }


  return 0;
}