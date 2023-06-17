#include <bits/stdc++.h>
using namespace std;
    int longestsubarraysum(vector<int> &a,int k){
        int left=0,right=0;
        int maxlength=0;int sum=0;
        for(right;right<=a.size()-1;right++){
            sum=sim
            while(left)
            int window=right-left+1;
        }
    }
     vector<int> findAnagrams(string s, string p) {   
        int len=s.size();
        int window=p.size();
        vector<int> ans;
        if(len<window)return ans;
        int left=0;int right=0;
        vector<int> phash(26,0);
        vector<int> shash(26,0);
        for(right=0;right<=window-1;right++){
           shash[s[right]-'a']+=1;
           phash[p[right]-'a']+=1;
        }
        
        if(shash==phash)ans.push_back(right-window);
        for(right;right<=len-1;right++){
           
           shash[s[left]-'a']-=1;
           left++;
           shash[s[right]-'a']+=1;
           if(shash==phash)ans.push_back(right+1-window);

        }
        return ans;

    }

    int longestcharacterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int result = 0;

        int l = 0;
        int maxfreq = 0;
        for (int i = 0; i <= s.length()-1; i++) {
            count[s[i]]++;
            maxfreq = max(maxfreq, count[s[i]]);

            if ((i - l + 1) - maxfreq > k) {//i-l+1 is length of window 
                count[s[l]]--;
                l++;
            }

            result = max(res, i - l + 1);
        }
        return result;
    }

    int lengthOfLongestSubstringwithrepeatingcharacters(string s) {
        if(s.size()==0)return 0;
        int longest=0;
        int l=0;
        unordered_set<char> st;
        
        for(int i=0;i<=s.size()-1;i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[l]);
                l++;
                //st.erase(s[l]);
                //it would be s[l] and not s[i],if first placed s[i]here          
            }
            st.insert(s[i]);
            longest=max(longest,i-l+1);
        }
        return longest;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;int r=0;
        int result=0;
        int total=0;
        while(r<=nums.size()-1){
            total=total+nums[r];

            while(nums[r]*(r-l+1) >(total+k)){
                total-=nums[l];
                l+=1;
            }
            result=max(result,r-l+1);
            r+=1;
        }
        return result
        
    }
    int minSubArrayLen(int s, vector<int>& nums){
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }


int main(){
    return 0;
}
