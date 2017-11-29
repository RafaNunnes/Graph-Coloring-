#include "initializer.hpp"
#include "constructor.hpp"

int* availableColors;
int counter;

int main()
{
    char* filename = "input/myciel5.col";

    int** adjMatrix;
    int nVertices;

    int* solution;
    int* newSolution;

    adjMatrix = buildAdjMatrix(filename, &nVertices);    
    
    solution = constructSolution(nVertices, adjMatrix);

    availableColors = new int[solution[0]];
    for(int j=0; j<solution[0]; j++)
    {
        availableColors[j] = 0;
    }

    counter = solution[0];

    for(int i=0; i <= 5; i++)       //VND
    {
        newSolution = constructNewSolution(nVertices, adjMatrix, solution);

        if(newSolution[0] < solution[0])
        {
            printf("\nAntiga solução:  ");
            printSolution(nVertices, solution);

            printf("\nNova solução:  ");
            printSolution(nVertices, newSolution);
            //i=0;
            solution = newSolution;
        }
        else
        {
            printf("Não houve melhora\n");
            //printSolution(nVertices, solution);
        }
    }

    return 0;
}