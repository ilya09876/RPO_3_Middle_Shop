#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

size_t maxStorageSize = 200;
size_t currentStorageSize = 0;

double maxPrice = 99999;

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
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
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

	else if (mode == 2)
	{
		system("cls");

		std::wcout << L"Списание товаров \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Свободного метса: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}

	else if (mode == 3)
	{
		system("cls");

		std::wcout << L"Изменение цен \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");
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
					if (count < 0 || count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректное кол-во! На скалде осталось: " << maxStorageSize - currentStorageSize << L" cвободных мест\n\n";
						system("pause");
					}

					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L"-----> " << countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								system("pause");
								break;
							}
							
							else if (choose == L"2")
							{
								std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
								system("pause");
								break;
							}

							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(2);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списания товаров\n\n";
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
				std::wcout << L"Введите кол-во товара для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > countArr[id])
					{
						std::wcout << L"Некорректное кол-во! На складе всего: " << countArr[id] << L" едениц этого товара\n\n";
						system("pause");
					}

					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L"-----> " << countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								system("pause");
								break;
							}

							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
								system("pause");
								break;
							}

							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;

	while (true)
	{
		ShowStorage(3);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изменения цен\n\n";
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
				std::wcout << L"Введите новую цену товара: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					double price = std::stod(choosePrice);
					if (price < 0 || price > maxPrice)
					{
						std::wcout << L"Некорректная цена! Максимально возможная цена: " << maxPrice << L"\n\n";
						system("pause");
					}

					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L"-----> " << price << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Цена успешно изменена\n\n";
								priceArr[id] = price;
								// :)
								system("pause");
								break;
							}

							else if (choose == L"2")
							{
								std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
								system("pause");
								break;
							}

							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void ChangeStorage()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"Редактирование склада\n\n";
		std::wcout << L"1 - Добвать новый товар\n";
		std::wcout << L"2 - Изменить название товара\n";
		std::wcout << L"3 - Удалить товар\n";
		std::wcout << L"4 - Изменить лимиты склада\n";
		std::wcout << L"0 - Выход\n";
		Getline(choose);

		if (choose == L"1")
		{
			AddNewProduct();
		}
		else if (choose == L"2")
		{

		}
		else if (choose == L"3")
		{

		}
		else if (choose == L"4")
		{

		}
		else if (choose == L"0")
		{
			std::wcout << L"Выход из редактора склада\n\n";
			system("pasue");
			break;
		}
		else
		{
			Err();
		}
	}
}

void AddNewProduct()
{
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;

	while (true)
	{
		while (true)
		{
			system("cls");

			std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				system("pause");
				return;
			}
			
			if (chooseName.size() > 40 || chooseName.size() < 2)
			{
				std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 2 до 40 символов\n\n";
				system("pause");
			}

			if (IsNotSame(chooseName, nameArr, sizeSt))
			{
				break;
			}
			else
			{
				std::wcout << L"Данный товар уже есть на складе\n\n";
			}
		}

		while (true)
		{
			system("cls");

			std::wcout << L"Введите кол-во нового товара или \"exit\" для выхода: ";
			Getline(chooseCount);
			if (chooseCount == L"exit" || chooseCount == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				system("pause");
				return;
			}

			if (IsNumber(chooseCount))
			{
				count = std::stoull(chooseCount);

				if (count < 0 || count > maxStorageSize - currentStorageSize)
				{
					std::wcout << L"Некорректное колличество! Максимально возможное колличество " << maxStorageSize - currentStorageSize << "\n\n";
					system("pause");
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");

			std::wcout << L"Введите цену нового товара или \"exit\" для выхода: ";
			Getline(choosePrice);
			if (choosePrice == L"exit" || choosePrice == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				system("pause");
				return;
			}

			if (IsNumber(choosePrice))
			{
				 price = std::stod(choosePrice);

				if (price < 0 || price > maxPrice)
				{
					std::wcout << L"Некорректная цена! Максимально возможная цена " << maxPrice << "\n\n";
					system("pause");
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");

			std::wcout << L"Новый товар: " << chooseName << L"\n";
			std::wcout << L"Колличество: " << count << L"\n";
			std::wcout << L"Цена: " << price << L"\n";
			std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
			Getline(choose);

			if (choose == L"1")
			{
				std::wcout << L"Загрузка новых данных в базу данных...";
				Sleep(2000);

				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);
				sizeSt++;
				idArr[sizeSt - 1] = sizeSt;
				nameArr[sizeSt - 1] = chooseName;
				countArr[sizeSt - 1] = count;
				priceArr[sizeSt - 1] = price;
				currentStorageSize += count;
				// :)
				std::wcout << L"\n\nНовый товар успешно добавлен!\n\n";
			}

			else if (choose == L"2")
			{
				std::wcout << L"Отмена\n\n";
				system("pause");
				break;
			}

			else
			{
				Err();
			}
		}
	}
}