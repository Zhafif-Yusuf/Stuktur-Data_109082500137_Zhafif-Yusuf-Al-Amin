#include <iostream>
#include <string>
using namespace std;

int main()
{
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    int n;
    cin >> n;

    if (n < 0 || n > 100)
    {
        cout << "Input harus antara 0 dan 100" << endl;
    }
    else if (n == 0)
    {
        cout << n << " : Nol" << endl;
    }
    else if (n < 10)
    {
        cout << n << " : " << satuan[n] << endl;
    }
    else if (n == 10)
    {
        cout << n << " : sepuluh" << endl;
    }
    else if (n == 11)
    {
        cout << n << " : sebelas" << endl;
    }
    else if (n < 20)
    {
        cout << n << " : " << satuan[n % 10] << " belas" << endl;
    }
    else if (n < 100)
    {
        cout << n << " : " << satuan[n / 10] << " puluh";
        cout << " " << satuan[n % 10] << endl;
    }
    else
    {
        cout << n << " : seratus" << endl;
    }
    return 0;
}