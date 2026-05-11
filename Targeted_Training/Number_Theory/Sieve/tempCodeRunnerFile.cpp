
void solve(){
    bool isprime[N];
    fill(isprime, isprime+N+1, 1);
    vi prime;
    isprime[0] = isprime[1] = 0;
    rep(i, 2, N - 1){
        if(isprime[i]){
            prime.push_back(i);
            for(ll j = (ll)i * i; j <= N - 1; j += i){
                isprime[j] = false;
            }