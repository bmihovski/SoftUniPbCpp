
#include <cstdio>
#include <iostream>

#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
    std::string products;
    std::string couriers;
    int         total_products = 0;
    std::getline(std::cin, products);
    std::getline(std::cin, couriers);

    std::stack<int>    products_stack;
    std::queue<int>    couriers_queue;
    std::istringstream pss(products);
    std::istringstream css(couriers);
    int                temp = 0;
    while (pss >> temp)
    {
        products_stack.push(temp);
    }

    while (css >> temp)
    {
        couriers_queue.push(temp);
    }

    while (!products_stack.empty() && !couriers_queue.empty())
    {
        int       current_product = products_stack.top();
        const int current_courier = couriers_queue.front();
        if (current_courier > current_product)
        {
            int const new_courier_size = current_courier - std::pow(current_product, 2);
            if (new_courier_size > 0)
            {
                couriers_queue.pop();
                couriers_queue.push(new_courier_size);
            }
            total_products += current_product;
            couriers_queue.pop();
        }
        else if (current_courier == current_product)
        {
            total_products += current_product;
            couriers_queue.pop();
            products_stack.pop();
        }
        else
        {
            current_product -= current_courier;
            total_products += current_product;
            products_stack.pop();
            products_stack.push(current_product);
            couriers_queue.pop();
        }
    }

    std::cout << "Total weight: " << total_products << " kg" << std::endl;
    if (!products_stack.empty() && couriers_queue.empty())
    {
        std::cout << "Unfortunately, there are no more available couriers to deliver the following packages : ";
        bool first = true;
        while (!products_stack.empty())
        {
            if (!first)
            {
                std::cout << ", ";
            }
            else
            {
                first = false;
                std::cout << products_stack.top();
            }
            products_stack.pop();
        }
        std::cout << std::endl;
    }
    else if (!couriers_queue.empty() && products_stack.empty())
    {
        std::cout << "Couriers are still on duty: ";
        bool first = true;
        while (!couriers_queue.empty())
        {
            if (!first)
            {
                std::cout << ", ";
            }
            else
            {
                first = false;
                std::cout << couriers_queue.front();
            }
            couriers_queue.pop();
        }
        std::cout << " but there are no more packages to deliver." << std::endl;
    }
    else
    {
        std::cout << "Congratulations, all packages were delivered successfully by the couriers today." << std::endl;
    }


    return 0;
}
