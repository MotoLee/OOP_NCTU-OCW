// lab1-3-2.cpp

#include <iostream>
inline int Area(int x,int y) {return x*y;}

int main()
{
 double n = Area(3,5.1);
 std::cout << "Area(3,5.1) = " << n << std::endl;
 return 0;
}
