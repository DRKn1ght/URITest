//Exercício 1091 URI
#include <iostream>
#include <vector> 
using namespace std;

vector<string>dir; //Vetor que guarda as respostas

void direcao(int N, int M, int X, int Y){
        if (X == N || Y == M)
            dir.push_back("divisa");
        else if (X > N)
        {
            if (Y > M)
                dir.push_back("NE");
            else
               dir.push_back("SE");
        }
        else
        {
            if (X < N)
            {
                if (Y > M)
                    dir.push_back("NO");
                else
                    dir.push_back("SO");
            }
        }
}
int main()
{
    int N, M, K, X, Y; //Variáveis;
    while (true)
    {
        cin >> K; //Pega o valor de K (primeira linha)
        if(K == 0){ //Se K = 0, lista o vetor com as respostas e fecha o programa
            for(auto v = dir.begin(); v != dir.end(); v++)
                cout << *v << endl;
            break;
        }
        cin >> N; //Pega o valor de N
        cin >> M; //Pega o valor de M
        while (K != 0) //Executa o numero de vezes o K
        {
            cin >> X;
            cin >> Y;
            direcao(N, M, X, Y); //Envia para a função as informações para salvar no vetor dir as respostas
            K--;
        }
    }
}
