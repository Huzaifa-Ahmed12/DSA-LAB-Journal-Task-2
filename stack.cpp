//#include<stdlib.h>
//#include<iostream>
//#include "stack.h"
//using namespace std;
//
//Stack::Stack() {
//	top = -1;
//}
//int Stack::isEmpty()const {
//	return (top == -1);
//}
//int Stack::isFull()const {
//	return (top == MAX_ITEMS - 1);
//}
//void Stack::Push(ItemType newItem) {
//	if (isFull()) {
//		cout << "Stack Overflow " << endl;
//		exit(1);
//	}
//	top++;
//	items[top] = newItem;
//}
//void Stack::Pop(ItemType& item) {
//	if (isEmpty()) {
//		cout << "Stack Underflow " << endl;
//		exit(1);
//	}
//	item = items[top];
//	top--;
//}
//
//ItemType Stack::Peek()const {
//	if (isEmpty()) {
//		cout << "Stack Underflow";
//		exit(1);
//	}
//	return items[top];
//}


// Implementation using Dynamic Array and Class Template
//
//#include<iostream>
//#include"stack.h"
//#include<stdlib.h>
//
//using namespace std;
//
//template<class ItemType>
//Stack<ItemType>::Stack() {
//	maxStack = 500;
//	top = -1;
//	items = new ItemType[500];
//}
//template<class ItemType>
//Stack<ItemType>::Stack(int max) {
//	maxStack = max;
//	top = -1;
//	items = new ItemType[max];
//}
//template<class ItemType>
//Stack<ItemType>::~Stack() {
//	delete[] items;
//}
//template<class ItemType>
//bool Stack<ItemType>::isEmpty() {
//	return (top == -1);
//}
//template<class ItemType>
//bool Stack<ItemType>::isFull() {
//	return (top == maxStack - 1);
//}
//template<class ItemType>
//void Stack<ItemType>::Push(ItemType newItem) {
//	if (isFull()) {
//		cout << "Stack Overflow!!";
//		exit(1);
//	}
//	top++;
//	items[top] = newItem;
//
//}
//template<class ItemType>
//void Stack<ItemType>::Pop(ItemType& item) {
//	if (isEmpty()) {
//		cout << "Stack Underflow!!";
//		exit(1);
//	}
//	item = items[top];
//	top--;
//}

