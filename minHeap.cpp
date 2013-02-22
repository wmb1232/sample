#include<iostream>
#include<iomanip>
#include"minHeap.h"
#include "cc.h"


using namespace std;

 
MinHeap::MinHeap(int numRoads, int numCities)
:numC(numCities),size(numRoads),lastPos(0),ClastPos(0)
{
  regionRoads = new Road[numRoads];
  regionCities = new int[numCities];
}

void MinHeap::push(Road *r)
{
  regionRoads[lastPos] = *r;
  int i = (lastPos - 1) / 2;//parent
  int j = lastPos;//child
  if(lastPos != 0)
  {
   
    while(regionRoads[j].getWeight() <= regionRoads[i].getWeight())
    {
      if((regionRoads[j].getWeight() == regionRoads[i].getWeight())&&(j == min(j,i)))
      {
        swap(regionRoads[j],regionRoads[i]);
        j = i;
        i = (i - 1) / 2;
        if(regionRoads[j].getWeight() > regionRoads[i].getWeight())
          break;
        if((regionRoads[j].getWeight() == regionRoads[i].getWeight())&&(i == min(j,i)))
          break;
      }
      else if(regionRoads[j].getWeight() < regionRoads[i].getWeight())
      {
        swap(regionRoads[j],regionRoads[i]);
        j = i;
        i = (i - 1) / 2;
        if(regionRoads[j].getWeight() > regionRoads[i].getWeight())
          break;
        if((regionRoads[j].getWeight() == regionRoads[i].getWeight())&&(i == min(j,i)))
          break;
      }
      else
        break;
      
    }
  }
  lastPos++;
}


void MinHeap::pushC(int c)
{
  regionCities[ClastPos] = c;
  int i = (ClastPos - 1) / 2;//parent
  int j = ClastPos;//child
  if(ClastPos != 0)
  {
   
    while(regionCities[j] < regionCities[i])
    {
      swapC(j,i);
      j = i;
      i = (i - 1) / 2;
      if(regionCities[j] > regionCities[i])
        break;
    }
  }
  ClastPos++;
}


void MinHeap::pop()
{
  swap(regionRoads[0],regionRoads[lastPos-1]);
  lastPos--;
  int i = 0;//min parent
  int mini = min(i);// min child
  while((regionRoads[i].getWeight() >= regionRoads[mini].getWeight()))
  {
    if(i == mini)
      break;
    if((regionRoads[i].getWeight() == regionRoads[mini].getWeight())
            &&(mini == min(i,mini)))
     {   
          swap(regionRoads[i],regionRoads[mini]);
         i = mini;
         mini = min(mini);
         if(mini == -1)
          break;
         if(regionRoads[i].getWeight() < regionRoads[mini].getWeight())
          break;
     }
    else if((regionRoads[i].getWeight() == regionRoads[mini].getWeight())
            &&(i == min(i,mini)))
    {
      break;
    }
     else
     {
      swap(regionRoads[i],regionRoads[mini]);
      i = mini;
      mini = min(mini);
      if(mini == -1)
       break;
      if(regionRoads[i].getWeight() < regionRoads[mini].getWeight())
        break; 
     }
  }
  
          
}



Road& MinHeap::top()
{
  return regionRoads[0];
}


void MinHeap::swap(Road &a, Road &b)
{
  Road temp;
  temp = a;
  a = b;
  b = temp;
}

void MinHeap::swapC(int a, int b)
{
  int temp;
  temp = regionCities[a];
  regionCities[a] = regionCities[b];
  regionCities[b] = temp;
        
}

int MinHeap::min(int a, int b)
{
  int minx,miny,maxx,maxy;
  int x1 = regionRoads[a].getCity1();
  int x2 = regionRoads[a].getCity2();
  int y1 = regionRoads[b].getCity1();
  int y2 = regionRoads[b].getCity2();
  if(x1 < x2)
  {
    minx = x1;
    maxx = x2;
  }
  else
  {
    minx = x2;
    maxx = x1;
  }
  if(y1 < y2)
  {
    miny = y1;
    maxy = y2;
  }
  else
  {
    miny = y2;
    maxy = y1;
  }
  if(minx < miny)
    return a;
  else if(minx == miny)
  {
    if(maxx < maxy)
      return a;
    else
      return b;
  }
  else
    return b;
    
}

