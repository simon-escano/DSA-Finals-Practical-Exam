#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "gentree.h"
using namespace std;

class MyGenTree : public GenTree {
	node* root;
	int size;

	public:
	node* addRoot(int e) {
		// TODO implementation [+10 pts]
        if (root) {
            throw logic_error("Already has root");
        }
        node* n = (node*) malloc (sizeof(node));
        n->elem = e;
        n->children = NULL;
        n->parent = NULL;
        n->num_child = 0;
        root = n;
        size++;
        return n;
	}

	node* addChild(node* p, int e) {
        if (!p->children) {
            p->children = (node**) malloc (10 * sizeof(node));
        }
        node* n = (node*) malloc (sizeof(node));
        n->elem = e;
        n->children = NULL;
        n->num_child = 0;
        n->parent = p;
        if (p->num_child < 10) {
            p->children[p->num_child] = n;
            p->num_child++;
            size++;
        }
        return n;
	}


	void remove(node* n) {
		// TODO implementation [+35 pts]
        if (n->num_child > 0) {
            cout << n->elem << " has children" << endl;
            return;
        }
        if (n->parent) {
            arrayRemove(n->parent->children, n->parent->num_child, n->elem);
            n->parent->num_child--;
        } else {
            root = NULL;
        }
        free(n);
        n = NULL;
        size--;
	}

    void arrayRemove(node** children, int num_child, int num) {
        for (int i = 0; i < num_child; i++) {
            if (children[i]->elem == num) {
                for (int j = i; j < num_child - 1; j++) {
                    children[j] = children[j + 1];
                }
                children[num_child - 1] = NULL;
                break;
            }
        }
    }

    // DO NOT MODIFY this line onwards.
	void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n) {
		cout << prefix;
        cout << "+-->: ";
        cout << n->elem << endl;
		for (int i = 0; i < n->num_child; i++) {
			print_node(prefix + "|   ", n->children[i]);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            return false;
        }
        bool res = true;
		for (int i = 0; i < curr->num_child; i++) {
			res &= check_parent(curr->children[i], curr);
		}
        return res;
    }
};