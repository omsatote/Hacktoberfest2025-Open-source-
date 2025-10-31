// stl_demo.cpp
// Compile: g++ -std=c++17 stl_demo.cpp -O2 -o stl_demo

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) vector + algorithms (sort, unique, remove_if, transform, accumulate)
    vector<int> v = {5, 3, 8, 3, 9, 1, 5};
    cout << "Original vector: ";
    for (int x : v) cout << x << ' ';
    cout << "\n";

    // sort ascending
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << ' ';
    cout << "\n";

    // remove duplicates (unique + erase idiom)
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "Unique: ";
    for (int x : v) cout << x << ' ';
    cout << "\n";

    // transform: square each element (in-place)
    transform(v.begin(), v.end(), v.begin(), [](int a){ return a * a; });
    cout << "Squared: ";
    for (int x : v) cout << x << ' ';
    cout << "\n";

    // accumulate (sum)
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << "\n\n";


    // 2) deque, stack, queue
    deque<string> dq = {"first", "middle", "last"};
    dq.push_front("new_front");
    dq.push_back("new_back");
    cout << "Deque front: " << dq.front() << ", back: " << dq.back() << "\n";

    stack<string> st;
    for (auto &s : dq) st.push(s);
    cout << "Stack pop order: ";
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << "\n";

    queue<string> q;
    q.push("one"); q.push("two"); q.push("three");
    cout << "Queue pop order: ";
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << "\n\n";


    // 3) priority_queue (max-heap by default) and min-heap
    priority_queue<int> maxpq; // largest on top
    priority_queue<int, vector<int>, greater<int>> minpq; // smallest on top
    for (int x : {7, 2, 5, 10}) {
        maxpq.push(x);
        minpq.push(x);
    }
    cout << "Max-heap pop: ";
    while (!maxpq.empty()) { cout << maxpq.top() << ' '; maxpq.pop(); }
    cout << "\nMin-heap pop: ";
    while (!minpq.empty()) { cout << minpq.top() << ' '; minpq.pop(); }
    cout << "\n\n";


    // 4) associative containers: set, multiset, map, unordered_map
    set<int> s = {4, 1, 3, 2};
    cout << "Set order (sorted, unique): ";
    for (int x : s) cout << x << ' ';
    cout << "\n";

    multiset<int> ms;
    ms.insert(2); ms.insert(2); ms.insert(1);
    cout << "Multiset contents: ";
    for (int x : ms) cout << x << ' ';
    cout << "\n";

    map<string, int> mp;
    mp["apple"] = 3;
    mp["banana"] = 2;
    mp["orange"] = 5;
    cout << "Map iteration (key: value):\n";
    for (auto &p : mp) cout << "  " << p.first << ": " << p.second << "\n";

    unordered_map<string, int> ump; // average O(1) lookup
    ump.reserve(16);
    ump["cat"] = 1; ump["dog"] = 2;
    cout << "unordered_map dog count: " << ump["dog"] << "\n\n";


    // 5) pairs, tuples, structured bindings
    pair<int, string> pr = {42, "answer"};
    auto [num, text] = pr; // structured binding (C++17)
    cout << "Pair: " << num << " -> " << text << "\n";

    tuple<int, double, string> tup(1, 3.14, "pi");
    auto [i, d, str] = tup;
    cout << "Tuple: " << i << ", " << d << ", " << str << "\n\n";


    // 6) algorithms with predicates: find_if, remove_if, partition
    vector<int> a = {10, 15, 20, 25, 30};
    auto it = find_if(a.begin(), a.end(), [](int x){ return x % 7 == 0; });
    cout << "First divisible by 7: " << (it == a.end() ? -1 : *it) << "\n";

    // remove all odd numbers
    a.erase(remove_if(a.begin(), a.end(), [](int x){ return x % 2 != 0; }), a.end());
    cout << "After removing odd: ";
    for (int x : a) cout << x << ' ';
    cout << "\n";

    // partition by >= 20
    vector<int> b = {5, 25, 15, 30, 10};
    auto pivot = partition(b.begin(), b.end(), [](int x){ return x >= 20; });
    cout << "Partitioned (>=20 first): ";
    for (int x : b) cout << x << ' ';
    cout << "\nElements >=20: ";
    for (auto it2 = b.begin(); it2 != pivot; ++it2) cout << *it2 << ' ';
    cout << "\n\n";


    // 7) iterator adapters, iota, generate
    vector<int> id(5);
    iota(id.begin(), id.end(), 1); // fills with 1,2,3,4,5
    cout << "iota: ";
    for (int x : id) cout << x << ' ';
    cout << "\n";

    vector<int> gen(5);
    int cur = 100;
    generate(gen.begin(), gen.end(), [&cur](){ return cur += 10; }); // 110,120,...
    cout << "generate: ";
    for (int x : gen) cout << x << ' ';
    cout << "\n\n";

    // Done
    cout << "STL demo finished.\n";
    return 0;
}
