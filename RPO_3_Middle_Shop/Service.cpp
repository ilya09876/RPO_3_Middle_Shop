#include "Service.hpp"

void Getline(std::wstring& str)
{
	std::getline(std::wcin, str, L'\n');
}

bool IsNumber(const std::wstring& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::wcout << L"Ошибка длины. Максимум 9-значное число\n\n";
		system("pause");
		return false;
	}

	for (size_t i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]))
		{
			if (!std::isdigit(str[i]))
			{
				std::wcout << L"Введённые данные";
				system("pause");
				return false;
			}
		}
		return true;
	}
}

bool IsNotSame(const std::wstring& chooseName, std::wstring* nameArr, size_t nameArrSize)
{
	for (size_t i = 0; i < nameArrSize; i++)
	{
		if (nameArr[i] == chooseName)
		{
			return false;
		}
	}
	return true;
}
