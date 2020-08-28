import java.util.*;

public class MainClass {
    static int n=10;
    static List<Integer> p=Arrays.asList(0, 9, 8, 4, 4, 3, 6, 5, 1, 5, 0, 2, 1, 1, 1, 1, 8, 8, 5, 3, 9, 8, 9, 9, 6, 1, 8, 4, 6, 4, 3, 7, 1, 3, 2, 9, 8, 6, 2, 9, 2, 7, 2, 7, 8, 4, 2, 3, 0, 1, 9, 4, 7, 1, 5, 9, 1, 7, 3, 4, 3, 7, 1, 0, 3, 5, 9, 9, 4, 9, 6, 1, 7, 5, 9, 4, 9, 7, 3, 6, 7, 7, 4, 5, 3, 5, 3, 1, 5, 6, 1, 1, 9, 6, 6, 4, 0, 9, 4, 3);

    public static void main(String[] args) {
        for(int i=1;i<=n;i++){
            System.out.println("n="+i+":");
            System.out.print("OPT:"+OPT(i)+"\t");
            System.out.print("LRU:"+LRU(i)+"\t");
            System.out.print("FIFO:"+FIFO(i)+"\t\n");
        }
    }

    public static int OPT(int x){
        int find=0;
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i=0;i<100;i++){
            if(a.contains(p.get(i))){
                find++;
                continue;
            }
            if(a.size()<x)
                a.add(p.get(i));
            else{
                ArrayList<Integer> temp = new ArrayList<Integer>();
                int j;
                for(j=i+1;j<100&&temp.size()<x-1;j++){ 
                    if(a.contains(p.get(j))&&!temp.contains(p.get(j))){
                        temp.add(p.get(j));
                    }
                }
                if(temp.size()==x-1||j==100){  
                    for(int k=0;k<x;k++){
                        if(!temp.contains(a.get(k))){
                            a.remove(k);
                            a.add(p.get(i));
                            break;
                        }
                    }
                }
            }
        }
        return 100-find;
    }

    public static int LRU(int x) {
        int find=0;
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i=0;i<100;i++){
            if(a.contains(p.get(i))){
                find++;
                a.remove(p.get(i));
                a.add(p.get(i));    
                continue;
            }
            if(a.size()<x)
                a.add(p.get(i));
            else{
                a.remove(0);
                a.add(p.get(i));
            }
        }
        return 100-find;
    }

    public static int FIFO(int x) {
        int find=0;
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i=0;i<100;i++){
            if(a.contains(p.get(i))){
                find++;
                continue;
            }
            if(a.size()<x)
                a.add(p.get(i));
            else{
                a.remove(0);
                a.add(p.get(i));
            }
        }
        return 100-find;
    }

}