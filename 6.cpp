// problem 6

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
        Node* next;
        };

        struct requirements{
            Node* head;
                vector<int>* pv;
                    int* result;
                    };

                    void* checkSeq(void* arg){
                        // pointer to a structure
                            requirements* args=(requirements*) arg;
                                Node* start=args->head;
                                    vector<int> &rv=*(args->pv);  // rv is reference to vector v
                                        int n=rv.size();
                                            int i=0;
                                                while(start && i<n){
                                                        if(start->val!=rv[i]){
                                                                    *(args->result)=0;
                                                                                return NULL;
                                                                                        }
                                                                                                start=start->next;
                                                                                                        i++;
                                                                                                            }
                                                                                                                *(args->result)=(start==NULL && i==n);
                                                                                                                    return NULL;
                                                                                                                    }

                                                                                                                    int main(){
                                                                                                                        // creating vector
                                                                                                                            vector<int> vj={1,2,3,4,5};
                                                                                                                                // creating LL
                                                                                                                                    Node* head=NULL;
                                                                                                                                        Node* a=new Node{1,NULL};
                                                                                                                                            Node* b=new Node{2,NULL};
                                                                                                                                                Node* c=new Node{3,NULL};
                                                                                                                                                    Node* d=new Node{4,NULL};
                                                                                                                                                        Node* e=new Node{5,NULL};
                                                                                                                                                            head=a;
                                                                                                                                                                a->next=b;
                                                                                                                                                                    b->next=c;
                                                                                                                                                                        c->next=d;
                                                                                                                                                                            d->next=e;

                                                                                                                                                                                // thread for verify
                                                                                                                                                                                    pthread_t t;
                                                                                                                                                                                        int ans=0;
                                                                                                                                                                                            // passing actual arguments to structure variable
                                                                                                                                                                                                requirements r={head,&vj,&ans};

                                                                                                                                                                                                    pthread_create(&t,NULL,checkSeq,&r);
                                                                                                                                                                                                        pthread_join(t,NULL);

                                                                                                                                                                                                            if(ans==1)
                                                                                                                                                                                                                    cout<<"Both LL and vector are sequentially same";
                                                                                                                                                                                                                        else
                                                                                                                                                                                                                                cout<<"Both LL and vector are not sequentially same";
                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                        return 0;
                                                                                                                                                                                                                                        }