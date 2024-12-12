#include "Engine.h"
#include "src/common/Command.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>

Engine::Engine(Controller* controller)
{
    this->controller = const_cast<Controller*>(controller);
}

void Engine::run()
{
    while (true)
    {
        std::string result;
        try
        {
            result = processInput();
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

std::string Engine::processInput() const
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
        result = addDestination(data);
        break;
    case Command::AddCar:
        result = addCar(data);
        break;
    case Command::ReachDestination:
        result = reachDestination(data);
        break;
    case Command::GetStatistics:
        result = getStatistics();
        break;
    case Command::Exit:
        result = "Exit";
        break;
    }

    return result;
}

std::string Engine::addCar(std::vector<std::string>& data) const
{
    return "";
}

std::string Engine::addDestination(std::vector<std::string>& data) const
{
    return "";
}

std::string Engine::reachDestination(std::vector<std::string>& data) const
{
    return "";
}

std::string Engine::getStatistics() const
{
    return "";
}
