#include "priority_queue.h"
#include<stdlib.h>
static bool pq_expand(priority_queue *this) {
    this->body = realloc(this->body, this->capacity * 2 * sizeof(int));

    if (this->body == NULL)
        return false;
    
    this->capacity = this->capacity * 2;

    return true;
}
priority_queue *pq_alloc(int capacity){
    priority_queue *this=malloc(sizeof(priority_queue));
    this->body=malloc(sizeof(int)*capacity);
    this->capacity=capacity;
    this->length=0;
    return this;
}
void pq_free(priority_queue *this){
    free(this);
}
int *pq_top(priority_queue *this){
    return &this->body[1];
}
bool pq_enqueue(priority_queue *this, int elem){
    if(this->capacity==this->length+1)
        pq_expand(this);
    int now=++this->length;
    this->body[now]=elem;
    int tmp;
    while(now!=1){
        if(this->body[now]>this->body[now/2]){
            tmp=this->body[now/2];
            this->body[now/2]=this->body[now];
            this->body[now]=tmp;
            now/=2;
        }
        else
            break;
    }
}
bool pq_dequeue(priority_queue *this){
    int now=1;
	int tmp;
	this->body[1]=this->body[this->length--];
	while(now <this->length){
		if(this->body[now]<this->body[now*2]){
			tmp=this->body[now*2];
			this->body[now*2]=this->body[now];
			this->body[now]=tmp;
			now*=2;
		}
		else if(this->body[now]<this->body[now*2+1]){
			tmp=this->body[now*2+1];
			this->body[now*2+1]=this->body[now];
			this->body[now]=tmp;
			now=now*2+1;
		}
		else
			break;
		
	}
}
bool pq_is_empty(priority_queue *this){
    return (this->length==0);
}
