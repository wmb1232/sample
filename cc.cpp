#include"edges.h"
#include "cc.h"
using namespace std;

CC::CC()
{
  
}

CC::CC(int i):CC_roads(NULL)
{
  CC_cities = new int[1];
  CC_cities[0] = i;
  sizeCC_cities = 1;
  sizeCC_roads = 0;
}

CC::CC(Stack<int> *region,Road *roads[],int sizeRoads):sizeCC_cities(region->size())
{
  CC_cities = new int[sizeCC_cities];
  CC_roads = new Road[sizeRoads];
  int count = 0;
  for(int i = 0; i < sizeCC_cities;i++)
  {
    CC_cities[i] = region->top();
    region->pop();
    for(int j = 0;j < sizeRoads;j++)
    {
      if((CC_cities[i] == roads[j]->getCity1()|| 
              CC_cities[i] == roads[j]->getCity2()) && 
              roads[j]->visit() == false)
      {
        CC_roads[count] = *roads[j];
        roads[j]->mark(true);
        count++;
      }
    }
  }
  sizeCC_roads = count;
  //heapSort();
  
}

CC::~CC()
{
  
}


void CC::heapSort()
{
  for(int i = sizeCC_roads/2;i >= 1;i++)
  {
    adjust(i);
  }
  for(int i = sizeCC_roads - 1; i >= 1; i--)
  {
    swap(0,i+1);
    adjust(0);
  }
}

void CC::adjust(int root)
{
  for(int i = sizeCC_roads; i != 0; i--)
  {
    //if(i % 2 == 0)
      
  }
}


Road* CC::getRoad(int x)
{
  return(&CC_roads[x]);
}

int CC::getCity(int x)
{
  return(CC_cities[x]);
}
/*
void CC::adjust(int root)
{
  Road e = CC_roads[root];
  int j;
  for(j = (2 *root);j <= sizeCC_roads; j= j*2)
  {
    if(j < sizeCC_roads && CC_roads[j].getWeight() < CC_roads[j+1].getWeight())
      j++;
    if(e.getWeight()>= CC_roads[j].getWeight())
      break;
    CC_roads[j/2] = CC_roads[j];
  }
  
  CC_roads[j/2] = e;
}

*/

void CC::swap(int i, int j)
{
  Road temp;
  temp = CC_roads[i];
  CC_roads[i] = CC_roads[j];
  CC_roads[j] = temp; 
}

void CC::CC_print()
{
  for(int i =0; i < sizeCC_cities; i++)
    cout<< CC_cities[i]<<", ";
  cout<<endl;
  for(int i = 0; i < sizeCC_roads; i++)
    CC_roads[i].print();
  cout<<endl;
}