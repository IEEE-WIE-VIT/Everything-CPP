void func(string t,int i,int n,string s){
    if(i==n){
        cout<<t<<endl;
    }
    else{
        func(t,i+1,n,s){
            t=t+s[i];
            func(t,i+1,n,s);
        }
    }
}