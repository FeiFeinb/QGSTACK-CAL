#pragma once
#include<string>
#include <iostream>
#include"listqgstack.h"
class Calculator
{
private:
	std::string infix;      //��׺���ʽ
	std::string backfix;    //��׺���ʽ
	//std::stack<char> chars; //����ջ��chars
	QGSTACK<char> chars;
public:
	bool isCorrect();
	void turnBackfix();  //��׺ת��׺
	void getResult();
	bool Isfrontk(const char& c); //�ж��Ƿ�Ϊ (
	bool Isbackk(const char& c);  //�ж��Ƿ�Ϊ  ��
	bool IsOperator(const char& c); //�ж��Ƿ�Ϊ�����
	bool IsOperand(const char& c); //�ж��Ƿ�Ϊ����
	bool Ishigher(const char& fixchar, const char& top); //�ж����ȼ�
	int highvalue(const char& c); //���ȼ�����ֵ
	Calculator(std::string math) : infix(math) {} //���캯�����˹�������׺��ʽ
};