#include <iostream>
#include <vector>
using namespace std;
int M, N, K, ver = 0;
char Result;

struct sensores{
    int X;
    int Y;
    int S;
    int cX;
    int cX2;
    int cY;
    int cY2;
}sens[10000];

struct area{
    int X = 10;
    int X2 = 0;
    int Y;
    int Y2;
}Area[0];

char Verificar(int *M, int *N)
{

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            
            if (sens[j].cX > sens[i].cX && j != i && (sens[j].X == sens[i].X || sens[j].Y == sens[i].Y || (sens[j].cX2 >= sens[i].X && sens[j].cY2 >= sens[i].Y)))
            {
                Area[0].X = sens[i].cX;
                //cout << Area[0].X << " area X" << endl;
            }
            if (sens[j].cX2 < sens[i].cX2 && j != i && (sens[j].X == sens[i].X || sens[j].Y == sens[i].Y || (sens[j].cX2 >= sens[i].X && sens[j].cY2 >= sens[i].Y)))
            {
                Area[0].X2 = sens[i].cX2;
                //cout << Area[0].X2 << " area X2" << endl;
            }

            if (sens[j].cY > sens[i].cY && j != i && (sens[j].X == sens[i].X || sens[j].Y == sens[i].Y || (sens[j].cX2 >= sens[i].X && sens[j].cY2 >= sens[i].Y)))
            {
                Area[0].Y = sens[i].cY;
                //cout << Area[0].Y << " area Y" << endl;
            }
            if (sens[j].cY2 < sens[i].cY2 && j != i && (sens[j].X == sens[i].X || sens[j].Y == sens[i].Y || (sens[j].cX2 >= sens[i].X && sens[j].cY2 >= sens[i].Y)))
            {
                Area[0].Y2 = sens[i].cY2;
                //cout << Area[0].Y2 << " area Y2" << endl;
            }
        }
    }
    if (Area[0].X <= 0 && Area[0].X2 >= *M)
    return 'N';
    //cout << Area[0].X << " <- area X - area X2 ->" << Area[0].X2 << endl;

    if (Area[0].Y <= 0 && Area[0].Y2 >= *N)
    return 'N';
    //cout << Area[0].Y << " <- area Y - area Y2 ->" << Area[0].Y2 << endl;

    return 'S';
}

int main()
{
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> sens[i].X >> sens[i].Y >> sens[i].S;
        int Sen = sens[i].S;
        sens[i].cX = sens[i].X - Sen;
        sens[i].cX2 = sens[i].X + Sen;

        sens[i].cY = sens[i].Y - Sen;
        sens[i].cY2 = sens[i].Y + Sen;
    }
    cout << Verificar(&N, &M) << endl;
    
    return 0;
}