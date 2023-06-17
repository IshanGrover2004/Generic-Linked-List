/**
 * @file Generic_linked_list.cpp
 * @author Ishan Grover
 * @brief Generic Linked List functions program.
 * 
 * Generic Linked List --> A Linked Lists which can store data of any data type.
 * Eg-: [1,2,3,4,5] or ['a','b','c','d']
 */

#include "Generic_linked_list.h"

/** **Logic-:**
   *    1. Make copy of head in current.
   *    2. Iterate until we reach last element which can be identified by @code
   *       {.cpp} current->next = nullptr @endcode
   *    3. Link the last node by new node & allots the element to it. \n  */
template <typename T> void LinkedList<T>::push_back(T element) noexcept {

  // if head is empty then data will be alloted in head Node.
  if (!head) 
    this->head = std::make_shared<Node<T>>(element);

  // if head is not empty then make a new node and link with the last element.
  else {
    auto current = this->head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = std::make_shared<Node<T>>(element);
  }
}

/** **Logic-:**
  *    1. Make newNode and assign data
  *    2. Point newNode to head
  *    3. Declare newNode as head \n    */
template <typename T> void LinkedList<T>::push_front(T element) noexcept {
  if (this->head == nullptr) {
    this->head = std::make_shared<Node<T>>(element);

  } else {
    auto new_node = std::make_shared<Node<T>>(element);      // Assign the value to new node
    new_node->next = this->head;       // new node gets address of head in its next
    this->head = new_node;
  }
}

/** **Logic-:**
  *    1. Make copy of head & make newNode and allocate data in it.
  *    2. Iterate until we reach "desired position".
  *    3. link the newNode to prevNode and link nextNode to newNode .
  *   @code {.cpp}
  *     auto temp = current->next;
  *     current->next = new_node;
  *     new_node->next = temp;
  *   @endcode
  *     */
template <typename T> void LinkedList<T>::insert(int position, T element) {

  if (position > this->size() + 1 || position <= 0)           // Case of invalid Position
    throw std::invalid_argument("Invalid Position in insert()");
  
  else if (position == 1) {
    auto new_node = std::make_shared<Node<T>>(element);
    new_node->next = this->head;
    this->head = new_node;
  
  } else if (position == this->size() + 1)      // Case where linked list size = 3 and position = 4 then add node at back.
    this->push_back(element);
  
  else {
    auto current = this->head;
    auto new_node = std::make_shared<Node<T>>(element);
    int count = 1;

    for (int i = 1; i <= position; i++) {
      if (count == position - 1) {
        auto temp = current->next;
        current->next = new_node;
        new_node->next = temp;
        break;
      }
      current = current->next;
      count++;
    }
  }
}

/** **Logic-:**
 *    1. Make head node copy in currentNode and make a prevNode.
 *    2. Iterate LinkedList till reach the **last node** & also update the
 *       prevNode,currentNode in each iteration.
 *    3. Unlink the prevNode & currentNode by @code {.cpp} prev->next = nullptr @endcode
 *    4. Delete currentNode. */
template <typename T> T LinkedList<T>::pop_back() {

  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to pop from back.");

  if (this->size() == 1) {
    auto rv = this->head;
    this->head = nullptr;     // We can't use "delete" keyword in smart pointers so declared this node nullptr.
    return rv->data;

  } else {
    std::shared_ptr<Node<T>> current = this->head;
    std::shared_ptr<Node<T>> prev = nullptr;

    while (current->next != nullptr) {
      prev = current;
      current = current->next;
    }
    auto rv = current->data;
    if (prev != nullptr)
      prev->next = nullptr;
    return rv;
  }
}

/** **Logic-:**
 *    1. Make head node copy in currentNode.
 *    2. Delete the head node and declare 2nd node as head.  */
template <typename T> T LinkedList<T>::pop_front() {
  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to pop from front.");

  if (head->next == nullptr) {
    auto rv = this->head->data;
    this->head = nullptr;         // Head deleted
    return rv;

  } else {
    std::shared_ptr<Node<T>> current = this->head->next;
    auto rv = this->head->data;
    this->head = nullptr;         // Head deleted
    this->head = current;
    return rv;
  }
}

/** **Logic-:**
  *    1. Make copy of head in prevNode and current as 2nd node.
  *    2. Iterate the linked list until reach element & update prevNode , currentNode.
  *    3. Delete the currentNode & link the prevNode and nextNode by @code {.cpp} prev->next = current->next @endcode*/
template <typename T> bool LinkedList<T>::remove(T element) noexcept {

  if (head == nullptr)
    return false;

  if (head->data == element) {
    std::shared_ptr<Node<T>> current = this->head->next;
    this->head = nullptr;         //Head deleted
    this->head = current;
    return true;

  } else {
    std::shared_ptr<Node<T>> prev = this->head;
    std::shared_ptr<Node<T>> current = this->head->next;

    while (current != nullptr) {
      if (current->data == element) {
        prev->next = current->next;
        current = nullptr;         // Current removed
        break;
      }
      prev = current;
      current = current->next;
    }
    return true;
  }
  return true;
}

