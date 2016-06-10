#pragma once

struct NodeMacro
{
	void* data;
	size_t sizeOfType;
	NodeMacro* next;
	NodeMacro* prev;

	NodeMacro(void * _data)
	{
		sizeOfType = sizeof(_data);
		data = malloc(sizeOfType);
		data = memcpy(data, _data, sizeOfType);
		next = nullptr;
		prev = nullptr;
	}

	~NodeMacro()
	{
		free(data);
	}
};

class StorageMacro
{
private:

	NodeMacro* head;
	NodeMacro* tail;
	NodeMacro* current;
	NodeMacro* tmp_ptr;

public:
	StorageMacro();
	~StorageMacro();

	void add(void *);
	void foreach(void (*func)(void));
	void foreach(void (*func)(void) const);
};