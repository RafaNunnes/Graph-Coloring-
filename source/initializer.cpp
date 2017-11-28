#include "initializer.hpp"

/*builds the adjacency matrix. inputs are filename
and IO int "matrix" to be allocated*/
int** buildAdjMatrix(const char* filename, int* nVertices)
{
    using namespace std;

    int** adjMatrix;

    char lineType;
    string garbage;
    int matrixSize, line, column;

    ifstream file(filename);

    while(file.good())
    {    
        file >> lineType;

        if( lineType == 'c')
        {        
            getline(file, garbage);
        } 
        else if( lineType == 'p')
        {
            file >> garbage;
            file >> matrixSize;

            adjMatrix = new int*[matrixSize];
            for(int i = 0; i < matrixSize; ++i)
            {
                adjMatrix[i] = new int[matrixSize];                                  
            }

            for(int i = 0; i < matrixSize; ++i)
            {
                for(int j = 0; j < matrixSize; ++j)
                {
                    adjMatrix[i][j] = 0;                    
                }
            }                
        }
        else if( lineType == 'e')
        {
            file >> line >> column;
            adjMatrix[line - 1][column - 1] = 1;
            adjMatrix[column - 1][line - 1] = 1;                     
        }
                
    }

    *nVertices = matrixSize;

    return adjMatrix;
}

void printMatrix(int matrixSize, int** matrix)
{
    for(int i = 0; i < matrixSize; ++i)
    {
        for(int j = 0; j < matrixSize; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printSolution(const int size, const int* solution)
{
    std::cout << "Coloring: " << solution[0] <<  std::endl;

    for(int i = 1; i <= size ; ++i)
    {      
        std::cout << solution[i] << " ";        
    }

    std::cout <<  std::endl;
}