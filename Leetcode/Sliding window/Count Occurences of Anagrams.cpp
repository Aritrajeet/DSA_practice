	int search(string pat, string txt) {
	    // code here
	    int ans=0;
	    int i=0,j=0;
	    map<char,int> m;
	    for (auto x : pat){     //insert pattern into map
	        m[x]++;
	    }
	    while(j<txt.length()){
	        if(m.find(txt[j]) != m.end()){      //if curr char present in the map decrement its count
	            m[txt[j]]--;
            }
	        if(j-i+1 < pat.length()){     //window not yet available
                j++;
	        }
	        else{
	            bool flag = true;
	            for(auto x:m){
	                if(x.second>0){     //if all counts are zero that is the map is empty then it means we have an anagram else ignore
	                    flag = false;
	                    break;
	                }
	            }
	            if(flag){
	                ans++;
	            }
	            if (m.find(txt[i]) != m.end()){     // Preparation for the next window- Increase the count of first ele of window if present in the map. Since it was decremented earlier.
	                m[txt[i]]++;
	            }
	            i++;      //Move to the next window
	            j++;
	        }
	    }
	    return ans;
	}
