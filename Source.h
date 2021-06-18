#pragma once
/// <summary>
/// Структура узла односвязного списка
/// </summary>
typedef struct Knot {
	int data;
	struct Knot* next;
}Knot;

/// <summary>
/// Структура односвязного списка
/// </summary>
typedef struct List {
	Knot* head;
	int size;
}List;

/// <summary>
/// Инициализация нового списка
/// </summary>
/// <param name="lst">Указатель на список</param>
void initList(List* lst);

/// <summary>
/// Добавление нового элемента
/// </summary>
/// <param name="lst">Указатель на список</param>
/// <param name="data">Новый элемент</param>
void insertList(List* lst, int data);

/// <summary>
/// Удаление элементов из связного списка
/// </summary>
/// <param name="lst">ссылка на головной элемент и кол-во</param>
/// <param name="data">данные которые надо удалить</param>
/// <returns>данные которые надо удалить</returns>
Knot* rm(List* lst, int data);

/// <summary>
/// Функция копирования односвязного листа
/// </summary>
/// <param name="Lst">Указатель на список который надо скопировать</param>
/// <returns>Скопированный список</returns>
List* copyList(List* lst);

/// <summary>
/// Функция проверки отсортирован ли односвязный список
/// </summary>
/// <param name="lst">Указатель на список</param>
/// <returns>Результат проверки</returns>
bool sortList(List* lst);

void printKnot(Knot* k,int open);

void printList(List* lst);
