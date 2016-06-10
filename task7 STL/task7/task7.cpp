// task7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

template<typename T>
void remove_dups(T & con)
{
	auto it = con.begin();
	auto eit = con.end();
	if (it == eit)
	{
		cout << "That's empty!" << endl;
		return;
	}
	auto max_value = *it;
	++it;
	con.erase(remove_if(it, eit, [&](auto curr_value) -> bool { return curr_value > max_value; }), eit);
}

template<typename T>
void dump(T con)
{
	size_t _size = size(con);
	if (typeid(con) == typeid(string)) printf("«string(%d): ", (int)_size);
	if (typeid(con) == typeid(vector<int>)) printf("«vector(%d):", (int)_size);
	if (typeid(con) == typeid(list<float>)) printf("«list(%d):", (int)_size);

	for (auto it : con)
	{
		if (typeid(con) == typeid(string)) cout << it;
		if (typeid(con) == typeid(vector<int>)) printf(" [%d]=%d", _size, it);
		if (typeid(con) == typeid(list<float>)) printf(" ~ %.2f", it);
	}
	cout << "»" << endl;
}

int main()
{
	vector<int> vec(3);
	vec[0] = 1; vec[1] = 1; vec[2] = 2;
	dump(vec); // âûâîäèò «vector(3): [0]=1 [1]=2 [2]=1»
	remove_dups(vec);
	dump(vec); // «vector(2): [0]=1 [1]=1»

	list<float> lst;
	lst.push_back(1.0); lst.push_back(1.25); lst.push_back(0.5);
	dump(lst); // «list(3): 1.0 ~ 1.25 ~ 0.5»
	remove_dups(lst);
	dump(lst); // «list(2): 1.0 ~ 0.5»

	string str = "min";
	dump(str); // «string(3): "min"»
	remove_dups(str);
	dump(str); // «string(2): "mi"»

	system("pause");
    return 0;
}
