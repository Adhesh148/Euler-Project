#include <stdio.h>
#include <math.h>
int main(){
  
  unsigned int n;
    scanf("%d",&n);
    unsigned int arr[55],carry=0,temp=0,store[50];
    for(int i=0;i<55;++i){
         arr[i] = 0;
    }
   for(int j=0;j<n;++j){
    for(int i=49;i>=0;--i){
        scanf("%1d",&store[i]);
    }
    for(int i=0;i<55;++i){
     // printf("%d\n",temp );
      temp =0;
        if(i<50)
          temp = store[i];
       arr[i] = arr[i] + temp+carry;
       if(arr[i]>9){
       carry = arr[i]/10;
       arr[i] = arr[i]%10;
       }
       else
        carry=0;
    }
}
//printf("YES\n");
int count =0,flag=0,i=54;
while(count!=10){
  if(flag==0 && arr[i]==0){
    --i;
  }
  else{
    flag =1;
    ++count;
    printf("%d",arr[i]);
    --i;
  }
}
}
