/**
 * @file Generic_linked_list.h
 * @author Ishan Grover
 * @brief Generic Linked List header file.
 * 
 * Generic Linked List --> A Linked Lists which can store data of any data type.
 * Eg-: [1,2,3,4,5] or ['a','b','c','d']
 */
// Created by Ishan Grover on 05-June-2023

#ifndef GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_H

#include <cassert>      // Header file for assert() function for making tests.
#include <iostream>
#include <memory>       // Header file for using smart pointers and access memory.
#include <ostream>

// Macro for making assert() statements "off" & "on" any time --> Just make this line comment
#define TESTS     /**< Macro to disable tests. */

/**
 * @class Node
 * @brief Making Node of Linked list.
 *
 * Node contains 2 things-:
 * a) data
 * b) next
 * @tparam T The type of data stored in the node.
 */
template <typename T> struct Node {
  T data;    /**< Data stored in a node. */
  std::shared_ptr<Node> next;   /**< next is a pointer pointing to the next Node of Linked list.\n
                                     We can access next Node using "this->next" */
  /**
   * @brief Default Constructor of Node class.
   */
  Node() = default;

  /**
   * @brief Parameterized Constructor taking "data" input to node
   *
   * @code {.cpp}
   * Node n = Node(3);
   * @endcode
   *
   * @param data The "data" value to be stored in the node.
   * @param next "next" is null pointer.
   */
  explicit Node(T data) {
    this->data = data;
    this->next = nullptr;
  }

public:
  T get_data() { return this->data; }     /**< To get @a data from Node*/
};

/**
 * @class LinkedList
 *
 * @brief Sequential data container using linked list.
 *
 * @tparam T The type of data stored.
 */
template <typename T> class LinkedList {
private:
  std::shared_ptr<Node<T>> head;  /**< head is the first Node of Linked list. */

public:
  /**
   * @brief Default Constructor.
   */
  LinkedList() = default;

  /**
   * @brief Constructor for storing data in head Node.
   *
   * @param data "data" is stored in head Node.
   */
  explicit LinkedList(T data) { this->head = std::make_shared<Node<T>>(data); }


// Operations or Function needed in linked list
  /**
   * @brief Adds a Node at **LAST** of linked list.\n
   *
   * @param element is data of any data type which we wanted to add in the LAST
   * node of linked list.
   */
  void push_back(T element) noexcept;
  
  /**
  * @brief Adds a Node at **STARTING** of linked list.
  * 
  * @param element is data of any data type which we wanted to add in the FIRST node of linked list.
  */
  void push_front(T element) noexcept;

  /**
  * @brief Adds a Node at **desired position** of linked list
  * 
  * @param position Location where we need to add the Node.
  * @param element is data of any data type which we wanted to add in any POSITION in linked list.
  * @attention Throw an Error message if @a position is incorrect.
  */
  void insert(int position, T element);

  /**
   * @brief Delete the last node.
   * 
   * @return data of deleted node
   * 
   * @attention Throw an Error message if Linked list is already empty.
   */
  T pop_back();

  /**
   * @brief Delete the **First** node.
   * 
   * @return data of deleted node
   * 
   * @attention Throw an Error message if Linked list is already empty.
   */
  T pop_front();

  /**
   * @brief Delete the node by searching @a data.
   * 
   * @param element is searched in LinkedList and the node contains this element
   * gets deleted.
   * @return true Data from linked list is removed.
   * @return false Data cannot be removed because of "Empty linked list".
   */
  bool remove(T element) noexcept;

  /**
   * @brief returns @a data of **Desired Node**.
   *
   * @param position Location of desired Node to get the data.
   * @return data of any Node.
   * 
   * @attention Throw an Error message if @a position is incorrect.
   */
  T get(int position);

  /**
   * @brief Returns the @a size of linked list
   *
   * @return @a size It return the size of Linked list or we can say number of
   * node linked together
   */
  int size() noexcept;

  /**
   * @brief Checks if the Linked list is empty or not.
   *
   * @return true When it contains one or more nodes in it.
   * @return false When the Linked list is empty.
   */
  bool is_empty() noexcept;

  /**
   * @brief Delete all the nodes in linked list.
   * 
   * @attention Throw an Error message if Linked list is already empty.
   */
  void clear();

  /**
   * @brief Display all elements of linked list.
   */
  void display_all() noexcept;

  /**
   * @brief Function Overloading of << .\n 
   * Function Overloading << to print whole linked list when applied cout and pass list to it.
   * @param os Output stream object
   * @param list Linked list to be printed.
   * @return std::ostream By returning output stream object, the function enables to make chain of additional output operations.
   */
  friend std::ostream& operator<<(std::ostream& os, const LinkedList& list){
    std::shared_ptr<Node<T>> node = list.head;
    while (node != nullptr) {
        os << node->data << " -> ";
        node = node->next;
    }
    os << "nullptr";
    return os;
  }
  
};

// Tests using assert() function
void tests();

// Invalid error messages
void errors();

#endif