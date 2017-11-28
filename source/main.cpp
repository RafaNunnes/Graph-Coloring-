#include "initializer.hpp"
#include "constructor.hpp"

int main()
{
    char* filename = "input/myciel5.col";

    int** adjMatrix;
    int nVertices;

    int* solution;
    int* newSolution;

    adjMatrix = buildAdjMatrix(filename, &nVertices);    
    
    solution = constructSolution(nVertices, adjMatrix);

    newSolution = constructNewSolution(nVertices, adjMatrix, solution);

    if(newSolution[0] < solution[0])
    {
    	printf("\nAntiga solução:  ");
    	printSolution(nVertices, solution);

    	printf("\nNova solução:  ");
    	printSolution(nVertices, newSolution);
    }
    else
    {
        printf("Não houve melhora\n");
    	//printSolution(nVertices, solution);
    }


    return 0;
}