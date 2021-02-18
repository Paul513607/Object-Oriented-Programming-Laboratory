#include <iostream>
#include <cstring>

using namespace std;

void convert_to_low(char s[])
{
    int i;
    for (i=0; s[i]; ++i)
        if (s[i]>='A' && s[i]<='Z')
            s[i]+=32;
}

void swaps(int &x,int &y)
{
    int aux=x;
    x=y;
    y=aux;
}

void bubble(int n, char v[][30],int c[])
{
    int m=n,i,ok;
    char aux[30],a1[30],a2[30];
    do
    {
        ok=1;
        for (i=1; i<m; ++i)
        {
            if (c[i]<c[i+1])
            {
                strcpy(aux,v[i]);
                strcpy(v[i],v[i+1]);
                strcpy(v[i+1],aux);
                ok=0;
                swaps(c[i],c[i+1]);
            }
            else if (c[i]==c[i+1])
            {
                strcpy(a1,v[i]); convert_to_low(a1);
                strcpy(a2,v[i+1]); convert_to_low(a2);
                if (strcmp(a1,a2)>0)
                {
                    strcpy(aux,v[i]);
                    strcpy(v[i],v[i+1]);
                    strcpy(v[i+1],aux);
                    ok=0;
                }
            }
        }
        m--;
    }
    while (ok==0);
}

int main()
{
    char s[200], v[20][30],*cuv;
    int c[20],p=0;
    cin.getline(s,200);
    cuv=strtok(s," ");
    while (cuv)
    {
        p++;
        strcpy(v[p],cuv);
        c[p]=strlen(cuv);
        cuv=strtok(NULL," ");
    }
    bubble(p,v,c);
    for (int i=1; i<=p; ++i)
        cout << v[i] << '\n';
    return 0;
}
