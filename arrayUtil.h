typedef struct arrays{
	void *base;
	int length;
	int typeSize;
}ArrayUtil;

typedef int (MatchFunc)(void * hint,void* item);

int areEqual(ArrayUtil ,ArrayUtil);
ArrayUtil create(int,int);
ArrayUtil resize(ArrayUtil,int);
int findIndex(ArrayUtil,void*);
void dispose(ArrayUtil util);
// void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
