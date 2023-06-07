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

void Clear(Queue& q); // ��������� �������� �������

bool isEmpty(const Queue& q); // �������� �� �������

void Attach(Queue& q1, Queue& q2);	// ���������� ��� �������� ������ ������� � ������

void Clone(Queue& q1, const Queue& q2);		// �������� �������� ������ ������� � ������

void Insert(Queue& q, int data, int beforeIndex);	// ��������� ����� ������� ����� beforeIndex

void Erase(Queue& q, int Index);	// ������� ������� � �������� Index

int Size(Queue& q);	// ���������� ������ ������

int LookAt(Queue& q, int index);	// ���������� ���������� ���� data Element'a � �������� Index 

#endif
