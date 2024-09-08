#include <iostream>
using namespace std;
void bookAdd(int bookList[][2], int &bookCount) 
{
    cout << "\n\tEnter Book-Id: ";
    cin >> bookList[bookCount][0]; 
    bookList[bookCount][1] = 5; 
    cout << "\tBook Added Successfully!";
    bookCount++; 
}
void bookBorrow(int bookList[][2], int maxBook)
{
    bool found = false;
    cout << "\n\tEnter Book-Id: ";
    int bookID;
    cin >> bookID;
    for (int i = 0; i < maxBook; i++)
    {
        if (bookList[i][0] == bookID)
        {
            if (bookList[i][1] > 0)
            {
                cout << "\tBook Borrowed Successfully!";
                bookList[i][1]--;
                found = true;
            }
            else
            {
                cout << "\n\tBook Not Available!";
                found = true;
            }
        }
    }
    if (!found)
    {
        cout << "\n\tBook Not Found!";
    }
}
void bookReturned(int bookList[][2], int maxBook)
{
    bool found = false;
    int bookID;
    cout << "\n\tEnter Book-Id: ";
    cin >> bookID;
    for (int i = 0; i < maxBook; i++)
    {
        if (bookList[i][0] == bookID)
        {
            cout << "\tBook Returned Successfully!";
            bookList[i][1]++;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\n\tBook Not Found Please add book First!";
    }
}
int main()
{
    int maxBook = 100, bookCount = 0;
    int bookList[maxBook][2];
    cout << "\n\t\tWelcome! Please enter at least one Book!\n\n";
    char choice;
    do
    {
        cout << "\n\n\t*** Library Menu ***";
        cout << "\n\t1. Add a Book";
        cout << "\n\t2. Borrow a Book";
        cout << "\n\t3. Return a Book";
        cout << "\n\t4. Exit";
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            bookAdd(bookList, bookCount);
            break;
        case '2':
            bookBorrow(bookList, maxBook);
            break;
        case '3':
            bookReturned(bookList, maxBook);
            break;
        case '4':
            cout << "\n\tExiting... Thank you!";
            break;
        default:
            cout << "\n\tInvalid choice! Please select a valid option.";
        }
    } while (choice != '4');

    return 0;
}