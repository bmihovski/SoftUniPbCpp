#include "Engine.h"
#include "src/common/Command.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>

Engine::Engine(Controller* controller)
{
    this->controller_ = const_cast<Controller*>(controller);
}

void Engine::Run()
{
    while (true)
    {
        std::string result;
        try
        {
            result = ProcessInput();
            if (result == "Exit")
            {
                break;
            }
        }
        catch (std::exception& e)
        {
            result = e.what();
        }
        std::cout << result << std::endl;
    }
}

std::string Engine::ProcessInput() const
{
    std::string              input;
    std::string              result;
    std::vector<std::string> data;
    std::cin >> input;
    Command command = valueOf(input);
    std::getline(std::cin, input);
    std::istringstream ss(input);
    while (ss >> input)
    {
        data.emplace_back(input);
    }

    switch (command)
    {
    case Command::AddDestination:
        result = AddDestination(data);
        break;
    case Command::AddCar:
        result = AddCar(data);
        break;
    case Command::ReachDestination:
        result = ReachDestination(data);
        break;
    case Command::GetStatistics:
        result = GetStatistics();
        break;
    case Command::Exit:
        result = "Exit";
        break;
    }

    return result;
}

std::string Engine::AddCar(std::vector<std::string>& data) const
{
    return "";
}

std::string Engine::AddDestination(std::vector<std::string>& data) const
{
    return "";
}

std::string Engine::ReachDestination(std::vector<std::string>& data) const
{
    return "";
}

std::string Engine::GetStatistics() const
{
    return "";
}
