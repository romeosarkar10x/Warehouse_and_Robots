#include "../sources/timestamp.cpp"


int main()
{
  srand(static_cast<u_int>(time(nullptr)) + clock());
  for(int i = 0; i < 100; i++)
  {
    auto t = new Timestamp;
    std::cout << (*t).to_string() << " " << (*t + 100).to_string() << std::endl;
    delete t;
  }
  return 0;
}