/** **Logic-:**
  *    1. Make head copy in current.
  *    2. Iterate LinkedList till reach the desired @a position of Node.
  *    3. Get the @a data from Node.*/
template <typename T> T LinkedList<T>::get(int position) {
  std::shared_ptr<Node<T>> current = this->head;
  size_t count = 0;
  if ((position > this->size()) && (position <= 0))
    throw std::invalid_argument("Invalid Position in get()");

  while (current != nullptr) {
    count++;
    if (count == position) {
      return current->get_data();
    }
    current = current->next;
  }
  throw std::invalid_argument("Invalid Position in get()");
}

/** **Logic-:**
 *    1. Make current as copy of head.
 *    2. Iterate and each time increase value of count as well as update the
 *       node by nextNode by @code {.cpp} current = current->next @endcode
 *    3. When we reach last node then count is the size.  */
template <typename T> int LinkedList<T>::size() noexcept {
  auto current = this->head;
  size_t size = 0;

  if (head != nullptr) {
    while (current != nullptr) {
      size++;
      current = current->next;
    }
  }
  return size;
}

/** **Logic-:**
 *    1. Just check the @a head is NULL or not.*/
template <typename T> bool LinkedList<T>::is_empty() noexcept {
  return (head == nullptr);
}

/** **Logic-:**
 *    1. Traverse the Linked list and delete each node.*/
template <typename T> void LinkedList<T>::clear() {
  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to clear.");
  
  std::shared_ptr<Node<T>> current = this->head;
  std::shared_ptr<Node<T>> prev;
  while (current->next != nullptr) {
    prev = current;
    current = current->next;
    prev = nullptr;
  }
  this->head = nullptr;
  std::cout << "Successfully deleted all Nodes." << std::endl;
  
}

/** **Logic-:**
 *    1. Traverse the Linked list and print @a element.  */
template <typename T> void LinkedList<T>::display_all() noexcept {
  std::shared_ptr<Node<T>> current = this->head;

  if (head == nullptr) 
    std::cout << "Empty Linked List" << std::endl;

  size_t count = 0;
  while (current != nullptr) {
    count++;
    std::cout << "Element at Node " << count << " is: " << current->data
              << std::endl;
    current = current->next;
  }
}

void tests(){
  // Linked List declaration
  LinkedList<int> list; 

  //  is_empty()
  assert(list.is_empty() == true);
  std::cout << "Empty Linked List" << std::endl << std::endl;

  // push_back(element)
  list.push_back(2); // 1
  list.push_back(4); // 2
  list.push_back(6); // 3

  assert(list.get(1) == 2);
  assert(list.get(2) == 4);
  assert(list.get(3) == 6);
  std::cout << "Successfully executed: push_back()" << std::endl << std::endl;

  // push_front(element)
  list.push_front(1);
  list.push_front(3);

  assert(list.get(2) == 1);
  assert(list.get(1) == 3);
  std::cout << "Successfully executed: push_front()" << std::endl << std::endl;

  // insert(position,element)
  list.insert(1, 9);
  list.insert(3, 10);

  assert(list.get(1) == 9);
  assert(list.get(2) == 3);
  assert(list.get(3) == 10);
  assert(list.get(6) == 4);
  std::cout << "Successfully executed: insert()" << std::endl << std::endl;

  // pop_back() & pop_front()
  assert(list.pop_front() == 9);       // 2 elements removed
  assert(list.pop_back() == 6);
  std::cout << "Successfully executed: pop_back() & pop_front()" << std::endl << std::endl;

  // remove(element)
  list.remove(10);

  assert(list.get(2) == 1);
  std::cout << "Successfully executed: remove()" << std::endl << std::endl;

  list.display_all();

  // clear()
  list.clear();

  assert(list.is_empty() == true);
  std::cout << std::endl
            << "Successfully executed: clear()" << std::endl
            << std::endl;
  std::cout << "All tests successfully passed" << std::endl;
}

void errors(){
  LinkedList<int> list;
  try{
    list.insert(3,9);         // std::invalid_argument("Invalid Position")
    list.get(10);             // std::invalid_argument("Invalid Position")
    list.pop_back();          // std::underflow_error("List is empty")
    list.pop_front();         // std::underflow_error("List is empty")
    list.clear();             // std::underflow_error("List is empty")
  }
  catch(std::invalid_argument &invalidPosition){
    std::cerr << "Invalid Argument Error: " << invalidPosition.what() << std::endl;
  }
  catch(std::underflow_error &emptyList){
      std::cerr << "Underflow Error: " << emptyList.what() << std::endl;
  }
}
