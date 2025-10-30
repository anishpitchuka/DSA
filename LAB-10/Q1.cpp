#include <iostream>
using namespace std;
struct Node {
	int key;
	Node* left;
	Node* right;
	Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

void insertNode(Node*& root, int key) {
	if (root == nullptr) {
		root = new Node(key);
		return;
	}
	if (key == root->key) {
		return;
	}
	if (key < root->key) {
		insertNode(root->left, key);
	} else {
		insertNode(root->right, key);
	}
}

bool searchNode(Node* root, int key) {
	Node* current = root;
	while (current != nullptr) {
		if (key == current->key) return true;
		if (key < current->key) current = current->left;
		else current = current->right;
	}
	return false;
}

void inorder(Node* root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

void preorder(Node* root) {
	if (root == nullptr) return;
	cout << root->key << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->key << " ";
}



int main() {
	Node* root = nullptr;

	while (true) {
		cout << "\nBinary Search Tree - Menu\n";
		cout << "1. Insert\n";
		cout << "2. Search\n";
		cout << "3. Inorder Traversal\n";
		cout << "4. Preorder Traversal\n";
		cout << "5. Postorder Traversal\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";

		int choice;
		if (!(cin >> choice)) {
			cout << "Invalid input. Exiting.\n";
			break;
		}

		if (choice == 1) {
			cout << "Enter value to insert: ";
			int val;
			if (!(cin >> val)) {
				cout << "Invalid input for value.\n";
		
				continue;
			}
			bool existed = searchNode(root, val);
			insertNode(root, val);
			if (existed) {
				cout << "Value already exists. Duplicate ignored.\n";
			} else {
				cout << "Inserted.\n";
			}
		} else if (choice == 2) {
			cout << "Enter value to search: ";
			int val;
			if (!(cin >> val)) {
				cout << "Invalid input for value.\n";
			
				continue;
			}
			if (searchNode(root, val)) cout << "Found "<<val<<endl;
			else cout << "Not found.\n";
		} else if (choice == 3) {
			cout << "Inorder: ";
			inorder(root);
			cout << "\n";
		} else if (choice == 4) {
			cout << "Preorder: ";
			preorder(root);
			cout << "\n";
		} else if (choice == 5) {
			cout << "Postorder: ";
			postorder(root);
			cout << "\n";
		} else if (choice == 6) {
			break;
		} else {
			cout << "Invalid choice. Try again.\n";
		}
	}


}