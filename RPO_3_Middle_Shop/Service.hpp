#ifndef _SERVICE_HPP_
#define _SERVICE_HPP_

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

void Getline(std::wstring& str);
bool IsNumber(const std::wstring& str);
bool IsNotSame(const std::wstring& chooseName, std::wstring* nameArr, size_t commonSize);

__forceinline void Err()
{
	std::wcout << L"Некорректный ввод\n";
	system("pause");
}

template <class ArrType>
void FillArray(ArrType* staticArr, ArrType* dynamicArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template <class ArrType>
void ArrPushBack(ArrType*& arr, size_t size)
{
	size++;
	ArrType* temp = new ArrType[size];
	for (size_t i = 0; i < size -1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[] temp;
}

#endif // !_SERVICE_HPP_