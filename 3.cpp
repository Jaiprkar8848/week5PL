// Problem 3

#include<bits/stdc++.h>
using namespace std;

// shared data-> vector and currIdx
vector<int> vj={3,6,21,75,34};
int currIdx=0;
pthread_mutex_t idM; // protect the shared variable idx

void* f(void* a){
    while(true){
        int i;
        // lock the mutex 
        // so that no other thread can access
        pthread_mutex_lock(&idM);

        // checking the vector is completely traversed or not
        if(currIdx>=vj.size()){
            // release the lock and exit the loop
            pthread_mutex_unlock(&idM);
            break;
        }

        i=currIdx;
        // next thread pe jao
        currIdx++;
        // release the lock
        pthread_mutex_unlock(&idM);

        cout<<"Thread "<<pthread_self()<<" processing index "<<i<<endl;
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


    // destroy the mutex
    pthread_mutex_destroy(&idM);
    return 0;
}