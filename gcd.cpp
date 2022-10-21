#include<bits/stdc++.h>
#define max 1000001
using namespace std;
int isPrime[max]={};
vector <vector<int> > factor (max);

void seive(){
    for(int i=1;i<max;i++)
    isPrime[i]=i;
    for(int i=1;i<max;i++)
    {
        if(i%2==0)
        isPrime[i]=2;
    }
    for(int i = 3;i*i<max;i++)
    {
        if(isPrime[i]==i)
        {
            for(int j=i*i;j<max;j+=i)
            {
                if(isPrime[j]==j)
                isPrime[j]=i;
            }
        }
    }
}
void primeFactor(){
    factor[1].push_back(1);
    for(int i=2;i<max;i++)
    {

        int x = i;
        while(x!=1)
        {
            int temp = isPrime[x];
            if(x%temp==0)
            {
                factor[i].push_back(temp);
            }
            while(x%temp==0){
                x=x/temp;
            }
        }

    }
}



int main()
{
    int t;
    cin>>t;
    seive();
    primeFactor();
    while(t--)
    {
        int n;
        cin>>n;
        int count = 0;
        vector <vector<int> > v;
        int visited[1000001]={};
        int days = 0;

        while(count!=n)
        {
            vector<int> temp;
            int p[100001]={};
            for(int i=1;i<=n;i++)
            {
                if(visited[i]!=1)
                {

                    vector <int> :: iterator it = factor[i].begin();
                    int count1=0;
                    for(it = factor[i].begin();it!=factor[i].end();it++)
                    {
                        if(p[(*it)]==0)
                        {
                            count1++;
                        }
                        else
                        break;
                    }
                    if(count1==factor[i].size())
                    {
                        count++;
                        temp.push_back(i);
                        visited[i]=1;
                        for(it = factor[i].begin();it!=factor[i].end();it++)
                        {
                            p[*it]=1;
                        }
                    }
                }
            }
            v.push_back(temp);
            days++;
        }
        cout<<days<<endl;
        for(int i=0;i<days;i++)
        {
            vector<int> :: iterator it;
            cout<<v[i].size()<<" ";
            for(it=v[i].begin();it!=v[i].end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }


    }
}