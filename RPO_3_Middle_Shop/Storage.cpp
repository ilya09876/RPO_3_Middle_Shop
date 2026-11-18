#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

void CreateStorage(int mode)
{
	if (mode == 0)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Кот					Порода: \"Петерболд\"",
			L"Собака				Порода: \"Ксолоитцкуинтли\"",
			L"Хомяк					Порода: \"Обычный\"",
			L"Черепаха				Порода: \"Свинорылая\"",
			L"Кролик				Порода: \"Рекс\"",
			L"Конь					Порода: \"Фалабелла\"",
			L"Клоп					Порода: \"Гладыш\"",
			L"Морская свинка		Порода: \"Лунуария\"",
			L"Жираф ручной			Порода: \"Сетчатый\"",
			L"Касатка ручная		Порода: \"Домосед\""
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
	}
}