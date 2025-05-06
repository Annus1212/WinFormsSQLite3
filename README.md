# WinFormsDB - C++/CLI WinForms SQLite Database Integration

This README provides guidance for setting up and working with the WinFormsDB project, which integrates SQLite3 with a C++/CLI WinForms application.

## Project Structure

The project consists of the following key files:

- **Globals.h**: Stores globally accessible data throughout the application
- **Database.h**: Contains declarations for CRUD functions (Create, Read, Update, Delete)
- **Database.cpp**: Implements the function bodies with database queries
- **DatabaseMain.cpp**: Handles SQLite3 database connection and query execution logic
- **STR.h** and **Stringer.h**: Helper files for string conversion between managed and unmanaged code

## Setup Instructions

### Required Files

Ensure these files are included in your project:
- Header Files: `Globals.h`, `Database.h`, `STR.h`, `Stringer.h`
- Source Files: `sqlite3.c`, `shell.c`, `Database.cpp`, `DatabaseMain.cpp`

### Configuration Steps

1. **Add Files to Project**:
   - Add all header files to your project
   - Add source files to a separate filter in your project

2. **Configure C Files**:
   - Select `sqlite3.c` and `shell.c` in the Solution Explorer
   - Right-click and select Properties
   - Navigate to C/C++ → General
   - Set "Common Language Runtime Support" to "No Common Language Runtime Support"

3. **Database Connection Setup**:
   - In your main form's initialization code (before `Application::Run(% form)`), create a Database object on the heap
   - Store the pointer in `Globals::DB`
   - Example:
     ```cpp
     Globals::DB = new Database();
     Application::Run(% form);
     ```

## Working with the Database

### Accessing Database Functions

Once properly set up, database functions can be accessed throughout the application:

```cpp
Globals::DB->functionName(parameters);
```

### Database Management

- For schema creation and one-time database modifications, use **DB Browser for SQLite**
- This GUI tool simplifies database setup and query debugging

### Data Handling

- The `execSQL` function returns data as a matrix of strings (Row × Column)
- Use the provided string conversion functions to convert between managed and unmanaged strings

### Debugging

- A DEBUGGING flag in the Globals file can be enabled to:
  - View return codes from database operations
  - See queries before execution

## String Conversion

Helper functions are provided for converting between `System::String^` and `std::string`:
- Use these functions when passing strings between managed UI code and unmanaged database code

## Getting Started

1. Set up the project structure as described above
2. Create your database schema using DB Browser for SQLite
3. Implement your database functions in Database.h and Database.cpp
4. Access these functions from your forms using the global database pointer

## Removing Sample Code

When starting your own project, you may remove any sample code provided in the function implementations that aren't relevant to your features.

## Reference

A video reference is provided to demonstrate adding the SQLite library to an existing WinForms project.