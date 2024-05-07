#include <iostream>
#include <stack>
using namespace std;

/**
 * return
 * 0: 合法
 * 1,2,3: 非法
*/
int validBracket(string s) {
    stack<char> st;
    for(int i=0;i<s.length();i+=1){
        char ch = s[i];
        // 1.ch is left-bracket
        if(ch=='(')
            st.push(')');
        else if(ch=='[')
            st.push(']');
        else if(ch=='{')
            st.push('}');
        // 2.ch is right-bracket
        else if(st.empty()) // 错误1: 栈为空
            return 1;
        else if(ch != st.top())
            return 2; // 错误2: 栈顶不匹配
        else 
            st.pop(); // 正常情况
    }
    if(!st.empty())
        return 3; // 错误3: 最终栈非空
    return 0; // 正确
}

int main(){
    string s;
    cout << "请输入待检测的括号序列:... (示例: '{([[[}}]])})' )\n";
    cin >> s;
    int res = validBracket(s);
    res==0?(cout<<"匹配"):(cout<<"检测结果：不匹配\n");
    if(res==1)
        cout<<"错误原因：右括号冗余";
    else if(res==2)
        cout<<"错误原因：括号不成对匹配";
    else if(res==3)
        cout<<"错误原因：左括号冗余";
    cin.get();
}
