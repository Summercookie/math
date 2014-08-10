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
	} elements_set[14];									//��������� ����� �������
	std::vector<f_element> function;					//�������
	bool stop = 0;										//���� �������� ���������� ���������

	std::string get_str();								//����� ��������� ������
	void fill_elements_set();							//���������� ����� �������
	int check(std::string mrph);						//�������� ����������� ��������� �� ������������ ��������� ��������� �������
	float strtonum(std::string mrph);					//�������������� ������ � ������������� �����
	void fill_function(std::string str);				//���������� �������

public:
	fnc();
	fnc(std::string str);
	~fnc();

	void out();
	int false_str();
	float calculation(float x);
};

