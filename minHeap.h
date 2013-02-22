/* 
 * File:   minHeap.h
 * Author: mauro
 *
 * Created on November 5, 2012, 12:02 AM
 */

#ifndef MINHEAP_H
#define	MINHEAP_H
#include"edges.h"

class MinHeap
{
public:
  Road *regionRoads;
  int *regionCities;
  int numC;
  int size;  
  int lastPos;
  int ClastPos;
 
public:
  MinHeap(int numRoads, int numCities);
  void push(Road * r);
  void pushC(int c);
  Road& top();
  void pop();
  int min(int a, int b);
  int min(int i);
  void swap(Road &a, Road &b);
  void swapC(int a, int b);
  void mhPrint();
  int getSize();
  bool isEmpty();
  int minRoad(int a, int b);
  int maxRoad(int a, int b);
  void detectCycles(int sets[],int num);
  int cFind(int sets[], int num);
  int minSets(int sets[], int a, int b);
  void printSets(int sets[],int num);
};


#endif	/* MINHEAP_H */

