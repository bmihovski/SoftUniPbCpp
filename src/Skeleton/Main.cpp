#include <cctype>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

void PrintQueue(std::queue<std::string>& q) {
  if (q.empty()) {
    std::cout << "<empty>" << std::endl;
    return;
  }
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

void PrintPeople(std::queue<std::string> queue1, std::queue<std::string> queue2,
                 std::stack<std::string> chairs) {
  std::cout << "1: ";
  PrintQueue(queue1);
  std::cout << "2: ";
  PrintQueue(queue2);
  std::cout << "3: ";
  if (chairs.empty()) {
    std::cout << "<empty>" << std::endl;
    return;
  }
  while (!chairs.empty()) {
    std::cout << chairs.top() << " ";
    chairs.pop();
  }
  std::cout << std::endl;
}

int main() {
  std::queue<std::string> queue1;
  std::queue<std::string> queue2;
  std::stack<std::string> chairs;

  std::string line;

  while (std::getline(std::cin, line) && line != "5") {
    std::string name;
    int number = 0;
    std::stringstream ss(line);
    if (!std::isdigit(line[0])) {
      ss >> name;
      ss >> number;
      if (number == 1) {
        queue1.push(name);

      } else {
        queue2.push(name);
      }
    } else {
      ss >> number;
      const int command_source = number / 10;
      const int command_dest = number % 10;
      switch (command_dest) {
        case 0:
          if (command_source == 1) {
            queue1.pop();
          } else {
            queue2.pop();
          }
          break;
        case 1: {
          if (chairs.empty()) {
            break;
          }
          const auto& from_chairs = chairs.top();
          chairs.pop();
          queue1.push(from_chairs);
          break;
        }
        case 2: {
          if (queue1.empty()) {
            break;
          }
          const auto& from_q1 = queue1.front();
          queue1.pop();
          queue2.push(from_q1);
          break;
        }
        case 3: {
          if (queue2.empty()) {
            break;
          }
          const auto& from_q2 = queue2.front();
          queue2.pop();
          chairs.push(from_q2);
          break;
        }
        default:
          PrintPeople(queue1, queue2, chairs);
      }
    }
  }

  return 0;
}
