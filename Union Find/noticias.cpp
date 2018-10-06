/* Problem Description
 *
 * This problem was taken from OmegaUp.
 *
 * Link to description:
 *  https://omegaup.com/arena/problem/Noticias#problems
 *
 **/
#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
    vector <int> Padres;
    vector <int> Ranks;
    vector <int> Sizes;
    int Size;

    void make(int n){
        Size = n;
        Padres.resize(n);
        Ranks.resize(n);
        Sizes.resize(n);
        for(int i=1;i<=n;i++){
            Padres[i] = i;
            Sizes[i] = 1;
        }
    }

    int Find(int x){
        if(x!=Padres[x]){
            Padres[x]=Find(Padres[x]);
        }
        return Padres[x];
    }

    void unionRank(int x, int y){
        int r=0,s=0;
        r=Find(x);
        s=Find(y);
        if(r==s){
            return ;
        }
        if(Ranks[r] > Ranks[s]){
            Padres[s]=r;
            Sizes[r] += Sizes[s];
        } else if(Ranks[r] < Ranks[s]){
            Padres[r]=s;
            Sizes[s] += Sizes[r];
        } else {
            Padres[r]=s;
            Sizes[s] += Sizes[r];
            Ranks[s]++;
        }
    }

    void print(){
        for(int i=1;i<Size;i++)
            cout << i << '\t';

        cout << '\n';
        for(int i=0;i<Size;i++)
            cout << Padres[i] << '\t';

        cout << '\n';
        for(int i=0;i<Size;i++)
            cout << Ranks[i] << '\t';
    }

};

int main(){
    UnionFind UF;
    char op;
    int n, I, x, y;

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> I;
    UF.make(n);

    for(int i=0; i<I; i++){
        cin >> op;
        if(op == 'A'){
            cin >> x >> y;
            UF.unionRank(x,y);
        }
        else {
            cin >> x;
            y = UF.Find(x);
            cout << UF.Sizes[y] << '\n';
        }
    }

    return 0;
}