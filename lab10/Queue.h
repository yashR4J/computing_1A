typedef struct queue *Queue;
// typedef struct node *Link;

// Create a queue
// Queue queueCreate(void);
Queue queueCreate(int maxSize);
// Add item to a queue
void enqueue(Queue q, int item);
// Return next item from queue but don't remove it
int queueFront(Queue q);
// Remove next item from queue and return it
int dequeue(Queue q);
// Return number of elements in queue
int queueSize(Queue q);
// Free a queue
void queueDestroy(Queue q);
// void free_list(Link head);
