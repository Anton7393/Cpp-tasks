#include "stdafx.h"
#include "StorageMacro.h"

using namespace std;

StorageMacro::StorageMacro()
{
	current = nullptr;
	head = nullptr;
	tail = nullptr;
}

StorageMacro::~StorageMacro()
{

}

void StorageMacro::add(void * element)
{
	if (head == nullptr)
	{
		head = new NodeMacro(element);
		head->prev = nullptr;
		head->next = nullptr;
		tail = head;
		return;
	}

	if (head == tail)
	{
		tail = new NodeMacro(element);
		tail->prev = head;
		tail->next = nullptr;
		head->next = tail;
		return;
	}

	tmp_ptr = new NodeMacro(element);
	tmp_ptr->next = nullptr;
	tmp_ptr->prev = tail;
	tail->next = tmp_ptr;
	tail = tmp_ptr;
}

void StorageMacro::foreach(void (*func)(void))
{
	current = head;
	while (current != nullptr)
	{
		(current->data->*func)();
		current = current->next;
	}
}

void StorageMacro::foreach(void (*func)(void) const)
{
	current = head;
	while (current != nullptr)
	{
		(current->data->*func)();
		current = current->next;
	}
}