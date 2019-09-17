#include <iostream>
#include <cmath>
using namespace std;
int V, N, VN;
int main()
{
    cin >> V >> N;
    VN = V*N;
    for (int i = 10; i <= 90; i+=10)
    {
        cout << ceil((float)(VN*i)/100) << " ";
    }
}