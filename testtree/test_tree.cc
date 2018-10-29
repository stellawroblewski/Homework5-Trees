#include "tree.hh"
#include <iostream>
#define DEBUG
#include <cassert>

int main()
{
    struct Tree* tr = create_tree(3, 4); //create tree with root of 3
    tr->left_ = create_tree(6, 4); //continue adding nodes....
    tr->left_->left_ = create_tree(23, 4);
    tr->right_ = create_tree(10, 4);
    tr->right_->right_ = create_tree(2, 4);
    tr->right_->left_ = create_tree(5, 4);
    tr->right_->left_->left_ = create_tree(27, 4);
    tr->right_->left_->left_->right_ = create_tree(100, 4);
    /*
            3
           /  \
          /    \
        6       10
        /      / \
      23      5   2
             /
            27
              \
             100 
*/
    bool is_key = is_key_in_tree (tr, 3); //test is_key_in_tree
    bool is_key1 = is_key_in_tree (tr, 6); //test is_key_in_tree
    bool is_key2 = is_key_in_tree (tr, 23); //test is_key_in_tree
    bool is_key3 = is_key_in_tree (tr, 10); //test is_key_in_tree
    bool is_key4 = is_key_in_tree (tr, 5); //test is_key_in_tree
    bool is_key5 = is_key_in_tree (tr, 27); //test is_key_in_tree
    bool is_key6 = is_key_in_tree (tr, 100); //test is_key_in_tree
    bool is_key7 = is_key_in_tree (tr, 2); //test is_key_in_tree
    bool is_key8 = is_key_in_tree (tr, 600); //test is_key_in_tree
    tree_ptr_t where_node = node_at(tr, "LL"); //test were_node
    key_t key = where_node->key_;
    tree_ptr_t where_node1 = node_at(tr, ""); //test were_node
    key_t key1 = where_node1->key_;
    tree_ptr_t where_node2 = node_at(tr, "RLLR"); //test were_node
    key_t key2 = where_node2->key_;

    std::string path = path_to(tr, 100); //test path_to node 
    std::cout << path << std::endl;
    assert(is_key = 1);
    assert(is_key1 = 1);
    assert(is_key2 = 1);
    assert(is_key3 = 1);
    assert(is_key4 = 1);
    assert(is_key5 = 1);
    assert(is_key6 = 1);
    assert(is_key7 = 1);
    std::cout << is_key8 << std::endl;
    assert(key = 23);
    assert(key1 = 3);
    assert(key2 = 100);
    destroy_tree(tr); //delete space taken up by the tree
    std::cout << "Tree" << tr << std::endl;
return 0;
}