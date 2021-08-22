#include<bits/stdc++.h>
using namespace std;

int compare=0; int invert=0;
 void print(int a[],int n)  
        {   for(int i=0;i<n;i++)
             cout<<a[i]<<" ";
             cout<<endl;
        }

void CompAndMerge(int a[],int s,int m,int e,int n)
    {
         int i=s; 
         int k=s;
         int j= m + 1;
         //creating a tmp array
         int tmp[n];

            while(i <= m && j <= e) {
                if(a[i] <= a[j]) {
                    tmp[k] = a[i];
                    compare++;
                    i++;
                    k++;                    
                }
                else{
                    tmp[k] = a[j];
                    compare++;
                    j++;
                    k++;
                }
            }

            while(i <= m){
                 tmp[k] = a[i];
                    i++;
                    k++;                    
            }

             while(j <= e){
                   tmp[k]=a[j];
                    j++;
                    k++;
            }
            /*now copying all the merged element from tmp array to original array*/
            for(int p = s;p <= e; p++){
                invert++;
              a[p] = tmp[p];
              }              
    }

    void Merge(int a[],int s,int e,int n){

      if(s < e) {  
          int mid = (s+e)/2;
            Merge(a,s,mid,n);            
            Merge(a,mid+1,e,n);            
            CompAndMerge(a, s, mid, e,n);
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
                            Merge(a,0,n-1,n);
                            print(a,n); 
                cout<<"comparison = "<<compare<<endl<<"inversion = "<<invert<<endl;
        }
          return 0;
    }