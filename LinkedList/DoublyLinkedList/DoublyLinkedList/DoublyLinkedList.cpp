#include<iostream>
using namespace std;

class Node {
public:
	int key;
	int data;
	Node* prev;
	Node* next;

	Node()
	{
		key = 0;
		data = 0;
		prev = NULL;
		next = NULL;
	}

	Node(int k, int d)
	{
		key = k;
		data = d;
	}
};

class DoublyLinkedList {
public:
	Node* head;

	DoublyLinkedList()
	{
		head = NULL;
	}

	DoublyLinkedList(Node* h)
	{
		head = h;
	}

	/// <summary>
	/// Function to check particular node exists or not
	/// </summary>

	Node* nodeExits(int k)
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
		if (nodeExits(n->key) != NULL)
		{
			cout << "Node already exists with key value: " << n->key << ". Append another node with different key value." << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node appended as head node." << endl;
			}
			else
			{
				Node* ptr = head;
				
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}

				ptr->next = n;
				n->prev = ptr;

				cout << "Node appended." << endl;
			}
		}
	}

	/// <summary>
	/// Prepends the node
	/// </summary>
	/// <param name="n"></param>

	void prependNode(Node* n)
	{
		if (nodeExits(n->key) != NULL)
		{
			cout << "Node already exists with key value: " << n->key << ". Append another node with different key value." << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node prepended as head node." << endl;
			}
			else {
				head->prev = n;
				n->next = head;
				head = n;

				cout << "Node prepended." << endl;
			}
		}
	}

	/// <summary>
	/// Insert node after particular node if key matches
	/// </summary>
	/// <param name="k"></param>
	/// <param name="n"></param>

	void insertAfterNode(int k, Node* n)
	{
		Node* ptr = nodeExits(k);

		if (ptr == NULL)
		{
			cout << "No node exists with key value." << endl;
		}
		else
		{
			if (nodeExits(n->key) != NULL)
			{
				cout << "Node already exists with key value: " << n->key << ". Append another node with different key value." << endl;
			}
			else
			{
				Node* nextNode = ptr->next;

				// inserting at the end
				if (nextNode == NULL)
				{
					ptr->next = n;
					n->prev = ptr;
					cout << "Node inserted at the end." << endl;
				}
				// inserting in between
				else
				{
					n->next = nextNode;
					nextNode->prev = n; //ptr->next->prev = n;
					n->prev = ptr;
					ptr->next = n;

					cout << "Node inserted." << endl;
				}
			}
		}
	}

	/// <summary>
	/// Deletes node by unique key
	/// </summary>
	/// <param name="k"></param>

	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExits(k);

		if (ptr == NULL)
		{
			cout << "No node exists with key value." << endl;
		}
		else
		{
			if (head == NULL)
			{
				cout << "Doubly linked list is already empty." << endl;
			}
			else
			{
				if (head->key == k)
				{
					head = head->next;
					cout << "Node UNLINKED with key value: " << k << endl;
				}
				else
				{
					Node* prevNode = ptr->prev;
					Node* nextNode = ptr->next;

					// Deleting at the end
					if (nextNode == NULL)
					{
						prevNode->next = NULL;
						cout << "Node deleted at the end." << endl;
					}
					// Deleting in between
					else
					{
						prevNode->next = nextNode;
						nextNode->prev = prevNode;
						cout << "Node deleted in between." << endl;
					}
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
		Node* ptr = nodeExits(k);

		if (ptr != NULL)
		{
			ptr->data = d;
			cout << "Node data updated successfully." << endl;
		}
		else
		{
			cout << "Node does't exist with key value." << endl;
		}
	}

	/// <summary>
	/// Display list
	/// </summary>

	void printList()
	{
		if (head == NULL)
		{
			cout << "Doubly linked list is empty." << endl;
		}
		else
		{
			cout << endl << "Doubly linked list values: ";

			Node* ptr = head;

			while (ptr != NULL)
			{
				cout << "(" << ptr->key << "," << ptr->data << ") <-->";
				ptr = ptr->next;
			}

			cout << endl;
		}
	}
};

int main()
{
	DoublyLinkedList d;
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

		Node* n1 = new Node();

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

			d.appendNode(n1);
			break;

		case 2:
			cout << "Prepend Node operation \nEnter key and data of the node to be prepended" << endl;
			cin >> key;
			cin >> data;

			n1->key = key;
			n1->data = data;
			d.prependNode(n1);

			break;

		case 3:
			cout << "Insert Node after operation \nEnter key of existing node after which you want to insert this new node: " << endl;
			cin >> k;

			cout << "Enter key and data of the new node: " << endl;
			cin >> key;
			cin >> data;

			n1->key = key;
			n1->data = data;
			d.insertAfterNode(k, n1);

			break;

		case 4:
			cout << "Delete node by key operation \nEnter key of the node to be deleted: " << endl;
			cin >> k;

			d.deleteNodeByKey(k);

			break;

		case 5:
			cout << "Update node by key operation" << endl;
			cout << "Enter key: " << endl;
			cin >> key;
			cout << "Enter data: " << endl;
			cin >> data;

			d.updateNodeByKey(key, data);

			break;

		case 6:
			d.printList();
			break;

		case 7:
			system("cls");
			break;

		default:
			cout << "Please enter valid option number." << endl;
			break;
		}
		
	} while (option!=0);
}