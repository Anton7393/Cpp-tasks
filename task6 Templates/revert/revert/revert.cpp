// revert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

//Корректно работает для типов char* и std::string
void revert_str(string);

//Корректно работает для массивов typename arr [N] и std::string
template<typename T, size_t N>
void revert_arr(T (&cont)[N]);

//корректно работает для все типов представленных в данном задании контейнеров
// std::string , typename arr [N] , List , Vektor , Deque , string
// Однако некоректно работает для строк char*, так как любая стока заканчивается уникальным символом \0
// Который учитывается алгоритмом.
template<typename T>
void revert_con(const T&);

int main()
{
	string str1 = "";
	string str2 = "ABBA";
	string str3 = "hello!";
	char str4[] = "";
	char str5[] = "level";
	char str6[] = "world";
	int arr1[] = {1,2,34,4,67,8,9};
	int arr2[] = { 1,2,3,4,3,2,1 };
	int arr3[] = { 0 };
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;
	list<int> lst1;
	list<int> lst2;
	list<int> lst3;
	deque<long> deq1;
	deque<long> deq2;
	deque<long> deq3;

	vec1.push_back(0);
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(1);
	vec1.push_back(0);

	vec2.push_back(0);
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	vec2.push_back(4);

	lst1.push_back(0);
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(1);
	lst1.push_back(0);

	lst2.push_back(0);
	lst2.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst2.push_back(4);

	deq1.push_back(0);
	deq1.push_back(1);
	deq1.push_back(2);
	deq1.push_back(1);
	deq1.push_back(0);

	deq2.push_back(0);
	deq2.push_back(1);
	deq2.push_back(2);
	deq2.push_back(3);
	deq2.push_back(4);

	revert_str(str1);
	revert_str(str2);
	revert_str(str3);
	revert_str(str4);
	revert_str(str5);
	revert_str(str6);

	revert_arr(arr1);
	revert_arr(arr2);
	revert_arr(arr3);
	revert_arr(str4);
	revert_arr(str5);
	revert_arr(str6);
	
	revert_con(str1);
	revert_con(str2);
	revert_con(str3);
	revert_con(str4);
	revert_con(str5);
	revert_con(str6);
	revert_con(arr1);
	revert_con(arr2);
	revert_con(arr3);
	revert_con(vec1);
	revert_con(vec2);
	revert_con(vec3);
	revert_con(lst1);
	revert_con(lst2);
    revert_con(lst3);
	revert_con(deq1);
	revert_con(deq2);
	revert_con(deq3);
	
	system("pause");
    return 0;
}

void revert_str(string str)
{
	size_t length = str.length();
	size_t counter = 0;
	if (!length)
	{
		cout << "String is empty" << endl;
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] != str[length-i-1])
		{
			cout << "String: " << str << " is not Palindrom" << endl;
			return;
		}
		counter++;
		if (counter > length / 2) break;
	}
	cout << "String: " << str << " is Palindrom" << endl;
}

template<typename T, size_t N>
void revert_arr(T (&cont)[N])
{
	size_t counter = 0;
	if (!N)
	{
		cout << "Array is empty" << endl;
		return;
	}
	for (size_t i = 0; i < N; i++)
	{
		if (cont[i] != cont[N - i - 1])
		{
			cout << "Array: ";
			for (auto i : cont)	cout << i << " ";
			cout << " is not Palindrom" << endl;
			return;
		}
		counter++;
		if (counter > N / 2) break;
	}
	cout << "Array: ";
	for (auto i : cont)	cout << i << " ";
	cout << " is Palindrom" << endl;
}

template<typename T>
void revert_con(const T & cont)
{
	size_t csize = size(cont);//begin(cont) - end(cont);
	size_t counter = 0;
	if (begin(cont) == end(cont))
	{
		cout << "Container is empty" << endl;
		return;
	}
	auto eit = end(cont);
	for (auto it = begin(cont); it != end(cont); it++)
	{
		if (*(it) != *(--eit))
		{
			cout << "Container: ";
			for (auto i : cont)	cout << i << " ";
			cout << " is not Palindrom" << endl;
			return;
		}
		counter++;
		if (counter > csize / 2) break;
	}
	cout << "Container: ";
	for (auto i : cont)	cout << i << " ";
	cout << " is Palindrom" << endl;
}
