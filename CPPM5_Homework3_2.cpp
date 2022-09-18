#include <iostream>
#include <windows.h>

class Counter
{
public:
	Counter()
	{
		_value = 1;
	}

	Counter(int value)
	{
		_value = value;
	}

	void increase()
	{
		++_value;
	}

	void decrease()
	{
		--_value;
	}

	int getCurrent()
	{
		return _value;
	}
private:
	int _value;
};

class CounterDemonstrator
{
public:
	void demonstrate()
	{
		char cmd;
		Counter cnt = initCounter();
		do
		{
			std::cout << "Введите команду ('+', '-', '=' или 'x'(англ.)): ";
			std::cin >> cmd;

			switch (cmd)
			{
			case CMD_INCREASE: cnt.increase();
				break;
			case CMD_DECREASE: cnt.decrease();
				break;
			case CMD_GET_CURRENT: std::cout << cnt.getCurrent() << std::endl;
				break;
			}
		} while (cmd != CMD_EXIT);
		std::cout << "До свидания!";
	}
private:
	const static char CMD_INCREASE = '+';
	const static const char CMD_DECREASE = '-';
	const static const char CMD_GET_CURRENT = '=';
	const static char CMD_EXIT = 'x';
	const std::string CMD_YES = "да";
	const std::string CMD_NO = "нет";

	Counter initCounter()
	{
		std::string answer;
		bool answerValid = false;
		bool needInitialValue = false;

		do
		{
			std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
			std::cin >> answer;
			answerValid = (needInitialValue = answer == CMD_YES) || answer == CMD_NO;
		} while (!answerValid);

		if (needInitialValue)
		{
			int initialValue = 0;
			std::cout << "Введите начальное значение счётчика: ";
			std::cin >> initialValue;
			return Counter(initialValue);
		}

		return Counter();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	CounterDemonstrator cntDemo;
	cntDemo.demonstrate();
}

