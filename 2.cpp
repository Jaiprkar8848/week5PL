// Problem 2

#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;

#define M 5

void* f(void *p){
    cout<<"Thread created"<<endl;
} 
int main(){
    int k;
    pthread_t jp[M];  // collection of m threads
    for(k=0;k<M;k++){
        pthread_create(&jp[k],NULL,f,NULL);
        pthread_join(jp[k],NULL);
    }
}