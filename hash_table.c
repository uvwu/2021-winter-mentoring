#include"hash_table.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
static unsigned int hash(char *key){
    unsigned int ret=0;
    for(int i=0;i<strlen(key);i++)
        ret+=key[i];
    return ret%1024;
}
hash_table *hash_table_alloc(void){
    hash_table *this=malloc(sizeof(hash_table));
    this->body=malloc(sizeof(element)*1024);
    this->capacity = 1024;
    for(int i=0;i<1024;i++){
        this->body[i].key=NULL;
        this->body[i].val=NULL;
    }
    return this;
}
void hash_table_free(hash_table *this){
    free(this->body);
    free(this);
}
bool hash_table_insert(hash_table *this, char *key, char *val){
    int ret=hash(key);
    while(ret<1024){
        if(this->body[ret].key==NULL){
            this->body[ret].key=strdup(key);
            this->body[ret].val=strdup(val);
            return true;
        }
        else
            ret++;
    }
    return false;
}
char *hash_table_get(hash_table *this, char *key){
    int ret=hash(key);
    if(this->body[ret].key!=NULL){
        while(strcmp(key, this->body[ret].key) != 0) { // key랑 this의 key랑 같지 않으면 while문 반복
        ret++;
    }}
    return this->body[ret].val;
}
bool hash_table_remove(hash_table *this, char *key){
    int ret=hash(key);
    while(strcmp(this->body[ret].key,key)!=0){
        ret++;
    }
    this->body[ret].key=NULL;
    this->body[ret].val=NULL;
    return true;
}

/*int main() {
    hash_table *table=hash_table_alloc();
    hash_table_insert(table,"정설봉","설봉");
    char* s= hash_table_get(table,"정설봉");
    printf("%s\n",s);
    return 0;
}*/