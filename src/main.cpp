/**
 * @file main.cpp
 * @author Ishan Grover
 * @brief Generic Linked List main() function.
 * 
 * Generic Linked List --> A Linked Lists which can store data of any data type.
 * Eg-: [1,2,3,4,5] or ['a','b','c','d']
 */

#include "Generic_linked_list.h"

/**
 * @brief main() function. \n
 * Testing is done using **assert()** to check all LinkedList
 * functions & operations . If not working properly then error message
 * displayed.
 *
 * @note assert( @a condition ) --> By using assert statements , we can verify
 * the certain conditions hold true or false.
 *              - If the condition is true, the program continues execution.
 *              - If the condition is false, the assert statement
 *                fails, and the program terminates with an error message.
 */
int main() {
  std::cout << std::endl;
  LinkedList<int> list;

// Testing through assert()
  #ifdef TESTS         // This is under the macro defined before as "TESTS". this is a whole block ... if macro definition is commented out then this whole block will be disabled.
    tests();
  #endif


  list.push_back(7);
  list.push_back(8);
  list.push_back(9);

// Displaying elements of LinkedList using Funcn Overloading.
  std::cout << std::endl << list <<std::endl;
  
}

/*things to add more
    Doxygen host on github
    multifile split
    Cmake
*/