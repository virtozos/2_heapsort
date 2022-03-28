#include <iostream>

using namespace std;

//zwraca indeks rodzica
int parent(int x) {
    return (x - 1) / 2;
}

//zamienia dwa elementy tablicy
void swap(int* array, int a, int b) {
    int ancillary = array[a];
    array[a] = array[b];
    array[b] = ancillary;
}

//wypisuje zawartosc tablicy
void print(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i != size - 1)
            cout << ' ';
    }
}

int main()
{
    //wczytuje liczbe przypadkow testowych
    int n;
    cin >> n;

    while (n) {
        //wczytuje liczbe elementow oraz elementy do tablicy
        int k;
        cin >> k;
        int* array = new int[k];
        for (int i = 0; i < k; i++) {
            cin >> array[i];
        }

        int index, size=k;

        for (int i = 0; i < k-1; i++) {
            
            //kopcowanie
            for (int j = 0; j < size; j++) {

                //porownuje i zamienia rodzica z dzieckiem
                for (index = j; index; index = parent(index)) {
                    if (array[index] > array[parent(index)])
                        swap(array, index, parent(index));
                    else
                        break;
                }
            }
            print(array, size);
            cout << '\n';
            swap(array, 0, size-1);
            size--;
        }

        //wypisywanie
        print(array, k);
        n--;
        if (n)
            cout << "\n\n";
        delete[] array;
    }
}