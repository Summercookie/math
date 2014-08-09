#include "fnc.h"

#include <iostream>
#include <string>
#include <vector>
//#include <stack>

using namespace std;

int main()
{
	setlocale(0, "Russian");

	cout << "Строчку сюда: ";
	string str;
	getline(cin,str);

	fnc lol(str);
	lol.out();
	cout << endl;

	system("pause");
	return 0;
}