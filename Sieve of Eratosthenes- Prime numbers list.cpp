// Sieve of Eratosthenes

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long prime_max(long n) {
    vector<long> vec{};
    long max{};
    for (long i = 0; i < n; i++) {
        vec.push_back(1);
    }
    if (n % 2 == 0) {
        return 2;
    } else {
        for (long i = 2; i <= sqrt(n); i++) {
            if (vec[i] == 1) {
                for (long j = 2; i * j <= n; j++) {
                    vec[i * j] = 0;
                }
            }
        }
    }
    for (int k = 2; k < n; k++) {
        if (vec[k] == 1) {
         cout <<k<<" ";
        }
    }
    return max;
}

int main() {
    cout << prime_max(1325);
    return 0;
}