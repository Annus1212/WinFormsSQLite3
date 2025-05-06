#include <iostream>
#include <string>

//using namespace std;

#pragma once
class StringList
{
private:
	std::string* data;
	int cols;
	int count;
	std::string& toStr(const char* data)
	{
		std::string* temp = new std::string{""};
		for (int i = 0; data[i] != 0; i++)
		{
			temp += data[i];
		}
		temp += '\0';
		return *temp;
	}
public:
	StringList()
	{
		this->cols = 0;
		count = 0;
		data = nullptr;
	}
	StringList(int cols)
	{
		this->rest(cols);
	}

	void rest(int cols)
	{
		this->cols = cols;
		count = 0;
		data = new std::string[cols];
	}

	void push(const unsigned char* data)
	{
		if (data == nullptr)
			return;
		for (int i = 0; data[i] != 0; i++)
		{
			this->data[count] += data[i];
		}
		this->data[count++] += '\0';
	}

	void push(const char* data)
	{
		if (data == nullptr)
			return;
		for (int i = 0; data[i] != 0; i++)
		{
			this->data[count] += data[i];
		}
		this->data[count++] += '\0';
	}

	std::string& operator[](int index)
	{
		return this->data[index];
	}

	~StringList()
	{
		delete[] data;
	}
};

class Result
{
	StringList* data;

public:
	const int colsCount;
	int rows;

	Result(int colCount) : colsCount(colCount)
	{
		data = nullptr;
		rows = 0;
	}

	void push(StringList& temp2)
	{
		StringList* temp = new StringList[rows + 1];
		for (int i = 0; i < rows; i++)
		{
			temp[i].rest(colsCount);
			for (int j = 0; j < colsCount; j++)
			{
				temp[i].push(data[i][j].c_str());
			}
		}
		temp[rows].rest(colsCount);
		for (int i = 0; i < colsCount; i++)
		{
			temp[rows].push(temp2[i].c_str());
		}
		rows++;
		delete[] data;
		data = temp;
	}

	StringList& operator[](int index)
	{
		return this->data[index];
	}

	~Result()
	{
		delete[] data;
	}
};