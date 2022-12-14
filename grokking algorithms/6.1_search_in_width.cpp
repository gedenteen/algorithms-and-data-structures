#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int searchInWidth(map<string, vector<string>> graph, string startName, const string nameToFind)
{
    queue<string> queueToSearch;
    queueToSearch.push(startName);
    map<string, char> searched; //хэш-таблица с людьми, которые уже проверены

    int cnt = 0; //сколько людей проверено
    while (!queueToSearch.empty()) {
        string person = queueToSearch.front(); //взять первое имя из списка
        queueToSearch.pop(); //удалить первое имя из списка

        cout << "debug: person = " << person << "\n";

        if (!searched[person]) {
            if (nameToFind == person) {
                return cnt;
            }
            for (int i = 0; i < graph[person].size(); i++) { //добавить в очередь для поиска всех друзей person
                queueToSearch.push(graph[person][i]); 
            }
            searched[person] = 1; //пометить человека как проверенного
            cnt++;
        }
        else {
            cout << "debug: already checked\n";
        }
    }

    return -1; //не найден nameToFind в graph
}

int main()
{
    map<string, vector<string>> graph;
    //1 уровень глубины
    graph["you"] = { "alice", "bob", "claire" };
    //2 уровень глубины
    graph["bob"] = { "anuj", "peggy" };
    graph["alice"] = { "peggy" };
    graph["claire"] = {"thom", "jonny", "anuj"};
    //3 уровень глубины
    graph["anuj"] = {"dima", "sasha"};
    graph["peggy"] = {"nastya", "sasha"};
    graph["thom"] = {"innokentiy"};
    graph["jonny"] = {"nastya", "dima"};
    //4 уровень глубины
    graph["dima"] = {};
    graph["anton"] = {};
    graph["nastya"] = {};
    graph["sasha"] = {};
    graph["innokentiy"] = {};

    string nameToFind;
    cout << "enter name to find: ";
    cin >> nameToFind;
    int ret_code = searchInWidth(graph, "you", nameToFind);
    cout << ret_code << endl;
}
