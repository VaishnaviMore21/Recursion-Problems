class Solution {
public:
  void reverse(vector<char>&str,int start,int end)
  {
    if(start>=end)
    {
        return;
    }
    char c=str[start];
    str[start]=str[end];
    str[end]=c;
    reverse(str,start+1,end-1);
  }


    void reverseString(vector<char>& s) {
       int start=0;
       int end=s.size()-1;
       reverse(s,start,end);
       
       
       

    }
};
