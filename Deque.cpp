#include <iostream>
#include <cstdlib>
#define N 5
using namespace std;


class Deque {

    int buffer[N];
    int start = -1, end = -1;
    int size = N;

public:
    Deque() = default;
    bool IsEmpty() const {
        return (start == end && end == -1);
    }
    bool IsFull() const {
        return ((end + 1) % N == start);
    }
    int counter() const {
        if (IsEmpty()) return 0;
        return (end >= start) ? (end - start + 1) : (N - (start - end - 1));
    }
    int front() const {
        if (IsEmpty()) exit(1);
        return buffer[start];
    }
    int back() const {
        if (IsEmpty()) exit(1);
        return buffer[end];
    }
    void reset() {
        start = end = -1;
    }

    bool pop() {
        if (IsEmpty()) return false;
        if (start == end) start = end = -1;
        else start = (start + 1) % N;
        return true;
    }

    bool pop_from_end() {
        if (IsEmpty()) return false;
        if (start == end) start = end = -1;
        else end = (end - 1) % N;
        return true;
    }

    bool push(int element) {
        if (IsFull()) return false;
        if (IsEmpty()) start = end = 0;
        else end = (end + 1) % N;
        buffer[end] = element;
        return true;
    }
    bool push_to_start(int element) {
        if (IsFull()) {
            cout << "Out of range \n";
            return false;
        }
        if (IsEmpty()) start = end = 0;
        
        else if (start == 0)   
            start = size - 1;
        else start = start - 1;
        buffer[start] = element;
        return true;
    }

    void print() const {
        if (IsEmpty()) cout << "The qeueu is empty \n";
        else if (end == start) cout << buffer[start] << endl;
        else {
            cout << "start = ";
            int i = start;
            while (i != end) {
                cout << buffer[i] << " -> ";
                i = (i + 1) % N;
            }
            cout << buffer[i] << endl;
        }
    }
};

int main()
{
    Deque q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.print(); // 1 2 3
    //cout<<q1.counter(); // 3

    q1.pop();   // 2 3
    q1.push(4);// 2 3 4 
    q1.push_to_start(7);
    q1.push_to_start(8);
    q1.push_to_start(9);
    q1.print(); 
   
    cout << q1.counter();

    Deque q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.print();
    q2.pop_from_end();
    q2.print();

    return 0;
}

