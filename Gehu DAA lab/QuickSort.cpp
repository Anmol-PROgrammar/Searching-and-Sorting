#include<bits/stdc++.h>
using namespace std;

int compare=0; int invert=0;
 void print(int a[],int n)  
        {   for(int i=0;i<n;i++)
             cout<<a[i]<<" ";
             cout<<endl;
        }

int Partation (int a[], int s,int e) {
        
        /*Consdidering last element as pivot*/
        int pivot = a[e];        
        int pindex = s;
        
      for(int i = s ; i < e ; i++)
      {     
           compare++;
          if(a[i] < pivot)
          { 
              swap(a[i],a[pindex]);
              pindex++;
              invert++;
          }
      }
        swap(a[pindex],a[e]);
        invert++;
        
        return pindex;

    }

    void Quick(int a[],int s,int e ){

        if(s < e){
            int p = Partation(a,s,e);
            Quick( a, s, (p-1));
            Quick(a, (p+1), e);
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
                            Quick(a,0,n-1);
                            print(a,n); 
                cout<<"comparison = "<<compare<<endl<<"inversion = "<<invert<<endl;
        }
          return 0;
    }