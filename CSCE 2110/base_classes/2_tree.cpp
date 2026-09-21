#include <iostream>
#include "queue.cpp"

template <typename T>
class BinaryTreeNode {
    public:
        BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}

        ~BinaryTreeNode() {
            delete left;
            delete right;
        }
        
        T getData() const {
            return data;
        }
        
        BinaryTreeNode* getLeft() const {
            return left;
        }
        
        BinaryTreeNode* getRight() const {
            return right;
        }

        void setData(T value) {
            data = value;
        }

        /*
        // If we aren't following binary search tree properties, then use these.
        void setLeft(BinaryTreeNode* node) {
            left = node;
        }
        
        void setRight(BinaryTreeNode* node) {
            right = node;
        }

        void deleteNode(T value) {
            if (value < data) {
                if (left != nullptr) {
                    if (left->getData() == value) {
                        BinaryTreeNode* temp = left;
                        left = nullptr;
                        delete temp;
                    } else {
                        left->deleteNode(value);
                    }
                }
            }
            else {
                if (right != nullptr) {
                    if (right->getData() == value) {
                        BinaryTreeNode* temp = right;
                        right = nullptr;
                        delete temp;
                    } else {
                        right->deleteNode(value);
                    }
                }
            }
        }
        */

        void insert(T value) {
            if (value < data) {
                if (left == nullptr) {
                    left = new BinaryTreeNode(value);
                } else {
                    left->insert(value);
                }
            } else {
                if (right == nullptr) {
                    right = new BinaryTreeNode(value);
                } else {
                    right->insert(value);
                }
            }
        }

        void deleteNode(T value) {
            if (value < data) {
                if (left != nullptr) {
                    left->deleteNode(value);
                }
            }
            else if (value > data) {
                if (right != nullptr) {
                    right->deleteNode(value);
                }
            }
            else {
                if (left == nullptr && right == nullptr) {
                    delete this;
                }
                else if (left == nullptr) {
                    BinaryTreeNode* temp = right;
                    *this = *temp;
                    temp->left = nullptr;
                    temp->right = nullptr;
                    delete temp;
                }
                else if (right == nullptr) {
                    BinaryTreeNode* temp = left;
                    *this = *temp;
                    temp->left = nullptr;
                    temp->right = nullptr;
                    delete temp;
                }
                else {
                    BinaryTreeNode* successor = right;
                    while (successor->left != nullptr) {
                        successor = successor->left;
                    }
                    data = successor->data;
                    right->deleteNode(successor->data);
                }
            }
        }

        void inOrderTraversal() {
            if (left != nullptr) {
                left->inOrderTraversal();
            }
            std::cout << data << " ";
            if (right != nullptr) {
                right->inOrderTraversal();
            }
        }

        void preOrderTraversal() {
            std::cout << data << " ";
            if (left != nullptr) {
                left->preOrderTraversal();
            }
            if (right != nullptr) {
                right->preOrderTraversal();
            }
        }

        void postOrderTraversal() {
            if (left != nullptr) {
                left->postOrderTraversal();
            }
            if (right != nullptr) {
                right->postOrderTraversal();
            }
            std::cout << data << " ";
        }

        void levelOrderTraversal() {
            if (this == nullptr) {
                return;
            }
            Queue<BinaryTreeNode*> q;
            q.push(this);
            while (!q.empty()) {
                BinaryTreeNode* current = q.front();
                q.pop();
                std::cout << current->getData() << " ";
                if (current->getLeft() != nullptr) {
                    q.push(current->getLeft());
                }
                if (current->getRight() != nullptr) {
                    q.push(current->getRight());
                }
            }
        }
    private:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
};