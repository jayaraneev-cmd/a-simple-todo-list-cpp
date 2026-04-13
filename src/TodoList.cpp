#include "TodoList.hpp"
#include <iostream>

using namespace std;

// ADD
void TodoList::add(const string& taskName) {
    if (taskName.empty()) {
        cout << "Invalid task.\n";
        return;
    }

    tasks.push_back({taskName, false});
}

// COMPLETE BY INDEX
void TodoList::complete(int index) {
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].completed = true;
    cout << "Completed: " << tasks[index - 1].name << endl;
}

// COMPLETE BY NAME
void TodoList::complete(const string& taskName) {
    for (auto& task : tasks) {
        if (task.name == taskName) {
            task.completed = true;
            cout << "Completed: " << taskName << endl;
            return;
        }
    }

    cout << "Task not found.\n";
}

// SHOW ALL
void TodoList::all() const {
    if (tasks.empty()) {
        cout << "No tasks.\n";
        return;
    }

    for (int i = 0; i < (int)tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].name
             << " [" << (tasks[i].completed ? "X" : " ") << "]\n";
    }
}

// SHOW COMPLETED
void TodoList::showCompleted() const {
    bool found = false;

    for (const auto& task : tasks) {
        if (task.completed) {
            cout << "- " << task.name << endl;
            found = true;
        }
    }

    if (!found) cout << "No completed tasks.\n";
}

// SHOW INCOMPLETE
void TodoList::showIncomplete() const {
    bool found = false;

    for (const auto& task : tasks) {
        if (!task.completed) {
            cout << "- " << task.name << endl;
            found = true;
        }
    }

    if (!found) cout << "No incomplete tasks.\n";
}

// REMOVE BY INDEX
void TodoList::remove(int index) {
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    cout << "Deleted: " << tasks[index - 1].name << endl;
    tasks.erase(tasks.begin() + index - 1);
}

// REMOVE BY NAME
void TodoList::remove(const string& taskName) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->name == taskName) {
            cout << "Deleted: " << it->name << endl;
            tasks.erase(it);
            return;
        }
    }

    cout << "Task not found.\n";
}

// CLEAR
void TodoList::clear() {
    tasks.clear();
    cout << "List cleared.\n";
}

// TEST HELP
bool TodoList::isCompleted(const string& taskName) const {
    for (const auto& task : tasks) {
        if (task.name == taskName) {
            return task.completed;
        }
    }
    return false;
}