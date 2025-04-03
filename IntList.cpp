#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


// Public

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &start)
{
   operator<<(out, start.head);
   return out;
}

bool IntList::exists(int val) const
{

   return exists(head, val);

}

// End of public


bool IntList::exists(IntNode *start, int val) const
{

   if(start == nullptr)
   {

      return false;

   }
   else
   {

      if(start->value == val)
      {
         return true;
      }
      else
      {
         return exists(start->next, val);
      }

   }

}

ostream & operator<<(ostream &out, IntNode *start)
{

   if(start == nullptr)
   {

      return out;

   }
   else
   {

      out << start->value;

      if(start->next != nullptr)
      {

         out << " ";

      }

      return operator<<(out, start->next);

   }

}