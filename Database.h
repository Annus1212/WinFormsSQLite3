#include "sqlite/sqlite3.h"
#include <string.h>
#include "Stringer.h"
#include <string>

using namespace System::Windows::Forms;
using namespace System;

#pragma once
class Database {

	sqlite3* DB;
public:

	Database();
	~Database();

	Result& execSQL(const char* SQL);

		/// <summary>
		/// Checks if the Credientals(Username and Password) are correct or not
		/// </summary>
		/// <param name="username">Username of User</param>
		/// <param name="password">Password of User</param>
		/// <returns>True if correct, false otherwise</returns>
		bool isValidCredientals(String^ username, String^ password);

		/// <summary>
		/// Inserts the User Feedback in the Database
		/// </summary>
		/// <param name="feedbackContent">Content of User Feedback</param>
		void insertFeedback(String^ feedbackContent);

		/// <summary>
		/// Gets a List of All the Inserted Feedbacks sorted by Date Posted in Ascending Order
		/// Size: You can use .size() method to get List of Feedbacks from string pointer
		/// </summary>
		/// <returns>Returns a Pointer that Points to an Array of Feedback Content, NullPtr if no Feedback Exists</returns>
		std::string* getListofFeedbacks();

		/// <summary>
		/// Checks if there is any Feedback in the Database
		/// </summary>
		/// <returns>True, If feedback exists otherwise false</returns>
		bool systemHasFeedbacks();

		/// <summary>
		/// Gets the Username of the Admin saved in DB
		/// </summary>
		/// <returns>Admin Username</returns>
		std::string getAdminUsername();

		/// <summary>
		/// Changes the Admin username to new username
		/// </summary>
		/// <param name="newUsername">New Username of Admin</param>
		/// <returns>True, If changed Successfully, Otherwise False</returns>
		bool changeAdminUsername(String^ newUsername);

		/// <summary>
		/// Changes the Admin Password to new Password
		/// </summary>
		/// <param name="newPassword">Admin New Password</param>
		/// <returns>True, If changed Successfully, Otherwise False</returns>
		bool changeAdminPassword(String^ newPassword);

		/// <summary>
		/// Saves the Electric Meters Quantity in Database
		/// </summary>
		/// <param name="meter1Value">Electric Meter 1 Quantity</param>
		/// <param name="meter2Value">Electric Meter 2 Quantity</param>
		/// <param name="meter3Value">Electric Meter 3 Quantity</param>
		/// <returns>True, If saved Successfully, Otherwise False</returns>
		bool SaveMeterValuesToDatabase(int meter1Value, int meter2Value, int meter3Value);

		/// <summary>
		/// Gets the Quantity of 1 Phase Meter.
		/// </summary>
		/// <returns>Quantity of 1 Phase Meters</returns>
		int get1PhaseMeterQuantity();

		/// <summary>
		/// Gets the Quantity of 2 Phase Meter.
		/// </summary>
		/// <returns>Quantity of 2 Phase Meters</returns>
		int get2PhaseMeterQuantity();

		/// <summary>
		/// Gets the Quantity of 3 Phase Meter.
		/// </summary>
		/// <returns>Quantity of 3 Phase Meters</returns>
		int get3PhaseMeterQuantity();

		/// <summary>
		/// Updates the Quantity of 1 Phase Meter to New Quantity.
		/// </summary>
		/// <returns>New Quantity of 1 Phase Meters</returns>
		bool set1PhaseMeterQuantity(int meter1Quantity);

		/// <summary>
		/// Updates the Quantity of 2 Phase Meter to New Quantity.
		/// </summary>
		/// <returns>New Quantity of 2 Phase Meters</returns>
		bool set2PhaseMeterQuantity(int meter2Quantity);

		/// <summary>
		/// Updates the Quantity of 3 Phase Meter to New Quantity.
		/// </summary>
		/// <returns>New Quantity of 3 Phase Meters</returns>
		bool set3PhaseMeterQuantity(int meter3Quantity);

		/// <summary>
		/// Inserts a New Appliances Data
		/// </summary>
		/// <param name="name">Appliance Name</param>
		/// <param name="power">Appliance Power</param>
		/// <param name="hour">Appliance Duration Usage</param>
		/// <param name="time">Appliance Usage Preferences</param>
		/// <param name="meterID">Meter Type where the Appliance Runs (1: 1Phase, 2: 2Phase, 3:3Phase)</param>
		void insertAppliancesData(String^ name, String^ power, String^ hour, String^ time, String^ meterID = "1");

		/// <summary>
		/// Updates an Existing Appliance Data
		/// </summary>
		/// <param name="id">RowID(DB Primary Key) of the Appliance</param>
		/// <param name="name">Appliance Name</param>
		/// <param name="power">Appliance Power</param>
		/// <param name="hour">Appliance Duration Usage</param>
		/// <param name="time">Appliance Usage Preferences</param>
		/// <param name="meterID">Meter Type where the Appliance Runs (1: 1Phase, 2: 2Phase, 3:3Phase)</param>
		void updateAppliancesData(String^ id, String^ name, String^ power, String^ hour, String^ time, String^ meterID = "1");

		/// <summary>
		/// Deletes an Appliance Data
		/// </summary>
		/// <param name="id">RowID(DB Primary Key) of the Appliance</param>
		void deleteAppliancesData(String^ id);

		/// <summary>
		/// Gets the Count of All the Appliances
		/// </summary>
		/// <returns>Count of Appliances Saved</returns>
		int getListOfAppliances();

		/// <summary>
		/// Checks if an Appliance is saved against a Primary Key (ID) 
		/// </summary>
		/// <param name="id">Primary Key of the Appliance</param>
		/// <returns>True if there is an Appliance is saved against the id, False otherwise</returns>
		bool isValidAppliance(String^ id);
		std::string DisplayHelloWorld();
};