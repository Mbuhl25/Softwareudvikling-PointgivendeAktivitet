# Softwareudvikling-PointgivendeAktivitet
For the first PA


# List of things I have asked CoPilot

### Spurgte om:
I have a vector of Tasks. How do I create my first task?
std::vector<Task> todolist;
### Fik givet:
```
todolist.push_back(Task("Buy milk"));
```

### Spurgte om:
In a std::string. How do I choose specific parts of the string?
what if I want anything but the 2 first?
### Fik givet:
```
std::string rest = s.substr(2);
```

### Spurgte om:
```
std::string command = "";
std::cin >> command;
if (command[0] == '2')
{
    std::cout << command.substr(2,2) << std::endl;
    backlog.tasklist.push_back(task_description.substr(2));
}
```
### Fandt ud af:
```
std::getline(std::cin, description);
er bedre end
std::cin >> description;
```

### Spurgte om:
This line:
```
backlog.tasklist.push_back(command.substr(2));
```
I don't quite understand what it does. Does it initiate an object and place it in the vector tasklist?

### Fandt ud af:
Den her:
```
backlog.tasklist.push_back(command.substr(2));
```
Burde skrives som:
```
backlog.tasklist.push_back(Task(command.substr(2)));
```

### Spurgte om:
How to split a string up in 3 parts?
"_word_ _word_ _sentence_"

### Fik givet:
```
        std::string line;
        if (!std::getline(std::cin, line)) break;  // EOF/ctrl-D

        std::string command, targetState, sentence;

        // Parse: first word -> command, second word -> targetState, rest of line -> sentence
        std::istringstream iss(line);
        iss >> command;                 // may be empty if user just pressed Enter
        iss >> targetState;             // optional; stays empty if not provided
        std::getline(iss, sentence);    // optional rest; may start with a leading space

```


### Spurgte om:
Debug hjælp

### Fik giver:
```
State* selected = nullptr;
for (size_t i = 0; i < stateList.size(); ++i) {
    if (targetState == stateList[i]._category) {
        selected = &stateList[i];                 // pointer to the real element
        break;
    }
}
State& state = *selected
```