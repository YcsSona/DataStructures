#include<iostream>
using namespace std;

class Node {
public:
	int key;
	int data;
	Node* next;

	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
	}

	Node(int k, int d)
	{
		key = k;
		data = d;
	}
};

class SinglyLinkedList {
public:
	Node* head;

	SinglyLinkedList()
	{
		head = NULL;
	}

	SinglyLinkedList(Node* n)
	{
		head = n;
	}

	/// <summary>
	/// Function to check particular node exists or not
	/// </summary>

	Node* nodeExists(int k)
	{
		Node* temp = NULL;
		Node* ptr = head;

		while (ptr != NULL)
		{
			if (ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	/// <summary>
	/// Append a node to the list
	/// </summary>
	/// <param name="n"></param>

	void appendNode(Node* n)
	{
		//Before appending node check key of newly passed node
		if (nodeExists(n->key) != NULL) // this means there exist a node which has same key
		{
			cout << "Node already exists with the key value: " << n->key << ". Append anothe node with diffrent key value" << endl;
		}
		else
		{
			//if LL has no nodes in it
			if (head == NULL)
			{
				head = n;
				cout << "Node appended" << endl;
			}
			else
			{
				Node* ptr = head;

				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}

				ptr->next = n;
				cout << "Node appended" << endl;
			}
		}
	}

	/// <summary>
	/// Prepends the node
	/// </summary>
	/// <param name="n"></param>

	void prependNode(Node* n)
	{
		if (nodeExists(n->key) != NULL) // this means there exist a node which has same key
		{
			cout << "Node already exists with the key value: " << n->key << ". Append anothe node with diffrent key value" << endl;
		}
		else
		{
			n->next = head;
			head = n;
			cout << "Node prepended" << endl;
		}
	}

	/// <summary>
	/// Insert node after particular node if key matches
	/// </summary>
	/// <param name="k"></param>
	/// <param name="n"></param>

	void insertNodeAfter(int k, Node* n)
	{
		Node* ptr = nodeExists(k);

		if (ptr == NULL)
		{
			cout << "No node exists with key value: " << endl;
		}
		else
		{
			// Also checks whether newly passed node has same key or not
			if (nodeExists(n->key) != NULL)
			{
				cout << "Node already exists with the key value: " << n->key << ". Append anothe node with diffrent key value" << endl;
			}
			else {
				n->next = ptr->next;
				ptr->next = n;
				cout << "Node inserted" << endl;
			}
		}
	}

	/// <summary>
	/// Deletes node by unique key
	/// </summary>
	/// <param name="k"></param>

	void deleteNodeByKey(int k)
	{
		if (head == NULL)
		{
			cout << "No nodes exists. Singly list is already empty." << endl;
		}
		else if (head != NULL)
		{
			// Deletes head node
			if (head->key == k)
			{
				head = head->next;
				cout << "Node UNLINKED with key value." << endl;
			}
			else
			{
				Node* temp = NULL;
				Node* prevPtr = head;
				Node* currentPtr = head->next;

				while (currentPtr != NULL)
				{
					if (currentPtr->key == k)
					{
						temp = currentPtr;
						currentPtr = NULL;
					}
					else
					{
						// move both pointer by one
						prevPtr = prevPtr->next;
						currentPtr = currentPtr->next;
					}
				}

				if (temp != NULL)
				{
					prevPtr->next = temp->next;
					cout << "Node UNLINKED with key value." << endl;
				}
				else
				{
					cout << "Node does not exist with key value." << endl;
				}
			}
		}
	}

	/// <summary>
	/// Update the data in particular key
	/// </summary>
	/// <param name="k"></param>
	/// <param name="d"></param>

	void updateNodeByKey(int k, int d)
	{
		Node* ptr = nodeExists(k);

		if (ptr != NULL)
		{
			ptr->data = d;
			cout << "Node data updated successfully!" << endl;
		}
		else
		{
			cout << "Node does not exist with key value." << endl;
		}
	}

	/// <summary>
	/// Display list
	/// </summary>

	void printList()
	{
		if (head == NULL)
		{
			cout << "No node in the singly list" << endl;
		}
		else
		{
			cout << endl << "Singly linked list values: ";
			Node* ptr = head;

			while (ptr != NULL)
			{
				cout << "(" << ptr->key << "," << ptr->data << ") --> ";
				ptr = ptr->next;
			}
			cout << endl;
		}
	}
};

int main()
{
	SinglyLinkedList s;
	int option, key, k, data;

	do
	{
		cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
		cout << "1. AppendNode()" << endl;
		cout << "2. PrependNode()" << endl;
		cout << "3. InsertNodeAfter()" << endl;
		cout << "4. DeleteNodeByKey()" << endl;
		cout << "5. UpdateNodeByKey()" << endl;
		cout << "6. Print()" << endl;
		cout << "7. Clear Screen" << endl;

		cin >> option;

		Node* n1 = new Node(); // dynamic memory allocation (uses heap memory)
		//Node n1; //uses stack

		switch (option)
		{
		case 0:
			break;

		case 1:
			cout << "Append Node operation \nEnter key and data of the node to be appended" << endl;
			cin >> key;
			cin >> data;

			n1->key = key;
			n1->data = data;
			s.appendNode(n1);

			break;

		case 2:
			cout << "Prepend Node operation \nEnter key and data of the node to be prepended" << endl;
			cin >> key;
			cin >> data;

			n1->key = key;
			n1->data = data;
			s.prependNode(n1);

			break;

		case 3:
			cout << "Insert Node after operation \nEnter key of existing node after which you want to insert this new node" << endl;
			cin >> k;

			cout << "Enter key & data of the new node: " << endl;
			cin >> key;
			cin >> data;

			n1->key = key;
			n1->data = data;
			s.insertNodeAfter(k, n1);

			break;

		case 4:
			cout << "Delete node by key operation \nEnter key of the node to be deleted: " << endl;
			cin >> k;

			s.deleteNodeByKey(k);

			break;

		case 5:
			cout << "Update node by key operation" << endl;
			cout << "Enter key: " << endl;
			cin >> key;
			cout << "Enter data: " << endl;
			cin >> data;

			s.updateNodeByKey(key, data);

			break;

		case 6:
			s.printList();
			break;

		case 7:
			system("cls");
			break;

		default:
			cout << "Please enter valid option number." << endl;
			break;
		}
	} while (option != 0);
}