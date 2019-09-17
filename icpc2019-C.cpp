//Guilherme P. Ferrari
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int H, V, C, A, B;
char D;

struct Cars{
    int posX;
    int posY;
    char dirc;
    int mov = 1;
    int bateu = 0;
}cars[100];

//Atualiza a posição dos carros, 1 movimento para cada carro de cada vez
void UpdatePos(int ID, int H, int V)
{

    //verifica se o ID do carro é igual a quantidade de carros existentes.
    if (ID == C)
    return;

    //Verifica se o carro atingiu os extremos, no caso, ele parou.
    if ((cars[ID].posY == 1 && cars[ID].dirc == 'O') || (cars[ID].posX == 1 && cars[ID].dirc == 'N') || (cars[ID].posY == H && cars[ID].dirc == 'L') || (cars[ID].posX == V && cars[ID].dirc == 'S'))
    {
        cars[ID].mov = 0;
        UpdatePos(ID + 1, H, V);
        return;
    }

    //Faz a movimentação de acordo com a direção do carro
    switch (cars[ID].dirc)
    {
        case 'N':
        cars[ID].posX -= 1;
        break;

        case 'S':
        cars[ID].posX += 1;
        break;

        case 'L':
        cars[ID].posY += 1;
        break;

        case 'O':
        cars[ID].posY -= 1;
    }

    //Faz a movimentação do próximo carro
    UpdatePos(ID + 1, H, V);
}

int main()
{
    int batidas = 0;
    cin >> V >> H >> C;
    vector<int> Pos;

    //Declaração das posições e direções pelo usuário
    for (int i = 0; i < C; i++)
    {
        cin >> A >> B >> D;
        cars[i].posX = A;
        cars[i].posY = B;
        cars[i].dirc = D;
    }

    //Primeiro loop: Pede para movimentar os carros, separados por "ciclos"
    for (int i = 0; i < C; i++)
    {
        UpdatePos(0, H, V);

        //Apartir daqui, verifica se o carro bateu ou não
        for (int j = 0; j < C; j++)
        {
            for (int ii = 1; ii < C; ii++)
            {
                //Se o carro tiver direção L ou O, ou seja, eixo horizontal, irá verificar apenas os carros que estarão no mesmo eixo para poupar verificações desnecessárias
                if (cars[j].dirc == 'L' ||cars[j].dirc == 'O')
                {
                    if((cars[j].posX == cars[ii].posX && cars[j].posY == cars[ii].posY) && j != ii && (cars[j].posX == H || 1) && (cars[ii].posX == H || 1) && (cars[j].mov == 1 || cars[ii].mov == 1) && (cars[j].bateu == 0 || cars[ii].bateu == 0))
                    {
                        //Como ocorre no segundo exemplo dado pelo exercício, caso o carro estiver parado em um dos extremos, não ocorrerá a batida mesmo que outro carro esteja na mesma posição
                        if (cars[ii].dirc == 'L' || cars[ii].dirc == 'O')
                        {
                            batidas++;
                            cars[j].bateu = 1;
                            cars[ii].bateu = 1;
                        }
                    }
                }else
                {
                    //mesmo de cima, só que para carros na direção S e N
                    if ((cars[j].posY == cars[ii].posY && cars[j].posY == cars[ii].posY) && j != ii && (cars[j].posY == V || 1) && (cars[ii].posY == V || 1) && (cars[j].mov == 1 || cars[ii].mov == 1) && (cars[j].bateu == 0 || cars[ii].bateu == 0))
                    {
                        batidas++;
                        cars[j].bateu = 1;
                        cars[ii].bateu = 1;
                    }    
                }
            }
        }
    }
    cout << "Batidas -> " << batidas << endl;
    
    return 0;
}