//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++
class TrieNode{

    public:

 

    char data;

    TrieNode* children[26];

    bool isTerminal;

 

    TrieNode(char ch){

        ch = data;

        for(int i=0; i<26; i++){

            children[i] = NULL;

        }

        isTerminal = false;

    }

};

class Trie {

 

public:

 

    TrieNode* root;

 

    /** Initialize your data structure here. */

    Trie() {

        root = new TrieNode('\0');

    }

 

    void insertUtil(TrieNode* root, string word){

        if(word.length()==0){

            root->isTerminal = true;
            return;
        }

 

        int index = word[0]-'a';

        TrieNode* child;

 

        if(root->children[index]){

            child = root->children[index];

        }

        else{

            child = new TrieNode(word[0]);

            root->children[index] = child;

        }

 

        insertUtil(child, word.substr(1));

    }

    /** Inserts a word into the trie. */

    void insert(string word) {

        insertUtil(root, word);

    }



void printsug(TrieNode* curr,vector<string> &temp,string prefix){
    if (curr->isTerminal) {
        temp.push_back(prefix);
    }
    for(char ch = 'a' ; ch <= 'z' ; ch++){
        TrieNode* next = curr->children[ch-'a'];

        if(next){
            prefix.push_back(ch);
            printsug(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getsug(string str){
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for(int i = 0 ; i < str.length(); i++){
        char lastch = str[i];

        prefix.push_back(lastch);

        TrieNode* curr = prev->children[lastch-'a'];

        if(!curr) break;

        vector<string> temp;
        printsug(curr,temp,prefix);

        output.push_back(temp);
        temp.clear();
        prev = curr;
    }
   int r= str.size()-output.size();
      for(int i=0; i<r; i++){
          output.push_back({"0"});
      }
      return output;
      
  }
};
class Solution{
public:



    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *t = new Trie();

    for(int i = 0 ; i < n;i++){
        string str = contact[i];
        t->insert(str);
    }
    return t->getsug(s);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends