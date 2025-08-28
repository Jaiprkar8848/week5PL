// Problem 5

#include<bits/stdc++.h>
using namespace std;

// shared data
vector<int> vj={10,42,12,67,53};
int currIdx=0;
// shared variable to protect currIdx and SLL
pthread_mutex_t idM;
pthread_mutex_t listM;
// Node structure
struct Node{
    int data;
    Node* next;
};
// initially LL is empty
Node* head=NULL;
Node* curr=NULL;

void insertIntoLL(int val){
    Node* nn=new Node{val,NULL};
    // entry section
    pthread_mutex_lock(&listM);
    // critical section
    if(head==NULL)
        head=nn;
    else
        curr->next=nn;
    curr=nn;
    pthread_mutex_unlock(&listM);
}

void* f(void* a){
    while(true){
        int i;

        // lock index mutex
        pthread_mutex_lock(&idM);
        if(currIdx>=vj.size()){
            pthread_mutex_unlock(&idM);
            break;
        }

        i=currIdx;
        currIdx++;
        pthread_mutex_unlock(&idM);

        int val=vj[i];
        insertIntoLL(val);

        cout<<vj[i]<<" inserted into Linked List"<<endl;
    }
    return NULL;
}

int main(){
    int n=4;
    pthread_t jp[n];

    //  mutex initialize krdo
    pthread_mutex_init(&idM,NULL);

    // create thread and join
    for(int i=0;i<n;i++){
        pthread_create(&jp[i],NULL,f,NULL);
        pthread_join(jp[i],NULL);
    }

    Node* start=head;
    while(start){
        cout<<start->data<<"->";
        start=start->next;
    }
    cout<<"NULL";

    // destroy the mutex
    pthread_mutex_destroy(&idM);
    pthread_mutex_destroy(&listM);
    return 0;
}