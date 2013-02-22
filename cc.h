/* 
 * File:   cc.h
 * Author: mauro
 *
 * Created on November 9, 2012, 9:02 AM
 */

#ifndef CC_H
#define	CC_H
#include"edges.h"
#include"stack.h"

class CC
{
public:
  int *CC_cities;
  int sizeCC_cities;
  Road *CC_roads;
  int sizeCC_roads;
public:
  CC();
  CC(int i);
  CC(Stack<int> * region,Road *roads[],int sizeRoads);
  ~CC();
  Road* getRoad(int x);
  int getCity(int x);
  void heapSort();
  void adjust(int root);
  void swap(int i, int j);
  void CC_print();
};

#endif	/* CC_H */

