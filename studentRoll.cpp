#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Student* student = new Student(s.getName(), s.getPerm());
  
  if (!head) {
    head = new Node;
    head->s = student;
    head->next = nullptr;
    
    tail = head;
    return;
  }

  tail->next = new Node;
  tail->next->s = student;
  tail->next->next = nullptr;

  tail = tail->next;
}

std::string StudentRoll::toString() const {
  std::string res = "[";
  
  Node* curr = head;
  while (curr) {
    res += curr->s->toString();
    if (curr->next) res += ",";

    curr = curr->next;
  }

  return res + "]";
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  if (!orig.head && ! orig.tail) {
    head = tail = NULL;
  } else {
    Node* o_curr = orig.head;
    Student* s = new Student(o_curr->s->getName(), o_curr->s->getPerm());
    head = new Node;
    head->s = s;
    head->next = nullptr;

    if (!o_curr->next) tail = head;
    o_curr = o_curr->next;

    Node* curr = head;
    while (o_curr) {
      s = new Student(o_curr->s->getName(), o_curr->s->getPerm());
      curr->next = new Node;
      curr->next->s = s;
      curr->next->next = nullptr;

      curr = curr->next;
      o_curr = o_curr->next;
    }

    tail = curr;
  }   
}

StudentRoll::~StudentRoll() {
  Node* curr = head;
  while (curr) {
    delete curr->s;
    Node* temp = curr->next;
    delete curr;
    curr = temp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* curr = head;
  while (curr) {
    delete curr->s;
    Node* temp = curr->next;
    delete curr;
    curr = temp;
  }

  if (!right.head) {
    head = tail = nullptr;
    return (*this); 
  }

  Node* r_curr = right.head;
  Student* s = new Student(r_curr->s->getName(), r_curr->s->getPerm());
  head = new Node;
  head->s = s;
  head->next = nullptr;

  if (!r_curr->next) tail = head;
  r_curr = r_curr->next;

  curr = head;
  while (r_curr) {
    s = new Student(r_curr->s->getName(), r_curr->s->getPerm());
    curr->next = new Node;
    curr->next->s = s;
    curr->next->next = nullptr;

    curr = curr->next;
    r_curr = r_curr->next;
  }

  tail = curr;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
}





