#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

struct Element
{
	int data;
	Element* next;
};

struct Queue
{
	Element* head = nullptr, * tail = nullptr;
};

void push(Queue& q, int d);

int pull(Queue& q);

void print(const Queue& q);

void Clear(Queue& q); // полностью очистить очередь

bool isEmpty(const Queue& q); // проверка на пустоту

void Attach(Queue& q1, Queue& q2);	// закидывает все элементы второй очереди в первую

void Clone(Queue& q1, const Queue& q2);		// копирует элементы второй очереди в первую

void Insert(Queue& q, int data, int beforeIndex);	// вставляет новый элемент перед beforeIndex

void Erase(Queue& q, int Index);	// удаляет элемент с индексом Index

int Size(Queue& q);	// возвращает размер списка

int LookAt(Queue& q, int index);	// показывает содержимое поля data Element'a с индексом Index 

#endif
