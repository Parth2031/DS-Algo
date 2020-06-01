// TODO:: In this question, Sum of Two Array means Sum using Carry Method.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void input(vector<int> &arr1,vector<int> &arr2)
{
  cout<<"Enter the 1st Array: "<<endl;
  for(int i=0;i<arr1.size();i++)
    cin>>arr1[i];

  cout<<"Enter the 2nd Array: "<<endl;
  for(int i=0;i<arr2.size();i++)
    cin>>arr2[i];    
}

void display(vector<int>& TotalSum)
{
  cout<<"Sum of Two Array's with Carry: "<<endl;
  for(int i:TotalSum)
    cout<<i<<" ";
  cout<<endl;
}

void SumofTwoArrays(vector<int> &arr1,vector<int> &arr2,int n,int m)
{
  int sum=0,carry=0,check;
  vector<int> TotalSum;

  int i = arr1.size()-1 ,j = arr2.size()-1;
  
  for(; i>=0 || j>=0; i--,j--) 
  {                          
    check=carry;

    if(i>=0) check+=arr1[i];
    if(j>=0) check+=arr2[j];
    
    sum=check % 10;
    TotalSum.push_back(sum);
    carry=check / 10;
  }

  if(carry!=0) 
    TotalSum.push_back(carry);
  
  reverse(TotalSum.begin() , TotalSum.end());

  display(TotalSum);  
}

int main(int args,char** argv)
{
  int n,m;
  cout<<endl<<"Enter the size of 1st array: ";
  cin>>n;
  cout<<endl<<"Enter the size of 2nd array: ";
  cin>>m;
  if(n<0 || m<0)
    exit(0);
  else
  {  
   vector<int> arr1(n,0),arr2(m,0);
   input(arr1,arr2);
   SumofTwoArrays(arr1,arr2,n,m); 
  }
  return 0;
}
