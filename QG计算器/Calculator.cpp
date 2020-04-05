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
		if (infix[i] == '(') //�����ж�
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
	for (int i = 0; i < infix.size(); i++) //������׺��ʽ
	{
		if (Isfrontk(infix[i]))   //�ж�
			chars.push(infix[i]);
		else if (IsOperand(infix[i]))  //�ж��Ƿ�Ϊ����
		{
			backfix += infix[i];
		}
		else if (IsOperator(infix[i]))  //�ж��Ƿ�Ϊ�����
		{
			if (i == 0 || IsOperator(infix[i - 1]) || Isfrontk(infix[i - 1])) //�����ж�
				backfix += infix[i];
			else {
				while (!chars.empty() && chars.top() != '(' && Ishigher(infix[i], chars.top())) //���ȼ���=�ң�true
				{
					backfix += ' ';
					backfix += chars.top();
					chars.pop();  // ����
				}
				chars.push(infix[i]); //������
				backfix += ' ';
			}
		}
		else if (Isbackk(infix[i]))  //�ж� ��
		{
			while (chars.top() != '(') //ջ����Ϊ ( ����ջ��Ϊ��
			{
				if (chars.empty()) //ջΪ�� ��������ʩ��
				{
					std::cout << "error" << std::endl;  //�����error��
					return;
				}
				backfix += ' ';
				backfix += chars.top();
				chars.pop();
				if (chars.empty()) //ջΪ�� ��������ʩ��
				{
					std::cout << "error" << std::endl;
					return;
				}
			}
			chars.pop();
		}
	}
	//������������ʼ��ջ�ﴢ���������ͷŵ���׺���ʽ��
	while (!chars.empty())  //ջ��Ϊ��
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
	//ջ����
	std::cout << "��׺���ʽΪ" <<  backfix << std::endl; //������ս��--��׺���ʽ
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
bool Calculator::Ishigher(const char& fixchar, const char& top)//�Ƚ����ȼ�
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