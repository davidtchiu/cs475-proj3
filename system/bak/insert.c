/* insert.c - insert */

#include <xinu.h>

/**
 * Insert a process into a queue in descending key order
 * @param pid	ID of process to insert
 * @param q	Pointer to the queue to use
 * @param key	key for the inserted process
 */

//placeholder for future project
status  insert(pid32 pid, struct Queue *q, int32 key)
{
        if (isfull(q) || isbadpid(pid)) {
                return SYSERR;
        }

	//first entry or if key is greater than last entry's key
	if (isempty(q)) {
		//kprintf("insert: first insert\n");
		enqueue(pid, q, key);
		return OK;
	}
	else if (key >= q->tail->key) {
		//kprintf("insert: subsequent insert, enqueue\n");
		enqueue(pid, q, key);
		return OK;
	}
	else
	{
		//kprintf("insert: subsequent insert, between\n");
		//create entry
		struct QEntry *newEntry = (struct QEntry*) getmem(sizeof(struct QEntry));
		newEntry->pid = pid;
		newEntry->key = key;
		newEntry->next = NULL;
		newEntry->prev = NULL;

		//find location
		struct QEntry *currEntry;	/* runs through items in a queue*/
		struct QEntry *prevEntry;	/* holds previous node index    */

		currEntry = q->head;
		while (currEntry != NULL && currEntry->key >= key)
			currEntry = currEntry->next;

		//goes in end of the queue
		if (currEntry == NULL)
		{
			//kprintf("insert: subsequent insert, at tail\n");
			enqueue(pid, q, key);
			return OK;
		}
		else
		{
			//kprintf("insert: subsequent insert, really in betwen\n");
			prevEntry = currEntry->prev;

			/* insert process between curr node and previous node */
			newEntry->prev = prevEntry;
			newEntry->next = currEntry;

			if (prevEntry != NULL)
				prevEntry->next = newEntry;
			if (currEntry != NULL)
				currEntry->prev = newEntry;

			/* update queue */
			q->size++;

	        	return OK;
		}
	}
}
