// You are tasked with creating a seating arrangement system for a cinema. The cinema has 10 rows 
// with 15 seats in each row. Represent this seating arrangement using a two-dimensional array where 
// each seat can be marked as `1` (occupied) or `0` (available). Write a program to: - Display the seating arrangement. - Allow users to book a seat by marking it as occupied. - Prevent users from booking an already occupied seat.

#include <iostream>
#include <ctime>
using namespace std;

const int ROWS = 10;
const int COLS = 15;
void displaySeats(int seats[ROWS][COLS])
{
  cout << "Current Seat Availability:\n";
  for (int i = 0; i < ROWS; ++i)
  {
    for (int j = 0; j < COLS; ++j)
    {
      cout << seats[i][j] << " ";
    }
    cout << "\n";
  }
}

bool bookSeat(int seats[ROWS][COLS], int row, int col)
{
  if (seats[row][col] == 1)
  {
    seats[row][col] = 0;
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int seats[ROWS][COLS];

  srand(time(0));
  for (int i = 0; i < ROWS; ++i)
  {
    for (int j = 0; j < COLS; ++j)
    {
      seats[i][j] = rand() % 2; // Randomly assign 0 or 1
    }
  }

  int row, col;
  char choice;

  do
  {
    displaySeats(seats);
    cout << "\nEnter row number: ";
    cin >> row;
    cout <<"Enter Column number: ";
    cin >> col;
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
      if (bookSeat(seats, (row-1), (col-1)))
      {
        cout << "Seat successfully booked.\n";
      }
      else
      {
        cout << "Seat already booked.\n";
      }
    }
    else
    {
      cout << "Invalid row or column.\n";
    }

    cout << "Do you want to book another seat? (y/n): ";
    cin >> choice;

  } while (choice == 'y' || choice == 'Y');

  cout << "Final Seat Availability:\n";
  displaySeats(seats);

  return 0;
}