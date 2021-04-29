template<class T>
class ArrayIterator
{
public:
	T** Value;
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	ArrayIterator()
	{
		Value = nullptr;
		Current = 0;
	}
	ArrayIterator& operator++ ()
	{
		Value++;
		Current++;
		return *this;
	}
	ArrayIterator& operator-- ()
	{
		Value--;
		Current--;
		return *this;
	}
	bool operator==(ArrayIterator<T>& it)
	{
		return (*Value == it->Value);
	}
	bool operator!=(ArrayIterator<T>& it)
	{
		return (Current != it.Current);
	}
	T operator*()
	{
		return **Value;
	}
	T* GetElement()
	{
		return *Value;
	}
};

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:

	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		this->Capacity = 0;
		this->Size = 0;
	}
	~Array() // destructor
	{
		if (this->Capacity > 0) delete[] this->List;
		this->Size = 0;
	}

	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		this->Capacity = capacity;
		this->Size = 0;
		this->List = new T * [this->Capacity];
	}
	Array(const Array<T>& otherArray) // constructor de copiere
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < Size; ++i)
			List[i] = otherArray.List[i];
	}

	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		if (index < 0 || index >= Size) throw Exception1();
		return *List[index];
	}

	void ReallocMemory()
	{
		int i;
		if (this->Capacity == 0) this->Capacity = 1;
		T** v_copy;
		v_copy = new T * [Capacity];
		for (i = 0; i < Size; ++i)
			v_copy[i] = this->List[i];
		Capacity *= 2;
		delete[] this->List;
		this->List = new T * [Capacity];
		for (i = 0; i < Size; ++i)
			this->List[i] = v_copy[i];
		delete[] v_copy;
	}

	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		if (Size + 1 > Capacity) 
			ReallocMemory();
		List[Size] = const_cast<T*> (&newElem);
		Size++;
		return *this;
	}
	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			if (index < 0 || index > Size) throw Exception1();
			if (Size + 1 > Capacity) 
				ReallocMemory();
			for (int i = Size; i > index; --i)
				List[i] = List[i - 1];
			Size++;
			List[index] = const_cast<T*> (&newElem);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
		}
		return *this;
	}
	const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			if (index < 0 || index > Size) throw Exception1();
			while (Size + otherArray.Size > Capacity) 
				ReallocMemory();
			for (int i = Size - 1; i >= index; --i)
				List[i + otherArray.Size] = List[i];
			Size+=otherArray.Size;
			int k = 0;
			for (int i = index; k < otherArray.Size; ++i)
				List[i] = otherArray.List[k++];
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
		}
		return *this;
	}
	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			if (index < 0 || index >= Size) throw Exception1();
			for (int i = index; i < Size - 1; ++i)
				List[i] = List[i + 1];
			Size--;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
		}
		return (*this);
	}

	const Array<T> operator=(const Array<T>& otherArray)
	{
		Size = otherArray.Size;
		delete[] List;
		List = new T * [otherArray.Capacity];
		for (int i = 0; i < Size; ++i)
			List[i] = otherArray.List[i];
		return *this;
	}

	bool operator==(const Array<T>& otherArray)
	{
		if (Size != otherArray.Size) return 0;
		for (int i = 0; i < Size; ++i)
			if (List[i] != otherArray.List[i]) return 0;
		return 1;
	}

	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		int ok, m = Size, i;
		do
		{
			ok = 0;
			for (i = 0; i < m - 1; ++i)
				if (*List[i] > *List[i + 1])
				{
					std::swap(List[i], List[i + 1]);
					ok = 1;
				}
			m--;
		} 		
		while (ok == 1);
	}
	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		try                       // Nu e necesara o exceptie aici.
		{
			if (compare == nullptr) throw Exception2();
			int ok, m = Size, i;
			do
			{
				ok = 0;
				for (i = 0; i < m - 1; ++i)
					if (!compare(*List[i], *List[i + 1]))
					{
						std::swap(List[i], List[i + 1]);
						ok = 1;
					}
				m--;
			} 			
			while (ok == 1);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
		}
	}
	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{
		int ok, m = Size, i;
		do
		{
			ok = 0;
			for (i = 0; i < m - 1; ++i)
				if (!comparator->CompareElements((void*) List[i], (void*) List[i + 1]))
				{
					std::swap(List[i], List[i + 1]);
					ok = 1;
				}
			m--;
		} 		
		while (ok == 1);
	}

	bool isSorted()
	{
		for (int i = 1; i < Size; ++i)
			if (*List[i] < *List[i - 1]) return false;
		return true;
	}
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		try                   // Nu este necesara o exceptie aici, puteam sa fac ca mai jos (cu afisare mesaj si return -1).
		{
			if (!isSorted()) throw Exception4();
			int st = 0, dr = Size, m;
			while (st <= dr)
			{
				m = (st + dr) / 2;
				if (elem == *List[m]) return m;
				else if (elem < *List[m]) dr = m - 1;
				else st = m + 1;
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
		}
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind binary search si o functie de comparatie
	{
		if (compare == nullptr)
		{
			std::cout << "There is no comparation function.\n";
			return -1;
		}
		if (!isSorted())
		{
			std::cout << "List is not sorted. Binary search cannot guarantee a right answer.\n";
			return -1;
		}
		int st = 0, dr = Size, m;
		while (st <= dr)
		{
			m = (st + dr) / 2;
			if (compare(elem, *List[m]) == 0) return m;
			else if (compare(elem, *List[m]) < 0) dr = m - 1;
			else st = m + 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator) //  cauta un element folosind binary search si un comparator
	{
		if (!isSorted())
		{
			std::cout << "List is not sorted. Binary search can not guarantee a right answer.\n";
			return -1;
		}
		int st = 0, dr = Size, m;
		while (st <= dr)
		{
			m = (st + dr) / 2;
			if (comparator->CompareElements((void*) &elem, (void*) List[m]) == 0) return m;
			else if (comparator->CompareElements((void*) &elem, (void*) List[m]) < 0) dr = m - 1;
			else st = m + 1;
		}
		return -1;
	}

	int Find(const T& elem) // cauta un element in Array
	{
		for (int i = 0; i < Size; ++i)
			if (elem == *List[i]) return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind o functie de comparatie
	{
		if (compare == nullptr)
		{
			std::cout << "There is no comparation function.\n";
			return -1;
		}
		for (int i = 0; i < Size; ++i)
			if (compare(elem, *List[i]) == 0) return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator) //  cauta un element folosind un comparator
	{
		for (int i = 0; i < Size; ++i)
			if (comparator->CompareElements((void*) &elem, (void*) List[i]) == 0) return i;
		return -1;
	}

	int GetSize()
	{
		return this->Size;
	}
	int GetCapacity()
	{
		return this->Capacity;
	}

	T GetFirst()
	{
		return *List[0];
	}

	void Print()
	{
		for (int i = 0; i < Size; ++i)
			std::cout << *List[i] << " ";
		std::cout << '\n';
	}

	ArrayIterator<T> begin()
	{
		ArrayIterator<T> tmp;
		tmp.Value = &List[0];
		tmp.Current = 0;
		return tmp;
	}
	ArrayIterator<T> end()
	{
		ArrayIterator<T> tmp;
		tmp.Value = &List[Size];
		tmp.Current = Size;
		return tmp;
	}
};