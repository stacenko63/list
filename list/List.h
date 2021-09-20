#pragma once
#include <iostream>
using namespace std;
class List
{
private:
	int size;
	struct Node
	{
		int key;
		char value[10];
		Node* next;
	};
	Node* start;
	Node* finish;
	int KeyAvailability(int key)
	{
		int index = 1;
		Node* tmp = start;
		while (tmp != NULL)
		{
			if (tmp->key == key) return index;
			tmp = tmp->next;
			index++;
		}
		return -1;
	}
public:
	List()
	{
		start = NULL;
		finish = NULL;
		size = 0;
	}
	void AddBegin(int key, char value[10])
	{
		if (KeyAvailability(key) == -1)
		{
			Node* NewNode = new Node;
			NewNode->key = key;
			strcpy(NewNode->value, value);
			NewNode->next = start;
			start = NewNode;
			if (finish == NULL) finish = NewNode;
			size++;
		}
		else throw "Добавляемый ключ уже присутствует в списке!";
	}
	void AddEnd(int key, char value[10])
	{
		if (KeyAvailability(key) == -1)
		{
			Node* NewNode = new Node;
			NewNode->key = key;
			strcpy(NewNode->value, value);
			NewNode->next = NULL;
			if (size != 0) finish->next = NewNode;
			finish = NewNode;
			if (start == NULL) start = NewNode;
			size++;
		}
		else throw "Добавляемый ключ уже присутствует в списке!";
	}
	void AddIndex(int key, char value[10], int index)
	{
		if (index <= 0 || index > size + 1) throw "Индекс вышел за границы списка!";
		else
		{
			if (index == 1) AddBegin(key, value);
			else if (index == size + 1) AddEnd(key, value);
			else
			{
				if (KeyAvailability(key) == -1)
				{
					int number = 1;
					Node* tmp = start;
					while (number != index - 1)
					{
						tmp = tmp->next;
						number++;
					}
					Node* NewNode = new Node;
					NewNode->key = key;
					strcpy(NewNode->value, value);
					NewNode->next = tmp->next->next;
					tmp->next = NewNode;
					size++;
				}
				else throw "Добавляемый ключ уже присутствует в списке!";
			}
		}
	}
	void DelBegin()
	{
		if (size == 0) throw "Список итак пуст!";
		else
		{
			Node* tmp = start->next;
			delete start;
			start = tmp;
			size--;
			if (size <= 1) finish = start;
		}
	}
	void DelIndex(int index)
	{
		if (size == 0) throw "Список итак пуст!";
		else if (index <= 0 || index > size) throw "Индекс вышел за границы списка!";
		else
		{
			if (index == 1) DelBegin();
			else
			{
				int number = 1;
				Node* tmp = start;
				while (number != index - 1)
				{
					tmp = tmp->next;
					number++;
				}
				Node* tmp2 = tmp->next;
				tmp->next = tmp->next->next;
				delete tmp2;
				size--;
			}
		}
	}
	void DelEnd()
	{
		if (size == 0) throw "Список итак пуст!";
		else DelIndex(size);
	}
	void DelKey(int key)
	{
		if (KeyAvailability(key) != -1) DelIndex(KeyAvailability(key));
		else throw "Ключа, который вы хотите удалить, итак нет в списке!";
	}
	void GetElementIndex(int index) const
	{
		if (index < 0 || index > size) throw "Индекс вышел за границы списка!";
		else
		{
			int number = 1;
			Node* tmp = start;
			while (number != index) tmp = tmp->next;
			printf("%d %s\n", tmp->key, tmp->value);
		}
	}
	void SetElementIndex(int key, char value[10], int index)
	{
		if (index < 0 || index > size) throw "Индекс вышел за границы списка!";
		if (KeyAvailability(key) != -1) throw "Такой ключ уже есть";
		else
		{
			int number = 1;
			Node* tmp = start;
			while (number != index) tmp = tmp->next;
			tmp->key = key;
			strcpy(tmp->value, value);
		}
	}
	void GetElementKey(int key)
	{
		if (KeyAvailability(key) != -1) GetElementIndex(KeyAvailability(key));
		else throw "Указанный ключ не найден!";
	}
	void SetElementKey(int key, int newkey, char value[10])
	{
		if (KeyAvailability(key) != -1) SetElementIndex(newkey, value, KeyAvailability(key));
		else throw "Указанный ключ не найден!";
	}
	int GetSize()
	{
		return size;
	}
	void Print()
	{
		Node* tmp = start;
		while (tmp != NULL)
		{
			printf("%d %s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
	}
	~List()
	{
		Clear();
	}
	void Clear()
	{
		while (start != NULL) DelBegin();
	}
};