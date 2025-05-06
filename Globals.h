#include "sqlite/sqlite3.h"
#include <iostream>
#include "Database.h"

//class Database

using namespace System::Runtime::InteropServices;

#pragma once
public ref class Globals {
	/// <summary>
	/// Debugging Flag
	/// </summary>
	public: static bool DEBUGGING;
	/// <summary>
	/// Main Connection to the Database
	/// </summary>
	public: static Database* DB;
	/// <summary>
	/// Username of the Current Logged User. -1 If User is not Logged in.
	/// </summary>
	public: static String^ ActiveUsername;
	/// <summary>
	/// Converts a Marshal(.NET) String into String.
	/// </summary>
	/// <param name="str">Marshal(.NET) String</param>
	/// <returns>String Equivalent of Marshal(.NET) String</returns>
	public: static std::string ToSystemStr(System::String^ str)
	{
		IntPtr ptr = Marshal::StringToHGlobalAnsi(str);
		const char* formattedStr = static_cast<const char*>(ptr.ToPointer());
		return std::string(formattedStr);
	}
	/// <summary>
	/// Converts a String into Marshal(.NET) String.
	/// </summary>
	/// <param name="str">std::string</param>
	/// <returns>Marshal String Equivalent of String</returns>
	public: static System::String^ ToStdString(std::string str)
	{
		System::String^ newSystemString = gcnew String(str.c_str());
		return newSystemString;
	}

public: static bool isEmptyBoxes(Windows::Forms::Form^ input)
{
	for each (Control ^ var in input->Controls)
	{
		if (Globals::DEBUGGING)
			break;
		if (var->GetType()->Name == "TextBox" && var->Text == "")
		{
			return true;
		}
	}
	return false;
}

public: static bool isEmptyBoxes(Windows::Forms::UserControl^ input)
{
	for each (Control ^ var in input->Controls)
	{
		if (Globals::DEBUGGING)
			break;
		if (var->GetType()->Name == "TextBox" && var->Text == "")
		{
			return true;
		}
	}
	return false;
}
	  /// <summary>
  /// Identify SQL injections
  /// </summary>
  /// <param name="str">System::string</param>
  /// <returns>true if string contains SQL injection characters, zero otherwise</returns>
public:static bool CheckSQL_injection(System::String^ str)
{
	std::string str1 = Globals::ToSystemStr(str);
	char characters[] = { '=',';','$','\n','"','-','\'' };
	for (char i : str1)
	{
		for (char j : characters)
		{
			if (i == j)
			{
				return true;
			}
		}
	}
	return false;
}
};