#include<iostream>
#include"adjlist.h"

using namespace std;

Node::Node():city(-1),next(NULL)
{
  
}//Node Constructor

Node::Node(int n):city(n),next(NULL)
{
  
}//Node Alternate Constructor

Node::~Node()
{
  
}//Node Destructor


int Node::retCity()
{
  return city;
}


void Node::printNode(Node *n)
{
  if(n->next != NULL)
  {  
    cout<<n->city<<" ->";
    printNode(n->next);
  }
  else
    cout<<n->city;
}


List::List():head(NULL)
{
  
}//List Constructor

List::~List()
{
  
}//List Destructor


void List::insert(int num)
{
  Node *n;
  if(head == NULL)
    head = new Node(num);
  else
  {
    for(n = head; n->next != NULL; n = n->next);
    n->next = new Node(num);
  }
}



int List::retNext(bool visited[])
{
  Node *n = head;
  while(visited[n->retCity()] == true)
  {
    if(n->next == NULL)
    {
      return -1;
    }  
    
    n = n->next;
    
  }
  
  return n->retCity();
}


void List::printList()
{
  head->printNode(head);
  cout<<endl;
}

