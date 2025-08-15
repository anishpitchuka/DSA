  cout<<"c: "<<endl;
    int m;
    cin>>m;
    for(int i=n-1; i>=0 && v[i] > m; i--){
        *(ptr + i + 1) = *(ptr + i);
    }