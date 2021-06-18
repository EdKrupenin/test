#include <iostream>
#include "Source.h"

List* findMaxAndRange(float persent, float* arr, int length) {
	if (length == 0 || arr == NULL) throw std::invalid_argument::invalid_argument("Bad Array.");
	persent /= 100;
	List* answer = new List;
	initList(answer);
	float max = *arr;
	for (int i = 1; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= (max - max * persent) && arr[i] <= (max + max * persent))
			insertList(answer, i);
	}
	return answer;
}

int main()
{
	float arr[5] = { 3.5f , 3.1f, 3.9f, 4.0f, 4.1f };
	printList(findMaxAndRange(10, arr, 5));
}

