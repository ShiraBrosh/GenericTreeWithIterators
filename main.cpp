#include <iostream>
#include <string>
#include "Node.hpp"
#include "tree.hpp"
#include "Complex.hpp"

using namespace std;

int main() {
    // Example with double values
    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_child_node(root_node, n1);
    tree.add_child_node(root_node, n2);
    tree.add_child_node(n1, n3);
    tree.add_child_node(n1, n4);
    tree.add_child_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "Pre-order traversal (double):" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Post-order traversal (double):" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "In-order traversal (double):" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "BFS traversal (double):" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "Range-based for loop (BFS traversal, double):" << endl;
    for (auto node : tree) {
        cout << node.get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // Tree output using operator<<
    cout << "Tree output using operator<< (double):" << endl;
    cout << tree; // Should print the graph using GUI.

    Tree<double> three_ary_tree(3); // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_child_node(root_node, n1);
    three_ary_tree.add_child_node(root_node, n2);
    three_ary_tree.add_child_node(root_node, n3);
    three_ary_tree.add_child_node(n1, n4);
    three_ary_tree.add_child_node(n2, n5);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    cout << "Three-ary tree output (double):" << endl;
    cout << three_ary_tree;

    // Example with Complex values
    Node<Complex> complex_root_node(Complex(1.0, 1.0));
    Tree<Complex> complex_tree; // Binary tree that contains Complex numbers.
    complex_tree.add_root(complex_root_node);
    Node<Complex> cn1(Complex(2.0, 3.0));
    Node<Complex> cn2(Complex(3.0, 4.0));
    Node<Complex> cn3(Complex(4.0, 5.0));
    Node<Complex> cn4(Complex(5.0, 6.0));
    Node<Complex> cn5(Complex(6.0, 7.0));

    complex_tree.add_child_node(complex_root_node, cn1);
    complex_tree.add_child_node(complex_root_node, cn2);
    complex_tree.add_child_node(cn1, cn3);
    complex_tree.add_child_node(cn1, cn4);
    complex_tree.add_child_node(cn2, cn5);

    cout << "Pre-order traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node) {
        cout << node->get_value() << endl;
    }

    cout << "Post-order traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_post_order(); node != complex_tree.end_post_order(); ++node) {
        cout << node->get_value() << endl;
    }

    cout << "In-order traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
        cout << node->get_value() << endl;
    }

    cout << "BFS traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << endl;
    }

    cout << "Range-based for loop (BFS traversal, Complex):" << endl;
    for (auto node = complex_tree.begin(); node != complex_tree.end(); ++node) {
        cout << node->get_value() << endl;
    }

    cout << "Tree output using operator<< (Complex):" << endl;
    cout << complex_tree;

    Tree<Complex> three_ary_complex_tree(3); // 3-ary tree.
    three_ary_complex_tree.add_root(complex_root_node);
    three_ary_complex_tree.add_child_node(complex_root_node, cn1);
    three_ary_complex_tree.add_child_node(complex_root_node, cn2);
    three_ary_complex_tree.add_child_node(complex_root_node, cn3);
    three_ary_complex_tree.add_child_node(cn1, cn4);
    three_ary_complex_tree.add_child_node(cn2, cn5);

    cout << "Three-ary tree output (Complex):" << endl;
    cout << three_ary_complex_tree;

    return 0;
}
