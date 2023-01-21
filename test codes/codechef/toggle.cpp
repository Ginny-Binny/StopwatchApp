int toggle(int n, vector<int> &arr){
    int p=0;
    int gfg1=0;
    int i=0;
    int zzz=0;
    int ooo=0;

    while(i<n){
        while(i<n && arr[i]==1){
            i++;
            p++;

        }
        while(i<n && arr[i]==0){
            zzz+++;
            i++;

        }
        while(i<n && arr[i]==1){
            i++;
            ooo++;

        }

        gfg1=max(gfg1,p+zzz+ooo);
        p=ooo;
        zzz=0;
        ooo=0;

    }
    return gfg1;
}