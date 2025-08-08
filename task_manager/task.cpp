#include "task.hpp"
#include <sstream>
#include <iomanip>


// Constructor
Task::Task(const std::string& desc, int prio):
    description(desc),
    priority(prio),
    completed(false),
    created_at(std::chrono::system_clock::now()) {}

// Getters
std::string Task::getDescription() const {
    return description;
}

int Task::getPriority() const {
    return priority;
}

bool Task::isCompleted() const {
    return completed;
}

std::chrono::system_clock::time_point Task::getCreatedAt() const {
    return created_at;
}

// Setters
void Task::markCompleted() {
    completed = true;
}

// Utility functions
std::string Task::to_string() const {
    std::ostringstream oss;
    std::time_t created_time = std::chrono::system_clock::to_time_t(created_at);
    std::tm tm_buf;

    localtime_r(&created_time, &tm_buf); // Thread-safe POSIX version

    oss << "Task: " << description
        << ", Priority: " << priority
        << ", Completed: " << (completed ? "Yes" : "No")
        << ", Created At: " << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

// File I/O helpers
std::string Task::serialize() const {
    return description + "," + std::to_string(priority) + "," +
           (completed ? "true" : "false") + "," +
           std::to_string(std::chrono::system_clock::to_time_t(created_at));
}

Task Task::deserialize(const std::string& data) {
    std::istringstream ss(data);
    std::string desc;
    int prio;
    bool comp;
    std::time_t created_time;

    std::getline(ss, desc, ','); // 1
    ss >> prio;
    ss.ignore(1); // Ignore the comma - 2
    std::string completed_str;
    std::getline(ss, completed_str, ','); // 3
    comp = (completed_str == "true");
    ss >> created_time;

    Task task(desc, prio);
    task.completed = comp;
    task.created_at = std::chrono::system_clock::from_time_t(created_time);

    return task;
}
