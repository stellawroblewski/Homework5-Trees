#include "tree.hh"
#define DEBUG
#include <cassert>

//////////////////////////////////////////////////////////////////////////////
// create_tree allocates space for a new tree node and fills it with the given
// data parameters. By default, the tree is a leaf, so its children point to
// nullptr, but you may override with actual pointers to other nodes.
tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left,
                       tree_ptr_t right){
    
    tree_ptr_t t = new Tree({key, value, left, right}); //allocate space in heap for a new tree struct, t 
    
    return t;
}

//////////////////////////////////////////////////////////////////////////////
// Deallocate all space consumed by this tree and its children.
void destroy_tree(tree_ptr_t tree)
{   
    if (tree == nullptr){ //recursively move through and delete all trees 
      return;}
    destroy_tree(tree->left_);
    destroy_tree(tree->right_);
  delete tree;
  tree = nullptr;
}
//////////////////////////////////////////////////////////////////////////////
// path_to: return a string representing the path taken from a given tree root
// to a given key in the tree. For each left child taken along the path, the
// string contains an 'L' character, and 'R' for a right child, in order.
// So for example for the following tree (only keys depicted, values omitted):
/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6    3
          /
         9
*/
// path_to(tree, 9) will return "LRL", path_to(tree, 3) will return "RL", and
// path_to(126) will return "".
// If the key isn't found in the tree, path_to may abort the program using an
// assert() or exit() call.
//
// If multiple matches to key exist in the tree, return the path to the
// leftmost match. For the tree above, path_to(tree, 12) returns "LL".

bool is_key_in_tree(tree_ptr_t tree, key_t k){
    if ((tree->left_ != nullptr) && is_key_in_tree(tree->left_, k) == true){
        return true; //to find leftmost; 
      }
    else{
      if (tree->key_ == k){ //check if root
      return true;
      }
      else if ((tree->right_ != nullptr) && is_key_in_tree(tree->right_, k) == true){
        return true; //traverse right 
      }
      else{
        return false; //return false if not in tree;
      }
    }
}



std::string path_to(tree_ptr_t t, key_t key){
  std::string string_path = "";
  bool is_key = is_key_in_tree(t, key);
  assert(is_key == true);
  if (t->left_ != nullptr && (is_key_in_tree(t->left_, key) == true)){
    string_path += 'L' + path_to(t->left_, key);
  }
  else if (t->key_ == key){
    return string_path;
  }
  else if(t->right_ != nullptr && (is_key_in_tree(t->right_, key) == true)){
    string_path += 'R' + path_to(t->right_, key); 
  }
  return string_path;
}



//////////////////////////////////////////////////////////////////////////////
// node_at: Follow a path from a given root node and return the node that is
// at the end of the path. For example, for the root of the tree above,
// node_at("LR") will return a pointer to the node whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)


tree_ptr_t node_at(tree_ptr_t tree, std::string path){
    tree_ptr_t location = tree;
    if (path == ""){
      return location; //return root ptr
    }
    else{
      for (char & c : path){ //for all characters in the given path
        if (location == nullptr){//check for nullptr
          location = nullptr;
          break;
        }
        else if (c == 'L'){ //if char is L the location now points from its current to the left of current
            location = location->left_;
          }
        else if (c == 'R'){//if char is R the location now points from its current to the right of he current
            location = location->right_;
          } 
      }
    }
  return location;
}


