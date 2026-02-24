#include <bits/stdc++.h>
using namespace std;

class Node{

    public:

    Node(int _val){

        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next){

        val = _val;
        next = _next;
    }

    int val;
    Node* next;
};

Node* reverseLL(Node* head){

    if(head == nullptr || head->next == nullptr){

        return head;
    }

    Node* prev = head;
    Node* temp = head->next;  

    while(temp != nullptr){

        Node* nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }

    return prev;
}

int main(){

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    Node* revHead = reverseLL(node1);

    return 0;
}