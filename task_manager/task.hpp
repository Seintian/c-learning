#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <chrono>

class Task {
private:
    std::string description;
    int priority;
    bool completed;
    std::chrono::system_clock::time_point created_at;

public:
    Task(const std::string& desc, int prio);

    // Getters
    std::string getDescription() const;
    int getPriority() const;
    bool isCompleted() const;
    std::chrono::system_clock::time_point getCreatedAt() const;

    // Setters
    void markCompleted();

    // Utility functions
    std::string to_string() const;

    // File I/O helpers
    std::string serialize() const;
    static Task deserialize(const std::string& data);
};

#endif // TASK_HPP
