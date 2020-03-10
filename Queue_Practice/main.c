#include"ALL.h"

Queue *front;
Queue *rear;

int main()
{
	srand((unsigned int)time(NULL));
	Node *List_N = Alloc_new_node();
	Node *List_E = Alloc_new_node();

	front = Add_new_queue();
	rear = Add_new_queue();
	printf("%d",Count_Queue());
	Emergency_Room(List_N, List_E);

	puts("보통환자 명단");
	Print_node(List_N);
	puts("");
	puts("응급환자 명단");
	Print_node(List_E);

}