template <class T1, class T2>
class MapIter
{
public:
    T1* p1;
    T2* p2;
    int index;
public:
    MapIter() { p1 = nullptr; p2 = nullptr; index = 0; }
    MapIter& operator++() { p1++; p2++; index++; return *this; }
    bool operator != (MapIter& it) { return index != it.index; }
    MapValues<T1, T2> operator* ()
    {
        MapValues<T1, T2> tmp(p1, p2, index);
        return tmp;
    }
};