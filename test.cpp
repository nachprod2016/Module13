#include "test.h"
#include <string>

Graph* Graph1()
{
    Graph* g = new Graph();
    g->addVertex("Oleg");
    g->addVertex("Nikita");
    g->addVertex("Nastya");
    g->addVertex("Vanya");
    g->addVertex("Jenya");
    g->createMatrix();
    g->addEdge("Oleg", "Nikita", 1);
    g->addEdge("Nikita", "Nastya", 1);
    g->addEdge("Nastya", "Vanya", 1);
    g->addEdge("Vanya", "Jenya", 1);
    return g;
}

Graph* Graph2()
{
    Graph* g = new Graph();
    g->addVertex("Petya");
    g->addVertex("Vasya");
    g->addVertex("Olya");
    g->addVertex("Oleg");
    g->addVertex("Nastya");
    g->addVertex("Kolya");
    g->addVertex("Igor");
    g->addVertex("Sasha");
    g->createMatrix();
    g->addEdge("Petya", "Vasya", 1);
    g->addEdge("Petya", "Sasha", 1);
    g->addEdge("Vasya", "Kolya", 1);
    g->addEdge("Vasya", "Nastya", 1);
    g->addEdge("Vasya", "Olya", 1);
    g->addEdge("Olya", "Oleg", 1);
    g->addEdge("Oleg", "Nastya", 1);
    g->addEdge("Oleg", "Igor", 1);
    g->addEdge("Igor", "Sasha", 1);
    g->addEdge("Nastya", "Kolya", 1);
    g->addEdge("Kolya", "Igor", 1);
    return g;
}

Graph* Graph3()
{
    Graph* g = new Graph();
    g->addVertex("Nikita");
    g->addVertex("Olya");
    g->addVertex("Sasha");
    g->addVertex("Kolya");
    g->addVertex("Igor");
    g->addVertex("Oleg");
    g->addVertex("Nastya");
    g->addVertex("Petya");
    g->addVertex("Vasya");
    g->createMatrix();
    g->addEdge("Sasha", "Vasya", 1);
    g->addEdge("Vasya", "Olya", 1);
    g->addEdge("Petya", "Vasya", 1);
    g->addEdge("Petya", "Olya", 1);
    g->addEdge("Petya", "Nikita", 1);
    g->addEdge("Nikita", "Oleg", 1);
    g->addEdge("Oleg", "Igor", 1);
    g->addEdge("Oleg", "Nastya", 1);
    g->addEdge("Igor", "Nastya", 1);
    g->addEdge("Nastya", "Kolya", 1);
    return g;
}