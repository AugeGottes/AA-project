#include<bits/stdc++.h>
using namespace std;


    int n,x,y,ix,d,dm,p,xm;
    float m,im,pm;
    int MIN =INT_MIN, MAX = INT_MAX;
    std::unordered_map<int,bool> M;

    void fill(bool clock, std::vector<vector<int>>& matrix){

        x = ix;

        if(clock){

            y = MIN;
            pm = (float) MAX;

            for(int i=0;i<n;i++){
                if(matrix[i][0]==x){
                    if(matrix[i][1]>y) {y = matrix[i][1];
                    }
                } 
                if(matrix[i][0]==xm) M[i]=true;
            }

        }
        else{

            y = MAX;
            pm = (float) MIN;

            for(int i=0;i<n;i++){
                if(matrix[i][0]==x){
                    M[i] = true;
                    if(matrix[i][1]<y) {
                        y = matrix[i][1];
                        }
                } 
            }

        }

        bool brk = false;

        while(true){
            if(clock) im = (float) MIN;
            else im = (float) MAX;
            for(int i=0;i<n;i++){
                if(x==matrix[i][0]) continue;
                m = ((float) (matrix[i][1]-y))/((float) (matrix[i][0]-x));
                if(clock && m<pm && m>im) im = m;
                if(!clock && m>pm && m<im) im = m;
            }
            if(im==MAX || im==MIN) break;
            dm = 0;
            pm = im;
            for(int i=0;i<n;i++){
                if(x==matrix[i][0]) continue;
                m = ((float) (matrix[i][1]-y))/((float) (matrix[i][0]-x));
                if(m==pm){
                    if(ix==matrix[i][0] || xm==matrix[i][0]){
                        brk = true;
                        continue;
                    }
                    M[i] = true;
                    d = (matrix[i][0]-x)*(matrix[i][0]-x) + (matrix[i][1]-y)*(matrix[i][1]-y);
                    if(d>dm){
                        dm = d;
                        p = i;
                    } 
                } 
            }
            if(brk) break;
            x = matrix[p][0];
            y = matrix[p][1];
        }
    }

    vector<vector<int>> helper(std::vector<vector<int>>& matrix) {

        ix = MAX;
        xm = MIN;
        n = matrix.size(); 
        for(int i=0;i<n;i++){
            if(matrix[i][0]<ix) ix = matrix[i][0];
        }
        for(int i=0;i<n;i++){
            if(matrix[i][0]>xm) xm = matrix[i][0];
        }

        fill(true, matrix);
        if(ix!=xm) fill(false, matrix);

        std::vector<vector<int>> ans;
        for(auto i : M){
            if(i.second) ans.push_back(matrix[i.first]);
        }

        return ans;
    }

int main(){
    vector<vector<int>>matrix={{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    vector<vector<int>>ans=helper(matrix);
   for (int i = 0; i < ans.size(); i++)
{
    for (int j = 0; j < ans[i].size(); j++)
    {
        cout << ans[i][j];
    }
    cout<<endl;
}

    return 0;
}