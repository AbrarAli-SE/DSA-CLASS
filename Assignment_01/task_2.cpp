// A company stores its monthly sales figures for each of its 12 branches in an array. Write a program
// that calculates the total annual sales by iterating through the array. Additionally, identify which
// branch had the highest and lowest sales for the year.
#include <iostream>
using namespace std;
int main()
{
    int maxBranches = 3, maxMonths = 3;
    int sale[maxBranches][maxMonths];
    int totalSales = 0, highSales = 0, lowSales = sale[0][0], highBranch = 0, lowBranch = 0;
    for (int i = 0; i < maxBranches; i++)
    {
        for (int j = 0; j < maxMonths; j++)
        {
            cout << "Enter sales for branch " << i + 1 << " in month " << j + 1 << ": ";
            cin >> sale[i][j];
            totalSales += sale[i][j];
            if (sale[i][j] > highSales)
            {
                highSales = sale[i][j];
                highBranch = i;
            }
            if (sale[i][j] < lowSales)
            {
                lowSales = sale[i][j];
                lowBranch = i;
            }
        }
    }
    cout << "\nTotal annual sales: " << totalSales << endl;
    cout << "Branch with highest sales: " << highBranch + 1 << endl;
    cout << "Branch with lowest sales: " << lowBranch + 1 << endl;
    return 0;
}