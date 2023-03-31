#include <iostream>
#include <iostream>     //g++ worker.cpp -o 1 -std=c++11
#include <fstream>
#include <unistd.h>
#include <vector>
#include <string>
#include <map>
#include<exception>
#include<stdexcept>
#include <string.h>
#include <iomanip>
#include <thread>

using namespace std;

class worker
{
	public:
			string name;
			int age;
			int salary;

			worker()
			{
				salary = 120;
				name = "Akakiy";
				age = 18;
			}
			worker(string name_, int age_, ifstream& input)
			{
				int salary_ = 0;
				input >> salary_; 
				if (age_ < 18)
				{
					throw invalid_argument("he/she is too young!!!!");
				}
				if (salary_ < 101)
				{
					throw invalid_argument("make salary bigger!!!!");
				}
				name = name_;
				age = age_;
				salary = salary_;

			}


};
			void dowork(ofstream& output, worker& a)
			{
				a.salary -= 1;
				try
				{
					if (a.salary == 100) 
						throw runtime_error("vosmutitsa");
				}
				catch(exception& ex)
				{
					//cout << setw(10) << left; 
					//cout << setfill('.');
					output<<a.name<<ex.what()<< ".is fired!!! "<<endl;
					//cout<<a.name<<ex.what()<< ".is fired!!! "<<endl;
					return;
				}

				if (a.salary > 100){


					output << setw(10) << left; 
					output << setfill('.');
					output<< a.name << "." << a.age << "." << a.salary<< "."<<endl;
					//cout<< a.name << "." << a.age << "." << a.salary<< "."<<endl;
				}
			}

int main()
{
	ifstream input("vvv.txt");
	ofstream output("ppp.txt", ios::app); // ----- куда выводим результат наш, открываем с правами a+
	output << setw(10) << left;   // ----- тут устанавливаем что у нас 10 ячеек в выводе, значит добавляем пустые символы
	output << setfill('.');
	worker a("akakiy", 20, input);
	worker b("vitek", 22, input);
	//cout << a.salary;
	// for(int i = 0; i < 21; i++)
	// {
	// 	dowork(output, a);
	// 	dowork(output, b);
	// }
	std::thread t1([&]()
    {
        for(auto i = 0; i < 100; i++)
            dowork(output, a);
    });
	std::thread t2([&]()
    {
        for(auto i = 0; i < 100; i++)
            dowork(output, b);
    });
    t1.join();
    t2.join();
	return 0;
}