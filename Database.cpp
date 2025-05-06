#include "Database.h"
#include "sqlite/sqlite3.h"
#include "Stringer.h"
#include "Globals.h"
#include <ctime>

using namespace System;
using namespace std;

bool Database::isValidCredientals(String^ username, String^ password)
{
	string sql = "SELECT username, password from Admin where username='" + Globals::ToSystemStr(username) + "' and password='" + Globals::ToSystemStr(password) + "';";
	Result ret = execSQL(sql.c_str());
	return ret.rows != 0;
}

void Database::insertFeedback(String^ feedbackContent)
{
	string timestamp = to_string(static_cast<unsigned int>(time(nullptr)));
	string sql = "INSERT INTO Feedback (Content, PostDate, Status) VALUES ('"+Globals::ToSystemStr(feedbackContent)+"'," + timestamp + ", 'Pending');";
	Result ret = execSQL(sql.c_str());
}

std::string* Database::getListofFeedbacks()
{
	string sql = "SELECT Content FROM Feedback ORDER BY PostDate;";
	Result ret = execSQL(sql.c_str());
	if (ret.rows == 0)
		return nullptr;
	std::string* contentList = new std::string[ret.rows];
	for (int i = 0; i < ret.rows; i++)
	{
		contentList[i] = ret[i][0];
	}
	return contentList;
}

bool Database::systemHasFeedbacks()
{
	string sql = "SELECT Content FROM Feedback;";
	Result ret = execSQL(sql.c_str());
	return ret.rows != 0;
}

std::string Database::getAdminUsername()
{
	string sql = "SELECT username FROM Admin;";
	Result ret = execSQL(sql.c_str());
	return ret[0][0];
}

bool Database::changeAdminUsername(String^ newUsername)
{
	string sql = "UPDATE Admin SET username='" + Globals::ToSystemStr(newUsername) + "' WHERE username='" + this->getAdminUsername().c_str() + "';";
	Result ret = execSQL(sql.c_str());
	return true;
}

bool Database::changeAdminPassword(String^ newPassword)
{
	string adminUsername = this->getAdminUsername();
	string sql = "UPDATE Admin SET password='" + Globals::ToSystemStr(newPassword) + "' WHERE username='" + adminUsername.c_str() + "';";
	Result ret = execSQL(sql.c_str());
	return true;
}

bool Database::SaveMeterValuesToDatabase(int meter1Value, int meter2Value, int meter3Value)
{
	int meterArr[] = { meter1Value, meter2Value, meter3Value };
	for (int i = 0; i < 3; i++)
	{
		string sql = "UPDATE Meter SET Quantity=" + std::to_string(meterArr[i]) + " WHERE id = " + std::to_string(i+1) + ";";
		execSQL(sql.c_str());
	}
	return true;
}

int Database::get1PhaseMeterQuantity()
{
	string sql = "SELECT Quantity From Meter WHERE id = 1;";
	Result ret = execSQL(sql.c_str());
	return Int32::Parse(Globals::ToStdString(ret[0][0]));
}

int Database::get2PhaseMeterQuantity()
{
	string sql = "SELECT Quantity From Meter WHERE id = 2;";
	Result ret = execSQL(sql.c_str());
	return Int32::Parse(Globals::ToStdString(ret[0][0]));
}

int Database::get3PhaseMeterQuantity()
{
	string sql = "SELECT Quantity From Meter WHERE id = 3;";
	Result ret = execSQL(sql.c_str());
	return Int32::Parse(Globals::ToStdString(ret[0][0]));
}

bool Database::set1PhaseMeterQuantity(int meter1Quantity)
{
	string sql = "UPDATE Meter SET Quantity=" + std::to_string(meter1Quantity) + " WHERE id = 1;";
	execSQL(sql.c_str());
	return true;
}

bool Database::set2PhaseMeterQuantity(int meter2Quantity)
{
	string sql = "UPDATE Meter SET Quantity=" + std::to_string(meter2Quantity) + " WHERE id = 1;";
	execSQL(sql.c_str());
	return false;
}

bool Database::set3PhaseMeterQuantity(int meter3Quantity)
{
	string sql = "UPDATE Meter SET Quantity=" + std::to_string(meter3Quantity) + " WHERE id = 1;";
	execSQL(sql.c_str());
	return false;
}

void Database::insertAppliancesData(String^ name, String^ power, String^ hour, String^ time, String^ meterID)
{
	string sql = "INSERT INTO Appliances (Name, Quantity, Power, MeterID, Days) VALUES ('" + Globals::ToSystemStr(name) + "'," + Globals::ToSystemStr(hour) + "," + Globals::ToSystemStr(power) + ","+Globals::ToSystemStr(meterID) + "," + Globals::ToSystemStr(time) + ");";
	execSQL(sql.c_str());
}

void Database::updateAppliancesData(String^ id, String^ name, String^ power, String^ hour, String^ time, String ^ meterID)
{
	string sql = "UPDATE Appliances SET Name='"+ Globals::ToSystemStr(name)+"', Power="+ Globals::ToSystemStr(power) + ", Quantity="+ Globals::ToSystemStr(hour) + ", Days=" + Globals::ToSystemStr(time) + ", MeterID=" + Globals::ToSystemStr(meterID) + " WHERE id = " + Globals::ToSystemStr(id) + ";";
	execSQL(sql.c_str());
}

void Database::deleteAppliancesData(String^ id)
{
	string sql = "DELETE FROM Appliances WHERE id = " + Globals::ToSystemStr(id) + ";";
	execSQL(sql.c_str());
}

int Database::getListOfAppliances()
{
	string sql = "SELECT id from Appliances;";
	Result ret = execSQL(sql.c_str());
	return ret.rows;
}

bool Database::isValidAppliance(String^ id)
{
	string sql = "SELECT * from Appliances where id = " + Globals::ToSystemStr(id) + ";";
	Result ret = execSQL(sql.c_str());
	return ret.rows != 0;
}

string Database::DisplayHelloWorld()
{
	string sql = "SELECT 'Hello World';";
	Result ret = execSQL(sql.c_str());
	return ret[0][0];
}