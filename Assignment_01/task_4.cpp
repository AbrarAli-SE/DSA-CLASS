// A temperature monitoring system records hourly temperatures for an entire week and stores them in
// a two-dimensional array where rows represent days and columns represent hours (24 hours per day).
// // Write a program to: -
// Calculate the average temperature for each day.
// - Identify the hour with the highest temperature for the entire week. -
// Find out which day had the lowest average temperature.

#include <iostream>
using namespace std;
int main()
{
    int maxDay=2,maxHour=6;
    int arr[maxDay][maxHour],maxTemp = 0, maxTempDay = 0,maxTempHour=0, minavg = 1000, minavgday = 0;
    float sum = 0;
    cout << "Enter the temperatures for each hour of each day:\n";
    for (int i = 0; i < maxDay; i++)
    {
        for (int j = 0; j < maxHour; j++)
        {
            cin >> arr[i][j];
        }
    }
    // avg per day
    for (int i = 0; i < maxDay; i++)
    {
        sum=0;
        for (int j = 0; j < maxHour; j++)
        {
            sum += arr[i][j];
            if (arr[i][j] > maxTemp)
            {
                maxTemp = arr[i][j];
                maxTempDay = i;
                maxTempHour = j;
            }
        }
        float avg = sum / maxHour;
        cout<<"\n\tAvg of temprature Day "<<i+1<<" is : "<<avg;
        if (avg < minavg) // low avg
        {
            minavg = avg;
            minavgday = i;
        }
    }
    cout << "\n\tThe day " << minavgday + 1 << " with the lowest average temperature " << minavg;
    cout << "\n\tThe hour " << maxTempHour + 1 << " of Day "<< maxTempDay + 1 << " have highest temperature " << maxTemp << endl;
        return 0;
}