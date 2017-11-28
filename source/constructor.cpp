#include "constructor.hpp"

/*returns an array of size matrixsize + 1
  the first element is the k-coloring!!!*/
int* constructSolution(const int matrixSize, int** matrix)
{
    int* solution = new int[matrixSize + 1];                                //solution matrix to be returned; index 0 is k-coloring

    std::vector <int> colors(matrixSize, 0);                                //vector of colors of each vertex; 0 is "null"

    for(int vertex = 0; vertex < matrixSize; ++vertex)                       //for each vertex
    {
        std::vector <int> neighbourColors;                                  //make a vector of the colors of neighbours

        for(int neighbour = 0; neighbour < matrixSize; ++neighbour)         //for each neighbour
        {
            if(matrix[vertex][neighbour])                                   //if they are both connected
            {
                neighbourColors.push_back(colors[neighbour]);               //add the color to the neighbours vector
            }
        }

        std::sort(neighbourColors.begin(), neighbourColors.end());          //sort the neighbour colors

        int color = 0;

        for(unsigned int i = 0; i < neighbourColors.size() - 1; ++i)                 //try to get the smallest color in a gap between neighbour colors
        {
            if(neighbourColors[i] + 1 < neighbourColors[i + 1])
            {
                color = neighbourColors[i] + 1;
                break;
            }            
        }

        if(color == 0)                                                      //if no gap, get biggest color + 1
        {
            color = neighbourColors.back() + 1;
        }

        colors[vertex] = color;                                             //update the colors vector
    }

    for(int i = 0; i < matrixSize; ++i)                                     //update solution array after solution is created
    {
        solution[i+1] = colors[i];
    }

    std::sort(colors.begin(), colors.end());                                //sort colors to get k coloring

    solution[0] = colors.back();                                            //index 0 is k coloring!!

    return solution;
}


int* constructNewSolution(const int matrixSize, int** matrix, const int* solution)
{
    srand (time(NULL));
    int* newSolution = new int[matrixSize + 1]; 
    int randomNumber = 0;

    /*while(!randomNumber)
    {
        randomNumber = (rand() % 100) % solution[0];
    }*/
    
    randomNumber = (rand() % 100) % solution[0];

    if(randomNumber == 0)
    {
        randomNumber++;
    }

    int maxColor = solution[0], newColor = 0;
    int end = 0;
    int* matrizColor = new int[maxColor];
    printf("COR RETIRADA = %d\n", randomNumber);
    newSolution[0] = solution[0]+1;

    for(int y=0; y < maxColor; y++)
    {
        matrizColor[y] = 0;
    }

    for(int i=1; i <= matrixSize; i++)          //Retira a cor selecionada randomicamente dos vértices do grafo
    {
        if(solution[i] == randomNumber)        
        {
            newSolution[i] = -1;
        }
        else
        {
            newSolution[i] = solution[i];
        }
    }

    for(int vertex=1; vertex <= matrixSize; vertex++)                       //Procura a nova cor a ser substituida
    {
        if(newSolution[vertex] == -1)
        {
            for(int neighbour=0; neighbour < matrixSize; neighbour++)       //Para cada vértice sem cor, procura seu vizinho
            {
                if(matrix[vertex-1][neighbour] == 1)                        //Encontra vizinho                                     
                {
                    //matrizColor[newSolution[neighbour]-1] = 1;  
                    matrizColor[solution[neighbour]-1] = 1;
                }
            }

            for(int k=0; k < maxColor; k++)
            {
                if(!(matrizColor[k] == 1) )          //Só seta a nova cor se os vizinhos não possuam essa cor
                {
                    newColor = k;


                    if(newColor==randomNumber || newColor==-1)
                    {
                        newColor=0;
                        continue;
                    }
                           
                    end = 1;
                    break;
                    
                }
            }
            
            if(end == 0)                                 //Não foi possível encontrar uma solução melhor
            {
                return newSolution;
            }
            else if((end == 1) && newColor!=0)                            //O vértice recebe uma nova cor
            {
                newSolution[vertex] = newColor;
                newColor = 0;
                end = 0;
            }
        }
    }

    newSolution[0] = solution[0] - 1;

    return newSolution;
}