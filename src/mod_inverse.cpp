#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1; 

    return g;
}

long long extended_euclid(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = extended_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long g = extended_euclid(a, m, x, y);

    if (g != 1) return -1;

    return (x % m + m) % m;
}

int main() {
    int a = 0, m = 0;
    cout << "Nhap a, m: ";
    cin >> a >> m;

    if (gcd(a, m) != 1) {
        cout << "Khong ton tai nghich dao modulo vi gcd(a, m) != 1.\n";
        return 0;
    }

    int inv = mod_inverse(a, m);
    cout << "Nghich dao cua " << a << " mod " << m << " la: " << inv << '\n';
    cout << "Kiem tra: " << a << " * " << inv << " % " << m
         << " = " << (1LL * a * inv % m) << '\n';
    return 0;
}