int MinHeap::min(int i)
{
  int a, b,last;
  a = ((2*i)+1);//Left Child
  b = ((2*i)+2);//Right Child
  last = lastPos -1;
  
      if((a > last && b > last))
        return -1;
      else if(b > last)
      {
        if(regionRoads[i].getWeight() < regionRoads[a].getWeight())
          return -1;
        else if(regionRoads[i].getWeight() > regionRoads[a].getWeight())
          return a;
        else if(regionRoads[i].getWeight() == regionRoads[a].getWeight())
          return minRoad(i,a);
      }
      else if(regionRoads[a].getWeight() < regionRoads[b].getWeight())
        return a;
      else if(regionRoads[a].getWeight() > regionRoads[b].getWeight())
        return b;
      else if(regionRoads[a].getWeight() == regionRoads[b].getWeight())
        return minRoad(a,b);
      else
        return -1;
}


void MinHeap::mhPrint()
{
  cout<<"-----------------start--------------------\n";
  cout<<"Cities: "<<endl;
  for(int i = 0; i < numC;i++)
  {
    cout<<regionCities[i]<<" ";
  }
  cout<<"Roads: "<<endl;
  for(int i = 0; i < size;i++)
  {
    regionRoads[i].print();
  }
  cout<<"-----------------end-------------------------\n";
}


int MinHeap::getSize()
{
  return size;
}

bool MinHeap::isEmpty()
{
  if(lastPos == 0)
    return true;
  else
    return false;
}


int MinHeap::minRoad(int a, int b)
{
  if(regionRoads[a].min() < regionRoads[b].min())
    return a;
  else if(regionRoads[a].min() == regionRoads[b].min())
    return maxRoad(a,b);
  else
    return b;
}

int MinHeap::maxRoad(int a, int b)
{
  if(regionRoads[a].max() < regionRoads[b].max())
    return a;
  else
    return b;
}


int MinHeap::cFind(int sets[], int num)
{
  int i;
  for(i = num; sets[i] >= 0; i = sets[i]);
  while(num != i)
  {
    int temp = sets[num];
    sets[num] = i;
    num = temp;
  }
  return i;
}

void MinHeap::detectCycles(int sets[], int num)
{
  int count = 0;
  while(count != (numC -1))
  {
    //cout<<"before----------------------------\n";
    //mhPrint();
    //printSets(sets,num);
   int temp,city_1,city_2;
   city_1 = top().getCity1();
   city_2 = top().getCity2();
   temp = sets[cFind(sets,city_1)] + sets[cFind(sets,city_2)];
   if(sets[cFind(sets,city_1)] > sets[cFind(sets,city_2)])
   {
     sets[city_1] = cFind(sets,city_2);
     sets[cFind(sets,city_2)] = temp;
     count++;
     top().print();
     pop();
   }
   else if(cFind(sets,city_1) == cFind(sets,city_2))
    {
      pop();
    }
   else
   {
     sets[city_2] = cFind(sets,city_1);
     sets[cFind(sets,city_1)] = temp;
     top().print();
     count++;
     pop();
   }
   //cout<<"after------------------------------------\n";
   //mhPrint();
   //printSets(sets,num);
   
  }
}

int MinHeap::minSets(int sets[], int a, int b)
{
  if(sets[a] < sets[b])
    return b;
  else
    return a;
}

void MinHeap::printSets(int sets[], int num)
{
  for(int i = 0; i < num;i++)
   {
      cout<<"|"<<setw(2)<<setfill('0')<<i<<"|";
   }
  cout<<endl;
  for(int i = 0; i < num;i++)
   {
    cout<<"|"<<setw(2)<<setfill('0')<<sets[i]<<"|";
   }
  cout<<endl;
}
