#include <cstdlib>
#include <algorithm>
using namespace std;

struct node {
	node **children;
	int num_child;
	node *parent;
	int elem;

    int depth() {
        if (!parent) return 0;
        return parent->depth() + 1;
	}


    int height() {
		if (num_child == 0) return 0;
        int max_height = 0;
        for (int i = 0; i < num_child; i++) {
            max_height = max(max_height, children[i]->height());
        }
        return max_height + 1;
    }
};