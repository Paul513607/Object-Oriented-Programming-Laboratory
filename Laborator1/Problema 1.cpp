#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ini.txt");

int convert_to_int(char x[])
{
    int i,nr=0,ok=1;
    for (i=0; x[i]; ++i)
    {
        if (x[i]>='0' && x[i]<='9')
            nr=nr*10+(x[i]-'0')%10;
        else ok=0;
    }
    if (ok==0) return 0;
    return nr;
}

int main()
{
    char x[20];
    int s=0,nr;
    while (fin >> x)
    {
        nr=convert_to_int(x);
        s+=nr;
    }
    cout << s;
    return 0;
}
