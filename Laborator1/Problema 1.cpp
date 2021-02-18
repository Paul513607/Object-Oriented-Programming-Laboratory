#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ini.txt");

int main()
{
    int x,s=0;
    while (fin >> x)
        s+=x;
    cout << s;
    return 0;
}
