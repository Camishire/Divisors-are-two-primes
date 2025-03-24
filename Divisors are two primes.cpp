#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<long long, int> factorial (long long z) {
    map<long long, int> factors;
    for (long long j = 2; j * j <= z; j++) {
        while (z % j == 0) {
            factors[j]++;
            z /= j;
        }
    }
    if (z > 1) factors[z]++;
    return factors;
}

int NoOfDivisors (long long z) {
    int divisor  = 1;
    map<long long, int> divisors = factorial (z);
    for (auto i : divisors) {
        divisor *= (i.second + 1);
    }
    return divisor;
}

int main() {
    long long n, k;
    long long dal = 0;
    int c = 0;
    vector <int> primes = { 2, 3, 5, 7, 11, 13, 17 };
    cin >> n >> k;
    for (long long i = n; i <= k; i++) {
        dal = NoOfDivisors (i);
        if (dal >= 4) {
            for (auto p : primes) {
                if (dal % p == 0) {
                    int q = dal / p;
                    if (find(primes.begin(), primes.end(), q) != primes.end()) {
                        if (c == 0) {
                            cout << i;
                            c++;
                        }
                        else cout << " " << i;
                        break;
                    }
                }
            }
        }
    }
    if (k <= 4) cout << 0;

    return 0;
}