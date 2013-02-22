#include<iostream>
#include<string>
#include"edges.h"
#include"nodes.h"

using namespace std;

Road::Road()
{
  
}


Road::Road(int c1,int c2, int l)
{
  city1 = c1;
  city2 = c2;
  lenght = l;
  visited = false;
}

Road::~Road()
{
  
}

void Road::print()
{
   cout<<"<road>";
    cout<<city1<<" ";
    cout<<city2<<" ";
    cout<<lenght;
    cout<<"</road>\n";
}


void Road::retCity1(int* c1, int* c2)
{
  *c1 = city1;
  *c2 = city2;
}

int Road::getCity1()

{
  return city1;
}

int Road::getCity2()
{
  return city2;
}

int Road::getWeight()
{
  return lenght;
}

bool Road::visit()
{
  return visited;
}

void Road::mark(bool v)
{
  visited = v;
}


//bool Road::isEmpty()
//{
//  if(city1 == NULL)
//    return true;
//  else
//    return false;
//}


Road& Road::operator =(Road& road)
{
  city1 = road.getCity1();
  city2 = road.getCity2();
  lenght = road.getWeight();
  visited = road.visit();
  return road; 
}


int Road::min()
{
  if(city1 > city2)
    return city2;
  else
    return city1;
}

int Road::max()
{
  if(city1 > city2)
    return city1;
  else
    return city2;
}

//istream & operator >>(istream & is, Road & r)
//{
  
//  is>>r.city1;
//  is>>r.city2;
//  is>>r.lenght;
//  return is;
  
//}

