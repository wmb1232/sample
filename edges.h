/* 
 * File:   region.h
 * Author: wbaron
 *
 * Created on October 30, 2012, 5:24 PM
 */

#ifndef REGION_H
#define	REGION_H
#include<string>
#include<iostream>
#include"nodes.h"
using namespace std;

class Road
{
private:
    int city1;
    int city2;
    int lenght;
    bool visited;
public:
  Road();
    Road(int c1, int c2, int l);
    ~Road();
    void print();
    void retCity1(int* c1, int* c2);
    int getCity1();
    int getCity2();
    int getWeight();
    bool visit();
    void mark(bool v);
//    bool isEmpty();
    int min();
    int max();
    
    
    Road& operator =(Road &road);
    
    friend istream & operator >>(istream & is, Road & r);
    friend ostream & operator <<(ostream & os, Road & r);
        
};


#endif	/* REGION_H */

