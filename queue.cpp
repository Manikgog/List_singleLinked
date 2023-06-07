#include "queue.h"

void push(Queue& q, int d)
{
	Element* e = new Element;
	e->data = d;
	e->next = nullptr;

	if (q.head == nullptr)
	{
		q.tail = e;
		q.head = e;
	}
	else
	{
		q.tail->next = e;
		q.tail = e;
	}
}

int pull(Queue& q)
{
	if (q.head == nullptr)
	{
		return 0;
	}

	int tmp = q.head->data;

	if (q.head == q.tail)
	{
		q.tail = nullptr;
	}

	Element* e = q.head;
	q.head = q.head->next;
	delete e;
	return tmp;
}

void print(const Queue& q)
{
	bool is_first = true;
	for (Element* cur = q.head; cur != nullptr; cur = cur->next)
	{
		if (!is_first)
			std::cout << ", ";
		is_first = false;
		std::cout << cur->data;
	}
	std::cout << std::endl;
}

int Size(Queue& q)
{
	
	if (q.head == q.tail)
	{
		if (q.head == nullptr)
		{
			return 0;
		}
		return 1;
	}
	int size = 0;
	for (Element* cur = q.head; cur != nullptr; cur = cur->next)
		size++;
	return size;
}

bool CheckRange(Queue& q, int index)
{
	if (index < 0 || index >= Size(q))
	{
		std::cout << "Index is out of range!\n";
		return false;
	}
	return true;
}

int LookAt(Queue& q, int index)
{
	if (!CheckRange(q, index))
		return 0;
	int i = 0;
	for (Element* cur = q.head; cur != nullptr; cur = cur->next, ++i)
	{
		if (i == index)
		{
			return cur->data;
		}
	}
	
}

void Insert(Queue& q, int data, int beforeIndex)
{
	if (beforeIndex == 0) {
		Element* tmp = new Element;
		tmp->data = data;
		tmp->next = q.head;
		q.head = tmp;
		return;
	}
	if (!CheckRange(q, beforeIndex))
		return;
	Element* previous = q.head;
	for (int i = 0; i < beforeIndex - 1; ++i)
	{
		previous = previous->next;
	}
	Element* tmp = new Element;
	tmp->data = data;
	tmp->next = previous->next;
	previous->next = tmp;
	return;
}

void Clear(Queue& q)
{
	int size = Size(q);
	for (int i = 0; i < size; ++i)
	{
		//std::cout << "Удалено - " << pull(q) << std::endl;
		pull(q);
	}
}