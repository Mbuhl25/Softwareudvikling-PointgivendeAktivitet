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
			std::cout << "| " << i << ": " << tasklist[i]._description << std::endl;
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
		//View ToDo-list
		if (command[0] == '1')
		{
			backlog.viewTasks();
		}
		//Add task to ToDo-list
		else if (command[0] == '2' && command.size() > 2)
		{
			backlog.tasklist.push_back(command.substr(2));
		}
		//Edit a specific task from ToDo-list
		else if (command[0] == '3')
		{
			std::cout << "write number of task you wish to edit\nfollowed by what you want to change it to" << std::endl;
			backlog.viewTasks();
			std::getline(std::cin, command);
			for (int i = 0; i < backlog.tasklist.size(); ++i)
			{
				if ((command[0] - '0') == i && command.size() > 2)
				{
					backlog.tasklist[i]._description = command.substr(2);
				}
			}
		}
		//Delete a specific task from ToDo-list
		else if (command[0] == '4')
		{
			std::cout << "write which task you wish to delete" << std::endl;
			backlog.viewTasks();
			std::getline(std::cin, command);
			for (int i = 0; i < backlog.tasklist.size(); ++i)
			{
				if ((command[0] - '0') == i)
				{
					backlog.tasklist.erase(backlog.tasklist.begin()+i);
				}
			}
		}
	}
    return 0;
}
