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
	if (!lol.false_str()) lol.out();
	else cout << "ERROR!";
	cout << endl;

	system("pause");
	return 0;
}