// Using Tries

class Trie{
    public:
    Trie *children[26];
    string word="";
    // Trie{
    //     for(int i=0;i<26;i++){
    //         children[i]=NULL;
    //     }
    // }
};
class Solution {
public:
    Trie* buildTrie(vector<string> words){
        Trie * root=new Trie();
        for(string word : words){
            Trie * current=root;
            for(int i=0;i<word.size();i++){
                int ind=word[i]-'a';
                if(current->children[ind]==NULL){
                    current->children[ind]=new Trie();
                }
                current=current->children[ind];
            }
            current->word=word;
        }
        return root;
        // return NULL;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        Trie * root=buildTrie(words);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                check(i,j,board,ans,root);
            }
        }
        return ans;
    }
    void check(int i,int j,vector<vector<char>> board,vector<string> &ans,Trie * root){
        // if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
        //     return;
        // }
        char c=board[i][j];
        int index=board[i][j]-'a';
        if(c=='$'||root->children[index]==NULL){
            return;
        }
        root=root->children[index];
        if(root->word!=""){
            ans.push_back(root->word);
            root->word="";
        }
        
        board[i][j]='$';
        if(i < board.size() - 1) 
            check(i+1,j,board,ans,root);
        if (i > 0)
            check(i-1,j,board,ans,root);
        if (j > 0)
            check(i,j-1,board,ans,root);
        if (j < board[0].size() - 1)
            check(i,j+1,board,ans,root);
        board[i][j]=c;
    }
};
