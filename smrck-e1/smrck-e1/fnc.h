#pragma once
#include <vector>
#include <string>

class fnc
{
private:
	struct f_element
	{
		std::string contents;
		int priority;
		int position;
		float value;
	} elements_set[14];									//Вероятные члены функции
	std::vector<f_element> function;					//Функция
	bool stop = 0;										//Флаг верности введенного выражения

	std::string get_str();								//Метод получения строки
	void fill_elements_set();							//Заполнение маски функций
	int check(std::string mrph);						//Проверка полученного выражения на соответствие возможным элементам функции
	float strtonum(std::string mrph);					//Преобразование строки в действтельное число
	void fill_function(std::string str);				//Заполнение функции

public:
	fnc();
	fnc(std::string str);
	~fnc();

	void out();
	int false_str();
	float calculation(float x);
};

