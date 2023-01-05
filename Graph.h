#pragma once
#include <vector>
#include <string>

class Graph
{
public:
    Graph();
    ~Graph();
    // добавление вершины
    void addVertex(std::string && name);
    // добавление ребра
    void addEdge(std::string && name1, std::string && name2, int weight);
    void createMatrix();
    void showNames() const;
    void getFriends(std::string & name);
    void walk(int start, int puth, bool* visited, int* numPuth);
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);
    int** matrix; // матрица смежности        
    std::vector<int> vertexes; // хранилище вершин
    std::vector<std::string> names;
    int vertexCount;
};