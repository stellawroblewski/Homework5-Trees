Tree project

create_tree establishes a tree_ptr_t t and stores in the heap. 

destroy_tree recursively moves through the given tree_ptr_t and deleted all nodes

path_to has a helper function is_key_in_tree that recursively moves through the tree and returns true if the node is found. path_to checks if the given key is in the given tree and passes an assert before the function continues. It then recursively moves left, then to the root, then right, adding to the string_path and returns the path. 

node_at first checks if the string is empty, then for each character in the given string checks for nullptr, the 'L', followed by the 'R' character and changes locations as it continues. 
