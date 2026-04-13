#include <iostream>
#include <string>
#include <algorithm>
#include "src/TodoList.hpp"

using namespace std;

int main() {
    TodoList list;

    int choice;
    string input;

    while (true) {
        cout << "\n===== TODO LIST MENU =====\n";
        cout << "1. Add task\n";
        cout << "2. Complete task\n";
        cout << "3. Show all tasks\n";
        cout << "4. Show completed tasks\n";
        cout << "5. Show incomplete tasks\n";
        cout << "6. Delete task\n";
        cout << "7. Clear list\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

            case 1:
                cout << "Enter task: ";
                getline(cin, input);
                list.add(input);
                break;

            case 2:
                cout << "Enter task number or name: ";
                getline(cin, input);

                if (!input.empty() &&
                    all_of(input.begin(), input.end(), ::isdigit)) {
                    list.complete(stoi(input));
                    } else {
                        list.complete(input);
                    }
                break;

            case 3:
                list.all();
                break;

            case 4:
                list.showCompleted();
                break;

            case 5:
                list.showIncomplete();
                break;

            case 6:
                cout << "Enter task number or name: ";
                getline(cin, input);

                if (!input.empty() &&
                    all_of(input.begin(), input.end(), ::isdigit)) {
                    list.remove(stoi(input));
                    } else {
                        list.remove(input);
                    }
                break;

            case 7:
                list.clear();
                break;

            case 8:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}