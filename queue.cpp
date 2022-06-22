#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue {    
    public:
        vector<int> data = {};
        void enqueue(int input) {
            this->data.push_back(input);
        }
        void dequeue() {
            this->data.erase(this->data.begin());
        }
        void printQ() {
            cout << this->data.front() << endl;
        }
};



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int a;
    cin >> a;
    
    Queue queue;
    
    for (int i = 0; i < a; i++ ) {
        int b, c;
        cin >> b;
        switch(b) {
            case 1:
                cin >> c;
                //cout << c << endl;
                queue.enqueue(c);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.printQ();
                break;
        }
    }
    return 0;
}


