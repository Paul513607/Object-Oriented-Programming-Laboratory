template <class T>
int cmp1(const T& a, const T& b)
{
	return (a <= b);
}

template <class T>
int cmp2(const T& a, const T& b)
{
	if (a == b) return 0;
	else if (a < b) return -1;
	else return 1;
}

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T = int>
class Compare_Sort : public Compare
{
public:
	int CompareElements(void* a, void* b)
	{
		return (*((T*) a) <= *((T*) b));
	}
};

template<class T = int>
class Compare_Search : public Compare
{
public:
	int CompareElements(void* a, void* b)
	{
		if (*((T*)a) == *((T*)b)) return 0;
		else if (*((T*)a) < *((T*)b)) return -1;
		else return 1;
	}
};