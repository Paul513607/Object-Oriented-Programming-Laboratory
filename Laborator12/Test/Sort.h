template <typename T>
void bubbleSort(std::list<T> &ls)
{
    T aux;
    typename std::list<T>::iterator it, ittemp;
    typename std::list<T>::iterator iend = ls.end();
    iend--;
    iend--;
    int ok;
    do
    {
        ok = 0;
        for (it = ls.begin(); it != iend; ++it)
        {
            ittemp = ++it;
            it--;
            if (*it > *ittemp)
            {
                aux = *it;
                *it = *ittemp;
                *ittemp = aux;
                ok = 1;
            }
        }
        if (iend != ls.begin())
            iend--;
    } while (ok == 1);
}