#include <cstdio>
#include <cstdlib>

template <typename T>
struct Stack {
    T* elements = NULL;
    int capacity = 0;
    int numElements = 0;

    Stack() {
        init(16);
    }

    Stack(int defaultCapacity) {
        init(defaultCapacity);
    }

    void init(int defaultCapacity) {
        capacity = defaultCapacity;
        numElements = 0;
        elements = new T[capacity];
    }

    void expand() {
        if (numElements == capacity) {
            capacity = capacity * 2;
            T* newElements = new T[capacity];
            memcpy(newElements, elements, sizeof(T) * numElements);
            free(static_cast<void*>(elements));
            elements = newElements;
        }
    }

    void push(T value) {
        expand();
        elements[numElements] = value;
        numElements++;
    }

    void pop() {
        numElements--;
    }

    T top() {
        return elements[numElements - 1];
    }

    int size() {
        return numElements;
    }

	void clear() {
		numElements = 0;
	}

    void freeStack() {
        delete[] elements;
    }
};
