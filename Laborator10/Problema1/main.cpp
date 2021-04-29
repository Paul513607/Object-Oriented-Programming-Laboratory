#include <iostream>
#include <exception>
#include <type_traits>
#include "Exception.h"
#include "Compare.h"
#include "Array.h"

int main()
{
	Array<int> arr1;
	Array<int> arr2(100);
	arr2 += 4;
	arr2 += 9;
	Array<int> arr3(arr2);
	arr3 += 1;
	std::cout << arr2[0] << " " << arr2[arr2.GetSize() - 1] << '\n';
	arr3.Print();
	arr1 += 5;
	arr1 += 4;
	arr1.Insert(0, 20);
	arr1.Insert(1, arr2);
	arr1.Delete(1);
	printf("%d %d\n", arr1.GetSize(), arr1.GetCapacity());
	arr1.Print();
	arr1.Sort(cmp1);

	for (auto it : arr1)
		std::cout << it << " ";

	std::cout << '\n';
	printf("%d %d %d %d\n", arr1.BinarySearch(9), arr1.BinarySearch(20, cmp2), arr1.Find(3), arr1.Find(18, cmp2));
	arr1.Insert(-2, 100);
	arr1.Insert(100, arr2);
	arr1.Delete(100);
	try
	{
		std::cout << arr1[40];
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
	arr1.Print();
	
	arr2 += 6;
	arr2 += (-5);
	Compare_Sort<decltype(arr2.GetFirst())> cmpa;
	Compare* a = &cmpa;
	arr2.Sort(a);
	arr2.Print();
	Compare_Search<decltype(arr2.GetFirst())> cmpb;
	printf("%d %d\n",arr2.Find(-5,&cmpb),arr2.BinarySearch(6,&cmpb));
	arr3.BinarySearch(4, &cmpb);
	try
	{
		arr2[1] = 400;
		arr2[-3] = 800;
		arr2[2] = 500;  // Nu se va apela (recomandat ar fi sa folosim try--catch pentru fiecare arr2[index])
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
	arr2.Print();
	return 0;
}
