# Tree Data Structure Implementation

## Project Description

This project implements a generic tree data structure in C++. The implementation supports a wide variety of data types and offers multiple tree traversal methods. Additionally, the project includes tree visualization capability using the SFML library.

## Key Features

1. **Genericity**: The tree can contain any data type, including complex numbers.
2. **Multiple Traversals**: 
   - Pre-order
   - Post-order
   - In-order
   - Breadth-First Search (BFS)
   - Depth-First Search (DFS)
   - Heap-based traversal for binary trees
3. **Flexibility**: Support for trees with varying numbers of children per node.
4. **Visualization**: Graphical representation of the tree using SFML.
5. **Iterators**: Implementation of iterators for all traversal types, allowing convenient use in loops and standard C++ functions.

## Project Structure

- `Node.hpp`: Defines the `Node` class representing a node in the tree.
- `tree.hpp`: Implements the `Tree` class with all traversal methods and additional functionality.
- `Complex.hpp`: Defines a class for complex numbers.
- `main.cpp`: Demonstrates usage of the tree implementation.
- `Test.cpp`: Contains unit tests using Doctest.

## Usage

Here's a basic example of creating a tree and traversing it:

```cpp
#include "Node.hpp"
#include "tree.hpp"

int main() {
    Node<int> root_node(1);
    Tree<int> tree;
    tree.add_root(root_node);
    
    Node<int> child1(2);
    Node<int> child2(3);
    
    tree.add_child_node(root_node, child1);
    tree.add_child_node(root_node, child2);
    
    // Traverse the tree in pre-order
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        std::cout << it->get_value() << " ";
    }
    
    return 0;
}

Advantages of the Implementation

Flexibility: The tree can be used with any data type, including custom types.
Efficiency: The implementation allows for efficient traversal of the tree using various methods.
Ease of Use: The iterators allow for easy and intuitive use of the tree.
Visualization: The ability to display the tree graphically aids in understanding and debugging.

Potential Applications

Hierarchical data structures
Decision trees in machine learning algorithms
Syntax analysis in natural language processing
File system directory structure
Representation of organizational structures

Summary
This project provides a flexible and efficient implementation of a tree data structure, with support for a wide range of operations and uses. It is suitable for use in a variety of applications and provides a solid foundation for extension and adaptation to specific needs.
