#include <xinu.h>

/**
 * Enter a critical section guarded by lock
 * @param lock	pointer to a mutex lock
 */
void mutex_lock(mutex_t *lock)
{
	//TODO - write a busy-wait loop using test_and_set
}


/**
 * Leave a critical section guarded by lock
 * @param lock	pointer to a mutex lock
 */
void mutex_unlock(mutex_t *lock)
{
	//TODO - unlock!
}
