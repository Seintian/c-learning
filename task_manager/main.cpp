#include <iostream>
#include "task_manager.hpp"


void inter_add_task(TaskManager& task_manager) {
    std::string description;
    int priority;

    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    std::cout << "Enter task priority (1-10): ";
    std::cin >> priority;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    task_manager.add_task(description, priority);
    std::cout << "Task added successfully.\n";
}

void inter_list_tasks(const TaskManager& task_manager) {
    std::cout << "Tasks:\n";
    task_manager.list_tasks();
}

void inter_complete_task(TaskManager& task_manager) {
    size_t index;

    std::cout << "Enter task index to complete: ";
    std::cin >> index;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        task_manager.complete_task(index);
        std::cout << "Task marked as completed.\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

void inter_remove_task(TaskManager& task_manager) {
    size_t index;

    std::cout << "Enter task index to remove: ";
    std::cin >> index;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        task_manager.remove_task(index);
        std::cout << "Task removed successfully.\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

void inter_save_tasks(const TaskManager& task_manager) {
    std::string filename;

    std::cout << "Enter filename to save tasks: ";
    std::getline(std::cin, filename);

    try {
        task_manager.save_to_file(filename);
        std::cout << "Tasks saved successfully.\n";
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }
}

void inter_load_tasks(TaskManager& task_manager) {
    std::string filename;

    std::cout << "Enter filename to load tasks: ";
    std::getline(std::cin, filename);

    try {
        task_manager.load_from_file(filename);
        std::cout << "Tasks loaded successfully.\n";
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    TaskManager task_manager;

    for (int choice = 0; choice != 6;) {
        std::cout << "=== Mini Task Manager ===\n"
            << "1. Add Task\n"
            << "2. List Tasks\n"
            << "3. Complete Task\n"
            << "4. Remove Task\n"
            << "5. Load Tasks from File\n"
            << "6. Save to a File and Exit\n"
            << "Choose an option: " << std::endl;

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            inter_add_task(task_manager);
            break;

        case 2:
            inter_list_tasks(task_manager);
            break;

        case 3:
            inter_complete_task(task_manager);
            break;

        case 4:
            inter_remove_task(task_manager);
            break;

        case 5:
            inter_load_tasks(task_manager);
            break;

        case 6:
            inter_save_tasks(task_manager);
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
