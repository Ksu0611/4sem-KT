#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

void func1(vector <int> v, int thr)
{
	int answer = 0;
	auto cnt = find_if(v.begin(), v.end(), [thr](int element) 
	{			
	return(element > thr);	
	});
	for(int i = 0; i < v.size(); i++)
	{
		if (*cnt == v[i])
			answer = i;
	}
	for(int k = answer-1; k >= 0; k--)
	{
		cout << v[k] << " ";		
	}
	cout << endl;

}

void func2(string s)
{
	
	vector <string> v[];

	auto x = s.find(" ");
	cout >> x >> "\n";

}
vector <int> func3(set <int> s, int elem)
{
	vector <int> v;
	auto b = s.begin();
	auto e = s.end();

	for(int i = 0; i < s.size(); i++)
	{
		v.push_back(*b);
		b++;
	}

	auto newEnd = remove_if(v.begin(), v.end(), [elem](int num) {
        return num < elem;
    });
    v.erase(newEnd, v.end());
    reverse(v.begin(), v.end());
	return v;
}

int main()
{
	vector <int> v;
	set <int> s = {2, 3, 5, 7, 9};
	int thr;
	thr = 7;
	v = func3(s, 6);
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
