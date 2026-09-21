#include <iostream>
#include "vector.cpp"
#include "queue.cpp"

template <typename T>
class GeneralTreeNode {
    public:
        GeneralTreeNode(T value) : data(value) {}
        
        ~GeneralTreeNode() {
            for (auto child : children) {
                delete child;
            }
        }

        T getData() const {
            return data;
        }

        Vector<GeneralTreeNode*> getChildren() const {
            return children;
        }

        void setData(T value) {
            data = value;
        }

        void addChild(GeneralTreeNode* child) {
            children.add_value(child);
        }

        void removeChild(GeneralTreeNode* child) {
            for (int i = 0; i < children.get_size(); ++i) {
                if (children[i] == child) {
                    children.remove_at(i);
                    return;
                }
            }
        }

        void preOrderTraversal() {
            std::cout << data << " ";
            for (int i = 0; i < children.get_size(); ++i) {
                children[i]->preOrderTraversal();
            }
        }

        void postOrderTraversal() {
            for (int i = 0; i < children.get_size(); ++i) {
                children[i]->postOrderTraversal();
            }
            std::cout << data << " ";
        }

        void inOrderTraversal() {
            if (children.get_size() > 0) {
                children[0]->inOrderTraversal();
            }
            std::cout << data << " ";
            for (int i = 1; i < children.get_size(); ++i) {
                children[i]->inOrderTraversal();
            }
        }

        void levelOrderTraversal() {
            Queue<GeneralTreeNode*> queue;
            queue.enqueue(this);
            while (!queue.empty()) {
                GeneralTreeNode* current = queue.dequeue();
                std::cout << current->data << " ";
                for (int i = 0; i < current->children.get_size(); ++i) {
                    queue.enqueue(current->children[i]);
                }
                queue.remove_at(0);
            }
        }
    private:
        T data;
        Vector<GeneralTreeNode*> children;
};