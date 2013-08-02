#include <iostream>
using namespace std;

int main()
{
    int i,j,legal;
    int dimx=7;
    int dimy=dimx;
    int dim=dimx*dimy;
    int caballo[dim][3];      /*  caballo[i][j] indica, para el turno i, la fila (j=0) y columna (j=1) y la dirección.
                                        Hay: dimx valores posibles para caballo[i][0],
                                             dimy valores posibles para caballo[i][1],
                                             8 valores posibles para caballo[i][2]
                                        para cualquier valor de i entre 0 y dim-1. */
    for(i=0;i<dim;i++)
    {
        caballo[i][0]=0;
        caballo[i][1]=0;
        caballo[i][2]=1;
    }
    cout << "Introduce la posición inicial del caballo." << endl;
    cout << "Fila (de 1 a " << dimx << "): ";
    cin >> caballo[0][0];
    cout << "Columna (de 1 a " << dimy << "): ";
    cin >> caballo[0][1];
    i=1;
    while(i<dim)
    {
        switch(caballo[i-1][2])
        {
            case 1:
                caballo[i][0] = caballo[i-1][0] + 1;
                caballo[i][1] = caballo[i-1][1] + 2;
                break;
            case 2:
                caballo[i][0] = caballo[i-1][0] + 2;
                caballo[i][1] = caballo[i-1][1] + 1;
                break;
            case 3:
                caballo[i][0] = caballo[i-1][0] + 2;
                caballo[i][1] = caballo[i-1][1] - 1;
                break;
            case 4:
                caballo[i][0] = caballo[i-1][0] + 1;
                caballo[i][1] = caballo[i-1][1] - 2;
                break;
            case 5:
                caballo[i][0] = caballo[i-1][0] - 1;
                caballo[i][1] = caballo[i-1][1] - 2;
                break;
            case 6:
                caballo[i][0] = caballo[i-1][0] - 2;
                caballo[i][1] = caballo[i-1][1] - 1;
                break;
            case 7:
                caballo[i][0] = caballo[i-1][0] - 2;
                caballo[i][1] = caballo[i-1][1] + 1;
                break;
            case 8:
                caballo[i][0] = caballo[i-1][0] - 1;
                caballo[i][1] = caballo[i-1][1] + 2;
                break;
            default:
                cout << "El código de movimiento se sale del rango. You lost the game.";
                return 0;
        }
        //cout << "Turno " << i << ". Probando casilla (" << caballo[i][0] << ", " << caballo[i][1] << "), mov. " << caballo[i-1][2] << ". ";
        legal=1;
        if(caballo[i][0]<1 || caballo[i][1]<1 || caballo[i][0]>dimx || caballo[i][1]>dimy)
        {
            legal=0;                            // Fuera de rango.
            //cout << "Fuera de rango." << endl;
        }
        j=0;
        while(legal && j<i)
        {
            if(caballo[i][0]==caballo[j][0] && caballo[i][1]==caballo[j][1])
            {
                legal=0;                        // Casilla ya ocupada.
                //cout << "Ya fue ocupada en el turno " << j << "." << endl;
            }
            else
            {
                j++;
            }
        }
        if(!legal)
        {
            caballo[i-1][2]++;
            while(caballo[i-1][2]>8)
            {
                if(i==1)                        // Se han agotado todas las posibilidades.
                {
                    cout << "No se ha encontrado solución.";
                    return 0;
                }
                else
                {
                    caballo[i-1][2]=1;
                    caballo[i-2][2]++;
                    i--;
                    //cout << "Volviendo al turno " << i << "." << endl;
                }
            }
        }
        else
        {
            i++;                                // Hecho.
            //cout << "Hecho." << endl;
        }
    }
    cout << "Se ha encontrado una solución." << endl;
    for(i=0;i<dim;i++)
    {
        cout << "Turno " << i << ": (" << caballo[i][0] << ", " << caballo[i][1] << ") " << endl;
    }
    return 0;
}
