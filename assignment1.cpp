#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int choice;
    string command;
//do while allows the menu to display at least once
    do {
        //display menu
        cout << "warning: dir and cd do not work with unix" << endl;
        cout << "1. List directory contents ----- dir (Windows equivalent of ls " << endl;
        cout << "2. Print working directory ----- cd (print directory - Windows equivalent of pwd)" << endl;
        cout << "3. Create a new directory ----- mkdir (create a new directory)" << endl;
        cout << "4. Display a message ----- echo (display a message)" << endl;
        cout << "5. Concatenate and display content of a file ----- type (Windows equivalent of cat)" << endl;
        cout << "6. Exit" << endl;

        //take input
        cout << "input (1-6) to indicate command: ";
        cin >> choice;

        //take choice and assign system command
       if (choice == 1) {
            command = "dir";
        } else if (choice == 2) {
            command = "cd";
        } else if (choice == 3) {
            cout << "enter directory name to create: ";
            cin.ignore();
            getline(cin, command);
            command = "mkdir " + command;
        } else if (choice == 4) {
            cout << "enter message to echo: ";
            cin.ignore(); //clear buffer
            getline(cin, command); //take input for command
            command = "echo " + command; //concat for formatting
        } else if (choice == 5) {
            cout << "enter the filename to `type`: ";
            cin.ignore(); //clear buffer
            getline(cin, command); //take input
            command = "type " + command; //concat for formatting
        } else if (choice == 6) {
            cout << "exiting program." << endl;
            return 0;
        } else {
            cout << "invalid input. enter number (1-6)." << endl;
            continue; //restart until a valid input is given (1-6)
        }

        //execute command and display success or fail
        cout << "executing: " << command << endl;
        int result = system(command.c_str());

        if (result == 0) {
            cout << "command executed successfully." << endl;
        } else {
            cout << "command execution failed." << endl;
        }
        cout << endl << endl;

    //program will continue infinitely unless "6" is entered
    } while (true);

    return 0;
}