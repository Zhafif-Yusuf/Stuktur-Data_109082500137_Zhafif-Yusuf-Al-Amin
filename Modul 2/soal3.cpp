#include <iostream>
using namespace std;

int minimum(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int maksimum(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i > max; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void HRataRata(int arr[], int n, float &rataRata)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    rataRata = total / n;
}

void tampilArray(int arr[], int n)
{
    cout << "Isi Array: ";
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arrA[] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int n = 10;
    int x;
    float rataRata = 0;

    do
    {
        cout << "---Menu Program Array---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari indeks maksimum\n";
        cout << "3. Cari indeks minimum\n";
        cout << "4. Hitung rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu 1-5: ";
        cin >> x;
        cout << endl;

        switch (x)
        {
        case 1:
            tampilArray(arrA, n);
            break;
        case 2:
            cout << "nilai maksimumnya " << maksimum (arrA, n) << endl;
            break;
        case 3:
            cout << "nilai minimumnya " << minimum (arrA, n) << endl;
            break;
        case 4:
            HRataRata(arrA, n, rataRata);
            cout << "rata rata " << rataRata << endl;
            break;

        case 5:
            cout << "program selesai\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    }
    while (x!=5);
    return 0;
}