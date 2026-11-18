#ifndef _SERVICE_HPP_
#define _SERVICE_HPP_

#include <iostream>
#include <string>
#include <Windows.h>

void Getline(std::wstring& str);

template <class ArrType>
void FillArray(ArrType* staticArr, ArrType* dynamicArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

#endif // !_SERVICE_HPP_