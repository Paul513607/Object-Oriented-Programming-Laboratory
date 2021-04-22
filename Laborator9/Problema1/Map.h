template <class T1, class T2>
class Map
{
private:
    T1 *key;
    T2 *value;
    int count;
    int max_size = 100;
public:

    Map()
    {
        key = new T1[max_size];
        value = new T2[max_size];
        count = 0;
    }

    bool Set(T1 key, T2 value)
    {
        for (int i = 0; i < count; ++i)
            if (this->key[i] == key)
            {
                this->value[i] = value;
                return true;
            }
        return false;
    }

    bool Get(const T1& key, T2& value)
    {
        for (int i = 0; i < count; ++i)
            if (this->key[i] == key)
            {
                value = this->value[i];
                return true;
            }
        return false;
    }

    int Count()
    {
        return count;
    }

    void Clear()
    {
        delete[] key;
        delete[] value;
        count = 0;
    }

    bool Delete(const T1& key)
    {
        for (int i = 0; i < count; ++i)
            if (this->key[i] == key)
            {
                for (int j = i + 1; j < count; ++j)
                {
                    this->key[j - 1] = this->key[j];
                    this->value[j - 1] = this->value[j];
                }
                count--;
                return true;
            }
        return false;
    }

    bool Includes(const Map<T1, T2>& map)
    {
        if (map.count > this->count) return false;
        for (int i = 0; i < map.count; ++i)
        {
            int ok = 0;
            for (int j = 0; j < this->count && !ok; ++j)
                if (map.key[i] == key[j]) ok = 1;
            if (ok == 0) return false;
        }
        return true;
    }

    T2& operator[](T1 key)
    {
        for (int i = 0; i < count; ++i)
            if (this->key[i] == key) return this->value[i];
        try
        {
            if (count + 1 > max_size) throw ("Too Many Numbers.\n");   // cred ca ar trebui sa pun exceptia in main cand fac atribuirile
            this->key[count++] = key;
            this->value[count - 1] = (T2)malloc(50);
            this->value[count - 1] = nullptr;
            return this->value[count - 1];
        }
        catch (const char* s)
        {
            std::cout << s;
        }
    }

    void Print()
    {
        for (int i = 0; i < count; ++i)
            std::cout << key[i] << " " << value[i] << '\n';
    }

    MapIter<T1, T2> begin() { MapIter<T1, T2> tmp; tmp.p1 = &key[0]; tmp.p2 = &value[0]; tmp.index = 0; return tmp; }
    MapIter<T1, T2> end() { MapIter<T1, T2> tmp; tmp.p1 = &key[count]; tmp.p2 = &value[count]; tmp.index = count; return tmp; }
};