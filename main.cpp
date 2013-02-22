#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<fstream>
#include"edges.h"
#include"nodes.h"
#include"adjlist.h"
#include"stack.h"
#include"cc.h"
#include"minHeap.h"



void swapHeap(MinHeap *heap[],int a, int b)
{
  MinHeap *temp;
  temp = heap[a];
  heap[a] = heap[b];
  heap[b] = temp;
}

int minCity(MinHeap *heap[],int a, int b)
{
  if(heap[a]->regionCities[0] < heap[b]->regionCities[0])
    return a;
  else
    return b;
}

int min(MinHeap *heap[],int i, int *lastPos)
{
  int a, b,last;
  a = ((2*i)+1);//Left Child
  b = ((2*i)+2);//Right Child
  last = *lastPos - 1;
  if(a > last && b > last)
        return -1;
      else if(b > last)
      {
        //return a;
        if(heap[i]->numC < heap[a]->numC)
          return -1;
        else if(heap[i]->numC > heap[a]->numC)
          return a;
        else if(heap[i]->numC == heap[a]->numC)
          return minCity(heap,i,a);
      }  
      else if(heap[a]->numC < heap[b]->numC)
        return a;
      else if(heap[a]->numC > heap[b]->numC)
        return b;
      else if(heap[a]->numC == heap[b]->numC)
        return minCity(heap,a,b);
      else
        return -1;
}

void heapPop(MinHeap *heap[],int *lastPos)
{
  swapHeap(heap,0,*lastPos -1);
  *lastPos = *lastPos -1;
  int i = 0;
  int mini = min(heap,i,lastPos);
  while(mini != -1 && heap[i]->numC >= heap[mini]->numC)
  {
    if(i == mini)
      break;
    if((heap[i]->numC == heap[mini]->numC)) //&& (mini == minCity(heap,i, mini)))
    {
      swapHeap(heap,i,mini);
      i = mini;
      mini = min(heap,mini,lastPos);
      if(mini == -1)
        break;
      if(heap[i]->numC < heap[mini]->numC)
        break;   
    }
    else
    {
      swapHeap(heap,i,mini);
      i = mini;
      mini = min(heap,mini,lastPos);
      if(mini == -1)
        break;
      if(heap[i]->numC < heap[mini]->numC)
        break;   
    }
  }
}

void printVC(bool visitedCities[],int size)
{
  for(int i = 0;i<size;i++ )
  {
      cout<<i<<" - ";
  }
  cout<<endl;
  for(int i = 0;i<size;i++ )
  {
    if(visitedCities[i] == true)
      cout<<"T - ";
    else
      cout<<"F - ";
  }
  cout<<endl;
}

void fill(bool visitedCities[],int numCities)
{
  for(int i = 0; i < numCities;i++)
  {
    visitedCities[i] = false;
  }
}


void DFS(bool visitedCities[],int c,List adjacencyList[],
        Stack<int> *found, int *size, Stack<int> *region)
{
  if(visitedCities[c] == false)
  {
    visitedCities[c] = true;
    found->push(c);
  }
  else if(found->isEmpty())
  {
    int num;
    num = adjacencyList[c].retNext(visitedCities);
    if(num != -1)
      DFS(visitedCities,num,adjacencyList,found,size,region);
  }
  while(!found->isEmpty())
  { 
    int num;
    num = adjacencyList[c].retNext(visitedCities);
    if(num == -1)
    {
      int a;
      a = found->top();
      region->push(a);
      found->pop();
      DFS(visitedCities,a,adjacencyList,found,size,region);
    }
    else
    {
      DFS(visitedCities,num,adjacencyList,found,size,region);
    }
     
  }  
  *size = region->size();
}


using namespace std;

int main(int argc, char* argv[])
{
    int numCities ,numOldRoads,countCC = 0;
    //ifstream is;
    //is.open(argv[1]);
    //is>>numCities;
    //is>>numOldRoads;
    cin>>numCities;
    cin>>numOldRoads;
    int arr[numCities];
    Stack<int> s(numCities);
    //City *graph[numCities];
    Road *roads[numOldRoads];
   for(int i = 0; i < numCities;i++)
   {
      arr[i] = -1;
   }
    //cout<<endl;
    for(int i = 0; i < numOldRoads; i++)
    {
      int c1,c2,len;
      //is>>c1;
      //is>>c2;
      //is>>len;
      cin>>c1;
      cin>>c2;
      cin>>len;
      if(c1>c2)
        roads[i] = new Road(c2,c1,len);
      else
        roads[i] = new Road(c1,c2,len);
      //roads[i]->print();//check for correct input
    }
   
    List adjacencyList[numCities];
    
    for(int i = 0; i < numOldRoads;i++)
    {
      int c1,c2;
      roads[i]->retCity1(&c1,&c2);
      adjacencyList[c1].insert(c2);
      adjacencyList[c2].insert(c1);
    }
    
   CC *conectedComponents[numCities];
   bool visitedCities[numCities];
   int j = 0, i = 0,size;
   Stack<int> region(numCities);
   Stack<int> found(numCities);
   fill(visitedCities,numCities);
   while(j != numCities)
   {  
    //printVC(visitedCities,numCities);
    if(visitedCities[j] == false && adjacencyList[j].head != NULL) 
    {
      DFS(visitedCities,j,adjacencyList,&found,&size,&region);
      conectedComponents[i] = new CC(&region, roads,numOldRoads);
      countCC++;
      i++;
    }
    else if(adjacencyList[j].head == NULL)
    {
      conectedComponents[i] = new CC(j);
      visitedCities[j] = true;
      countCC++;
      i++;
    }
    j++;
   }
   
   MinHeap *heap[countCC];
   
   for(int i = 0; i< countCC;i++)
   {
     heap[i] = new MinHeap(conectedComponents[i]->sizeCC_roads,
             conectedComponents[i]->sizeCC_cities);
     //conectedComponents[i]->CC_print();
     //cout<<endl;
     for(int k = 0; k < conectedComponents[i]->sizeCC_cities; k++)
     {
       heap[i]->pushC(conectedComponents[i]->getCity(k));
     }
     for(int j = 0; j < conectedComponents[i]->sizeCC_roads; j++)
     {
       heap[i]->push(conectedComponents[i]->getRoad(j));
     }
     //cout<<endl;
   }
   
   MinHeap *sortedHeap[countCC];
   int LP = 0;
   int x,y;
   while(LP != countCC)
   { 
     x = (LP -1) / 2;//parent
     y = LP;//child
     sortedHeap[LP] = heap[LP];
     if(LP != 0)
     {
       while(sortedHeap[y]->numC < sortedHeap[x]->numC)
       {
         swapHeap(sortedHeap,y,x);
         y = x;
         x = (x - 1)/ 2;
         if(sortedHeap[y]->numC > sortedHeap[x]->numC)
           break;
       } 
     }
     LP++;  
   }
   

  fill(visitedCities,numCities);
  cout<<"<?xml version=\"1.3\"?>\n";
  cout<<"<country>\n";
  for(int i = 0; i < countCC;i++)
   {
      //cout<<"heap ---------------"<<endl;
      //sortedHeap[i]->mhPrint(); 
      cout<<"<region>\n";
      sortedHeap[0]->detectCycles(arr,numCities);
      heapPop(sortedHeap,&LP);
      cout<<"</region>\n";
   }
   cout<<"</country>\n";
   return 0;
    
   
}

