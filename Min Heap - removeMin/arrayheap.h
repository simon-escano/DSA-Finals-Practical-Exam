#include <iostream>
#include <cstdlib>
#include <cmath>
#include "minheap.h"
using namespace std;

class ArrayMinHeap : public MinHeap {
    int* array;
    int size;
    int capacity = 50;

    // TODO get index of parent of index n
    int parent(int n) {
        return (n - 1) / 2;
	}

    // TODO get index of left child of index n
	int left(int n) {
        return (2 * n) + 1;
	}

    // TODO get index of right child of index n
	int right(int n) {
        return (2 * n) + 2;
	}

	void swap(int p1, int p2) {
		int temp = array[p1];
		array[p1] = array[p2];
		array[p2] = temp;
	}

    public:
    ArrayMinHeap() {
    	array = (int*) calloc ( capacity, sizeof(int) );
    	size = 0;
	}

	void insert(int num) {
		array[size++] = num;
		int ind = size-1;
		while (ind > 0) {
			int par = parent(ind);
			if (array[ind] < array[par]) {
				swap(ind, par);
			}
			ind = par;
		}
	}

    // TODO remove the minimum value
	int removeMin() {
        if (size == 0) {
            return -1;
        }
        int temp = array[0];
        array[0] = array[size-1];
        size--;
        removeMin(0);
		return temp;
	}

    void removeMin(int i) {
        int min = i;
        if (left(i) < size && array[left(i)] < array[min]) min = left(i);
        if (right(i) < size && array[right(i)] < array[min]) min = right(i);
        if (min > i) {
            swap(i, min);
            removeMin(min);
        }
    }

    // DO NOT modify the code below
	void print() {
		if (size == 0) {
			cout << "EMPTY" << endl;
            return;
		} else {
			cout << "Size: " << size << endl;
			cout << "TREE: " << endl;
			print_tree("", 0, false);
		}
		cout << "ARRAY: ";
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void print_tree(string prefix, int n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << array[n] << endl;
		if (left(n) < size) {
			print_tree(prefix + "|   ", left(n), true);
		}
		if (right(n) < size) {
			print_tree(prefix + "|   ", right(n), false);
		}
	}
};