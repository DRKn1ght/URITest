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
    int i = 0, input, kaux, N, M, K; //Variáveis
    vector<int> X, Y; //Vetor X e Y de cada casa
    while (true)
    {
        cin >> K; //Pega o valor de K (primeira linha)
        kaux = K; //K Auxiliar
        if(K == 0){ //Se K = 0, lista o vetor com as respostas e fecha o programa
            for(auto v = dir.begin(); v != dir.end(); v++)
                cout << *v << endl;
            cout << endl;
            break;
        }
        cin >> N; //Pega o valor de N
        cin >> M; //Pega o valor de K
        while (kaux != 0) //Executa o numero de vezes o K
        {
            cin >> input; X.push_back(input);
            cin >> input; Y.push_back(input);
            direcao(N, M, X[i], Y[i]); //Envia para a função as informações para salvar no vetor dir as respostas
            i++;
            kaux--;
        }
    }
}