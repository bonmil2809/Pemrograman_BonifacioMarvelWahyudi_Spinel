#include <iostream>
using namespace std;

int hitungPanjang(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void enkripsiPesan(const char pesan[], char hasil[]) {
    int len = hitungPanjang(pesan);

    for (int i = 0; i < len; i++) {
        if (i == 0) {
            hasil[i] = pesan[i];
        } else {
            int nilaiSekarang = pesan[i] - 'A' + 1;
            int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;
            int nilaiBaru = (nilaiSekarang + nilaiSebelumnya - 1) % 26 + 1;
            hasil[i] = 'A' + nilaiBaru - 1;
        }
    }
    hasil[len] = '\0';
}

int main() {
    char pesan[1000];
    char hasil[1000];

    cout << "Masukkan pesan: ";
    cin >> pesan;

    enkripsiPesan(pesan, hasil);

    cout << "Pesan setelah disandi: " << hasil << endl;
    return 0;
}