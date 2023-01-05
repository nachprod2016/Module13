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
    int veryBig = 1000;
    int distances[vertexCount];
    for (int i = 0; i < vertexCount; i++) // инициализация меток
    {
        distances[i] = veryBig;
    }
    int fromVert = -1;
    for (int i = 0; i < vertexCount; i++)
    {
        if (name == names[i])
        {
            fromVert = i;
            break;
        }
    }
    if (fromVert == -1)
    {
        return;
    }
    distances[fromVert] = 0;
    bool passed[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        passed[i] = false; // все неокрашены изначально
    }
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while(min_dist != veryBig)
    {
        passed[currentVertexNum] = true;
        for(int i = 0; i < vertexCount; i++)
        {
            // для смежных ребер пересчитываем метки
            if(edgeExists(currentVertexNum,i)
               && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
                    distances[i] = 
                      distances[currentVertexNum] + matrix[currentVertexNum][i];
        }
        min_dist = veryBig;
        for(int i = 0; i< vertexCount; i++)
        {
            // выбираем новую текущую вершину
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist) // выбор новой вершины
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }
    std::cout << "Друзья " << name << ": ";
    for(int i=0; i<vertexCount; i++) // вывод результата
    {
        if (distances[i] < 4 && i != fromVert)
        {
            std::cout << names[i] << " ";
        }
    }
    std::cout << std::endl;
}
