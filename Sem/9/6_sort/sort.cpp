#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sort_function (int i,int j)
{
	return (i<j);
}

struct sort_class
{
	bool operator() (int i, int j)
	{ return (i<j);}
} sort_object;

int main ()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector<int> myvector (myints, myints+8);
	// теперь в контейнере: 32 71 12 45 26 80 53 33
	vector<int>::iterator it;
    
	// используем сравнение по-умолчанию
	sort (myvector.begin(), myvector.begin()+4);
	// теперь в контейнере: (12 32 45 71)26 80 53 33
    
    // иcпользуем нашу функцию сравнения
    sort (myvector.begin()+4, myvector.end(), sort_function);
    // теперь в контейнере: 12 32 45 71(26 33 53 80)
    
	// вот сюда будем добавлять остальные варианты сортировки
    
	// печатаем содежимое
	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;
    
	cout << endl;
    
    // используем функутор сортировки
	sort (myvector.begin(), myvector.end(), sort_object);
	// теперь в контейнере: (12 26 32 33 45 53 71 80)
    
    cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;
    
	cout << endl;
    
	return 0;
}