import java.util.*;
public class CandidateCode {
    static ArrayList<Integer> list = new ArrayList<>();
    static int tot = 0;
    
    static void comb(int arr[], int n, int r, 
                          int index, int data[], int i) 
    { 
        if (index == r) { 
            tot++;
            return; 
        } 
  
        if (i >= n) 
            return; 
  
        data[index] = arr[i]; 
        comb(arr, n, r, index + 1,  
                               data, i + 1); 
  
        comb(arr, n, r, index, data, i + 1); 
    } 
  
    static void pcomb(int arr[], int n, int r) 
    { 
        int data[] = new int[r]; 
        comb(arr, n, r, 0, data, 0); 
    }
    
    
    
    static void store(int n, int arr[], int i){
        if(i == n){
            
            int flag = 0;
            for(int q=0;q<n-1;q++){
                if(arr[q] == 1 && arr[q+1] == 1){
                    flag++;
                }
            }
            if(flag == 0){
                int fin=0;
                for(int q =0;q<n;q++){
                fin = fin*10 + arr[q];
                    
                    
                }
                list.add(fin);
            }
            return;
        }

        arr[i] = 1;
        store(n,arr,i+1);
        arr[i] = 2;
        store(n,arr,i+1);
    }



    public static void main(String args[] ) throws Exception {

     //Write code here
        Scanner ob = new Scanner(System.in);
        int v = ob.nextInt();
        int m = ob.nextInt();
        int x = ob.nextInt();
        for(int q = m;q<=x;q++){
            int[] arr = new int[q];
            list.clear();
            store(q,arr,0);
            int[] arr1 = new int[list.size()];
            arr1 = list.stream().mapToInt(Integer::intValue).toArray();
            int n = arr1.length; 
            pcomb(arr1, n, v);
            
        }
        System.out.println(tot);

   }
}