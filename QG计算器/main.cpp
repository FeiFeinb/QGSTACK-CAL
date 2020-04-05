#include "calculator.h"
#include"arrqgstack.h"

void iloveqg();

int main()
{
	iloveqg();
	system("pause");
}

template<class T, int SIZE = 100>
bool hiqg(QGARRSTACK<T>& qq)
{
	while (true) {
		std::cout << "1.压栈 2.弹栈 3.顶部 4.清空 5.大小 6.返回" << std::endl;
		std::string way;
		std::cin >> way;
		if (way == "1") {
			std::cout << "输入存入的数字" << std::endl;
			T val;
			std::cin >> val;
			qq.push(val);
		}
		else if (way == "2") {
			qq.pop();
		}
		else if (way == "3") {
			if (!qq.isEmpty())
				std::cout << qq.top() << std::endl;
			else
				std::cout << "EMPTY!" << std::endl;
		}
		else if (way == "4") {
			qq.clear();
		}
		else if (way == "5") {
			std::cout << "栈中元素的个数为" << qq.howBig() << std::endl;
		}
		else if (way == "6") {
			break;
		}
		else {
			std::cout << "输入错误" << std::endl;
			system("pause");
		}
	}
	return false;
}

void iloveqg() {
	while (true) {
		system("cls");
		std::string typeselect;
		std::cout << "请输入int，string，double，float,calculator,数组栈的默认容量为100" << std::endl;
		std::cin >> typeselect;
		if (typeselect == "int") {
			QGARRSTACK<int> qgarr;
			while (hiqg(qgarr)) {};
		}
		else if (typeselect == "string") {
			QGARRSTACK<std::string> qgarr;
			while (hiqg(qgarr)) {};
		}
		else if (typeselect == "double") {
			QGARRSTACK<double> qgarr;
			while (hiqg(qgarr)) {};
		}
		else if (typeselect == "float") {
			QGARRSTACK<float> qgarr;
			while (hiqg(qgarr)) {};
		}
		else if (typeselect == "calculator") {
			std::string math;
			std::cout << "请输入计算式" << std::endl;
			std::cin >> math;
			Calculator cal(math);
			if (cal.isCorrect())
			{
				cal.turnBackfix();
				cal.getResult();
			}
			else
				std::cout << "表达式输入错误" << std::endl;
		}
		else
			std::cout << "输入错误" << std::endl;
		system("pause");
	}
}
