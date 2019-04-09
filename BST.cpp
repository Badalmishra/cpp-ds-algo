#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else {
		// Leaf Node.
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//has One child node
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// has 2 child node
		else {
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

void Inorder(Node *root) {
	if(root == NULL) {
            cout << endl;
            return;
    }

	Inorder(root->left);       //Visit left subtree
	cout << " "<<root->data;  //Print data
	Inorder(root->right);      // Visit right subtree
}

Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
                5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);
    Inorder(root);

	//Application runner
	int choice;
	int data;
	cout << "BST WITH INSERT INORDER AND DELETE (Find min also)"<<endl;
	while(choice){
        cout
            << "1 to delete"
            <<endl<<"2 to insert"
            <<endl<<"3 for inorder traversal"
            <<endl<<"any other key to exit"
            <<endl<<"0 for exit"
        <<endl;

        cin >>choice;
        switch(choice){
            case 0:
                cout << "Good Bye Human"<<endl;break;
            case 1 :
                cout << "Enter data to be deleted";cin >> data; Delete(root,data);
                break;
            case 2:
                cout << "Enter data to be inserted";cin >> data;Insert(root,data);
                break;
            case 3:
                cout << "Inorder"<<endl;Inorder(root);

            default:
                cout << "Choose between the options"<<endl;
        }


	}
}
