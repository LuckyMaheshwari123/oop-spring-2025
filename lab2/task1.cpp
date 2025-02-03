#include <iostream>
using namespace std;
int*memoryAllocation(int rows){
    int *ptr=new int[rows];
    return ptr;
}
void arrayInput(int*ptr,int rows){
    for(int i=0;i<rows;i++){
    cout<<"Enter the element"<<i+1<<":";
    cin>>*(ptr+i);
    }
    
}
void displayOutput(int*ptr,int rows){
    float sum=0;
    cout<<"The elements are:";
    for(int i=0;i<rows;i++){
   cout<<*(ptr+i)<<" ";
   sum+=*(ptr+i);
   
    }
    int max=ptr[0];
    for(int i=0;i<rows;i++){
        if(*(ptr+i)>max){
            max=*(ptr+i);
        }
    }
    float average;
    average=sum/rows;
    
    cout<<"\nThe sum is:"<<sum<<endl;
    cout<<"The average is:"<<average<<endl;
    cout<<"The max element is:"<<max<<endl;
    
    
}
void free(int *ptr,int rows){
    delete[] ptr;
    
}

    





int main()
{
    int rows;
    cout << "Enter the number of elements: ";
    cin >> rows;

    int* ptr = memoryAllocation(rows);
    
    arrayInput(ptr, rows);
    displayOutput(ptr, rows);

    free(ptr);

    return 0;
}
