#include <io.h>
#include <fcntl.h>
#include "Authorization.hpp"
#include <iostream>

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	std::wcout << L"Hello Привет";

	Start();


	return 0;
}



/*
	Авторизация: ввод логина и пароля
	Аккаунты: бд пользователей + функции. Суперадмин, админ, пользователь
	Продажи: покупка, оплата, чек
	Склад: бд товаров, функции
	Служебные: всякое для работы программы
*/