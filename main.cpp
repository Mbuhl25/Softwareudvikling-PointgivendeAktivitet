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
	while (true)
	{
		
		std::cout << "write a task" << std::endl;
		std::string task_description = "";
		std::cin >> task_description;
		backlog.tasklist.push_back(task_description);
		std::cout << "You have these task\n" << std::endl;
		backlog.viewTasks();

	}
    return 0;
}
