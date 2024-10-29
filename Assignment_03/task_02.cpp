#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    string name;
    Node *next;
    Node(int val, string n) : value(val), name(n), next(NULL) {}
};

void insertAtTail(Node *&head, int val, string name)
{
    Node *newNode = new Node(val, name);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *insertionSort(Node *head)
{
    if (!head)
        return head;
    Node *sorted = NULL;
    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        if (!sorted || sorted->value < current->value)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next && temp->next->value >= current->value)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "\t" << temp->name << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;

    insertAtTail(head, 24904, "Hamza Baig");
    insertAtTail(head, 27773, "Muhammad Ayaz");
    insertAtTail(head, 35622, "FAIZAN KHAN");
    insertAtTail(head, 37532, "Shoaib Iqbal");
    insertAtTail(head, 44172, "Shehryar Ahmed");
    insertAtTail(head, 45804, "Ghazen Ahmed");
    insertAtTail(head, 45923, "Haider Ali");
    insertAtTail(head, 46202, "Muhammad Waleed");
    insertAtTail(head, 46292, "Rehan Ahmed");
    insertAtTail(head, 46334, "Sauod Azad");
    insertAtTail(head, 46411, "Ali Hammad Afzal");
    insertAtTail(head, 46451, "Mian Muhammad Hashir");
    insertAtTail(head, 46465, "Ehsan Ullah");
    insertAtTail(head, 46488, "Nouman Ashfaq");
    insertAtTail(head, 46980, "Ali Naseer");
    insertAtTail(head, 47231, "Muhammad Abdullah");
    insertAtTail(head, 47419, "Usman Pervez");
    insertAtTail(head, 47527, "Mussab bin Aziz");
    insertAtTail(head, 47729, "Abdullah Ajmal");

    head = insertionSort(head);

    cout << "\nSorting in Descending order using Bubble Sort:\n\n";
    display(head);

    return 0;
}
