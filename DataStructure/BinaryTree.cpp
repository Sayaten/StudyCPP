#include <iostream>

template<typename T>
class Node
{
	private:
		T data;
		Node<T> *left;
		Node<T> *right;
	public:
		Node();
		Node(T data);
		~Node();
		Node<T>* getLeftSubTree();
		Node<T>* getRightSubTree();
		void makeLeftSubTree(Node<T>* &sub);
		void makeRightSubTree(Node<T>* &sub);
		void makeLeftChild(T data);
		void makeRightChild(T data);
		void removeSubTree(Node<T>* &node);
		void setData(T data);
		T getData();
};

template<typename T>
class BinaryTree
{
	private:
		Node<T> *root;
	public:
		BinaryTree();
		~BinaryTree();
		Node<T>* getRoot();
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = new Node<T>;
}
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	removeSubTree(root -> left);
	removeSubTree(root -> right);
	delete root;
}
template<typename T>
Node<T>* BinaryTree<T>::getRoot()
{
	return root;
}
template<typename T>
Node<T>::Node()
{
	data = 0;
	left = nullptr;
	right = nullptr;
}
template<typename T>
Node<T>::Node(T data)
{
	this -> data = data;
	left = nullptr;
	right = nullptr;
}
template<typename T>
Node<T>* Node<T>::getLeftSubTree()
{
	return left;
}
template<typename T>
Node<T>* Node<T>::getRightSubTree()
{
	return right;
}
template<typename T>
void Node<T>::makeLeftSubTree(Node<T>* &sub)
{
	if(left != nullptr)
	{
		removeSubTree(left);
		delete left;
	}
	left = sub;
}
template<typename T>
void Node<T>::makeRightSubTree(Node<T>* &sub)
{
	if(right != nullptr)
	{
		removeSubTree(right);
		delete right;
	}
	right = sub;
}
template<typename T>
void Node<T>::makeLeftChild(T data)
{
	if(left != nullptr)
	{
		removeSubTree(left);
		delete left;
	}
	left = new Node<T>;
	left -> data = data;
	left -> left = nullptr;
	left -> right = nullptr;
}
template<typename T>
void Node<T>::makeRightChild(T data)
{
	if(right != nullptr)
	{
		removeSubTree(right);
		delete right;
	}
	right = new Node<T>;
	right -> data = data;
	right -> left = nullptr;
	right -> right = nullptr;
}
template<typename T>
void Node<T>::removeSubTree(Node<T>* &node)
{

	if(node == nullptr)
	{
		return;
	}

	removeSubTree(node -> left);
	removeSubTree(node -> right);
	node -> left = nullptr;
	node -> right = nullptr;
}
template<typename T>
void Node<T>::setData(T data)
{
	this -> data = data;
}
template<typename T>
T Node<T>::getData()
{
	return data;
}

int main()
{
	BinaryTree<int> *tree = new BinaryTree<int>;
	tree -> getRoot() -> setData(10);
	std::cout << tree -> getRoot() -> getData() << std::endl;
	return 0;
}
