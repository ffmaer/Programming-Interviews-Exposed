//IntElement

typedef struct  IntElement
{
	struct IntElement *next;
	int data;
}IntElement;

// insert
bool insertInFront(IntElement **head, int data){
	if(!head || !*head) //check for null pointers
		return false;
	IntElement *newElem = malloc(sizeof(IntElement));
	if(!newElem) return false;
	newElem->data = data;
	newElem->next = *head;
	*head = newElem;
	return true;
}

// delete
bool deleteElement(IntElement **head, IntElement *deleteMe)
{
	if(!head || !*head || !deleteMe) //check for null pointers
		return false;

	IntElement *elem;
	elem = *head;

	if(deleteMe == *head){//special case for head
		*head = elem.next;
		free(deleteMe);
		return true;
	}

	while(elem){
		if(elem->next == deleteMe){
			elem->next = deleteMe->next;
			free(deleteMe);
			return true;
		}
		elem = elem->next;
	}
	return false;
}

//head
IntElement *head = malloc(sizeof(IntElement));

// push
bool push(int data){
	return insertInFront(**head, data);
}

// pop
int pop(){
	if(!head)
		return -1;
	int toReturn = head->data;
	IntElement *deleteMe = malloc(sizeof(IntElement));
	deleteElement(**head, deleteMe);
	return toReturn;
}


//delete
bool delete(IntElement **head, IntElement **tail, IntElement *elem){

	// check empty stack
	if(*head == NULL) return false;


	//delete the head and the tail
	if(*head == elem && *tail == elem){
		*head = NULL;
		*tail = NULL;
		free(elem);
		return true;
	}

	IntElement *pointer = *head;
	while(pointer){
		//delete the head
		if(*head == elem){
			*head = head->next;
			free(elem);
			return true;
		}
		//delete the tail
		else if(pointer->next == elem && pointer->next == *tail){
			pointer->next = NULL;
			*tail = pointer;
			free(elem);
			return true;
		}
		//delete the middle
		else if(pointer->next == elem){
			pointer->next = elem->next;
			free(elem);
			return true;
		}
		else{
			pointer=pointer->next;
		}
	}
	return false;
}

//insertAfter
bool insertAfter(IntElement **head, IntElement **tail, IntElement *elem, int data){

	IntElement *newElem = malloc(sizeof(IntElement));
	if(!newElem) return false;
	newElem->data = data;

	//insert into empty stack
	if(head == NULL && elem == NULL){
		*head = newElem;
		*tail = newElem;
		return true;
	}
	//insert before head
	if(elem == NULL){
		newElem->next = *head;
		*head = newElem;
		return true;
	}

	//other cases
	IntElement *pointer = *head;
	while(pointer){
		if(pointer == elem){
			//when the element is the last one in the original list
			if(pointer->next == NULL){
				*tail = newElem;
			}
			newElem->next = pointer->next;
			pointer->next = newElem;
			return true;
		}
		pointer = pointer->next;
	}
	return false;
}

bool lastMthElement(IntElement **head, int m, int *data){
	

	IntElement *curPos;
	curPos = *head;
	IntElement *lagPointer = NULL;//lag start to appear when curPos has moved to index m
	lagPointer = *head;

	int index = 0;

	while(curPos){// as long as it points to some elements
		//the last element has no next
		if(curPos->next == NULL){
			if(index < m){//M is too large
				return false
			}else{
				*data = lagPointer->data;
				return true;
			}
		}else{
			curPos = curPos->next;
			index ++;
			if(index > m){
				lagPointer= lagPointer->next;
			}
		}
	}
	return false;

}