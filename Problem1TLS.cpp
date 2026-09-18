#include <iostream>
using namespace std;

void hapusAstronaut(int arr[], int &size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void simulasiEliminasi(int n, int k) {
    if (k < 2) k = 2;

    int astronaut[1000];
    for (int i = 0; i < n; i++) {
        astronaut[i] = i + 1;
    }

    int size = n;
    int pos = 0;

    cout << "\nUrutan eliminasi: ";
    while (size > 1) {
        pos = (pos + k - 1) % size;
        int eliminated = astronaut[pos];
        cout << eliminated << " ";

        hapusAstronaut(astronaut, size, pos);

        if (eliminated % 2 == 0) {
            k += 2;
        } else {
            k--;
            if (k < 2) k = 2;
        }
    }
    cout << "\nAstronaut terakhir: " << astronaut[0] << endl;
}

int main() {
    int n, k;
    cout << "Masukkan N: ";
    cin >> n;
    cout << "Masukkan K: ";
    cin >> k;

    simulasiEliminasi(n, k);
    return 0;
}