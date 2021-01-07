#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <bits/stdc++.h>
using namespace std;

///https://www.youtube.com/watch?v=KNVPFVG49Oc

struct cq { ///структура для буквы: сама буква и ее частота в строке
    char ch;
    int freq;
    cq(char ch_): ch(ch_), freq(1) {}; ///конструктор
};

struct vertex {
    char ch;
    int freq;
    vertex *left = NULL;
    vertex *right = NULL;
};

bool myPred(cq a, cq b) ///предикат для сортировки вектора
{
    return a.freq > b.freq;
}

struct vertexCompare ///для сортировки list
{
    bool operator() (const vertex *l, const vertex *r) const
    {
        return l->freq < r->freq;
    }

};

vector<bool> code;
map<char,vector<bool> > table;

void BuildTable(vertex *root)
{
    if (root->left!=NULL)
                      { code.push_back(0);
                      BuildTable(root->left);}

    if (root->right!=NULL)
                       { code.push_back(1);
                       BuildTable(root->right);}

    if (root->left==NULL && root->right==NULL) table[root->ch]=code;

    code.pop_back();
}

int main() {
    string st;
    cin >> st;
    int i, u, len = st.size(), cnt_chars = 0;
    vector<cq> cq_arr;
    for (i = 0; i < len; i++) ///вычисляю частоту появляения той или иной буквы
    {
        bool new_char = true;
        for (u = 0; u < cnt_chars; u++)
        {
            if (st[i] == cq_arr[u].ch)
            {
                new_char = false;
                cq_arr[u].freq++;
                break;
            }
        }
        if (new_char)
        {
            cq_arr.push_back(cq(st[i]));
            cnt_chars++;
        }
    }

    sort(cq_arr.begin(), cq_arr.end(), myPred);
    list<vertex*> tree; ///list - контейнер в виде списка (очередь), т.е. есть ссылка на след. объект
    for (i = 0; i < cnt_chars; i++) ///создаю дерево для кодов символов
    { ///дерево пока что без связей налево, направо
        vertex *p = new vertex;
        p->ch = cq_arr[i].ch;
        p->freq = cq_arr[i].freq;
        tree.push_back(p);
    } ///сейчас кол-во эл-ов в дереве = кол-ву различных букв
    while (tree.size() != 1) ///формирую дерево
    {
        tree.sort(vertexCompare());
        vertex *vert1 = tree.front();
        tree.pop_front();
        vertex *vert2 = tree.front();
        tree.pop_front();

        vertex *parent = new vertex;
        parent->freq = vert1->freq + vert2->freq;
        parent->left = vert1;
        parent->right = vert2;
        tree.push_back(parent);
    }

    ///если только один символ
    if (cq_arr.size() == 1)
    {
        cout << "1 " << cq_arr[0].freq << endl;
        cout << cq_arr[0].ch << ": 0 \n";
        for (u = 0; u < cq_arr[0].freq; u++)
            cout << "0";
        return 0;
    }

    BuildTable(tree.front()); ///строю таблицу с кодами

    ///вывод: кол-во различных символов и кол-во бит после кодировки
    cout << cq_arr.size() << " ";
    int new_len = 0;
    for (i = 0; i < st.length(); i++)
    {
        char c = st[i];
        vector<bool> x = table[c];
        for (u = 0; u < x.size(); u++)
            new_len++;
    }
    cout << new_len << endl;

    ///вывод: символ и его код
    for (i = 0; i < cnt_chars; i++)
    {
        char c = cq_arr[i].ch;
        vector<bool> x = table[c];
        cout << c << ": ";
        for (u = 0; u < x.size(); u++)
            cout << x[u];
        cout << endl;
    }

    ///вывод: закодировання строка
    for (i = 0; i < st.length(); i++)
    {
        char c = st[i];
        vector<bool> x = table[c];
        for (u = 0; u < x.size(); u++)
            cout << x[u];
    }

    return 0;
}
