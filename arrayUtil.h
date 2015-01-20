
typedef struct arrays{
	void *base;
	int length;
	int typeSize;
}ArrayUtil;

// typedef struct arrays ArrayUtil;

int areEqual(ArrayUtil ,ArrayUtil);
ArrayUtil create(int,int);
ArrayUtil resize(ArrayUtil,int);
int findIndex(ArrayUtil,void*);

