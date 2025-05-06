#include <iostream>
#include <string>
#pragma once
public ref class STR {
	public: static char* ToSystemStr(char* str)
	{
		char* temp = new char[strlen(str) + 1];
		for (int i = 0; str[i] != 0; i++)
		{
			temp[i] = str[i];
		}
		temp[strlen(str)] = '\0';
		return temp;
	}

	public: static char* ToSystemStr(const char* str)
	{
		char* temp = new char[strlen(str)+1];
		for (int i = 0; str[i] != 0; i++)
		{
			temp[i] = str[i];
		}
		temp[strlen(str)] = '\0';
		return temp;
	}

	public: static std::string ToSystemStr(const unsigned char* str)
	{
		std::string* temp = new std::string;
		for (int i = 0; str[i] != 0; i++)
		{
			temp += str[i];
		}
		temp += '\0';
		return *temp;
	}
};