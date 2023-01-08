#include <iostream>
#include <regex>
#include <string>
#include <Windows.h>

void ip(std::string temp)
{
	std::regex ip("((?:0|128|192|224|240|248|252|254|255)\.){3}(?:0|128|192|224|240|248|252|254|255)");
	if (regex_match(temp.c_str(), ip))
	{
		std::cout << "1 - ok" << std::endl;
	}
}

void proto(std::string temp)
{
	std::regex protocol("(?:https|http|ftp)");
	if (regex_search(temp.c_str(), protocol))
	{
		std::cout << "2 - ok" << std::endl;
	}
}

bool dt(std::string temp)
{
	std::regex dat("2023");		//расчитано лишь на получение реальной даты (32.13.2022 будет считаться нормой)
	if (regex_search(temp.c_str(), dat))
		return false;
	else
		return true;
}

void del_ws(std::string& temp)
{
	std::regex white_space("\\s");
	temp = regex_replace(temp.c_str(), white_space, "");
	std::cout << temp << std::endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string ipv4 = "255.255.255.255";
	ip(ipv4);
	std::string adr = "https:\/\/vk.com";
	proto(adr);
	std::string data = "22.12.2022";
	bool fl = dt(data);
	if (fl)
	{
		std::cout << "3 - ok" << std::endl;
	}

	std::string str = "abc de fg";
	del_ws(str);

	return 0;
}