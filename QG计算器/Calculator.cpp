#include"calculator.h"
bool Calculator::isCorrect()
{
	//std::stack<char> k;
	QGSTACK<char> k;
	if (infix.front() == '*' || infix.front() == '/' || infix.back() == '*' || infix.back() == '/')
		return false;
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '/' && infix[i + 1] == '0')
			return false;
		if ((!IsOperand(infix[i])) && (!IsOperator(infix[i])) && (!Isfrontk(infix[i])) && (!Isbackk(infix[i])))
			return false;
		if (infix[i] == '(') //括号判断
			k.push(infix[i]);
		else if (infix[i] == ')')
		{
			if (k.empty() || !(k.top() == '(' && infix[i] == ')'))
				return false;
			else
				k.pop();
		}
	}
	return k.empty() ? true : false;
}
void Calculator::turnBackfix()
{
	for (int i = 0; i < infix.size(); i++) //遍历中缀算式
	{
		if (Isfrontk(infix[i]))   //判断
			chars.push(infix[i]);
		else if (IsOperand(infix[i]))  //判断是否为数字
		{
			backfix += infix[i];
		}
		else if (IsOperator(infix[i]))  //判断是否为运算符
		{
			if (i == 0 || IsOperator(infix[i - 1]) || Isfrontk(infix[i - 1])) //负数判断
				backfix += infix[i];
			else {
				while (!chars.empty() && chars.top() != '(' && Ishigher(infix[i], chars.top())) //优先级左＜=右，true
				{
					backfix += ' ';
					backfix += chars.top();
					chars.pop();  // 弹出
				}
				chars.push(infix[i]); //往里塞
				backfix += ' ';
			}
		}
		else if (Isbackk(infix[i]))  //判断 ）
		{
			while (chars.top() != '(') //栈顶不为 ( ，且栈不为空
			{
				if (chars.empty()) //栈为空 （保护措施）
				{
					std::cout << "error" << std::endl;  //输出“error”
					return;
				}
				backfix += ' ';
				backfix += chars.top();
				chars.pop();
				if (chars.empty()) //栈为空 （保护措施）
				{
					std::cout << "error" << std::endl;
					return;
				}
			}
			chars.pop();
		}
	}
	//遍历结束，开始将栈里储存的运算符释放到后缀表达式中
	while (!chars.empty())  //栈不为空
	{
		if (chars.top() == '(')
		{
			std::cout << "error" << std::endl;
			return;
		}
		else
		{
			backfix += ' ';
			backfix += chars.top();
			chars.pop();
		}
	}
	//栈空了
	std::cout << "后缀表达式为" <<  backfix << std::endl; //输出最终结果--后缀表达式
}
bool Calculator::Isfrontk(const char& c)
{
	if (c == '(')
		return true;
	return false;
}
bool Calculator::Isbackk(const char& c)
{
	if (c == ')')
		return true;
	return false;
}
bool Calculator::IsOperand(const char& c)
{
	if (c >= '0' && c <= '9')
		return true;
	else if (c == '.')
		return true;
	return false;
}
bool Calculator::IsOperator(const char& c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}
bool Calculator::Ishigher(const char& fixchar, const char& top)//比较优先级
{
	if (highvalue(fixchar) <= highvalue(top))
		return true;
	else
		return false;
}
int Calculator::highvalue(const char& c)
{
	int num = -1;
	switch (c)
	{
	case '+':
	case '-':
		num = 1;
		break;
	case '*':
	case '/':
		num = 2;
	}
	return num;
}
void Calculator::getResult()
{
	std::string temp;
	float val1;
	float val2;
	//std::stack<float> f;
	QGSTACK<float> f;
	for (int i = 0; i < backfix.size(); i++)
	{
		if (backfix[i] == ' ')
		{
			if (!temp.empty())
			{
				f.push(std::stof(temp));
				temp.clear();
			}
		}
		else if (IsOperator(backfix[i]) && (backfix[i + 1] == ' ' || backfix[i + 1] == '\0'))
		{
			switch (backfix[i])
			{
				case '+':
					val1 = f.top(); f.pop();
					val2 = f.top(); f.pop();
					f.push(val2 + val1);break;
				case '-':
					val1 = f.top(); f.pop();
					val2 = f.top(); f.pop();
					f.push(val2 - val1); break;
				case '/':
					val1 = f.top(); f.pop();
					val2 = f.top(); f.pop();
					f.push(val2 / val1); break;
				case '*':
					val1 = f.top(); f.pop();
					val2 = f.top(); f.pop();
					f.push(val2 * val1); break;
			}
		}
		else
			temp += backfix[i];
	}
	std::cout << f.top() << std::endl;
}