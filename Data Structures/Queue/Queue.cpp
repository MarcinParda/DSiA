#include "pch.h"
#include <cstring>
#include <iostream>

using namespace std;

class Element {
	friend class Queue;
	int data = 0;
	Element* after = NULL;
	Element(int d) {
		this->data = d;
		this->after = NULL;
	}
};

class Queue {
	Element* first = NULL;
	Element* last = NULL;
	//Add to the end of Queue
public:
	void add(int d) {
		Element* newElement = new Element(d);
		if (this->first == NULL || this->last == NULL)
			this->first = this->last = newElement;
		else
		{
			this->last->after = newElement;
			this->last = newElement;
		}
	}
	//Remove from first place of queue
	void remove() {
		if (this->first == NULL) return;
		Element* tmp = this->first;
		this->first = this->first->after;
		delete tmp;
	}
	int size() {
		int i = 0;
		Element* tmp = this->first;
		while (tmp != NULL)
		{
			i++;
			tmp = tmp->after;
		}
		return i;
	}
	void showQueue() {
		Element* tmp = first;
		while (tmp != NULL)
		{
			cout << tmp->data << ".";
			tmp = tmp->after;
		}
		cout << "NULL" << endl
			<< "There is " << this->size() << " elements" << endl << endl;
	}
};


int main()
{
	Queue myQueue;
	myQueue.showQueue();

	myQueue.add(1);
	myQueue.add(2);
	myQueue.add(3);
	myQueue.add(4);
	myQueue.showQueue();

	myQueue.remove();
	myQueue.showQueue();

	system("pause");
	return 0;
}