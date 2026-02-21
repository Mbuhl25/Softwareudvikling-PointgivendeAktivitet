# Softwareudvikling-PointgivendeAktivitet
For the first PA


# List of things I have asked CoPilot

## Spurgte om:
I have a vector of Tasks. How do I create my first task?
std::vector<Task> todolist;
## Fik givet:
```
todolist.push_back(Task("Buy milk"));
```

## Spurgte om:
In a std::string. How do I choose specific parts of the string?
what if I want anything but the 2 first?
## Fik givet:
```
std::string rest = s.substr(2);
```

## Spurgte om:
```
std::string command = "";
std::cin >> command;
if (command[0] == '2')
{
    std::cout << command.substr(2,2) << std::endl;
    backlog.tasklist.push_back(task_description.substr(2));
}
```
## Fandt ud af:
```
std::getline(std::cin, description);
er bedre end
std::cin >> description;
```