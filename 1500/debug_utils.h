#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

// DEBUGGER
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)

// Generic print
void _print() {}

template<typename T>
void _print(const T& t);

// Special print for pair
template<typename T1, typename T2>
void _print(const pair<T1, T2>& p) {
    cerr << "(";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << ")";
}

// Special print for vector
template <typename T>
void _print(const vector<T>& v) {
    cerr << "[";
    bool first = true;
    for (const auto& ele : v) {
        if (!first) cerr << ", ";
        first = false;
        _print(ele);
    }
    cerr << "]";
}

// Special print for 2D vector (vector of vectors)
template <typename T>
void _print(const vector<vector<T>>& mat) {
    cerr << endl;  // Adding a newline for 2D vector header
    for (const auto& row : mat) {
        _print(row);  // Print each row (which is a 1D vector)
        cerr << endl;  // Move to the next line for the next row
    }
}

// Special print for set
template <typename T>
void _print(const set<T>& s) {
    cerr << "{";
    bool first = true;
    for (const auto& ele : s) {
        if (!first) cerr << ", ";
        first = false;
        _print(ele);
    }
    cerr << "}";
}

// Special print for unordered_set
template <typename T>
void _print(const unordered_set<T>& s) {
    cerr << "{";
    bool first = true;
    for (const auto& ele : s) {
        if (!first) cerr << ", ";
        first = false;
        _print(ele);
    }
    cerr << "}";
}

// Special print for multiset
template <typename T>
void _print(const multiset<T>& s) {
    cerr << "{";
    bool first = true;
    for (const auto& ele : s) {
        if (!first) cerr << ", ";
        first = false;
        _print(ele);
    }
    cerr << "}";
}

// Special print for map
template <typename K, typename V>
void _print(const map<K, V>& m) {
    cerr << endl;  // Adding a newline for map header
    for (const auto& [key, val] : m) {
        _print(key);   // Print the key
        cerr << " : "; // Separator
        _print(val);   // Print the value
        cerr << endl;
    }
}

// Special print for unordered_map
template <typename K, typename V>
void _print(const unordered_map<K, V>& m) {
    cerr << endl;  // Adding a newline for unordered_map header
    for (const auto& [key, val] : m) {
        _print(key);   // Print the key
        cerr << " : "; // Separator
        _print(val);   // Print the value
        cerr << endl;
    }
}

// Special print for multimap
template <typename K, typename V>
void _print(const multimap<K, V>& m) {
    cerr << endl;  // Adding a newline for multimap header
    for (const auto& [key, val] : m) {
        _print(key);   // Print the key
        cerr << " : "; // Separator
        _print(val);   // Print the value
        cerr << endl;
    }
}

// Special print for unordered_multimap
template <typename K, typename V>
void _print(const unordered_multimap<K, V>& m) {
    cerr << endl;  // Adding a newline for unordered_multimap header
    for (const auto& [key, val] : m) {
        _print(key);   // Print the key
        cerr << " : "; // Separator
        _print(val);   // Print the value
        cerr << endl;
    }
}


// Generic print for other types
template<typename T>
void _print(const T& t) {
    cerr << t;
}

// _debug recursive function to process multiple args
template<typename T, typename... Args>
void _debug(const string& names, T&& arg, Args&&... args) {
    int idx = 0, n = names.length();
    string var_name = "";

    while (idx < n && names[idx] != ',') {
        var_name += names[idx++];
    }

    cerr << var_name << ": ";
    _print(arg);

    if constexpr (sizeof...(args)) {
        cerr << " |";
        _debug(names.substr(idx + 1), args...);
    } else {
        cerr << endl;
    }
}

#endif // DEBUG_UTILS_H
