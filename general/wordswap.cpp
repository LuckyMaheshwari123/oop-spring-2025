#include<iostream>
#include<cstring>
using namespace std;
class Reverse{
    public:
    int getstring(char arr[]){
        int i=0;
        char ch;
        cout<<"Enter the string:";
        while(i<100){
            ch=getchar();
            if(ch=='\n'){
                break;
            }
            else{
                arr[i]=ch;
                i++;
            }
        }
        arr[i]='\0';
        return strlen(arr);

    }
    void display(char arr[],int length){
        for(int i=0;i<length;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
    void reversestring(char arr[],int length){
        for(int i=0;i<length/2;i++){
            char temp=arr[i];
            arr[i]=arr[length-i-1];
            arr[length-i-1]=temp;
        }
    }
    void reverseWords(char arr[],int length){
        int start=0;
        
        for(int i=0;i<=length;i++){
            if(arr[i]==' '|| arr[i]=='\0'){
                int end=i-1;
                while(start<end){
                    char temp=arr[start];
                    arr[start]=arr[end];
                    arr[end]=temp;
                    start++;
                    end--;
                }
                start=i+1;

            }
        }
    }


};
int main(){
   Reverse r1;
   char arr[100];
   int length=r1.getstring(arr);
   r1.display(arr,length);
   r1.reversestring(arr,length);
   r1.display(arr,length);
   r1.reverseWords(arr,length);
   r1.display(arr,length);

}
