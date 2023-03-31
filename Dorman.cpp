//============================================================================
// Name        : Dorman.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;


template <typename T>
bool f1v (vector <T> v, T x)
{
	bool k = false;
	for (auto elem: v)
	{
		if (v[elem] == x)
			k = true;
	}
	return k;
}

template <typename T1, typename T2, typename T3>
bool f1m(map<T1, T2> mp, T3 elem)
{
	bool x = false;
	//map <T1, T2> :: iterator it = mp.begin();
	auto it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++)
	{
		if ((it->first == elem) || (it->second == elem))
			x = true;
	}
	return x;
}

template <typename T4, typename R2>
bool f2v (vector <T4> v, R2 r)
{
	bool x = false;
	int i = 0;
	for (auto elem: v)
	{
		i++;
	}
	if (i % 2 == 0)
		x = true;
	return x;

}

template <typename T5, typename T6, typename R>
bool f2m(map <T5, T6> mp, R r)
{
	auto it = mp.begin();
	bool x = false;
	int k = 0;
	for (int i = 0; it != mp.end(); it++, i++)
	{
		k++;
	}
	if (k % 2 == 0)
		x = true;
	return x;
}



class checker
{
public:
	int counter = 0;
	template <typename foo, class container, typename T7>
	void check(foo t, vector <container> v, T7 elem)
	{
		int i = 0;
		for (auto k: v)
		{
			if (t(k, elem) == true)
				counter++;
		}
		cout  << counter << endl;
	}

};

// template<typename T>
// vector {
// public:
// 	T data[10];
// };



int main()
{

	//checker<f1, vector<int>, int> coun;
	vector <int> v = {1, 2, 3, 4, 5, 6};
	vector <vector <int>>  rrr = {{1, 2, 3, 11}, {1, 12, 13, 15, 7}, {1, 2, 3, 4}};
	map <string, string> book = {{"Hi", "РџСЂРёРІРµС‚"},
                             {"Student", "РЎС‚СѓРґРµРЅС‚"},
                             {"!", "!"}};
	// if (f1m(book, "РџСЂРёРІРµС‚") == true)
	// {
	// 	cout << "true" << endl;
	// }
	// else
	// 	cout << "false" << endl;

	// cout << f2v(v) << endl;
	// cout << f2m(book) << endl;
	checker coun;
	coun.check(f1v<int>, rrr, 2);

	return 0;
}
