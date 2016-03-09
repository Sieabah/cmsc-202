
#include "List.h"
#include <iostream>

using namespace std;

Node::Node(int data)
   : m_data(data)
{
   next = NULL;
}

List::List()
   : m_head(new Node(0))
{ /* No code */ }

List::List(const List &rhs)
   : m_head(new Node(0))
{
   // Assign RHS into this List
   (*this) = rhs;
}

List::~List()
{
   clear();

   delete m_head;
}

const List& List::operator=(const List &rhs)
{
   // check for self-assignment
   if(this == &rhs) return *this;

   // we are going to be overwriting, so delete our old stuff
   clear();
 
   Node* rhs_current = rhs.m_head;
   Node* current = m_head;

   while(rhs_current->next != NULL) {
      current->next = new Node(rhs_current->next->m_data);

      current = current->next;
      rhs_current = rhs_current->next;
   }

   return *this;
}

void List::insert(int data)
{
   Node* current = m_head;

   // traverse linked list
   while(current->next != NULL) {
      if(current->next->m_data > data) {
         // found place to insert
 
         // insert a new node inbetween current and
         // the current current->next
         // now:   [CURRENT] -> [CURRENT NEXT]
         // after: [CURRENT] -> [NEW NODE] -> [OLD CURRENT NEXT]
         // PUT CODE HERE:
	
	//Create node
         Node* nud = new Node(data);
	 //Link to next node
         nud->next = current->next;
	 //link current node to new node
         current->next = nud;         

         // exit the function
         return;
      }

      current = current->next;
   }

   // insert at the end of the list
   // this will only get here if the node is the last one to insert
   current->next = new Node(data);
}

bool List::remove(int data)
{
   Node* current = m_head;

   // traverse the linked list and find the element
   while(current->next != NULL) {
      if(current->next->m_data == data) {
         // found place to delete

         // delete current's next and reassign current's next
         // now:   [CURRENT] -> [CURRENT NEXT] -> [CURRENT NEXT NEXT]
         // after: [CURRENT] -> [OLD CURRENT NEXT NEXT]
         // PUT CODE HERE:

	//Get pointer to next node
         Node* nud = current->next;
	 //Make the current node equal to the next next node
         current->next = current->next->next;
	 
	 //delete node and make null
         delete nud;
	 nud = NULL;

         // exit the function
         return true;
      }

      current = current->next;
   }

   return false;
}

void List::Print() const
{
   Node* current = m_head;

   while(current->next != NULL) {
      cout << current->next->m_data << ' ';
      current = current->next;
   }
}

void List::clear()
{
   // it's empty already!
   if(m_head->next == NULL) return;

   Node* previous = m_head->next;
   Node* current = m_head->next->next;

   m_head->next = NULL;

   while(current != NULL) {
      delete previous;

      previous = current;

      current = current->next;
   }
}

unsigned int List::size() const
{
   // traverse linked list with a while loop and count the number of
   // elements.
   // PUT CODE HERE:
  //EMPTY
   if(m_head->next == NULL)
   {
      return 0;
   }

   //Get pointer and setup counter
   Node* node = m_head->next;
   unsigned int count = 0;
   do{
     //increment
      count++;
      //go to next node
      node = node->next;

      //test to see if the new node is null
   } while(node != NULL);

   //if it's null return current count
   return count;

   // REPLACE ZERO WITH CORRECT NUMBER:
   //return 0;
}

void List::ReversePrint() const
{
   // *extra credit*
   // does the same thing as Print(), but prints backwards;
   // PUT CODE HERE:
  
  //For all elements in the size
   for (unsigned int i = 0; i < size(); i++)
   {
     //Get pointer to starting node
      Node* nud = m_head->next;
      //Go down the linked list until the element is reached
      for(unsigned int j = size()-(i+1); j > 0; j--)
      {
	//return the node
         nud = nud->next;
      }
      //print the node data
      cout << nud->m_data << " ";
   }
   /*

     stack<int> printStack;
     Node *current = m_head;

    */
}
