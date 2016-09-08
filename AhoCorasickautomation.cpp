//
// Created by 王若璇 on 16/9/9.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <csetjmp>
#include <functional>

#define T_SIZE 1001000
#define P_SIZE 50
#define TOTAL_P 10000
using namespace std;

struct trie{ //结构体封装字典树的特点
    trie *next[26];
    trie *fail;
    int num;
    trie(){
        for(int i = 0;i<26;i++){
            next[i] = NULL;
        }
        fail = NULL;
        num = 0;
    }
};

char T[T_SIZE+1];
char P[P_SIZE+1];
trie* q[TOTAL_P*P_SIZE];
void insert(trie* root,char *s){
    //将字符串s所表示的单词插入到字典树中。
    trie *p = root;
    for(int i = 0;s[i]!='\0';i++){
        if(p->next[s[i]-'a']==NULL)
            p->next[s[i]-'a'] = new trie;
        p = p->next[s[i]-'a'];
    }
    p->num++;
}
void build_ac_automation(trie *root){
    int head = 0,tail = 0;
    q[tail++] = root;
    while (head!=tail){
        trie* front = q[head++];
        //front 为队头元素
        for(int i = 0;i<26;i++){
            if(front->next[i]!=NULL){
                //遍历队头元素的子节点
                trie *p = front->fail;
                while (p!=NULL){
                    //只有根节点的失败指针为NULL
                    if(p->next[i]!=NULL){
                        //顺着失败指针往回走，直至某个节点，其拥有一个字母为'a'+i的子节点。
                        front->next[i]->fail = p->next[i];
                        break;
                    }
                    p = p->fail;
                }
                if(p==NULL)
                    front->next[i]->fail = root; //说明顺着失败指针往回走的过程中没有找到合适的节点，所以将失败指针指向根节点
                q[tail++] = front->next[i];
            }
        }
    }
}
int ac_find(trie *root,char *T){
    trie* p = root;
    int sum = 0;
    for(int i = 0,len=strlen(T);i<len;i++){
        while (p->next[T[i]-'a']==NULL&&p!=root){
            //若当前的节点没有一个字符为 T[i] 的儿子且当前节点不是根节点
            //通俗的讲，就是顺着失败指针往回走，直至找到合适的节点或者根节点为止。
            p = p->fail;
        }
        if(p->next[T[i]-'a']!=NULL) //p->next[T[i]-'a'］== NULL 说明没找到合适的节点，p指针在根节点上。
            p = p->next[T[i]-'a'];
        trie* temp = p;
        while (temp!=root&&temp->num!=-1) {
            //顺着失败指针往回走，一直走到根节点.
            sum+=temp->num;
            //若当前节点的num不为0，则说明以当前节点字母结尾的单词出现过一次。
            //此单词是以上一次循环的节点单词为结尾的单词的子集
            temp->num=-1;
            //标记为num为－1, 避免重复计算。
            temp = temp->fail;
        }

    }
    return sum;
}

int main(){
    int t;
    for(scanf("%d",&t);t>0;t--){
        trie *root = new trie;
        int n;
        scanf("%d",&n);
        getchar();
        for(int i = 0;i<n;i++){
            gets(P);
            insert(root,P);
        }
        build_ac_automation(root);
        gets(T);
        printf("%d\n",ac_find(root,T));
    }
}
