#pragma once
#include"ALL.h"

#ifndef __FUNC_H__
#define __FUNC_H__

/*BASIC_QUEUE*/
Queue* Add_new_queue();
void enQueue(Patient ptemp);
Patient deQueue();
int IsEmpty();
int Count_Queue();

/*ER_QUEUE_SYSTEM*/
char Rand_Priority();
Patient Queue_System(Patient In_Patient);
void Emergency_Room(Node *List_N, Node *List_E);

/*SINGULAR_LIST*/
Node * Alloc_new_node();
void Add_node(Node* head_node, Patient cured);
void Print_node(Node *head_node);
#endif

