class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        int l=0;
       int h= n-1;
       int temp;
       int a= 0;
       while(l<h)
       {
           temp= min(height[h],height[l]);
           int min = temp* (h-l-1);
           a= max(a, min);
           
           if(height[l]<=height[h])
           {
               l++;
           }
           else
           {
               h--;
           }
       }
       return a;
        
    }   
};