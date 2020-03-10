#include"ALL.h"

extern Queue *front;
extern Queue *rear;

Queue* Add_new_queue()
{
	Queue *temp = (Queue*)malloc(sizeof(Queue));
	temp->Patient.number = 0;
	temp->Patient.priority = '\0';
	temp->Link = NULL;

	return temp;
}

void enQueue(Patient ptemp)//rear로 추가된다.
{
	Queue *temp = Add_new_queue();
	temp->Patient.number = ptemp.number;
	temp->Patient.priority = ptemp.priority;

	if (front->Link == NULL)
	{
		front->Link = temp;
		rear->Link = temp;
	}
	else
	{
		rear->Link->Link = temp;
		rear->Link = temp;
	}

}

Patient deQueue()//front부터 나간다.
//아무것도 없을때 하나일때 여러개일때.
{
	Queue *deQueue_mem;
	Patient deQueue_nData;
	Patient result;

	if (front->Link == NULL)
	{
		puts("FAIL");
		result.number = 0;
		result.priority = '\0';
	}
		
	else
	{
		deQueue_mem = front->Link;
		deQueue_nData = front->Link->Patient;
		result = deQueue_nData;

		if (front->Link != rear->Link)
		{
			front->Link = deQueue_mem->Link;
			free(deQueue_mem);
		}

		else
		{
			front->Link = deQueue_mem->Link;
			rear->Link = deQueue_mem->Link;
			free(deQueue_mem);
		}
		
	}
	
	return result;
}

int IsEmpty()
{
	return front->Link == NULL;
}

int Count_Queue()
{
	int result;
	int cnt = 0;
	Queue *Count = front->Link;

	if (Count == NULL)
		result = cnt;
	else
	{
		while (Count->Link != NULL)
		{
			cnt++;
			Count = Count->Link;
		}
		cnt++;
		result = cnt;
	}
	
	return result;
}

char Rand_Priority()
{
	char result;
	if ((rand() % 2) == 0)
		result = 'N';
	
	else
		result = 'E';
	
	return result;
}

Patient Rotation(Patient In_Patient)
{
	Patient temp;

	if (In_Patient.priority == 'E')
	{
		enQueue(In_Patient);
		temp = deQueue();

	}

	Rotation(temp);
}

Patient Queue_System(Patient In_Patient)
{
	Patient temp;

	if (In_Patient.priority == 'E')
	{
		enQueue(In_Patient);
		while (front->Link->Patient.priority != 'E')
		{
			temp = deQueue();
			enQueue(temp);
		}
		temp = deQueue();
	}

	else//N인 환자가 들어왔을때
	{
		if (Count_Queue() == 3)
		{
			temp = deQueue();
			enQueue(In_Patient);
		}
		else
		{
			enQueue(In_Patient);
			temp.number = 0;
			temp.priority = '\0';
		}
	}

	return temp;
}

void Emergency_Room(Node *List_N, Node *List_E)
{
	int P_num = 1;
	
	Patient temp;
	Patient cured;

	/*규칙
	*큐에 3개가 쌓이면 먼저 들어온 순으로 나간다
	*우선 순위가'E'인 환자가 들어오면 로테이션을 통해 가장 먼저 처리 될 수 있게 한다.
	*/
	for (P_num = 1; P_num < 16; P_num++)
	{
		temp.number = P_num;
		temp.priority = Rand_Priority();
		cured = Queue_System(temp);

		if (cured.priority == 'N')
			Add_node(List_N, cured);
		else if (cured.priority == 'E')
			Add_node(List_E, cured);
		else
			printf("현재 대기자 수:%d\n", Count_Queue());
	}

	while (Count_Queue() > 0)
	{
		cured = deQueue();
		if (cured.priority == 'N')
			Add_node(List_N, cured);
		else 
			Add_node(List_E, cured);
	}
}
/*SINGULAR_LIST*/
Node * Alloc_new_node()
{
	Node *temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->Patient.number = 0;
	temp->Patient.priority = '\0';
	temp->pNext = NULL;

	return temp;
}

void Add_node(Node* head_node, Patient cured)
{
	Node *pointing_node = head_node;//이름표 같은 친구
	Node *temp = Alloc_new_node();//새로 추가할 노드
	temp->Patient.number = cured.number;
	temp->Patient.priority = cured.priority;

	while (pointing_node->pNext != NULL)//pointing_node의 pNext가  NULL이 나올때 까지 반복
	{
		pointing_node = pointing_node->pNext;
	}

	pointing_node->pNext = temp;

}

void Print_node(Node *head_node)
{
	Node *pointing_node = head_node;

	while (pointing_node->pNext != NULL)
	{
		pointing_node = pointing_node->pNext;
		printf("%d, %c\n", pointing_node->Patient.number, pointing_node->Patient.priority);
	}
	printf("\n");
}