#include <iostream>
#include <memory>

class Node {
public:
    Node(int val) : value(val) {}
    void setNext(std::shared_ptr<Node> nextNode) {
        next = nextNode;
    }
    int getValue() {
        return value;
    }

private:
    int value;
    std::weak_ptr<Node> next;
};

int main() {
    auto node1 = std::make_shared<Node>(1);
    auto node2 = std::make_shared<Node>(2);

    node1->setNext(node2);
    node2->setNext(node1); // Creates a circular reference

    // Access the value and break the circular reference
    std::cout << "Node 1 value: " << node1->getValue() << std::endl;
    std::cout << "Node 2 value: " << node2->getValue() << std::endl;

    return 0;
}
