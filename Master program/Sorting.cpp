#include<bits/stdc++.h>

using namespace std;

class Sorting{ 
 
    private :

     void swap(int &x,int &y){
         int tmp=x;
         x=y;
         y=tmp;
     }

     public :

     void print(int a[],int n)  
        {   for(int i=0;i<n;i++)
             cout<<a[i]<<" ";
             cout<<endl;
        }
       
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
        print(a,n);
    }

    void Insertion(int a[],int n){
            
        int i,j;    
            for( i=1;i<n;i++){
                int key=a[i];
                
                        /*using for loop for second loop*/ 
                // for( j=i-1;j>=0;j--){
                //     if(a[j]>key){
                //         a[j+1]=a[j];                        
                //     }
                //     else
                //         break;
                // }

                        /*using while loop for second loop*/ 
                j=i-1;
                while(j>=0&&a[j]>key){
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1]=key;
            }
            print(a,n);
    }
    void Bubble(int a[],int n){
        
        
        bool flag=true;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    flag=false;
                }
            }
            if(flag)
                break;
        }
        print(a,n);
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
                    i++;
                    k++;                    
                }
                else{
                    tmp[k] = a[j];
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

    int Partation (int a[], int s,int e) {
        
        /*Consdidering last element as pivot*/
        int pivot = a[e];        
        int pindex = s;
        
      for(int i = s ; i < e ; i++)
      {
          if(a[i] < pivot)
          {
            swap(a[i],a[pindex]);
              pindex++;
          }
      }
        swap(a[pindex],a[e]);

        return pindex;

    }

    void Quick(int a[],int s,int e ){

        if(s < e){
            int p = Partation(a,s,e);
            Quick( a, s, (p-1));
            Quick(a, (p+1), e);
        }        
    }

    void Counting(int a[],int n){
        
        int range=10;
        int tmp[range]={};
        int OutputArr[n];

/*placing element of input array at the equalivalent index of tmp array*/
        for(int i = 0; i < n ;i++){
            ++tmp[a[i]];
        }
/*Performing arthimetic on tmp array 
Adding all the values to the right*/
    for(int i = 1; i <= range ; i++ )
        tmp[i]+=tmp[i-1];

/*Performing arthimetic on tmp array 
placing values in output array*/

        for(int i = 0; i < n; i++){
            OutputArr[--tmp[a[i]]]=a[i];
        }
    //copying all the element from output to original
      for(int i = 0; i < n; i++){
            a[i]=OutputArr[i];
        }

    print(a,n);
 }
            /* finding max element from the array*/
        int Max(int a[],int n){
            
            int max = a[0];
            for(int i = 1; i < n ; i++ ) {
                    if (a[i] > max)
                       max = a[i];
            }
          return max;
        }
                /*modified countiing sort for better efficency given by radix sort */
    void countsort(int arr[],int size,int div){         
            
            int output[size]; 
    int count[10] = {0}; 
  
    for (int i = 0; i < size; i++) 
        count[ (arr[i]/div)%10 ]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = size - 1; i >= 0; i--) 
    { 
        output[--count[ (arr[i]/div)%10 ] ] = arr[i]; 
        
    } 
  
    for (int i = 0; i < size; i++) 
        arr[i] = output[i]; 
} 
    


    void Radix(int a[], int n) 
    {
        int max = Max(a ,n);
        for(int div = 1; max/div > 0; div*=10)
            countsort(a,n,div);
            print(a,n);
    }

    void Shell();


};
        
 int main(){

     int ch,n;
     cout<<"enter the size of the aray"<<endl;
     cin>>n;
     int a[n];
         for(int i=0;i<n;i++)
             cin>>a[i];
     Sorting ob ;
    do{

        cout<<"ENTER YOUR CHOICE OF SORTING ALGORTHIM YOU WANT TO PERFORM"<<endl<<"Press 0 to EXIT"<<endl;
         cout<<" 1 : Insertion Sort"<<endl;
         cout<<" 2 : Bubble Sort"<<endl;
         cout<<" 3 : Merge Sort"<<endl;
         cout<<" 4 : Quick Sort"<<endl;
         cout<<" 5 : Counting Sort"<<endl;
         cout<<" 6 : Radix Sort"<<endl;
         cout<<" 7 : Shell Sort"<<endl;
         cout<<" 8 : Selection Sort"<<endl;
         cout<<" 9 : clear screen"<<endl;
             cin>>ch;
            switch(ch){
                case 1:
                    cout<<"performing insertion sort"<<endl;
                    ob.Insertion(a,n); 
                break;
                case 2:
                    cout<<"performing bubble sort"<<endl;
                    ob.Bubble(a,n); 
                break;
                case 3:
                    cout<<"performing merge sort"<<endl;
                    ob.Merge(a,0,n-1,n);
                    ob.print(a,n); 
                break;
                case 4:
                    cout<<"performing quick sort"<<endl;
                    ob.Quick(a,0,n-1);
                    ob.print(a,n);  
                break;
                case 5:
                    cout<<"performing counting sort"<<endl;
                    ob.Counting(a,n); 
                break;
                case 6:
                    cout<<"performing radix sort"<<endl;
                    ob.Radix(a,n); 
                break;
                case 7:
                    cout<<"performing shell sort"<<endl;
                    // ob.Shell(); 
                break;
                case 8:
                    cout<<"performing selection sort"<<endl;
                    ob.Selection(a,n); 
                break;
                case 9:
                 system("cls");
                break;
                default:
                    cout<<"Wrong"<<endl;                                   
            }
         }
     while(ch!=0);
         
     return 0;
 }