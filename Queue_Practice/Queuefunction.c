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

void enQueue(Patient ptemp)//rear�� �߰��ȴ�.
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

Patient deQueue()//front���� ������.
//�ƹ��͵� ������ �ϳ��϶� �������϶�.
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

	else//N�� ȯ�ڰ� ��������
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

	/*��Ģ
	*ť�� 3���� ���̸� ���� ���� ������ ������
	*�켱 ������'E'�� ȯ�ڰ� ������ �����̼��� ���� ���� ���� ó�� �� �� �ְ� �Ѵ�.
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
			printf("���� ����� ��:%d\n", Count_Queue());
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
	Node *pointing_node = head_node;//�̸�ǥ ���� ģ��
	Node *temp = Alloc_new_node();//���� �߰��� ���
	temp->Patient.number = cured.number;
	temp->Patient.priority = cured.priority;

	while (pointing_node->pNext != NULL)//pointing_node�� pNext��  NULL�� ���ö� ���� �ݺ�
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