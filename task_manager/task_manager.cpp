#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include "task_manager.hpp"


void TaskManager::add_task(const std::string& description, int priority) {
    tasks.emplace_back(description, priority);
}

void TaskManager::list_tasks(bool show_completed) const {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (show_completed || !tasks[i].isCompleted())
            std::cout << i + 1 << ". " << tasks[i].to_string() << std::endl;
    }
}

void TaskManager::complete_task(size_t index) {
    if (index < 1 || index > tasks.size())
        throw std::out_of_range("Task index out of range");

    tasks[index - 1].markCompleted();
}

void TaskManager::remove_task(size_t index) {
    if (index < 1 || index > tasks.size())
        throw std::out_of_range("Task index out of range");

    tasks.erase(tasks.begin() + index - 1);
}

void TaskManager::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open())
        throw std::ios_base::failure("Could not open file for writing");

    for (const auto& task : tasks)
        file << task.serialize() << std::endl;

    // Check for write errors before closing
    if (file.bad())
        throw std::ios_base::failure("Error writing to file");

    file.close();
}

void TaskManager::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::ios_base::failure("Could not open file for reading");

    tasks.clear();
    std::string line;
    while (std::getline(file, line)) {
        Task task = Task::deserialize(line);
        tasks.push_back(task);
    }

    // Check for read errors before closing
    if (file.bad())
        throw std::ios_base::failure("Error reading from file");

    file.close();
}
