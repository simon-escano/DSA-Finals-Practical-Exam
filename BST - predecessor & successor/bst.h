#include "mybinarytree.h"

class BST {
	BinaryTree* tree = new MyBinaryTree();

	public:
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}

	bool insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			tree->addRoot(num);
		}
		return insert_node(n, num);
	}

	bool insert_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return false;
		}
		if (num > n->elem) {
			if (!n->right) {
				tree->addRight(n, num);
				return true;
			} else {
				return insert_node(n->right, num);
			}
		} else {
			if (!n->left) {
				tree->addLeft(n, num);
				return true;
			} else {
				return insert_node(n->left, num);
			}
		}
	}

    // TODO predecessor
    int predecessor(int num) {
        return predecessor(tree->getRoot(), num);
    }

    int predecessor(node* n, int num) {
        if (!n) return -1;
        if (n->elem == num) {
            if (n->left) {
                node* curr = n->left;
                while (curr->right) {
                    curr = curr->right;
                }
                return curr->elem;
            }
            node* curr = n->parent;
            while (curr && n->elem < curr->elem) {
                curr = curr->parent;
            }
            if (curr) return curr->elem;
            return -1;
        }
        if (n->elem > num) return predecessor(n->left, num);
        return predecessor(n->right, num);
    }

    // TODO successor
    int successor(int num) {
        return successor(tree->getRoot(), num);
    }

    int successor(node* n, int num) {
        if (!n) return -1;
        if (n->elem == num) {
            if (n->right) {
                node* curr = n->right;
                while (curr->left) {
                    curr = curr->left;
                }
                return curr->elem;
            }
            node* curr = n->parent;
            while (curr && n->elem > curr->elem) {
                curr = curr->parent;
            }
            if (curr) return curr->elem;
            return -1;
        }
    
        if (n->elem > num) return successor(n->left, num);
        return successor(n->right, num);
    }

	void print() {
		tree->print();
	}
};