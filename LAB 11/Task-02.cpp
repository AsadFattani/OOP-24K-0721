#include <iostream>
#include <stdexcept>

using namespace std;

class QueueException : public exception {
    public:
        string message;

        QueueException(string msg) : message(msg) {}

        const char* what() noexcept {
            return message.c_str();
        }
};

class QueueOverflowException : public QueueException {
    public:
        QueueOverflowException(string msg) : QueueException(msg) {}
};

class QueueUnderflowException : public QueueException {
    public:
        QueueUnderflowException(string msg) : QueueException(msg) {}
};

template <typename T>
class Queue {
    private:
        int size;
        int capacity;

    public:
        Queue(int cap) : size(0), capacity(cap) {}

        void enqueue(T value) {
            if (size >= capacity) {
                throw QueueOverflowException("Queue overflow occurred!");
            }
            size++;
            cout << "Enqueued: " << value << endl;
        }

        void dequeue() {
            if (size <= 0) {
                throw QueueUnderflowException("Queue underflow occurred!");
            }
            size--;
            cout << "Dequeued an element." << endl;
        }
};

int main() {
    Queue<int> q(2);

    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
    } catch (QueueOverflowException& e) {
        cout << "Caught QueueOverflowException what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();
        q.dequeue();
        q.dequeue();
    } catch (QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException what(): " << e.what() << endl;
    }

    return 0;
}

