#include <bits/stdc++.h>
# include <pthread.h>
#include <unistd.h>
using namespace std;
int t=0,m=0,p=0;
queue<int>q1;
queue<int>q2;
queue<int>q3;
pthread_mutex_t x,smoker_p,smoker_m,smoker_t,smoker;
bool agent_turn=true;
#define   wait pthread_mutex_lock
# define  signal pthread_mutex_unlock
# define  SIGNAL pthread_cond_signal
# define  WAIT   pthread_cond_wait


void * agent_pass(void *arg){
    while(true){
        sleep(1);
        while(!agent_turn);
        wait(&x);
        cout<<"x-------------------------x--------------------------x"<<endl;
        int chance=rand()%3;
        switch(chance){
            case 0:
                // When agent passes tobacco & Paper
                t=1;p=1;
                cout<<"Agent passes Tobacco & Paper"<<endl;
                break;
            case 1:
                // When agent passes tobacco & Match
                t=1;m=1;
                cout<<"Agent passes Tobacco & Match"<<endl;
                break;
            case 2:
                // When agent passes Match & Paper
                m=1;p=1;
                cout<<"Agent passes Match & Paper"<<endl;
                break;
        }
        agent_turn=false;
        signal(&x);
    }
}
void*Intermediation(void *arg){
    while(1){
        wait(&x);
        if(m == 1 && t==1) {
            m = 0; t = 0;
            cout<<"Paper Smoker Turn"<<endl;
            SIGNAL(&smoker_p);

        }
        else if(m == 1 && p==1) {
            m = 0; p = 0;
            cout<<"Tobacco Smoker Turn"<<endl;
            SIGNAL(&smoker_t);


        }
        else if(p == 1 && t==1) {
            p= 0; t = 0;
            cout<<"Match Smoker Turn"<<endl;
            SIGNAL(&smoker_m);

        }
        signal(&x);
    }
}
void * smoking_t(void *arg){

    while(1){
        wait(&smoker);
        WAIT(&smoker_t, &smoker);
        p = 0; m = 0;
        agent_turn= true;
        cout<<"Tobacco Smoker number "<< q1.front() << " starts Smoking..."<<endl;
        q1.push(q1.front());
        q1.pop();
        signal(&smoker);
    }
}
void * smoking_p(void *arg){

    while(1){
        wait(&smoker);
        WAIT(&smoker_p, &smoker);
        t = 0; m = 0;
        agent_turn= true;
        cout<<"Paper Smoker number "<< q2.front() <<" starts Smoking...."<<endl;
        q2.push(q2.front());
        q2.pop();
        signal(&smoker);
    }
}
void * smoking_m(void *arg){
    while(1){
        wait(&smoker);
        WAIT(&smoker_m, &smoker);
        p = 0; t = 0;
        agent_turn= true;
        cout<<"Match Smoker number "<< q3.front()<<" starts Smoking..."<<endl;
        q3.push(q3.front());
        q3.pop();
        signal(&smoker);
    }
}
int main(){
    pthread_t Agent,Smoker_page,Smoker_tobacco,Smoker_match,Intermediator;
    pthread_mutex_init (&x,NULL);
    pthread_mutex_init (&smoker_p,NULL);
    pthread_mutex_init (&smoker_m,NULL);
    pthread_mutex_init (&smoker_t,NULL);
    pthread_mutex_init (&smoker,NULL);
    int a,b,c;
    cout<<"Enter value of a,b,c"<<endl;
    cout<<"a is number of smokers with tobacco"<<endl;
    cout<<"b is number of smokers with paper"<<endl;
    cout<<"c is number of smokers with match"<<endl;
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
        q1.push(i);
    }
    for(int i=1;i<=b;i++){
        q2.push(i);
    }
    for(int i=1;i<=c;i++){
        q3.push(i);
    }
    pthread_create(&Agent,NULL,agent_pass,NULL);
    pthread_create(&Smoker_page,NULL,smoking_p,NULL);
    pthread_create(&Smoker_tobacco,NULL,smoking_t,NULL);
    pthread_create(&Smoker_match,NULL,smoking_m,NULL);
    pthread_create(&Intermediator,NULL,Intermediation,NULL);

    pthread_join(Agent, NULL);
    pthread_join(Intermediator, NULL);
    pthread_join(Smoker_match, NULL);
    pthread_join(Smoker_page, NULL);
    pthread_join(Smoker_tobacco, NULL);

}

