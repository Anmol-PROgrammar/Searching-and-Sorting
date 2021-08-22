#include<bits/stdc++.h>
using namespace std;


    void Selection(int a[], int n){
        int min=0;
        for(int i=0;i<n-1;i++){  

            min=i;
                for(int j=i+1;j<n;j++){
                 if(a[min]>a[j])
                    min=j;
                }
            if(min!=i){
                swap(a[min],a[i]);
            }
        }
        
    }

    int main(){
        
        int t;
        cin>>t;
        while(t--)
        {        int n;
                cin>>n;
            int a[n];
                for(int i=0;i<n;i++)
                    cin>>a[i];
            int k;
            cin>>k;        
             Selection(a,n);
           cout<<a[k-1];                     
        }
          return 0;
    }