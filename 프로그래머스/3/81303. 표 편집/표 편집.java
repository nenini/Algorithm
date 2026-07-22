import java.util.*;

class Solution {
    public static final int HEAD=-1;
    public static final int TAIL=-2;
    
    public String solution(int n, int k, String[] cmd) {
        StringBuilder answer = new StringBuilder(n);
        
        Node[] list=new Node[n];
        boolean[] deleted=new boolean[n];
        Deque<Integer> removed=new ArrayDeque<>();
        
        int head=0;
        int tail=n-1;
        
        list[0]=new Node(HEAD,1);
        list[n-1]=new Node(n-2,TAIL);
        
        for(int i=1;i<n-1;i++){
            list[i]=new Node(i-1,i+1);
        }
        
        int curPos=k;
        
        for(int i=0;i<cmd.length;i++){
            char command=cmd[i].charAt(0);
            if(command=='U'){
                int X = Integer.parseInt(cmd[i].substring(2));
                curPos=findNextPosition(curPos,X,0,list);
            }else if(command=='D'){
                int X = Integer.parseInt(cmd[i].substring(2));
                curPos=findNextPosition(curPos,X,1,list);
            }else if(command=='C'){
                deleted[curPos]=true;
                removed.push(curPos);

                int prevPos = list[curPos].prev;
                int nextPos = list[curPos].next;             
                
                if (prevPos == HEAD) {
                    head = nextPos;
                } else {
                    list[prevPos].next = nextPos;
                }
                
                if (nextPos == TAIL) {
                    tail = prevPos;
                } else {
                    list[nextPos].prev = prevPos;
                }
                
                if(nextPos==TAIL){
                    curPos=prevPos;
                }else{
                    curPos=nextPos;
                }
                
            }else{
                int removedPos=removed.pop();
                int prev=list[removedPos].prev;
                int next=list[removedPos].next;
                
                if(prev==HEAD){
                    head=removedPos;
                    list[next].prev=removedPos;
                }else{
                    list[prev].next=removedPos;
                }
                
                if(next==TAIL){
                    tail=removedPos;
                    list[prev].next=removedPos;
                }else{
                    list[next].prev=removedPos;
                }
                
                deleted[removedPos]=false;
            }
        }
        for(int i=0;i<n;i++){
            if(deleted[i]){
                answer.append("X");
            }else{
                answer.append("O");
            }
        }
        
        return answer.toString();
    }
    
    public int findNextPosition(int curPos,int X,int direction,Node[] list){
        for(int i=0;i<X;i++){
            if(direction==0){
                curPos=list[curPos].prev;            
            }else{
                curPos=list[curPos].next;           
            }
        }
        return curPos;
    }
}

class Node{
    int prev;
    int next;
    
    Node(int prev, int next){
        this.prev=prev;
        this.next=next;
    }
}