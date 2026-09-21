#include "2_tree.cpp"

template <typename T>
class AVLTreeNode : public BinaryTreeNode<T> {
    public:
        // Constructor: initializes the default AVL tree node
        AVLTreeNode(T value) : BinaryTreeNode<T>(value), height(1) {}
        
        // Returns the height of the node
        int getHeight() const {
            return height;
        }
        
        // Sets the height of the node
        void setHeight(int h) {
            height = h;
        }
        
        // Performs a left-left rotation on the node
        void Left_Left_Rotation() {
            AVLTreeNode* newRoot = this->getLeft();
            this->setLeft(newRoot->getRight());
            newRoot->setRight(this);
            this->setHeight(1 + std::max(getHeight(this->getLeft()), getHeight(this->getRight())));
            newRoot->setHeight(1 + std::max(getHeight(newRoot->getLeft()), getHeight(newRoot->getRight())));
        }
        
        // Performs a right-right rotation on the node
        void Right_Right_Rotation() {
            AVLTreeNode* newRoot = this->getRight();
            this->setRight(newRoot->getLeft());
            newRoot->setLeft(this);
            this->setHeight(1 + std::max(getHeight(this->getLeft()), getHeight(this->getRight())));
            newRoot->setHeight(1 + std::max(getHeight(newRoot->getLeft()), getHeight(newRoot->getRight())));
        }
        
        // Performs a left-right rotation on the node
        void Left_Right_Rotation() {
            AVLTreeNode* newRoot = this->getLeft()->getRight();
            this->getLeft()->setRight(newRoot->getLeft());
            newRoot->setLeft(this->getLeft());
            this->setLeft(newRoot);
            this->getLeft()->setHeight(1 + std::max(getHeight(this->get
            Left()->getLeft()), getHeight(this->getLeft()->getRight())));
            this->setHeight(1 + std::max(getHeight(this->getLeft()), getHeight(this->getRight())));
            newRoot->setHeight(1 + std::max(getHeight(newRoot->getLeft()), getHeight(newRoot->getRight())));
        }
        
        // Performs a right-left rotation on the node
        void Right_Left_Rotation() {
            AVLTreeNode* newRoot = this->getRight()->getLeft();
            this->getRight()->setLeft(newRoot->getRight());
            newRoot->setRight(this->getRight());
            this->setRight(newRoot);
            this->getRight()->setHeight(1 + std::max(getHeight(this->get
            Right()->getLeft()), getHeight(this->getRight()->getRight())));
            this->setHeight(1 + std::max(getHeight(this->getLeft()), getHeight(this->getRight())));
            newRoot->setHeight(1 + std::max(getHeight(newRoot->getLeft()), getHeight(newRoot->getRight())));
        }
    private:
        int height;
};