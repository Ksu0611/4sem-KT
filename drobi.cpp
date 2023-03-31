#include <iostream>     //g++ drobi.cpp -o 1 -std=c++11
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int NOD(int A, int B)
{
	cout << A << B <<endl;
	while (A != B)
	{
	if (A > B) 
		A = A - B;
	else 
		B = B - A;
	}
	//cout << A;
	return A;
}
class rational
{
	public:
		int numerator;
		int denominator;
		rational()
		{
			numerator = 0;
			denominator = 1;
		}
		rational(int numerator_, int denominator_)
		{
			if (denominator_ == 0)
			{
				throw invalid_argument("denominator is bad");
			}

			else
			{
				if (denominator_< 0)
				{
					denominator_ = denominator_ * (-1);
					numerator_ = numerator_ * (-1);
				}
				numerator = numerator_;
				denominator = denominator_;
				int x = NOD(abs(numerator), abs(denominator));
				//cout << x;
				if ((x != 0))
				{
					numerator = numerator / x;
					denominator = denominator / x;
				}
				if (denominator == 0)
				{
					//cout << "error" << endl;
					throw invalid_argument("denominator is bad");
				}
				else
				{
					if (denominator< 0)
					{
						denominator = denominator * (-1);
						numerator = numerator * (-1);
					}
					// if ((a.numerator % a.denominator) == 0)
					// {
					// 	a.numerator = a.numerator / a.denominator;
					// 	a.denominator = 1;
					// }
				}


			}
		}
		rational operator=(rational b)
		{
			numerator = b.numerator;
			denominator = b.denominator;
			return *this;
		}

};
rational cut(rational a)
{
	int x = NOD(abs(a.numerator), abs(a.denominator));
	//cout << x;
	if ((x != 0))
	{
		a.numerator = a.numerator / x;
		a.denominator = a.denominator / x;
	}
	if (a.denominator == 0)
	{
		//cout << "error" << endl;
		throw invalid_argument("denominator is bad");
	}
	else
	{
		if (a.denominator< 0)
		{
			a.denominator = a.denominator * (-1);
			a.numerator = a.numerator * (-1);
		}
		// if ((a.numerator % a.denominator) == 0)
		// {
		// 	a.numerator = a.numerator / a.denominator;
		// 	a.denominator = 1;
		// }
	}
	return a;
}
rational operator+(rational a, rational b)
{
	int x1 = a.numerator * b.denominator;
	int x2 = a.denominator * b.numerator;
	a.denominator = a.denominator * b.denominator;
	a.numerator = x1 + x2;
	a = cut(a);
	return a;
}

rational operator-(rational a, rational b)
{
	int x1 = a.numerator * b.denominator;
	int x2 = a.denominator * b.numerator;
	a.denominator = a.denominator * b.denominator;
	a.numerator = x1 - x2;
	a = cut(a);
	return a;

}
rational operator*(rational a, rational b)
{
	a.numerator = a.numerator * b.numerator;
	a.denominator = a.denominator * b.denominator;
	return a;
}
rational operator/(rational a, rational b)
{
	a.numerator = a.numerator * b.denominator;
	a.denominator = a.denominator * b.numerator;
	return a;
}
bool operator==(rational a, rational b)
{
	a = cut(a);
	b = cut(b);
	if((a.numerator == b.numerator) && (a.denominator == b.denominator))
		return 1;
	else
		return 0;
}
bool operator>(rational a, rational b)
{
	int ax;
	int bx;
	ax = a.numerator * b.denominator;
	bx = b.numerator * a.denominator;
	if (ax > bx)
		return 1;
	else
		return 0;
}
bool operator<(rational a, rational b)
{
	int ax;
	int bx;
	ax = a.numerator * b.denominator;
	bx = b.numerator * a.denominator;
	if (ax < bx)
		return 1;
	else
		return 0;
}
rational& operator++(rational& a)
{
	rational w(1, 1);
	rational b;
	b = a;
	a = a + w;
	a = b;
	return a;

}
rational operator++(rational a, int)
{
	rational w(1, 1);
	a = a + w;
	return a;

}
ostream& operator<<(ostream& os, rational a)   
{
	a = cut(a);
    os << a.numerator << "/" << a.denominator << endl;
    return os; 
}
istream& operator>>(istream& is, rational& a)
{
	is >> a.numerator >> a.denominator;
	return is;
}

int main()
{
	rational a(16, 0);
	rational b(7, 8);
	rational c(1, 1);
	
	c = a + b;
	++c;
	cout << c;
	return 0;
}