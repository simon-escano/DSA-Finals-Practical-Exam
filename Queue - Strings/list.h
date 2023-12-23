#include <iostream>
#include <cstdlib>
using namespace std;

class List {
    public:
    virtual void add(string) = 0;
    virtual string get(int pos) = 0;
    virtual int remove(string num) = 0;
    virtual void print() = 0;
};