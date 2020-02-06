//exercício 1140 URI
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string>result;
void verifica(string a)
{
    for(int i = 1; i <= a.size(); i++)
        if (a[0] != a[a.size() - i]){
            result.push_back("N");
            return;
        }
    result.push_back("Y");
}

int main()
{
    int i, index;
    while (true)
    {
        string a, b;
        i = 0;
        index = 0;
        getline(cin, a, '\n');
        if (a == "*") //Quando recebe *, o programa lista o vetor result e 
        {
            for(auto v = result.begin(); v != result.end(); v++)
                cout << *v << endl;
            break;
        }
        while (a[i] != '\0')
        {
            if (a[i] == ' ' || i == 0)
            {
                if (i != 0)
                {
                    b.push_back(toupper(a[i + 1]));
                }
                else
                {
                    b.push_back(toupper(a[i]));
                }
            }
            i++;
        }
        verifica(b);
    }
}