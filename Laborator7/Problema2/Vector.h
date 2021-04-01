#define MAX 10

template <class T>
class Vector
{
private:
    int count;
    int max_size=MAX;
    T *v;
public:

    typedef bool(*MyCompareFunction) (const T &a,const T &b);

    Vector() {count=0; v=new T[max_size];};

    // puteam pune copy/move constructors si assignment operators dar nu pentru clasa Vector, dar putem copia/muta doar this->v daca e nevoie

    Vector(std::initializer_list<T> l)
    {
        int j=0;
        v=new T[max_size];
        while (l.size()>max_size)
        {
            delete[] v;
            max_size*=2;
            T *v=new T[max_size];
        }
        for (int i : l)
        {
            v[j]=i;
            j++;
        }
        count=l.size();
    }

    void push(T value)
    {
        if (count==max_size)
        {
            int i;
            T *v_new=new T[max_size];
            for (i=0; i<count; ++i)
                v_new[i]=v[i];
            max_size*=2;
            delete[] v;
            v=new T[max_size];
            for (i=0; i<count; ++i)
                v[i]=v_new[i];
            delete[] v_new;
        }
        v[count++]=value;
    }

    T top()
    {
        if (count == 0)
        {
            //throw MyException();
        }
        return v[count-1];
    }

    T pop()
    {
        if (count == 0)
        {
            //throw MyException();
        }
        return v[--count];
    }

    void remove(int index)
    {
        int i;
        for (i=index+1; i<count; ++i)
            v[i-1]=v[i];
        count--;
    }

    void insert(T value, int index)
    {
        if (index<0 || index>=count)
        {
            std::cout << "\nValue " << value << " can't be inserted at index " << index << " (index " << index << " does not exist).\n";
        }
        else
        {
            int i;
            if (count==max_size)
            {
                T *v_new=new T[max_size];
                for (i=0; i<count; ++i)
                    v_new[i]=v[i];
                max_size*=2;
                delete[] v;
                v=new T[max_size];
                for (i=0; i<count; ++i)
                    v[i]=v_new[i];
                delete[] v_new;
            }
            for (i=count-1; i>=index; --i)
                v[i+1]=v[i];
            count++;
            v[index]=value;
        }
    }

    void sort(MyCompareFunction cmp)
    {
        int m=count,ok,i;
        do
        {
            ok=0;
            for (i=0; i<m-1; ++i)
                if (cmp)
                {
                    if(cmp(v[i],v[i+1]))
                    {
                        std::swap(v[i],v[i+1]);
                        ok=1;
                    }
                }
                else if (v[i]<v[i+1])
                {
                    std::swap(v[i],v[i+1]);
                    ok=1;
                }
            m--;
        }
        while (ok==1);
    }

    T Get(int index)
    {
        if (index<0 || index>=count)
        {
            std::cout << "\nIndex " << index << " does not exist.\n";
        }
        return v[index];
    }

    void Set(T value, int index)
    {
        if (index<0 || index>=count)
        {
            std::cout << "\nIndex " << index << " does not exist.\n";
            return;
        }
        v[index]=value;
    }

    int Count()
    {
        return count;
    }

    int firstIndexOf(T value, MyCompareFunction cmp)
    {
        int i;
        for (i=0; i<count; ++i)
            if (cmp)
            {
                if (cmp(v[i],value)) return i;
            }
            else if (v[i]==value) return i;
        std::cout << "\nValue " << value << " does not exist.\n";
    }

    void print()
    {
        int i;
        for (i=0; i<count; ++i)
            std::cout << v[i] << " ";
        std::cout << '\n';
    }

    ~Vector() {delete v;}
};
