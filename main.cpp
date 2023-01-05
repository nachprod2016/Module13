#include <iostream>
#include <cstdlib>
#include "test.h"
#include "Graph.h"

int main()
{
    bool flag = true;
    Graph* g = nullptr;
    std::string choice;
    while (flag)
    {
        std::cout << "1 - Выбрать граф для теста" << std::endl;
        std::cout << "2 - Найти всех друзей для выбранного человека" << std::endl;
        std::cout << "3 - Показать все имена" << std::endl;
        std::cout << "4 - Завершить программу" << std::endl;
        std::cin >> choice;
        int a = atoi(&choice[0]);
        switch (a)
        {
            case 1:
            {
                std::cout <<  "1 - Graph1" << std::endl;
                std::cout <<  "2 - Graph2" << std::endl;
                std::cout <<  "3 - Graph3" << std::endl;
                std::cin >> choice;
                a = atoi(&choice[0]);
                if (g != nullptr)
                {
                    delete g;
                    g = nullptr;
                }
                switch (a)
                {
                    case 1:
                    {
                        g = Graph1();
                        break;
                    }
                    case 2:
                    {
                        g = Graph2();
                        break;
                    }
                    case 3:
                    {
                        g = Graph3();
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                if (g != nullptr)
                {
                    std::cout << "Введите имя человека: ";
                    std::cin >> choice;
                    g->getFriends(choice);
                }
                break;
            }
            case 3:
            {
                if (g != nullptr)
                {
                    g->showNames();
                }
                break;
            }
            case 4:
            {
                flag = false;
                break;
            }
        }
    }
    return 0;
}