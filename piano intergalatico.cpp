#include<iostream>
#include <sstream>
#include <vector> 
#include <algorithm>

using namespace std;

int N = 0, k = 0, f = 0, Q = 0, a1 = 0, b1 = 0, mf = 0, P[100], a[100], b[100];
int MaisFreq(int A, int B);

struct info
{
    int freq;
    int num;
}Info[100];

int main()
{
    cin >> N;
    cin >> Q;
    P[N-1];
    a[Q];
    b[Q];
    for (int i = 0; i < N; i++)
    {
        P[i] = 1;
    }

    for (int i = 1; i <= Q; i++)
    {
        cin >> a1;
        cin >> b1;
        a[i] = a1;
        b[i] = b1;
    }
    
    for (int i = 1; i <= Q; i++)
    {
        MaisFreq(a[i], b[i]);
        for (int i = 0; i < N; i++)
        {
            //cout << P[i] << " ";
        }
        //cout << " A e B: (" << a[i] << ", " << b[i] <<")" << endl;
    }
     for (int i = 0; i < N; i++)
    {
        cout << P[i] << endl;
    }
}

int MaisFreq(int A, int B)
{
    int count = 0, index = 0, hi, i2 = 0, i3 = 0;
    vector<int> vectorN;
    
    for (int i = A; i <= B; i++)
    {
        count = 0;
        for (int j = A; j <= B; j++)
        {
           vector<int>::iterator it = find(vectorN.begin(), vectorN.end(), P[i]);
           if(it != vectorN.end())
           break;
           
            if (P[i] == P[j])
            {
                count++;
                Info[index].freq = count;
                Info[index].num = P[i];
            }
        }
        vectorN.push_back(Info[index].num);
        cout << Info[index].freq << " - " << Info[index].num << " i-> " << i << endl;

        index++;
    }
    
    
    for (int i = A; i <= B; i++)
    {
        //cout << "Numero i2: " << Info[i2].num << " - Freq: " << Info[i2].freq << " || Numero i: " << Info[i3].num << " - Freq: " << Info[i3].freq << endl;
        if (Info[i2].freq <= Info[i3].freq)
        {
            if (Info[i2].freq < Info[i3].freq)
            i2 = i3;
            if (Info[i2].num <= Info[i3].num)
            {
                i2 = i3; 
            }
        }
        i3++;
    }
    
    for (int i = A; i <= B; i++)
    {
        int NovaNota = P[i] + Info[i2].num;
        if (NovaNota > 8)
        {
            NovaNota = NovaNota - 9;
            if (NovaNota < 0)
            NovaNota = NovaNota * -1;
        }
        P[i] = NovaNota;
    }
    return i2;
}