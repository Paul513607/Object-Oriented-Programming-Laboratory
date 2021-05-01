#include <iostream>

class Testing
{
private:
    int x, y, z;
public:
    Testing() : x(0), y(0), z(0) {}
    Testing(int x, int y, int z) : x(x), y(y), z(z) {}
    ~Testing() {};
    friend std::istream& operator>> (std::istream& in, Testing& t)
    {
        in >> t.x >> t.y >> t.z;
        return in;
    }
    friend std::ostream& operator<< (std::ostream& out, const Testing& t)
    {
        out << t.x << " " << t.y << " " << t.z << '\n';
        return out;
    }
};

int main()
{
    Testing t1(1, 2, 4);
    Testing t2;
    Testing t3 = { 10,20,40 };
    std::cin >> t2;
    std::cout << t1 << t2 << t3;
    return 0;
}