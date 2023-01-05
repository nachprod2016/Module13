#include "Graph.h"
#include <iostream>

Graph::Graph() : matrix(nullptr), vertexCount(0) {}

Graph::~Graph()
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < vertexCount; i++)
        {
            delete [] matrix[i];
        }
        delete [] matrix;
    }
}

void Graph::addVertex(std::string && name)
{
    int size = names.size();
    for (int i = 0; i < size; i++)
    {
        if (names[i] == name)
        {
            std::cout << "Одинаковые имена не допускаются!" << std::endl;
            return;
        }
    }
    names.push_back(name);
    vertexes.push_back(names.size());
}

void Graph::addEdge(std::string && name1, std::string && name2, int weight)
{
    if (matrix == nullptr)
    {
        std::cout << "Матрица смежности еще не создана" << std::endl;
        return;
    }
    if (name1 == name2)
    {
        std::cout << "Одинаковые имена не допускаются!!!" << std::endl;
        return;
    }
    int v1 = -1;
    int v2 = -1;
    for (int i = 0; i < vertexCount; i++)
    {
        if (names[i] == name1)
        {
            v1 = i;
        }
        if (names[i] == name2)
        {
            v2 = i;
        }
        if (v2 != -1 && v1 != -1)
        {
            matrix[v1][v2] = weight;
            matrix[v2][v1] = weight;
            break;
        }
    }
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}

bool Graph::vertexExists(int v)
{
    int size = vertexes.size();
    for(int i = 0; i < size; i++)
    {
       if (vertexes[i] == v)
       {
            return true;
       }
    }
    return false;
}

void Graph::createMatrix()
{
    if (vertexCount == vertexes.size())
    {
        std::cout << "Расчет матрицы не требуется" << std::endl;
        return;
    }
    int size = vertexes.size();
    int** bufMatrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        bufMatrix[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            bufMatrix[i][j] = 0;
        }
    }
    if (matrix != nullptr)
    {
        for (int i = 0; i < vertexCount; i++)
        {
            for (int j = 0; j < vertexCount; j++)
            {
                bufMatrix[i][j] = matrix[i][j];
            }
            delete [] matrix[i];
        }
        delete [] matrix;   
    }
    matrix = bufMatrix;
    vertexCount = size;
}

void Graph::showNames() const
{
    int size = names.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << names[i] << std::endl;
    }
}

void Graph::getFriends(std::string & name)
{
    int start = -1;
    for (int i = 0; i < vertexCount; i++)
    {
        if (name == names[i])
        {
            start = i;
            break;
        }
    }
    if (start == -1)
    {
        return;
    }
    int puth = 0;
    bool visited[vertexCount];
    int numPuth[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        visited[i] = false;
        numPuth[i] = 1000;
    }
    walk(start, puth, visited, numPuth);
    std::cout << "Друзья " << name << ": ";
    for (int i = 0; i < vertexCount; i++)
    {
        if (numPuth[i] < 4 && start != i)
        {
            std::cout << names[i] << " ";
        }
    }
    std::cout << std::endl;
}

void Graph::walk(int start, int puth, bool* visited, int* numPuth)
{
    bool c_visited[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        c_visited[i] = visited[i];
    }
    if (numPuth[start] > puth)
    {
        numPuth[start] = puth;
    }
    c_visited[start] = true;
    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix[start][i] != 0 && c_visited[i] == false)
        {
            walk(i, puth + 1, c_visited, numPuth);
        }
    }
}