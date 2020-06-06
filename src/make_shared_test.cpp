#include <iostream>
#include <memory>
#include <type_traits>

struct C
{
  C(int i) : i(i) {} //< constructor needed (until C++20)
  int i;
};

int main()
{
    auto sp = std::make_shared<C>(12);

    std::cout << sp->i << '\n';
}