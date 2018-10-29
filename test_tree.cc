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
    std::string path = path_to(tr, 100); //test path_to node
    bool is_key = is_key_in_tree (tr, 100); //test is_key_in_tree
    tree_ptr_t where_node = node_at(tr, "LL"); //test were_node
    key_t key = where_node->key_;
    std::cout << "Path to 100:" << path << std::endl;    assert(is_key = 1);
    assert(key = 23);
    destroy_tree(tr);   //delete space taken up by the tree
    std::cout << "Tree" << tr << std::endl;
return 0;
}