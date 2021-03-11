//
// Created by 谢卓 on 2021/3/3.
//

#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<map>

using namespace std;

struct node {
    double num;
    char op;
    bool flag; //true 数字，false 字符
};

int convert(const string &str) {
    map<char, int> m;
    m['+'] = m['-'] = 1;
    m['*'] = m['/'] = 2;

    queue<node> q;  // 存放后缀表达式
    stack<char> op; // 临时存放操作符
    for (int i = 0; i < str.length();) {
        node temp{};
        if (isdigit(str[i]) || str[i] == '.') {
            string num;
            num += str[i++];
            while (i < str.length() && (isdigit(str[i]) || str[i] == '.')) {
                num += str[i++];
            }
            temp.num = stod(num);
            temp.flag = true;
            q.push(temp);
            cout << temp.num << " ";
        } else {
            if (op.empty() || str[i] == '(') {
                op.push(str[i]);
            } else if (str[i] == ')') {
                while (op.top() != '(') {
                    temp.op = op.top();
                    temp.flag = false;
                    q.push(temp);
                    cout << op.top() << " ";
                    op.pop();

                }
                op.pop();
            } else if (m[str[i]] > m[op.top()]) {
                op.push(str[i]);

            } else if (m[str[i]] <= m[op.top()]) {
                while (!op.empty() && m[str[i]] <= m[op.top()] && op.top() != '(') {
                    temp.op = op.top();
                    temp.flag = false;
                    q.push(temp);
                    cout << op.top() << " ";
                    op.pop();

                }
                op.push(str[i]);
            }
            i++;
        }
    }
    int op_size = op.size();
    for (int i = 0; i < op_size; i++) {
        cout << op.top() << " ";
        node temp{};
        temp.op = op.top();
        temp.flag = false;
        q.push(temp);
        op.pop();
    }
    cout << endl;

    // 计算
    int q_size = q.size();
    cout << q_size << endl;
    stack<double> num;//存放数字
    for (int i = 0; i < q_size; i++) {
        if (q.front().flag) {
            num.push(q.front().num);
            q.pop();
        } else {
            double t1, t2;
            t2 = num.top();
            num.pop();
            t1 = num.top();
            num.pop();

            if (q.front().op == '+') num.push(t1 + t2);
            else if (q.front().op == '-') num.push(t1 - t2);
            else if (q.front().op == '*') num.push(t1 * t2);
            else if (q.front().op == '/') num.push(t1 / t2);

            q.pop();

        }
    }

    cout << "result: " << num.top() << endl;
    return 0;
}

// 中缀表达式转化为后缀表达式
string inToPost(const string &str) {
    map<char, int> m; // 存储运算符优先级
    m['+'] = m['-'] = 1;
    m['*'] = m['/'] = 2;

    stack<char> op; // 用于存储运算符的临时栈
    string res;
    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];
        switch (ch) {
//            case ' ': // 若为' ',直接跳出(预处理后这步可以不用)
//                break;
            case '(': // 若为'(',直接进栈
                op.push(ch);
                break;
            case ')': // 若为')',出栈至'('
                while (!op.empty() && op.top() != '(') {
                    res += op.top();
                    op.pop();
                }
                op.pop();
                break;
            default:
                if (isdigit(ch) || ch == '.') { // 若为数字或者小数点，直接进字符串
                    if (isdigit(str[i + 1]) || str[i + 1] == '.') {
                        res += ch;
                    } else {
                        res += ch;
                        res += '#'; // 数字结束后加#用以区分
                    }
                } else if (op.empty() || op.top() == '(' ||
                           (op.top() != '(' && m[ch] > m[op.top()])) { //若为运算符，且比栈顶运算符优先级高，则直接进栈
                    op.push(ch);
                } else { // 否则出栈至遇到低优先级的运算符
                    while (!op.empty() && m[ch] <= m[op.top()]) {
                        res += op.top();
                        op.pop();
                    }

                    op.push(ch);
                }
                break;
        }
    }

    while (!op.empty()) {
        res += op.top();
        op.pop();
    }

    return res;
}

// 计算后缀表达式的值
double resultPost(const string &str) {
    double num1, num2;
    stack<double> nums;
    for (int i = 0; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            string temp;
            while (str[i] != '#') {
                temp += str[i];
                i++;
            }
            nums.push(stod(temp));
        } else if (str[i] != '#') { // 遇到运算符后出栈两次，用num1和num2分别暂时存储
            num1 = nums.top();
            nums.pop();
            num2 = nums.top();
            nums.pop();
        }

        switch (str[i]) { // 遇到运算符就对num1和num2进行相应运算,并入栈
            case '+':
                nums.push(num2 + num1);
                break;
            case '-':
                nums.push(num2 - num1);
                break;
            case '*':
                nums.push(num2 * num1);
                break;
            case '/':
                nums.push(num2 / num1);
                break;
            default:
                break;
        }
    }

    return nums.top();
}

string & trim_all(string &str) {
    int index = 0;
    if (!str.empty()) {
        while ((index = str.find(' ', index)) != string::npos) {
            str.erase(index, 1);
        }
    }

    return str;
}

string &replace_all(string &str, const string &old_value, const string &new_value) {
    while (true) {
        string::size_type pos(0);
        if ((pos = str.find(old_value)) != string::npos)
            str.replace(pos, old_value.length(), new_value);
        else break;
    }

    return str;
}

string &preproccess(string &str) {
    str = trim_all(str);
    str = "0" + str;
    str = replace_all(str, "(-", "(0-");
    return str;
}

int main() {
    string s4 = "-5.2*(-3+4)-6";
    string s3 = "1+2*3-9/3";
    string s2 = "9+(3-1)*3+10/2";
    string s1 = "11+(3-1)*2+4";
    string s = "100*((30+10)/10+22)";
    s4 = preproccess(s4);
    //convert(s4);
    string res = inToPost(s4);
    cout << res << endl;
    cout << resultPost(res) << endl;
    return 0;
}