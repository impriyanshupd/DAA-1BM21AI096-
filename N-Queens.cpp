#include <iostream>

int place(int x[], int k)
{
    for (int i = 1; i <= k - 1; i++)
    {
        if (i + x[i] == k + x[k] || i - x[i] == k - x[k] || x[i] == x[k])
            return 0;
    }
    return 1;
}

void nqueens(int n)
{
    int k, x[20], count = 0;
    k = 1;
    x[k] = 0;
    while (k != 0)
    {
        x[k]++;
        while (place(x, k) != 1 && x[k] <= n)
            x[k]++;
        if (x[k] <= n)
        {
            if (k == n)
            {
                std::cout << "\nSolution is " << ++count << "\n";
                std::cout << "Queen\t\tPosition\n";
                for (k = 1; k <= n; k++)
                    std::cout << k << "\t\t" << x[k] << "\n";
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
            k--;
    }
}

int main()
{
    int n;
    std::cout << "Enter the number of Queens\n";
    std::cin >> n;
    nqueens(n);
    return 0;
}
