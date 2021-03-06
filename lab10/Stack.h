#define MAX_SIZE 100

typedef struct stack Stack;
typedef struct node Node;

Stack *stackCreate(void);
void stackPush(Stack *s, char item);
char stackTop(Stack *s);
char stackPop(Stack *s);
int stackSize(Stack *s);
void stackDestroy(Stack *s);
