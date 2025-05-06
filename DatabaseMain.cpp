#include "Database.h"
#include "Globals.h"

inline System::String^ StdStringToSystemString(const std::string& std_str)
{
	System::String^ sys_str = gcnew System::String(std_str.c_str());
	return sys_str;
}

inline System::String^ StdStringToSystemString(const unsigned char* std_str)
{
	const char* dd = reinterpret_cast<const char*>(std_str);
	System::String^ sys_str = gcnew System::String(dd);
	return sys_str;
}

Database::Database()
{
	int exit = 0;
	// Here is the Relative Path of the Database.
	exit = sqlite3_open("Database.db", &DB);
	MessageBox::Show(exit.ToString());
	if (Globals::DEBUGGING)
		MessageBox::Show("Database Opened Successfully");
}

Database::~Database()
{
	sqlite3_close(DB);
}

Result& Database::execSQL(const char* SQL)
{
	sqlite3_stmt* stmt;
	int rc = sqlite3_prepare_v2(DB, SQL, -1, &stmt, NULL);

	rc = sqlite3_step(stmt);
	int colCount = sqlite3_column_count(stmt);
	Result* temp = new Result(colCount);
	if (Globals::DEBUGGING)
	{
		MessageBox::Show(StdStringToSystemString(std::to_string(rc)));
		MessageBox::Show(StdStringToSystemString(SQL));

	}
	while (rc != SQLITE_DONE && rc != SQLITE_OK)
	{
		StringList* tempList = new StringList(colCount);
		for (int colIndex = 0; colIndex < colCount; colIndex++)
		{
			const unsigned char* data = sqlite3_column_text(stmt, colIndex);
			if (data == nullptr)
				continue;
			//MessageBox::Show(StdStringToSystemString((data)));
			tempList->push(data);
		}
		temp->push(*tempList);
		rc = sqlite3_step(stmt);
	}
	rc = sqlite3_finalize(stmt);
	//MessageBox::Show(StdStringToSystemString(std::to_string(rc)));
	return *temp;
}