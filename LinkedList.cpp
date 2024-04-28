#include "LinkedList.h"

#include <limits>

LinkedList::LinkedList() { head = nullptr; }

LinkedList::LinkedList(int* array, int len) {
  head = nullptr;
  if (len > 0) {
    for (int i = 0; i < len; ++i) {
      insertPosition(i + 1, array[i]);
    }
  }
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->getLink();
    delete current;
    current = next;
  }
}

void LinkedList::insertPosition(int pos, int newNum) {
  Node* newNode = new Node(newNum);
  if (pos <= 0) {
    pos = 1;
  }
  if (head == nullptr || pos == 1) {
    newNode->setLink(head);
    head = newNode;
  } else {
    Node* current = head;
    int count = 1;
    while (count < pos - 1 && current->getLink() != nullptr) {
      current = current->getLink();
      count++;
    }
    newNode->setLink(current->getLink());
    current->setLink(newNode);
  }
}

bool LinkedList::deletePosition(int pos) {
  if (pos <= 0) return false;
  if (head == nullptr) return false;
  Node* current = head;
  if (pos == 1) {
    head = head->getLink();
    delete current;
    return true;
  }
  int count = 1;
  while (count < pos - 1 && current->getLink() != nullptr) {
    current = current->getLink();
    count++;
  }
  if (current->getLink() == nullptr) return false;
  Node* temp = current->getLink();
  current->setLink(temp->getLink());
  delete temp;
  return true;
}

int LinkedList::get(int pos) {
  if (pos <= 0) return std::numeric_limits<int>::max();
  Node* current = head;
  int count = 1;
  while (current != nullptr) {
    if (count == pos) return current->getData();
    current = current->getLink();
    count++;
  }
  return std::numeric_limits<int>::max();
}

int LinkedList::search(int target) {
  Node* current = head;
  int count = 1;
  while (current != nullptr) {
    if (current->getData() == target) return count;
    current = current->getLink();
    count++;
  }
  return -1;
}

void LinkedList::printList() {
  std::cout << "[";
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->getData();
    current = current->getLink();
    if (current != nullptr) std::cout << " ";
  }
  std::cout << "]" << std::endl;
}