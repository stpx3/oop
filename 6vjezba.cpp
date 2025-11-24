#include <iostream>

using namespace std;

int const N = 10000;

struct Elem {
	void* data;     
	int priority;
};

struct PriorityQueue {
	Elem heap[N];
	int size;
};
void create(PriorityQueue &pq) {
	pq.size = 0;
}
void swap(Elem &a, Elem &b) {
	Elem t = a;
	a = b;
	b = t;
}
void heapifyUp(PriorityQueue &pq, int idx) {
	while (idx > 0) {
		int parent = (idx - 1) / 2;

		if (pq.heap[idx].priority <= pq.heap[parent].priority)
			return;

		swap(pq.heap[idx], pq.heap[parent]);
		idx = parent;
	}
}
bool insert(PriorityQueue &pq, void* data, int priority) {
	if (pq.size >= N)
		return false;  

	pq.heap[pq.size].data = data;
	pq.heap[pq.size].priority = priority;

	heapifyUp(pq, pq.size);
	pq.size++;

	return true;
}

void heapifyDown(PriorityQueue &pq, int idx) {
	while (true) {
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		int largest = idx;

		if (left < pq.size && pq.heap[left].priority > pq.heap[largest].priority)
			largest = left;

		if (right < pq.size && pq.heap[right].priority > pq.heap[largest].priority)
			largest = right;

		if (largest == idx)
			return;

		swap(pq.heap[idx], pq.heap[largest]);
		idx = largest;
	}
}

Elem extractMax(PriorityQueue &pq) {
	if (pq.size == 0)
		return { nullptr, -1 }; 

	Elem maxElem = pq.heap[0];

	pq.heap[0] = pq.heap[pq.size - 1];
	pq.size--;

	heapifyDown(pq, 0);

	return maxElem;
}

int main() {


	PriorityQueue pq;
	create(pq);

	insert(pq, nullptr, 4);
	insert(pq, nullptr, 10);
	insert(pq, nullptr, 7);

	cout << "Izvadjen: " << extractMax(pq).priority << endl; // 10
	cout << "Izvadjen: " << extractMax(pq).priority << endl; // 7
	cout << "Izvadjen: " << extractMax(pq).priority << endl; // 4

	return 0;
}