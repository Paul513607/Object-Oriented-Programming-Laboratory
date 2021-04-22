template <class T1, class T2>
struct MapValues
{
    T1 v1;
    T2 v2;
    int index;
    MapValues(T1* p1, T2* p2, int p3) : v1(*p1), v2(*p2), index(p3) {}
};