/* 
 * File:   adjlist.h
 * Author: mauro
 *
 * Created on November 8, 2012, 2:52 PM
 */

#ifndef ADJLIST_H
#define	ADJLIST_H

#include<iostream>
using namespace std;

class Node
{
private:
  int city;
  Node * next;
public:
  Node();
  Node(int n);
  ~Node();
  void printNode(Node * n);
  int retCity();
 
  friend class List;
  
};

class List
{
public:
  Node *head;
public:
  List();
  ~List();
  void insert(int num);
  void printList();
  int retNext(bool visited[]);
 
};

#include"adjlist.cpp"

#endif	/* ADJLIST_H */

