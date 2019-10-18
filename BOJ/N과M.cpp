#include <iostream>

using namespace std;
int N,M;
int comp[9];
bool nums[9];
void mixx(int cnt){
    if(cnt==M+1){
        for(int i=1;i<=M;i++){
            cout<<comp[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=1;i<=N;i++){
        if(!nums[i]){
            comp[cnt]=i;
            nums[i]=true;
            mixx(cnt+1);
        }
        nums[i]=false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>N>>M;
    mixx(0);
    return 0;
}

