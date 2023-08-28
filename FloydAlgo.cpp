#include <iostream>

int a[10][10], n;

void floyds();
int min(int, int);

int main()
{
    int i, j;
    std::cout << "Enter the no. of vertices: ";
    std::cin >> n;
    std::cout << "Enter the cost matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }
    floyds();
    return 0;
}

void floyds()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    std::cout << "\nAll pair shortest path matrix is:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << "\t";
        }
        std::cout << "\n\n";
    }
}

int min(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
