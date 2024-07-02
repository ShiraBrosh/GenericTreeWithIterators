
//shira1d2631@gmail.com
//Shira Brosh - 211821137

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "tree.hpp"
#include "Complex.hpp"

TEST_CASE("Tree traversal with int") {
    Node<int> root_node(1);
    Tree<int> tree;
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_child_node(root_node, n1); // Add n1 as a child of root_node
    tree.add_child_node(root_node, n2); // Add n2 as a child of root_node
    tree.add_child_node(n1, n3); // Add n3 as a child of n1
    tree.add_child_node(n1, n4);
    tree.add_child_node(n2, n5);

    auto pre_order_it = tree.begin_pre_order(); // Create an iterator for pre-order traversal
    CHECK(pre_order_it->get_value() == 1); // Check the value of the current node
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == 2); // Check the value of the next node
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == 4);
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == 5);
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == 3);
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == 6);

    auto post_order_it = tree.begin_post_order(); // Create an iterator for post-order traversal
    CHECK(post_order_it->get_value() == 4);
    ++post_order_it;
    CHECK(post_order_it->get_value() == 5);
    ++post_order_it;
    CHECK(post_order_it->get_value() == 2);
    ++post_order_it;
    CHECK(post_order_it->get_value() == 6);
    ++post_order_it;
    CHECK(post_order_it->get_value() == 3);
    ++post_order_it;
    CHECK(post_order_it->get_value() == 1);

    auto in_order_it = tree.begin_in_order(); // Create an iterator for in-order traversal
    CHECK(in_order_it->get_value() == 4);
    ++in_order_it;
    CHECK(in_order_it->get_value() == 2);
    ++in_order_it;
    CHECK(in_order_it->get_value() == 5);
    ++in_order_it;
    CHECK(in_order_it->get_value() == 1);
    ++in_order_it;
    CHECK(in_order_it->get_value() == 6);
    ++in_order_it;
    CHECK(in_order_it->get_value() == 3);

    auto bfs_it = tree.begin_bfs_scan();
    CHECK(bfs_it->get_value() == 1);
    ++bfs_it;
    CHECK(bfs_it->get_value() == 2);
    ++bfs_it;
    CHECK(bfs_it->get_value() == 3);
    ++bfs_it;
    CHECK(bfs_it->get_value() == 4);
    ++bfs_it;
    CHECK(bfs_it->get_value() == 5);
    ++bfs_it;
    CHECK(bfs_it->get_value() == 6);
}

TEST_CASE("Tree traversal with Complex") {
    Node<Complex> root_node(Complex(1.0, 1.0)); // Create a node with a complex value
    Tree<Complex> tree; // Create a tree with complex values
    tree.add_root(root_node); // Add the root node to the tree
    Node<Complex> n1(Complex(2.0, 3.0));
    Node<Complex> n2(Complex(3.0, 4.0));
    Node<Complex> n3(Complex(4.0, 5.0));
    Node<Complex> n4(Complex(5.0, 6.0));
    Node<Complex> n5(Complex(6.0, 7.0));

    tree.add_child_node(root_node, n1);
    tree.add_child_node(root_node, n2);
    tree.add_child_node(n1, n3);
    tree.add_child_node(n1, n4);
    tree.add_child_node(n2, n5);

    auto pre_order_it = tree.begin_pre_order(); // Create an iterator for pre-order traversal
    CHECK(pre_order_it->get_value() == Complex(1.0, 1.0));
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == Complex(2.0, 3.0));
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == Complex(4.0, 5.0));
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == Complex(5.0, 6.0));
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == Complex(3.0, 4.0));
    ++pre_order_it;
    CHECK(pre_order_it->get_value() == Complex(6.0, 7.0));

    auto post_order_it = tree.begin_post_order(); // Create an iterator for post-order traversal
    CHECK(post_order_it->get_value() == Complex(4.0, 5.0));
    ++post_order_it;
    CHECK(post_order_it->get_value() == Complex(5.0, 6.0));
    ++post_order_it;
    CHECK(post_order_it->get_value() == Complex(2.0, 3.0));
    ++post_order_it;
    CHECK(post_order_it->get_value() == Complex(6.0, 7.0));
    ++post_order_it;
    CHECK(post_order_it->get_value() == Complex(3.0, 4.0));
    ++post_order_it;
    CHECK(post_order_it->get_value() == Complex(1.0, 1.0));

    auto in_order_it = tree.begin_in_order(); // Create an iterator for in-order traversal
    CHECK(in_order_it->get_value() == Complex(4.0, 5.0));
    ++in_order_it;
    CHECK(in_order_it->get_value() == Complex(2.0, 3.0));
    ++in_order_it;
    CHECK(in_order_it->get_value() == Complex(5.0, 6.0));
    ++in_order_it;
    CHECK(in_order_it->get_value() == Complex(1.0, 1.0));
    ++in_order_it;
    CHECK(in_order_it->get_value() == Complex(6.0, 7.0));
    ++in_order_it;
    CHECK(in_order_it->get_value() == Complex(3.0, 4.0));

    auto bfs_it = tree.begin_bfs_scan(); // Create an iterator for BFS traversal
    CHECK(bfs_it->get_value() == Complex(1.0, 1.0));
    ++bfs_it;
    CHECK(bfs_it->get_value() == Complex(2.0, 3.0));
    ++bfs_it;
    CHECK(bfs_it->get_value() == Complex(3.0, 4.0));
    ++bfs_it;
    CHECK(bfs_it->get_value() == Complex(4.0, 5.0));
    ++bfs_it;
    CHECK(bfs_it->get_value() == Complex(5.0, 6.0));
    ++bfs_it;
    CHECK(bfs_it->get_value() == Complex(6.0, 7.0));
}
