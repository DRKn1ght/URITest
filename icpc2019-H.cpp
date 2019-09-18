#include <iostream>
#include <cmath>
using namespace std;
long long int V, N, VN;
int main()
{
    cin >> V;
    cin >> N;
    VN = V*N;
    for (int i = 10; i <= 90; i+=10)
    {
        if (i < 90)
        {
            cout << int(ceil((float)(VN*i)/100)) << " ";
        }else{
            cout << int(ceil((float)(VN*i)/100)) << endl;
        }
    }
}