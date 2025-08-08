#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <vector>
#include <string>
#include "task.hpp"


class TaskManager {
public:
    // Add a new task
    void add_task(const std::string& description, int priority);

    // List all tasks (optionally only incomplete ones)
    void list_tasks(bool show_completed = true) const;

    // Mark a task as completed by its index
    void complete_task(size_t index);

    // Remove a task by its index
    void remove_task(size_t index);

    // Save the task list to a file
    void save_to_file(const std::string& filename) const;

    // Load tasks from a file
    void load_from_file(const std::string& filename);

private:
    std::vector<Task> tasks; // container for all tasks
};

#endif // TASK_MANAGER_HPP
