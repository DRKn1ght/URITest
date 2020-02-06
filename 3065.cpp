//Exercício 3065 URI
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> r; //Vetor que guarda os números lidos
vector<int> answ; //Vetor que guarda as respostas pra cada caso
int main()
{
    while (true)
    {
        string equation, EAux, k;
        int y, i = 0;
        cin >> k;
        if (k == "0") //Se K for 0, printa o vetor answ contendo as respostas
        {
            for (int count = 0; count < answ.size(); count++)
                cout << "Teste " << count + 1 << endl
                     << answ[count] << endl
                     << endl;
            break;
        }
        cin >> equation;
        for (i; i <= equation.size(); i++) //Lê cada char da equação
        {
            if (equation[i] == '+' || equation[i] == '-') //se for + ou -
            {
                r.push_back(stoi(EAux)); //Pega a string que tem em EAux e coloca no vetor r
                EAux.erase(); //Apaga a string EAux
                EAux.push_back(equation[i]); //seta EAux como o operador encontrado (+ ou -)
            }
            else //Se não for + ou -
            {
                if (i == equation.size()) //Caso especial → se i for o ultimo loop; 
                {
                    EAux.push_back(equation[i]); //Coloca o numero no final do EAux
                    r.push_back(stoi(EAux)); //Coloca tudo que tem no EAux no vetor r
                    EAux.erase();
                }
                else //Se não for o caso especial
                {
                    EAux.push_back(equation[i]);
                }
            }
        }
        int resposta = 0;
        for (int x = 0; x < r.size(); x++)
        {
            resposta += r[x];
        }
        r.erase(r.begin(), r.end());
        answ.push_back(resposta);
    }
}