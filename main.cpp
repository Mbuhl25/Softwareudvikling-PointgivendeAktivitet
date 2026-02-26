#include <iostream>
#include <fstream>
#include <sstream>
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

class State
{	
public:
	std::string _category;
	std::vector<Task> tasklist;
	State(std::string category)
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
		std::cout << "\n" << std::endl;
	}

	void editTask(std::string description)
	{
		std::cout << "Which description do you wish to change to ?" << description << std::endl;
		int taskNr = 0;
		std::cin >> taskNr;
		tasklist[taskNr]._description = description;
	}

	void deleteTask()
	{
		std::cout << "write which task you wish to delete" << std::endl;
		int taskNr = 0;
		std::cin >> taskNr;
		tasklist.erase(tasklist.begin()+taskNr);
	}
};


int main() {
	// Initiate all the different parts of the To Do list:
    State stateBacklog = State("Backlog");
	State stateDoing = State("Doing");
	State stateTest = State("test");
	std::vector<State> stateList;
	stateList.push_back(stateBacklog);
	stateList.push_back(stateDoing);
	stateList.push_back(stateTest);

	State* statePointer = nullptr;

	
	std::cout << "Welcome to the todo list\n" << std::endl;
	while (true)
	{
		std::cout << "Enter: <command> [targetState] [sentence]" << std::endl;
		std::cout << "1 | View task (from [targetState])\n2 | to [targetstate] add [sentence]\n3 | edit task from [targetState] to [sentence]\n4 | delete task from [targetState]\n5 | move task from [targetState] to a [sentence]\n>";

		// Get user Input as three variables: <command> [targetState] [sentence]
		std::string line;
		std::getline(std::cin, line);
        std::string command, targetState, sentence;
        std::istringstream iss(line);
        iss >> command;
        iss >> targetState;
        std::getline(iss, sentence);

		// assign a variable "toDoListPart", which points to the part of the ToDo-list to evaluate the command over
		for (int i = 0; i < stateList.size(); ++i)
		{
			if (targetState == stateList[i]._category)
			{
				statePointer = &stateList[i];
				break;
			}
		}
		State& toDoListPart = *statePointer;



		//View ToDo-list
		if (command == "1")
		{
			if (targetState != ""){
				toDoListPart.viewTasks();
			}
			else
			{
				for (int i = 0; i < stateList.size(); ++i)
				{
					stateList[i].viewTasks();
				}
			}
		}
		
		//Add task to ToDo-list
		else if (command == "2")
		{
			toDoListPart.tasklist.push_back(Task(sentence));
		}
		
		//Edit a specific task from ToDo-list
		else if (command == "3")
		{
			toDoListPart.viewTasks();
			toDoListPart.editTask(sentence);
		}
		//Delete a specific task from ToDo-list
		else if (command == "4")
		{
			toDoListPart.viewTasks();
			toDoListPart.deleteTask();
		}
	}
	return 0;
}
