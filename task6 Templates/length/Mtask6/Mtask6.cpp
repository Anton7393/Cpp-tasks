// Mtask6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

template<typename T, size_t N>
void length(T (&arr)[N])
{
	cout << N << endl;
}

int main()
{
	char s[] = "hello";
	length(s); // ���������� 6
	int a[] = { 0 , 1 };
	length(a); // ���������� 2
	int* t[4];
	length(t); // ���������� 4
	int *p = new int[3];
	//length(p); // ������ ����������/��������
	//length(0); // ������ ����������/��������

	system("pause");
	return 0;
}


