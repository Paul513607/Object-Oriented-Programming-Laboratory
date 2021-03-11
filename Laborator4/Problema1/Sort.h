class Sort
{
private:
    int n,v[100];
public:
    Sort(int n,int min,int max);
    Sort(std::initializer_list<int> l)
    {
        int j=0;
        for (int i : l)
        {
            v[j]=i;
            j++;
        }
        n=l.size();
    }
    Sort(int n,int v[]);
    Sort(int n, ...);
    Sort(const char *s);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
