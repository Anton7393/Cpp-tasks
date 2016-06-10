// Storage.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

using namespace std;

class Cat {
public:
	void miaow() const { printf("miaow\n"); }
};

class Counter {
	int value_;
public:
	Counter(int start) : value_(start) {}
	Counter(const Counter& copy) { value_ = copy.value_; }
	void step() { ++value_; }
	void print() const { printf("[%d]", value_); }
};

template<typename T>
struct NodeTemplate
{
	T* data;
	NodeTemplate* next;
	NodeTemplate* prev;

	NodeTemplate(T& _data)
	{
		data = new T(_data);
		next = nullptr;
		prev = nullptr;
	}

	~NodeTemplate()
	{
		delete data;
	}
};

template<typename T>
class StorageTemplate
{
private:

	NodeTemplate<T>* head;
	NodeTemplate<T>* tail;
	NodeTemplate<T>* current;
	NodeTemplate<T>* tmp_ptr;

public:
	StorageTemplate()
	{
		current = nullptr;
		head = nullptr;
		tail = nullptr;
	}
	~StorageTemplate()
	{
		current = tail;
		while (current != nullptr)
		{
			if (current->prev != nullptr)
			{
				current = current->prev;
				delete current->next;
			}
			else
			{
				delete current;
				current = nullptr;
			}
		}
	}

	void add(T element)
	{
		if (head == nullptr)
		{
			head = new NodeTemplate<T>(element);
			head->prev = nullptr;
			head->next = nullptr;
			tail = head;
			return;
		}

		if (head == tail)
		{
			tail = new NodeTemplate<T>(element);
			tail->prev = head;
			tail->next = nullptr;
			head->next = tail;
			return;
		}

		tmp_ptr = new NodeTemplate<T>(element);
		tmp_ptr->next = nullptr;
		tmp_ptr->prev = tail;
		tail->next = tmp_ptr;
		tail = tmp_ptr;
	}

	void foreach(void (T::*func)(void))
	{
		current = head;
		while (current != nullptr)
		{
			(current->data->*func)();
			current = current->next;
		}
	}

	void foreach(void (T::*func)(void) const)
	{
		current = head;
		while (current != nullptr)
		{
			(current->data->*func)();
			current = current->next;
		}
	}
};

int main()
{
	StorageTemplate<Cat> cats;
	cats.add(Cat());
	cats.add(Cat());
	cats.foreach(&Cat::miaow);

	StorageTemplate<Counter> counters;
	counters.add(Counter(10));
	counters.add(Counter(20));
	counters.foreach(&Counter::print);
	counters.foreach(&Counter::step);
	counters.foreach(&Counter::print);

	system("pause");
    return 0;
}

