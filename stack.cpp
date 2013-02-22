#include<iostream>
#include"stack.h"
using namespace std;

/*        
void changeSizeArr(City* c,const int oldSize,const int newSize)
{
  if(newSize < 0)
    cout<<"New length must be >=0"<<endl;
  Stack* temp =  new Stack(newSize);
  int number = oldSize;
  copy(c,c + number,temp);
  delete[] c;
  c = temp;
  
}

void copy(int *beg, int *end,City st[])
{
  int i = 0;
  while(beg != end)
  {
    *st[i] = beg;
    i++;
    beg++;
  }
  return;
}
*/

template <class T>
Stack<T>::Stack(int cap):stack(new T[cap]),capacity(cap),t(-1)
{
  if(capacity < 1)
  {
    //cout<<"Capacity must be > 0"<<endl;
    return;
  }
}

template <class T>
Stack<T>::~Stack()
{
  
}

template <class T>
bool Stack<T>::isEmpty() const
{
  
  return(t < 0);
}


template <class T>
void Stack<T>::pop()
{
  if(isEmpty())
  {
    cout<<"Stack is empty \n";
  }
  t--;
 
}


template <class T>
int Stack<T>::size() const
{
  return(t+1);
}


template <class T>
void Stack<T>::push(const T& e)
{
  if(size() == capacity)
  { 
    //changeSizeArr(stack, capacity, capacity * 2);
    //capacity *= 2;
    cout<<"push into full stack \n";
  }
  stack[++t] = e;
}



template <class T>
T& Stack<T>::top() const
{
  return stack[t];
}




