#include <iostream>

int max(int, int);

int main() {
    int n, m;
    std::cout << "Enter the no. of items: ";
    std::cin >> n;

    int w[n+1], p[n+1], v[n+1][n+1];

    std::cout << "Enter the weight of each item:\n";
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }

    std::cout << "Enter the profit of each item:\n";
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }

    std::cout << "Enter the knapsack's capacity: ";
    std::cin >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j - w[i] < 0) {
                v[i][j] = v[i-1][j];
            } else {
                v[i][j] = max(v[i-1][j], v[i-1][j-w[i]] + p[i]);
            }
        }
    }

    std::cout << "\nThe output is:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            std::cout << v[i][j] << "\t";
        }
        std::cout << "\n\n";
    }

    std::cout << "The optimal solution is " << v[n][m] << "\n";
    std::cout << "The solution vector is:\n";

    int x[n+1];
    for (int i = n; i >= 1; i--) {
        if (v[i][m] != v[i-1][m]) {
            x[i] = 1;
            m = m - w[i];
        } else {
            x[i] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << x[i] << "\t";
    }

    return 0;
}

int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
