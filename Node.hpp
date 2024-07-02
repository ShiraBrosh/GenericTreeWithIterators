//shira1d2631@gmail.com
//Shira Brosh - 211821137

#pragma once
#include <vector>

template <typename T>
class Node {
private:
    T value;
    std::vector<Node<T>*> children;

public:
    Node(const T& val) : value(val) {} // Constructor

    const T& get_value() const {
        return value;
    }

    void set_value(const T& val) {
        value = val;
    }

    void add_child(Node<T>* child) { // Add a child to the node
        children.push_back(child);
    }

    const std::vector<Node<T>*>& get_children() const { // Get the children of the node
        return children;
    }
};