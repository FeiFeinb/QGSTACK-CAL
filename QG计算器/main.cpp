#include "calculator.h"
int main()
{
#if 0
	Calculator cal("");
	if (cal.isCorrect())
	{
		cal.turnBackfix();
		cal.getResult();
	}
	else
		std::cout << "���ʽ�������" << std::endl;
#endif
	QGSTACK<int> qgstack;
	qgstack.push(10);
	qgstack.push(20);
	std::cout << qgstack.size() << std::endl;
	qgstack.clear();
	std::cout << qgstack.size() << std::endl;
	system("pause");
}