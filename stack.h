/* 
 * File:   stack.h
 * Author: mauro
 *
 * Created on November 7, 2012, 7:57 PM
 */

#ifndef STACK_H
#define	STACK_H


template <class T>
class Stack
{
private:
  T *stack;
  int capacity;
  int t;
public:
  Stack(int cap);
  ~Stack();
  int size()const;
  bool isEmpty()const;
  T& top()const;
  void push(const T& e);
  void pop();
  //friend void changeSizeArr(City& c,const int oldSize, const int newSize);
  //friend void copy(int *beg, int *end,City st[]);
};

#include"stack.cpp"

#endif	/* STACK_H */

