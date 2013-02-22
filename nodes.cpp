#include<iostream>
#include "nodes.h"
using namespace std;

City::City():number(-1)
{
  
}


City::City(int num)
{
  number = num;
}

City::~City()
{
  
}

ostream & operator<<(ostream& os,City &r)
{
  os<<r.number;
  return os;
}

void City::print()
{
  cout<<number;
}
        
