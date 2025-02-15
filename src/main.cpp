#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>


int main(int /*argc*/, char* /*argv*/[])

{
    std::string line;
    std::getline(std::cin, line);
    char* buffer = static_cast<char*>(malloc(line.size() + 1));

    if (buffer == nullptr)
    {
        return 1;
    }
    char* p = buffer;

    for (; p != buffer + line.size(); ++p)
    {
        *p = line[p - buffer];
        std::cout << *p;
    }
    *p = '\0';

    char* lower_case_letters = static_cast<char*>(malloc(line.size() + 1));
    char* lc_p               = lower_case_letters + line.size() + 1;
    for (; p != buffer; --p)
    {
        *lc_p = std::tolower(*p);
        --lc_p;
    }

    char* upper_case_letters = static_cast<char*>(malloc(line.size() + 1));
    char* uc_p               = upper_case_letters;
    for (; p != buffer + line.size(); ++p)
    {
        *uc_p = std::toupper(*p);
        ++uc_p;
    }
    *uc_p = '\0';
    std::cout << upper_case_letters;

    for (size_t i = 0; i < line.size(); ++i)
    {
        std::cout << lower_case_letters[i];
    }
    for (size_t i = 0; i < line.size(); ++i)
    {
        std::cout << upper_case_letters[i];
    }
    free(buffer);
    free(lower_case_letters);
    free(upper_case_letters);

    return 0;
}
