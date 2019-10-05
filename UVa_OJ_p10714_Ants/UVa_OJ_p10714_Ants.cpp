#include<cstdio>
using namespace std;

int main(void){
    int n;
    scanf("%d",&n);
    while(n--){
        int len,ants,min=0,max=0;
        scanf("%d %d",&len,&ants);
        while(ants--){
            int ant,min_t,max_t;
            scanf("%d",&ant);
            if(ant< len-ant){
                min_t=ant;
                max_t=len-ant;
            }else{
                min_t=len-ant;
                max_t=ant;
            }
            if(min<min_t)
                min=min_t;
            if(max<max_t)
                max=max_t;
        }
        printf("%d %d\n",min,max);
    }
    return 0;    
}
