//leetcode
#include<iostream>
#include<math.h>
using namespace std;
//REVERSE INTEGER
/* 
int main(){
    int n;
    cout<<"enter n";
     cin>>n;
    int rem;
    int sum =0;
     while(n!=0){
        rem=n%10;
        sum=sum*10+rem;
        n=n/10;
        }
    
    cout<<sum<<endl;
 }*/
//POWER OF 2 
 /*int  main(){
    int n;
     std::cout<<"enter the value of n";
    std::cin>>n;
    int i=0;
    
    while(i<=n){
        int val= pow(2,i);
    if(val==n){
        std::cout<<"true";
    }
        i++;
    
    }
}*/
//give an integer n return the difference bw the product and the sum 
int main(){
    int n;
    cout<<"enter the value of n";
    cin>>n;
    
    int sum=0;
    int k=0;
    while(n!=0){
    if (n&1){
        sum++;
    }
    n=n>>1;
    
    }
    cout<<sum;

    }