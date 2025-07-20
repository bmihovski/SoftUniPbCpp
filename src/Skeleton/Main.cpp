#include <cctype>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

void ProcessClient(const std::string& cashier_name,
                   std::queue<std::map<std::string, int>>& client_queue) {
  std::cout << cashier_name << " ";
  if (client_queue.empty()) {
    std::cout << "Idle" << std::endl;
    return;
  }
  auto& client_data = client_queue.front();
  auto [name, minutes] = *client_data.begin();
  std::cout << "processing " << name << std::endl;
  minutes--;
  if (minutes <= 0) {
    client_queue.pop();
  } else {
    client_data[name] = minutes;
  }
}

int main() {
  int commands_num = 0;
  int work_minutes = 0;
  std::string line;
  std::queue<std::map<std::string, int>> mimi_queue;
  std::queue<std::map<std::string, int>> pepi_queue;

  std::cin >> commands_num;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while ((commands_num--) != 0) {
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::string cashier;
    std::string customer;
    int minutes = 0;
    ss >> cashier >> customer >> minutes;

    if (cashier == "Mimi") {
      std::map<std::string, int> customer_map;
      customer_map[customer] = minutes;
      mimi_queue.push(customer_map);
    } else if (cashier == "Pepi") {
      std::map<std::string, int> customer_map;
      customer_map[customer] = minutes;
      pepi_queue.push(customer_map);
    }
  }

  std::cin >> work_minutes;
  while ((work_minutes--) != 0) {
    ProcessClient("Pepi", pepi_queue);
    ProcessClient("Mimi", mimi_queue);
  }
  return 0;
}
