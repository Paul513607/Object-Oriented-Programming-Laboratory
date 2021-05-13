class MyVectorIter
{
public:
    int* p;
    int index;
public:
    MyVectorIter() { p = nullptr; index = 0; }
    MyVectorIter& operator++() { p++; index++; return *this; }
    bool operator != (MyVectorIter& it) { return index != it.index; }
    int operator*() { return *p; }
};

class MyVector
{
private:
    int* v;
    int count;
    int max_size;
public:
    MyVector();
    void ReallocMemory();
    bool Add(const int& value); // return true if the value was added. As a result, the size of the vector increases with one
    bool Delete(int index); // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.
    void Iterate(int i1, int i2, bool (*f)(int& val));
    void Filter(int i1, int i2, bool (*f)(int& val));
    int& operator[](int index);
    int GetCount();
    MyVectorIter begin() { MyVectorIter tmp; tmp.p = &v[0]; tmp.index = 0; return tmp; }
    MyVectorIter end() { MyVectorIter tmp; tmp.p = &v[count]; tmp.index = count; return tmp; }
    ~MyVector() { delete[] v; }
};