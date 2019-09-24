#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    int N[T], result[T];
    for (int i = 0; i < T; i++)
    {
        cin >> N[i];
    }
    for (int i = 0; i < T; i++)
    {
        result[i] = 0;
        for (int j = 0; j < N[i]; j++)
        {
            result[i] += pow(2, j);
        }
        cout << result[i] << endl;
    }
    
    return 0;
}