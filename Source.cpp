#include "Source.h"
#include <cstddef>
#include <iostream>

#pragma region ����������� ������
void initList(List* lst) {
	lst->head = NULL;
	lst->size = 0;
}

void insertList(List* lst, int data) {
	Knot* newKnot = new Knot;
	newKnot->data = data;
	newKnot->next = NULL;

	Knot* current = lst->head;
	if (current == NULL) {
		lst->head = newKnot;
		lst->size++;
		return;
	}
	else {
		while (current->next != NULL)
			current = current->next;
		current->next = newKnot;
		lst->size++;
	}
}

Knot* rm(List* lst, int data) {
	Knot* current = lst->head;
	Knot* parent = NULL;
	if (current == NULL) return NULL;
	while (current->next != NULL && current->data != data) {
		parent = current;
		current = current->next;
	}
	if (current->data != data) return NULL;
	if (current == lst->head) {
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

List* copyList(List* lst) {
	List* newLst = new List; //������� ����� ���� ������� ������ �� �����...
	initList(newLst);
	Knot* current = lst->head; //�������� ������ ������� ������� ������ � ��������� ��� �� NULL...
	if (current == NULL) return NULL;
	//�������� �� ������� �������� ������� ������, �������� ������ �������� � �������� � �������
	//�������, ��� �� �������� ���� ������ �� ����� ������, ��� ����������� ��� ��� ����� ��������
	//����� ����������
	while (current->next != NULL) {
		insertList(newLst, current->data);
		current = current->next;
	}
	return newLst;
}

bool sortList(List* lst) {
	Knot* current = lst->head; //�������� ������ ������� ������� ������ � ��������� ��� �� NULL...
	if (current == NULL) return NULL;
	int tmp = 0; //��������� ���������� ��� �������� ����������� �������� 
	//( � ���������� ������ ��� �� ����� �.�. ���� ������ �� ���������� ��������)
	bool retUP = true; //������������ �� �����������
	bool retDown = true; //������������ �� ��������
	tmp = current->data; //������ �������� ������ �������
	current = current->next;
	//�������� �� ������� �������� ������� ������
	while (current->next != NULL) {
		if (!(tmp <= current->data && retUP))
			retUP = false;
		if (!(tmp >= current->data && retDown))
			retDown = false;
		tmp = current->data;
		current = current->next;
	}
	return (retUP || retDown);
}

void printKnot(Knot* k, int open) {
	if (k == NULL) {
		std::cout << "[]";
		return;
	}
	std::cout << k->data << (open == 0 ? ',':']');
}

void printList(List* lst) {
	Knot* current = lst->head;
	std::cout << '[';
	int i = 0;
	if (current == NULL) printKnot(current,0);
	else
	{
		do {
			i != lst->size-1 ? printKnot(current,0) : printKnot(current, 1);
			current = current->next;
			i++;
		} while (current != NULL);
	}
	std::cout << "Size: " << lst->size << std::endl;
}
#pragma endregion
