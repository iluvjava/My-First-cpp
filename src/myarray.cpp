/*
 * myarray.cpp
 *	This file is am implementation for the myarray.h header file.
 *  Created on: Apr 2, 2020
 *      Author: alto
 */


#include "myarray.h"
#include <iostream>
#include <string>
using namespace Array;
using namespace std;

IntNode::IntNode(int n, IntNode* next)
{
    this->data = n;
    this->next = next;
}

IntNode::~IntNode()
{

}

/////////////////////////////////////////////////////////////////////

MyIntLinkedList::MyIntLinkedList()
{
    IntNode* dummy = new IntNode(0, nullptr);
    this->dummynode = dummy;
    this->tail = dummy;
}

string MyIntLinkedList::ToString() const
{
    IntNode* node = this->dummynode->next;
    if(node == nullptr)return "[]";

    string res = "[";
    while (node->next != nullptr)
    {
        res += to_string(node->data) + ", ";
        node = node->next;
    }
    return res + to_string(node->data) +"]";
}

void MyIntLinkedList::Append(int n)
{
    IntNode* newnode = new IntNode(n);
    this->tail->next = newnode;
    this->tail = newnode;
    len++;
}

int MyIntLinkedList::Size() const
{
	return len - 1;
}

void MyIntLinkedList::operator += (int n)
{
	this->Append(n);
}

void MyIntLinkedList::operator += (const MyIntLinkedList& arr)
{

}

int MyIntLinkedList::Pop()
{
	if(len == 1)throw "4321";

    int res = this->dummynode->next->data;
    IntNode* todispose = this->dummynode->next;
    this->dummynode->next = this->dummynode->next->next;
    // update tail if the last element is popped out.
    if(this->dummynode->next == nullptr)
    {
    	this->tail = this->dummynode;
    }
    len--;
    delete todispose; // release memory
    return res;
}

ostream& Array::operator << (ostream& os, const MyIntLinkedList& mll)
{
	os << mll.ToString();
	return os;
}

IntNode* MyIntLinkedList::PopOutNode(int n)
{
	IntNode* node = this-> dummynode;
	while(node->next != nullptr && n-- >= 0)
	{
		node = node->next;
	}
	return node;
}

