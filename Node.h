#ifndef NODE_H
#define NODE_H

class Node {
 private:
  int data;
  Node* link;

 public:
  Node(int value);
  int getData();
  void setData(int value);
  Node* getLink();
  void setLink(Node* nextNode);
};

#endif