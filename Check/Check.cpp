#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>

using namespace std;
/*
class node {
public:
	int data;
	node* next;
	node(int d) {
		this->data = d;
		this->next = nullptr;
	}
};

class doublyNode {
public:
	int data;
	doublyNode* next;
	doublyNode* prev;
	doublyNode(int d) {
		this->data = d;
		this->next = nullptr;
		this->prev= nullptr;
	}
};

doublyNode* insertNodeInDoublyList(doublyNode* head, int data) {
	if (head == NULL) {
		head = new doublyNode(data);
		return head;
	}
	head->next = insertNodeInDoublyList(head->next, data);
	head->next->prev = head;
	return head;
}

node* insertNodeAtTail(node* head, int data) {
	if (head == NULL) {
		head = new node(data);
		return head;
	}
	head->next = insertNodeAtTail(head->next, data);
	return head;
}

void printList(node* head) {
	while (head != nullptr) {
		cout << head->data << "  ";
		head = head->next;
	}
}


void printList1(doublyNode* head) {
	while (head != nullptr) {
		cout << head->data << "  ";
		head = head->next;
	}
}

int result = 0;

int getNode(node* head, int position) {
	if (head == NULL)
		return 0;
	int count = getNode(head->next, position);
	if (count == position) {
		result = head->data;
		return count + 1;
	}
	else
		return count + 1;
}

node* deleteDuplicate(node* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	if (head->data == head->next->data) {
		return deleteDuplicate(head->next);
	}
	head->next = deleteDuplicate(head->next);
	return head;
}

vector<node*> v;

bool cycleNode(node* head) {
	if (head == nullptr)
		return 0;
	for (int i = 0; head != nullptr; i++) {
		v.push_back(head);
		for (int j = i - 1; j >= 0; j--) {
			if (head == v[j])
				return 1;
		}
		head = head->next;
	}
	return 0;
}

doublyNode* sortedInsert(doublyNode* head, int data) {
	if (head == nullptr)
		return new doublyNode(data);
	if (head->data > data) {
		doublyNode* temp = new doublyNode(data);
		if(head->prev != nullptr)
			head->prev->next = temp;
		temp->next = head;
		temp->prev = head->prev;
		head->prev = temp;
		return temp;
	}
	head->next = sortedInsert(head->next, data);
	return head;
}

doublyNode* reverse(doublyNode* head) {
	doublyNode* temp = nullptr;
	doublyNode* current = head;
	while (head != nullptr) {
		temp = head->prev;
		head->prev = head->next;
		head->next = temp;
		head = head->prev;
	}
	if(temp!=nullptr)
		current = temp->prev;
	return current;
}

class tree_type {
public:
	int data;
	tree_type* left;
	tree_type* right;
	tree_type(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

int height_of_tree(tree_type* root) {
	//int max = 0;
	if (root == nullptr)
		return -1;
	int count_left = height_of_tree(root->left);
	int count_right = height_of_tree(root->right);
	if (count_left > count_right)
		return count_left + 1;
	else
		return count_right + 1;;
}

//void topView(tree_type* root) {
//	if (root == nullptr)
//		return;
//	topView(root->left);
//}

void levelView(tree_type* root) {
	if (root == nullptr)
		return;
	else {
		queue<tree_type*> q;
		//vector<tree_type> v;
		q.push(root);
		while (!q.empty())
		{
			tree_type* temp = q.front();
			cout << temp->data << " ";
			if (temp->left != nullptr)
				q.push(temp->left);
			if (temp->right != nullptr)
				q.push(temp->right);
			q.pop();
		}	
	}
}


int* check(int arr[], int a, int b)
{
	arr[0] = a;
	arr[1] = b;
	return arr;
}
*/

int* increment(int* a) {
	a = a + 1;
	return a;

}
int main()
{

	/*vector<int> v{ 12345,23564,23564,47128 };

	for (int i = 0; i < v.size() - 2; i++) {
		int sum = 0;
		if (v[i] == v[i + 2]) {
			sum = v[i] + v[i + 1] + v[i + 2];
			v[i] = sum;
			v[i+1] = sum;
			v[i+2] = sum;
			i++;
		}
		else if (v[i] == v[i + 1]) {
			sum = v[i] + v[i + 1];
			v[i] = sum;
			v[i + 1] = sum;
		}
	}
	if (v.size() > 1 && (v[v.size() - 2] == v[v.size() - 1])) {
		v[v.size()-1]= v[v.size() - 1] + v[v.size() - 2];
	}

	int m = INT_MIN;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > m)
			m = v[i];
	}
	cout << m << endl;*/

	int i = 0;
	int* p = &i;
	cout << p << endl;
	increment(p);
	cout << p << endl;
	return 0;
}