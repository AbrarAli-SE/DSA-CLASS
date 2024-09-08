// An e-commerce website stores customer order IDs in a one-dimensional array. After every
// transaction, the array is updated with the new order ID. The website wants to implement a feature to
// search for a specific order ID in the array and determine its position. Write a function that performs
// this search efficiently, assuming the array can have up to 1,000 orders.
#include <iostream>
using namespace std;
int main()
{
    int arr[1000], n, pos = -1, target;
    cout << "\n\tEnter the number of orders: ";
    cin >> n;
    cout<<endl<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\tEnter the order " << i + 1 << " ID: ";
        cin >> arr[i];
    }
    cout << "\tEnter the order ID to search for: ";
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            pos = i;
            break;
        }
    }
    // display if the order id found if not then show not found massage
    if (pos != -1)
    {
        cout << "\n\tOrder ID found at position: " << pos + 1 << endl;
    }
    else
    {
        cout << "\n\tOrder ID not found in the array." << endl;
    }
    return 0;
}