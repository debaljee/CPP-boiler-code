#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void input(char str[]){
    int i=0;
    char c=getchar();
    while(c!='\n'){
        str[i]=c;
        i+=1;
        c=getchar();
    }
    str[i]='\0';
}
void toUpper(char str[]){
    int i=0;
    while(str[i]!='\0'){
        int ascii=(int)str[i];
        if(ascii>=97 && ascii<(97+26))
            ascii-=32;
        str[i]=(char)ascii;
        i+=1;
    }
}
void toLower(char str[]){
    int i=0;
    while(str[i]!='\0'){
        int ascii=(int)str[i];
        if(ascii>=65 && ascii<(65+26))
            ascii+=32;
        str[i]=(char)ascii;
        i+=1;
    }
}
void substring(char str1[],char str2[],int i,int j){
    int p=0;
    for(p=0;p<(j-i);p++){
        str2[p]=str1[p+i];
    }
    str2[j-i]='\0';
}
int length(char str[]){
    int i=0;
    while(str[i]!='\0')
        i++;
    return(i);
}
void search(char str1[],char str2[]){
    int n1=length(str1);
    int n2=length(str2);
    int i;
    for(i=0;i<(n1-n2+1);i++){
        char sub[50];
        substring(str1,sub,i,i+n2);
        if(strcmp(sub,str2)==0)
            printf("%d\n",i);
    }
}
float myRound(float item){
    float low=floor(item);
    if(item>=(low+0.5))
        return(low+1);
    else
        return(low);
}
float mod(float a,float b){
    float ans=((a/b)-floor(a/b))*b;
    return(myRound(ans));
}
int toInt(char str[]){
    int ans=0;
    int i=0;
    while(str[i]!='\0'){
        int ascii=(int)str[i];
        int digit=ascii-48;
        ans=ans*10+digit;
        i+=1;
    }
    return(ans);
}
void reverse(char str[]){
    char ans[length(str)];
    int n=length(str);
    int i;
    for(i=0;i<n;i++)
        ans[i]=str[n-i-1];
    ans[n]='\0';
    strcpy(str,ans);
}
void toString(int item,char str[]){
    float num=(float)item;
    int i=0;
    while(num!=0){
        float digit=mod(num,10);
        int ascii=48+(int)digit;
        str[i]=(char)ascii;
        i+=1;
        num=floor(num/10);
    }
    str[i]='\0';
    reverse(str);
}
struct node{
    struct node *right;
    struct node *left;
    char data[50];
};
struct queue{
    struct node *front;
    struct node *back;
};
struct queue *initQueue(){
    struct queue *myQ=(struct queue *)malloc(sizeof(struct queue));
    myQ->front=NULL;
    myQ->back=NULL;
    return(myQ);
}
void insertQueue(struct queue *myQ,char item[]){
    if(myQ->front==NULL && myQ->back==NULL){
        myQ->front=(struct node *)malloc(sizeof(struct node));
        myQ->back=myQ->front;
        struct node *temp=myQ->front;
        temp->right=NULL;
        temp->left=NULL;
        strcpy(temp->data,item);
    }
    else{
        struct node *temp=myQ->back;
        temp->right=(struct node *)malloc(sizeof(struct node));
        temp->right->left=temp;
        temp=temp->right;
        temp->right=NULL;
        strcpy(temp->data,item);
        myQ->back=temp;
    }
}
void delQueue(struct queue *myQ,char ans[]){
    if(myQ->front==NULL && myQ->back==NULL)
        strcpy(ans,"Queue underflow");
    else if(myQ->front==myQ->back){
        strcpy(ans,myQ->front->data);
        myQ->front=NULL;
        myQ->back=NULL;
    }
    else{
        strcpy(ans,myQ->front->data);
        myQ->front=myQ->front->right;
        myQ->front->left=NULL;
    }
}
int main(){
    struct queue *myQ=initQueue();
    char inp[50];
    strcpy(inp,"Debal");
    insertQueue(myQ,inp);
    strcpy(inp,"Debdut");
    insertQueue(myQ,inp);
    strcpy(inp,"Debojyoti");
    insertQueue(myQ,inp);
    char ans[50];
    delQueue(myQ,ans);
    printf("%s\n",ans);
    delQueue(myQ,ans);
    printf("%s\n",ans);
    delQueue(myQ,ans);
    printf("%s\n",ans);
    delQueue(myQ,ans);
    printf("%s\n",ans);
    delQueue(myQ,ans);
    printf("%s\n",ans);
    delQueue(myQ,ans);
    printf("%s\n",ans);
}