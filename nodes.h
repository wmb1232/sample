/* 
 * File:   nodes.h
 * Author: mauro
 *
 * Created on November 4, 2012, 10:59 PM
 */

#ifndef NODES_H
#define	NODES_H

#include<iostream>
using namespace std;


class City
{
  public:
    int number;
    City();
    City(int num);  
    ~City();
    void print();
    friend ostream & operator <<(ostream & os, City & r);
};

#endif	/* NODES_H */

