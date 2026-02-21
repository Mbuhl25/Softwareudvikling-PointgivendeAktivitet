#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Task
{
public:
	std::string _description;
	Task(std::string description){
		_description = description;
	}
};

class TodoList
{	
public:
	std::string _category;
	std::vector<Task> tasklist;
	TodoList(std::string category)
	{
		_category = category;
	}

	void viewTasks()
	{
		std::cout << "" << std::endl;
		std::cout << "+==================================" << std::endl;
		std::cout << "|               " << _category << std::endl;
		std::cout << "+==================================" << std::endl;
		for (int i = 0; i < tasklist.size(); ++i)
		{
			std::cout << "| " << tasklist[i]._description << std::endl;
			std::cout << "+----------------------------------+" << std::endl;
		}
	}
};

int main() {

    TodoList backlog = TodoList("Backlog");
	std::cout << "Welcome to the todo list" << std::endl;
	std::cout << "What would you like to do?\n - 1: view tasks\n - 2: add task to backlog\n - 3: edit tasks" << std::endl;
	while (true)
	{
		
		std::cout << "\nwrite a task" << std::endl;
		std::string command = "";
		std::getline(std::cin, command);
		if (command[0] == '1')
		{
			backlog.viewTasks();
		}
		else if (command[0] == '2' && command.size() > 2)
		{
			backlog.tasklist.push_back(command.substr(2));
		}
	}
    return 0;
}
