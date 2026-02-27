#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

class Task {
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

class State {	
public:
	std::string _category;
	std::vector<Task> tasklist;
	State(std::string category){
		_category = category;
	}

	void viewTasks(std::ostream& out = std::cout) {
		out << "\n";
		out << "+==================================\n";
		out << "|               " << _category << "\n";
		out << "+==================================\n";
		for (size_t i = 0; i < tasklist.size(); ++i) {
			out << "| " << i << ": " << tasklist[i]._description << "\n";
			if (!tasklist[i]._dueDate.empty()) {
				out << "| Due Date: " << tasklist[i]._dueDate << "\n";
			}
			out << "+----------------------------------+\n";
		}
		out << "\n\n";
	}

	void editTask(std::string description) {
		std::cout << "Which description do you wish to change to: " << description << std::endl;
		std::string taskIdx = "0";
		std::getline(std::cin, taskIdx);
		int taskNr = stoi(taskIdx);
		tasklist[taskNr]._description = description;
	}

	void deleteTask() {
		std::cout << "write which task you wish to delete" << std::endl;
		std::string taskIdx = "0";
		std::getline(std::cin, taskIdx);
		int taskNr = stoi(taskIdx);
		tasklist.erase(tasklist.begin()+taskNr);
	}

	void changeDate(std::string date) {
		std::cout << "Which task do you wish to add a due date to?" << std::endl;
		std::string taskIdx = "0";
		std::getline(std::cin, taskIdx);
		int taskNr = stoi(taskIdx);
		tasklist[taskNr]._dueDate = date;
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

	
	std::cout << "Welcome to the todo list\n" << std::endl;
	while (true) {
		std::cout << "Enter: <command> [first] [second]" << std::endl;
		std::cout << "1 | View task (from Stage[first])\n2 | To Stage[first] add task-description[second]\n3 | Edit task from Stage[first] to task-description[second]\n4 | Delete task from Stage[first]\n5 | Move task from Stage[first] to a Stage[second]\n6 | From a task in Stage[first] add a due-date[second]\n7 | Save To do list to text.txt file (only Stage[first])\n8 | exit program\n>";

		// Get user Input as three variables: <command> [targetState] [sentence]
		std::string line;
		std::getline(std::cin, line);
        std::string command, targetState, sentence;
        std::istringstream iss(line);
        iss >> command;
        iss >> targetState;
        std::getline(iss >> std::ws, sentence);


		
		State* statePointer = nullptr;
		for (size_t i = 0; i < stateList.size(); ++i) {
			if (targetState == stateList[i]._category) {
				statePointer = &stateList[i];
				break;
			}
		}

		if (!statePointer && command != "1" && command != "7" && command != "8") {
			std::cout << "Unknown stage: " << targetState << "\n\n";
			continue;
		}
		State& toDoListPart = *statePointer;

		// assign a variable "targettoDoListPart", which points to the part of the ToDo-list to evaluate the command over
		State* targetStatePointer = nullptr;
		for (size_t i = 0; i < stateList.size(); ++i) {
			if (sentence == stateList[i]._category) {
				targetStatePointer = &stateList[i];
				break;
			}
		}
		if (!statePointer && command != "1" && command != "7" && command != "8") {
			std::cout << "Unknown stage: " << sentence << "\n" << std::endl;
			continue;
		}
		State& targetToDoListPart = *targetStatePointer;



		//View ToDo-list
		if (command == "1") {
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
		else if (command == "2") {
			toDoListPart.tasklist.push_back(Task(sentence));
			toDoListPart.viewTasks();
		}
		
		//Edit a specific task from ToDo-list
		else if (command == "3") {
			toDoListPart.viewTasks();
			toDoListPart.editTask(sentence);
			toDoListPart.viewTasks();
		}
		
		//Delete a specific task from ToDo-list
		else if (command == "4") {
			toDoListPart.viewTasks();
			toDoListPart.deleteTask();
			toDoListPart.viewTasks();
		}

		//Move a task from a stage to another stage
		else if (command == "5") {
			toDoListPart.viewTasks();
			std::cout << "Which task do you wish to move to " << sentence << std::endl;
			std::string taskIdx = "0";
			std::getline(std::cin, taskIdx);
			int taskNr = stoi(taskIdx);
			//adds the description from toDoListPart to targetToDoListPart
			targetToDoListPart.tasklist.push_back(toDoListPart.tasklist[taskNr]);
			//targetToDoListPart.tasklist.push_back(Task(toDoListPart.tasklist[taskNr]._description));
			toDoListPart.tasklist.erase(toDoListPart.tasklist.begin()+taskNr);
			toDoListPart.viewTasks();
		}
		//Add A Due Date to a task
		else if (command == "6") {
			std::regex pattern(R"(^\d{4}-\d{4}$)");
			if (std::regex_match(sentence, pattern)) {
				toDoListPart.viewTasks();
				toDoListPart.changeDate(sentence);
				toDoListPart.viewTasks();
			}
			else {
				std::cout << sentence << std::endl;
				std::cout << "date is invalid" << std::endl;
				std::cout << "Use input format \"DDMM-YYYY\"" << std::endl;
			}
		}
		else if (command == "7") {
			std::cout << "Saving the To Do list to a text.txt file\nIf You get an error here, please add an empty text.txt file to this folder.\n" << std::endl;
			std::ofstream file("text.txt");
			if (!file) {
				std::cerr << "open failed\n";
				continue;
			}
			if (targetState != ""){
				toDoListPart.viewTasks(file);
			}
			else
			{
				for (int i = 0; i < stateList.size(); ++i)
				{
					stateList[i].viewTasks(file);
				}
			}
		}
		else if (command == "8") {
			break;
		}
		else {
			std::cout << "Command has to be from [1-8]\n" << std::endl;
		}
	}
}