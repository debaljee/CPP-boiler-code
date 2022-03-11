import math
from collections import deque
def toUpper(item):
    arr=[char for char in item]
    for i in range(len(arr)):
        ascii=ord(arr[i])
        if(ascii>=97 and ascii<(97+26)):
            ascii-=32
        arr[i]=chr(ascii)
    return(''.join(arr))
def toLower(item):
    arr=[char for char in item]
    for i in range(len(arr)):
        ascii=ord(arr[i])
        if(ascii>=65 and ascii<(65+26)):
            ascii+=32
        arr[i]=chr(ascii)
    return(''.join(arr))
def search(a,b):
    n1=len(a)
    n2=len(b)
    for i in range(n1-n2+1):
        sub=a[i:i+n2]
        if(sub==b):
            print(i)
def myRound(item):
    low=math.floor(item)
    if(item>=low+0.5):
        return(low+1)
    else:
        return(low)
def mod(a,b):
    ans=((a/b)-math.floor(a/b))*b
    return(myRound(ans))
def toInt(item):
    ans=0
    arr=[char for char in item]
    for i in range(len(arr)):
        ascii=ord(arr[i])
        digit=ascii-48
        ans=ans*10+digit
    return(ans)

def reverse(item):
    arr=[char for char in item]
    ans=['' for char in item]
    for i in range(len(arr)):
        ans[i]=arr[len(arr)-i-1]
    return(''.join(ans))
def toStr(item):
    ans=''
    while(item!=0):
        digit=mod(item,10)
        ascii=48+digit
        ans=ans+chr(ascii)
        item=math.floor(item/10)
    return(reverse(ans))
def initRank2Matrix(n):
    arr=[[0 for i in range(n)]for j in range(n)]
    return(arr)
def cofac(arr,i,j):
    n=len(arr)
    mat=initRank2Matrix(n-1)
    a=0
    b=0
    for p in range(n):
        for q in range(n):
            if(p!=i and q!=j):
                mat[a][b]=arr[p][q]
                b+=1
                if(b==n-1):
                    b=0
                    a+=1
    return(mat)
def det(arr):
    if(len(arr)==1):
        return(arr[0][0])
    sum=0
    sign=1
    for i in range(len(arr)):
        sum=sum+arr[0][i]*sign*det(cofac(arr,0,i))
        sign=sign*(-1)
    return(sum)

class node:
    def __init__(self):
        self.left=None
        self.right=None
        self.data=''
class queue:
    def __init__(self):
        self.front=None
        self.back=None
def initQueue():
    myQueue=queue()
    myQueue.front=None
    myQueue.back=None
    return(myQueue)
def insertQueue(myQueue,item):
    if(myQueue.front==None and myQueue.back==None):
        myQueue.front=node()
        myQueue.back=myQueue.front
        temp=myQueue.front
        temp.left=None
        temp.right=None
        temp.data=item
    else:
        temp=myQueue.back
        temp.right=node()
        temp.right.left=temp
        temp=temp.right
        temp.right=None
        temp.data=item
        myQueue.back=temp
def deleteQueue(myQueue):
    if(myQueue.front==None and myQueue.back==None):
        return('Queue underflow')
    elif(myQueue.front==myQueue.back):
        item=myQueue.front.data
        myQueue.front=None
        myQueue.back=None
        return(item)
    else:
        item=myQueue.front.data
        myQueue.front=myQueue.front.right
        myQueue.front.left=None
        return(item)

class gNode:
    def __init__(self):
        self.left=None
        self.right=None
        self.index=-1
def initGraph(n):
    arr=[None for i in range(n)]
    return(arr)
def insertGraph(myGraph,i,j):
    myNode=gNode()
    myNode.index=j
    myNode.right=myGraph[i]
    if(myNode.right!=None):
        myNode.right.left=myNode
    myNode.left=None
    myGraph[i]=myNode
def displayGraph(myGraph):
    for i in range(len(myGraph)):
        temp=myGraph[i]
        myString=''
        myString=myString+str(i)
        while(temp!=None):
            myString=myString+'->'
            myString=myString+str(temp.index)
            temp=temp.right
        print(myString)
mydict={}
mydict['Debal']=2323
print(mydict['Debal'])
