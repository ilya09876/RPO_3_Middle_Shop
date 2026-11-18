#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

size_t maxStorageSize = 200;
size_t currentStorageSize = 0;

void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Кот\t\t\t"			L"Порода: \"Петерболд\"\t",
			L"Собака\t\t\t"			L"Порода: \"Ксолоитцкуинтли\"\t",
			L"Хомяк\t\t\t"			L"Порода: \"Обычный\"\t",
			L"Черепаха\t\t"			L"Порода: \"Свинорылая\"\t",
			L"Кролик\t\t\t"			L"Порода: \"Рекс\"\t",
			L"Конь\t\t\t"			L"Порода: \"Фалабелла\"\t",
			L"Клоп\t\t\t"			L"Порода: \"Гладыш\"",
			L"Морская свинка\t\t"	L"Порода: \"Лунуария\"\t\t",
			L"Жираф ручной\t\t"		L"Порода: \"Сетчатый\"\t\t",
			L"Касатка ручная\t\t"	L"Порода: \"Домосед\"\t\t"
		};
		size_t countArrStatic[staticSize]{ 14, 30, 9, 18, 23, 7, 22, 40, 10, 3 };
		double priceArrStatic[staticSize]{ 143.3, 210.4, 452.1, 377.3, 116.8, 287.2, 140.4, 210.3, 899.9, 1900.0 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArrStatic, idArr, sizeSt);
		FillArray(nameArrStatic, nameArr, sizeSt);
		FillArray(countArrStatic, countArr, sizeSt);
		FillArray(priceArrStatic, priceArr, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}
		isStorageCreated = true;
	}
	
	else if (mode == 1)
	{
		// TO_DO
	}

	else
	{
		std::wcout << L"Склад уже создан\n\n";
		Sleep(500);
	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");

		std::wcout << L"Товары \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");
	}

	else if (mode == 1)
	{
		system("cls");

		std::wcout << L"Пополнение товаров \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Свободного метса: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(1);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товаров\n\n";
			system("pause");
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;

			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 && count > maxStorageSize - currentStorageSize)
					{
						// Продолжить...
					}
				}
			}
		}
	}
}
