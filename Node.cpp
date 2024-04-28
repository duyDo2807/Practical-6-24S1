#include "Node.h"

Node::Node(int value) {
  data = value;
  link = nullptr;
}

int Node::getData() { return data; }

void Node::setData(int value) { data = value; }

Node* Node::getLink() { return link; }

void Node::setLink(Node* nextNode) { link = nextNode; }