/*
 * myarray.h
 *
 *  Created on: Apr 2, 2020
 *      Author: alto
 */

#ifndef MYARRAY_H_
#define MYARRAY_H_

#include <iostream>
#include <string>

namespace Array
{
    class IntNode
	{
		public:
			int data;
			IntNode* next;
		/**
		 * @param n
		 * int
		 * @param next
		 * the next node.
		 */
		public:
			IntNode(int n, IntNode* next=nullptr);
			virtual ~IntNode();
	};

    /**
     * This is a linked list that stores array.
     */
    class MyIntLinkedList
    {
        IntNode* dummynode;
        IntNode* tail;
        int len = 1; // dummy node should be established at the
        //beginning.
        public:
            /**
             * The default constructor.
             */
            MyIntLinkedList();

            /**
             * Append an element to the tail of the linked list.
             */
            void Append(int n);
            /**
             * Returns the length of the array.
             */
            int Size() const;
            void operator += (int n);
            /**
             * Concate the linkedlist, data will be copied.
             * right hand side of the array will not be modified.
             */
            void operator += (const MyIntLinkedList& mll);
            /**
             * Pop out the first element in the linked list.
             * @returns
             * The integer inside the first node.
             * @throws 4321: Poping from empty array.
             */
            int Pop();
            /**
             * returns a string representing the array.
             * @returns A string.
             */
            std::string ToString() const; // Const member function!

            friend std::ostream& operator << (std::ostream& os, const MyIntLinkedList& mll);

        protected:
            /**
             * get the reference to the nth node in the linked list,
             * ignoring the dummy node at the head, if n>=len
             * then it will return the reference to the last node(the tail)
             * of the linked list.
             * @returns:
             * Pointer to the node.
             *
             */
            IntNode* PopOutNode(int n);
    };

    std::ostream& operator << (std::ostream& os, const MyIntLinkedList& mll);

}



#endif /* MYARRAY_H_ */
