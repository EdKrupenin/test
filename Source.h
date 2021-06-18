#pragma once
/// <summary>
/// ��������� ���� ������������ ������
/// </summary>
typedef struct Knot {
	int data;
	struct Knot* next;
}Knot;

/// <summary>
/// ��������� ������������ ������
/// </summary>
typedef struct List {
	Knot* head;
	int size;
}List;

/// <summary>
/// ������������� ������ ������
/// </summary>
/// <param name="lst">��������� �� ������</param>
void initList(List* lst);

/// <summary>
/// ���������� ������ ��������
/// </summary>
/// <param name="lst">��������� �� ������</param>
/// <param name="data">����� �������</param>
void insertList(List* lst, int data);

/// <summary>
/// �������� ��������� �� �������� ������
/// </summary>
/// <param name="lst">������ �� �������� ������� � ���-��</param>
/// <param name="data">������ ������� ���� �������</param>
/// <returns>������ ������� ���� �������</returns>
Knot* rm(List* lst, int data);

/// <summary>
/// ������� ����������� ������������ �����
/// </summary>
/// <param name="Lst">��������� �� ������ ������� ���� �����������</param>
/// <returns>������������� ������</returns>
List* copyList(List* lst);

/// <summary>
/// ������� �������� ������������ �� ����������� ������
/// </summary>
/// <param name="lst">��������� �� ������</param>
/// <returns>��������� ��������</returns>
bool sortList(List* lst);

void printKnot(Knot* k,int open);

void printList(List* lst);
