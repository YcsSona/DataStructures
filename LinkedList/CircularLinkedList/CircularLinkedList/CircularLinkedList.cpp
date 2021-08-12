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

class CircularLinkedList {
public:
	Node* head;

	CircularLinkedList()
	{
		head = NULL;
	}

	CircularLinkedList(Node* h)
	{
		head = h;
	}

	/// <summary>
	/// Function to check particular node exists or not
	/// </summary>

	Node* nodeExists(int k)
	{
		Node* temp = NULL;
		Node* ptr = head;

		if (ptr == NULL)
		{
			return temp;
		}
		else
		{
			do
			{
				if (ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;

			} while (ptr != head); // circular 

			return temp;
		}
	}

	/// <summary>
	/// Append a node to the list
	/// </summary>
	/// <param name="n"></param>

	void appendNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node already exists with key value: " << n->key << ". Append another node with different key values." << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				n->next = head; // pointing to itself
				cout << "Node appended as head node." << endl;
			}
			else
			{
				Node* ptr = head;

				while (ptr->next != head)
				{
					ptr = ptr->next;
				}

				ptr->next = n;
				n->next = head;
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
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node already exists with key value: " << n->key << ". Append another node with different key values." << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				n->next = head;
				cout << "Node prepended as head node." << endl;
			}
			else
			{
				Node* ptr = head;

				while (ptr->next != head)
				{
					ptr = ptr->next;
				}

				ptr->next = n;
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

	void insertNodeAfter(int k, Node* n)
	{
		Node* ptr = nodeExists(k);

		if (ptr == NULL)
		{
			cout << "No node exist with key value: " << k << endl;
		}
		else
		{
			if (nodeExists(n->key) != NULL)
			{
				cout << "Node already exists with key value: " << n->key << ". Append another node with different key value." << endl;
			}
			else
			{
				// Insertion at the end
				if (ptr->next == head)
				{
					n->next = head;
					ptr->next = n;
					cout << "Node inserted at the end." << endl;
				}
				else
				{
					// Insertion in between
					n->next = ptr->next;
					ptr->next = n;
					cout << "Node inserted in between." << endl;
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
		Node* ptr = nodeExists(k);

		if (ptr == NULL)
		{
			cout << "No node exist with key value of: " << k << endl;
		}
		else
		{
			// Delete head node
			if (ptr == head)
			{
				if (head->next = head)
				{
					head = NULL;
					cout << "Head node UNLINKED...List is empty." << endl;
				}
				else
				{
					Node* ptrr = head;

					while (ptrr->next != head)
					{
						ptrr = ptrr->next;
					}

					ptrr->next = head->next; // points to the next node of head
					head = head->next; // make the next node as head node
					cout << "Node UNLINKED with key value " << k << endl;
				}
			}
			// Delete node except head node
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
						prevPtr = prevPtr->next;
						currentPtr = currentPtr->next;
					}
				}

				if (temp != NULL)
				{
					prevPtr->next = temp->next;
					cout << "Node UNLINKED with key value: " << k << endl;
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
			cout << "Node data updated successfully." << endl;
		}
		else
		{
			cout << "Node does not exist with key value: " << k << endl;
		}
	}

	/// <summary>
	/// Display list
	/// </summary>

	void printList()
	{
		if (head == NULL)
		{
			cout << "No node in the circular list" << endl;
		}
		else
		{
			cout << endl << "Head address: " << head << endl;
			cout << "Circular linked list values: " << endl;

			Node* ptr = head;

			do
			{
				cout << "(" << ptr->key << " , " << ptr->data << " , " << ptr->next << ") -->";
				ptr = ptr->next;
			} while (ptr!=head);
		}
	}
};

int main()
{
	CircularLinkedList c;
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

			c.appendNode(n1);
			break;

		case 2:
			cout << "Prepend Node operation \nEnter key and data of the node to be prepended" << endl;
			cin >> key;
			cin >> data;

			n1->key = key;
			n1->data = data;
			c.prependNode(n1);

			break;

		case 3:
			cout << "Insert Node after operation \nEnter key of existing node after which you want to insert this new node: " << endl;
			cin >> k;

			cout << "Enter key and data of the new node: " << endl;
			cin >> key;
			cin >> data;

			n1->key = key;
			n1->data = data;
			c.insertNodeAfter(k, n1);

			break;

		case 4:
			cout << "Delete node by key operation \nEnter key of the node to be deleted: " << endl;
			cin >> k;

			c.deleteNodeByKey(k);

			break;

		case 5:
			cout << "Update node by key operation" << endl;
			cout << "Enter key: " << endl;
			cin >> key;
			cout << "Enter data: " << endl;
			cin >> data;

			c.updateNodeByKey(key, data);

			break;

		case 6:
			c.printList();
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