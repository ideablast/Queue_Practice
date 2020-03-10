#ifndef __Data_H__
#define __Data_H__

typedef struct _Patient {
	int number;
	char priority;

}Patient;

typedef struct _Queue {

	struct _Patient Patient;
	struct _Queue *Link;
	
}Queue;

typedef struct Node {
	struct _Patient Patient;
	struct Node *pNext;
}Node;


#endif

#define TRUE 1
#define FALSE 0
#define FAIL -1

#define ERR_1 100
#define ERR_2 200
#define ERR_3 300
