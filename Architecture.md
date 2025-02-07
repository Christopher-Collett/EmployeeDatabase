# DBView
dbview <file_path> <options>
    <file_path>   The path to the database file, which contains a properly formatted database header.
    <options>     ONE option from below (additional options will be ignored)

## Options
    -a <name>;<address>;<hours>     Add a new employee.
    -u <id>;<hours>                 Update employee hours.
    -c <id>;<name>;<address>        Update employee info.
    -d <id>                         Delete employee.
    -fn <name>                      Filter employees by name (displays up to 100).
    -fa <address>                   Filter employees by address (displays up to 100).
    -fh <hours>                     Filter employees by hours (displays up to 100).

# Quick Whiteboard of Architecture
- File I/O Component
    - Converts a struct (or structs) containing all employee data into a file format, and vice versa.
    - Ensures the file will not become corrupted through use of the database.
- Employee Array
    - An array of employee structs, each containing name, address and hours worked
- Add/Update Component
    - Add a new employee to the employee array
    - Find an employee by name and change their information (including name, if needed)
- Save/Load Component
    - Save an employee array using file I/O component
    - Load a new employee array using file I/O component
- Search Component
    - Find all matches of employees within the employee array using name, address, or hours worked as the criterion
- Console Component
    - Define commands available to users
    - Validate/sanitize user input before executing any command
    - Provide feedback to users when a command is executed
    - Retrieve and display data to users when queried
