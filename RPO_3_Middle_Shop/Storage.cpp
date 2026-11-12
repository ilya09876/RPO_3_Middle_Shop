#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

void CreateStorage(int mode)
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
	
}