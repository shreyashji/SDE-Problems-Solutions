vector<string> AllPossibleStrings(string s){
		    int n = s.size(); 
		    vector<string> ans; 
		    for(int num = 0; num < (1 << n); num++) { //to iterate 2^n
		        string sub = ""; 
		        for(int i = 0;i<n;i++) { //to iterate  0 to 2
		            if(num & (1<<i)) { //check if ith bit is set or not
		                sub += s[i];
		            }
		        }
		        if(sub.size() > 0)
		            ans.push_back(sub); 
		    }
		    sort(ans.begin(), ans.end()); //in sequence
		    return ans; 
		}