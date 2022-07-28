int main() {
	int T;
	cin >> T;
	while(T--){
	    int n;
	    cin >> n;
	    unordered_map<int,int>ff;
	    for(int i=0;i<n;i++){
	        int t;
	        cin >> t;
	        ff[t]++;
	    }
	    vector<int>y;
	    for(auto i:ff)y.push_back(i.second);
	    sort(y.begin(),y.end());
	    int m=y.size();
	    int a=y[m-1];
	    int b=0;
	    if(m>1)b=y[m-2];
	    cout << max(a/2+(int)(a%2!=0),b) << endl;
	}
	return 0;
}
