#include <cstdio>
#include <cstdlib>
#include <cilk/cilk.h>
#ifdef CILK_SERIALIZE
#include <cilk/cilk_stub.h>
#endif
#include "timer.h"
#include "io.h"
#include <stdlib.h>

// Main method
int main(int argc, char *argv[])
{
    int N, M;
    int **World;
    int **proximoResultado;
    double elapsedTime;

    // checking parameters
    if (argc != 3 && argc != 4)
    {
        cout << "Parameters: <N> <M> [<file>]" << endl;
        return 1;
    }
    N = atoi(argv[1]);
    M = atoi(argv[2]);

    World = new int *[N];
    proximoResultado = new int *[N];
    for (int i = 0; i < N; i++)
    {
        proximoResultado[i] = new int[N];
        World[i] = new int[N];
    }

    if (argc == 4)
    {
        readMatrixFile(World, N, argv[3]);
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                World[i][j] = 0 + rand() % (2);
            }
        }
    }

    timerStart();

    while (M != 0)
    {
        cilk_for(int x = 0; x < N; x++)
        {
            for (int
                     y = 0;
                 y < N;
                 y++)
            {

                int vecino = 0;

                int i, j;

                if (x > 0 && y > 0)
                    if (World[x - 1][y - 1] == 1)
                        vecino++;

                if (y > 0)
                    if (World[x][y - 1] == 1)
                        vecino++;

                if (x < N - 1 && y > 0)
                    if (World[x + 1][y - 1] == 1)
                        vecino++;

                if (x > 0)
                    if (World[x - 1][y] == 1)
                        vecino++;

                if (x < N - 1)
                    if (World[x + 1][y] == 1)
                        vecino++;

                if (x > 0 && y < N - 1)
                    if (World[x - 1][y + 1] == 1)
                        vecino++;

                if (y < N - 1)
                    if (World[x][y + 1] == 1)
                        vecino++;

                if (x < N - 1 && y < N - 1)
                    if (World[x + 1][y + 1] == 1)
                        vecino++;

                if ((World[x][y] == 1) && (vecino < 2))
                {
                    proximoResultado[x][y] = 0;
                }
                else if ((World[x][y] == 1) && (vecino > 3))
                {
                    proximoResultado[x][y] = 0;
                }
                else if ((World[x][y] == 0) && (vecino == 3))
                {
                    proximoResultado[x][y] = 1;
                }
                else
                {
                    proximoResultado[x][y] = World[x][y];
                }
            }
        }

        World = proximoResultado;

        proximoResultado = new int *[N];
        for (int i = 0; i < N; i++)
        {
            proximoResultado[i] = new int[N];
        }

        M--;
    }

    printMatrix(World, N);

    elapsedTime = timerStop();

    cout << "Duration: " << elapsedTime << " seconds" << std::endl;

    for (int i = 0; i < N; i++)
    {
        delete[] World[i];
    }
    delete[] World;

    return 0;
}
