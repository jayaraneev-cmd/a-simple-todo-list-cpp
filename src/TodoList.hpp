#ifndef TODOLIST_HPP
#define TODOLIST_HPP

#include <string>
#include <vector>

class TodoList {
private:
    struct Task {
        std::string name;
        bool completed;
    };

    std::vector<Task> tasks;

public:
    void add(const std::string& taskName);

    void complete(int index);
    void complete(const std::string& taskName);

    void showCompleted() const;
    void showIncomplete() const;
    void all() const;

    void remove(int index);
    void remove(const std::string& taskName);

    void clear();

    bool isCompleted(const std::string& taskName) const;
};

#endif