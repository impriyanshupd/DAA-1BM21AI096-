#include <iostream>

int bin(int n, int k) {
    int i, j, c[10][10];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            if (j == 0 || i == j)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    return c[n][k];
}

int main() {
    int n, k;
    std::cout << "Enter the value of n & k such that n > k" << std::endl;
    std::cin >> n >> k;
    std::cout << "C(" << n << "," << k << ") = " << bin(n, k) << std::endl;
    return 0;
}
