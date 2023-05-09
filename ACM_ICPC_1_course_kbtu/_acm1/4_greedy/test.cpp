bool check(long long teams) 
{ 
    long long t = teams*m; 
    for(long long i = 0; i < n; i++) { 
        long long tmp = min(a[i], min(teams, t)); 
        t -= tmp; 
        if(t == 0)
            return 1;
    } 

    return 0; 
}