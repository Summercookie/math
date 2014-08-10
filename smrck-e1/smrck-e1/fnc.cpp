#include "fnc.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

fnc::fnc()
{
	string str = get_str();
	fill_elements_set();
	fill_function(str);
}

fnc::fnc(string str)
{
	int k = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') k++;
		if (str[i] == ')') k--;
		if (k < 0) stop = 1;
	}
	if (k) stop = 1;

	fill_elements_set();
	fill_function(str);
}

fnc::~fnc()
{
}

string fnc::get_str()
{
	cout << "‘ормула: ";
	string str;
	getline(cin, str);

	int k = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') k++;
		if (str[i] == ')') k--;
		if (k < 0) stop = 1;
	}
	if (k) stop = 1;

	return str;
}

void fnc::fill_elements_set()
{
	string fnc_set[] = {"", "x", "+", "-", "*", "/", "^", "ln", "sin", "cos", "tg", "ctg", "(", ")" };

	for (int i = 0; i < 13; i++)
	{
		elements_set[i].contents = fnc_set[i];
		if (i < 2) elements_set[i].priority = 0;
		else
		if ((i > 1) && (i < 4)) elements_set[i].priority = 1;
		else elements_set[i].priority = 2;
	}
}

int fnc::check(std::string mrph)
{
	string tmp = mrph;
	for (int i = 0; i < tmp.length();)
	{
		if ((tmp[i] >= 48) && (tmp[i] <= 57)) tmp.erase(i, 1);
		else i++;
	}
	if ((tmp.empty()) || (tmp == ".")) return  0;

	for (int i = 1; i < 12; i++)
	if (mrph == elements_set[i].contents) return i;

	return -1;
}

float fnc::strtonum(std::string mrph)
{
	bool point = 0;
	float num = 0, fraction = 0;

	for (int i = 0; i < mrph.length(); i++)
	{
		if (mrph[i] == '.') point = 1;
		else
		if (point) fraction = fraction * 10 + ((int)mrph[i] - 48);
		else num = num * 10 + ((int)mrph[i] - 48);
	}

	while (fraction > 1) fraction /= 10;
	return (num + fraction);
}

void fnc::fill_function(std::string str)
{
	stack<f_element> operations;
	
	for (int i = 0; i < str.length(); i++)
	{
		string mrph;														//morphe - синтаксическа€ единица
		while ((str[i] != ' ') && (str[i] != '(') && (str[i] != ')') && (mrph != "+") && (mrph != "-") && (mrph != "*") && (mrph != "/") && (mrph != "^") && (i < str.length()))
		{
			mrph += str[i];
			i++;
		}

		if (!mrph.empty())
		{
			switch (check(mrph))
			{
			case -1:
				stop = 1;
				break;
			case 0:
			{
					  f_element tmp;
					  tmp.contents = mrph;
					  tmp.priority = 0;
					  tmp.value = strtonum(mrph);
					  function.push_back(tmp);
			} break;
			case 1:
				function.push_back(elements_set[1]);
				break;

			default:
			{
					   //≈сли стек пуст || приоритет операции в стеке <= операции прочитанной за исключением открывающей скобки
					   if (operations.empty() || (operations.top().priority <= elements_set[check(mrph)].priority) || (operations.top().contents == "(")) 
						   operations.push(elements_set[check(mrph)]);
					   else
					   {
						   while (!operations.empty() && (operations.top().priority > elements_set[check(mrph)].priority) && (operations.top().contents != "("))
							   //ѕока стек не пуст && приоритет операции в топе выше текущей  && не одна из скобок
						   {
							   function.push_back(operations.top());
							   operations.pop();
						   }
						   operations.push(elements_set[check(mrph)]);
					   }
			}
				break;
			}
		}
		if (str[i] == '(') operations.push(elements_set[12]);
		if (str[i] == ')') 
		{
			while (operations.top().contents != "(")
			{
				function.push_back(operations.top());
				operations.pop();
			}
			operations.pop();

			//≈сли стек пуст, то проверка не происходит
			if ((!operations.empty()) && ((operations.top().contents == "^") || (operations.top().contents == "sin") || (operations.top().contents == "cos") || (operations.top().contents == "tg") || (operations.top().contents == "ctg")))
			{
				function.push_back(operations.top());
				operations.pop();
			}
		}
	}

	while (!operations.empty())
	{
		function.push_back(operations.top());
		operations.pop();
	}
}

void fnc::out()
{
	if (function.empty()) cout << "Empty!\n";
	else for (vector<f_element>::iterator it = function.begin(); it != function.end(); it++)
	cout <<(*it).contents << ' ';
}

int fnc::false_str()
{
	if (stop) return 1;
	else return 0;
}

float fnc::calculation(float x)
{
	for (vector<f_element>::iterator it = function.begin(); it != function.end(); it++)
	{
		int i = 0;
		for (i = 0; i < 12; i++)

		switch (i)
		{
			
		}
	}
}