#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

class Task
{
public:
	std::string _description;
	std::string _dueDate;
	Task(std::string description) {
		_description = description;
		_dueDate = "";
	}
	void setDueDate(std::string dueDate) {
		_dueDate = dueDate;
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
			if (tasklist[i]._dueDate != "") {
				std::cout << "| Due Date: " << tasklist[i]._dueDate << std::endl;
			}
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
	State stateDone = State("Done");
	std::vector<State> stateList;
	stateList.push_back(stateBacklog);
	stateList.push_back(stateDoing);
	stateList.push_back(stateDone);

	State* statePointer = nullptr;

	
	std::cout << "Welcome to the todo list\n" << std::endl;
	while (true)
	{
		std::cout << "Enter: <command> [first] [second]" << std::endl;
		std::cout << "1 | View task (from Stage[first])\n2 | To Stage[first] add task-description[second]\n3 | Edit task from Stage[first] to task-description[second]\n4 | Delete task from Stage[first]\n5 | Move task from Stage[first] to a Stage[second]\n6 | From a task in Stage[first] add a due-date[second]\n>";

		// Get user Input as three variables: <command> [targetState] [sentence]
		std::string line;
		std::getline(std::cin, line);
        std::string command, targetState, sentence;
        std::istringstream iss(line);
        iss >> command;
        iss >> targetState;
        std::getline(iss >> std::ws, sentence);

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

		else if (command == "6")
		{
			std::regex pattern(R"(^\d{4}-\d{4}$)");
			if (std::regex_match(sentence, pattern)) {
				toDoListPart.viewTasks();
				std::cout << "Which task do you wish to add a due date to?" << std::endl;
				int taskNr = 0;
				std::cin >> taskNr;
				toDoListPart.tasklist[taskNr]._dueDate = sentence;
			}
			else {
				std::cout << sentence << std::endl;
				std::cout << "date is invalid" << std::endl;
			}
		}
	}
	return 0;
}
