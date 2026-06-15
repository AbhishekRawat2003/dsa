#include <iostream>
using namespace std;
#include <vector>

class Node {
public:
  int data;
  Node *next;

  Node(int val) {
    data = val;
    next = nullptr;
  }
};

class LinkedList {
public:
  Node *head;

  LinkedList() { head = nullptr; }

  void append(int data) {
    Node *newNode = new Node(data);

    if (head == nullptr) {

      head = newNode;
      return;
    }
    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }

  void deleteMiddleNode() {

    if (head == nullptr || head->next == nullptr) {
      head = nullptr;
      return;
    }
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next; 
      prev = slow;
      slow = slow->next; 
    }

    // slow ab middle par hai
    prev->next = slow->next;
    delete slow;
  }

  void display() {
    Node *current = head;

    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};

int main() {

  vector<int> nums = {1, 3, 4, 7, 1, 2, 6};
  LinkedList ll;
  // add element to ll.
  for (auto num : nums) {
    ll.append(num);
  }

  ll.display();

  ll.deleteMiddleNode();
  ll.display();
  return 0;
}