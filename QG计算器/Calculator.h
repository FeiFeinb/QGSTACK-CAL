#pragma once
#include<string>
#include <iostream>
#include"listqgstack.h"
class Calculator
{
private:
	std::string infix;      //中缀表达式
	std::string backfix;    //后缀表达式
	//std::stack<char> chars; //定义栈：chars
	QGSTACK<char> chars;
public:
	bool isCorrect();
	void turnBackfix();  //中缀转后缀
	void getResult();
	bool Isfrontk(const char& c); //判断是否为 (
	bool Isbackk(const char& c);  //判断是否为  ）
	bool IsOperator(const char& c); //判断是否为运算符
	bool IsOperand(const char& c); //判断是否为数字
	bool Ishigher(const char& fixchar, const char& top); //判断优先级
	int highvalue(const char& c); //优先级的数值
	Calculator(std::string math) : infix(math) {} //构造函数，人工输入中缀算式
};