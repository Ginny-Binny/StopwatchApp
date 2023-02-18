#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <unordered_map>
// Uncomment below line to send network request if needed.
// #include <curl/curl.h>

std::unordered_map<char, int> in_degree;
std::unordered_map<char,std::vector<char>>graph;

void dfs(char node, std::vector<char>& order, std:: unordered_map<char, bool>& visited){
    visited[node]=true;
    for(char neighbour: graph[node]) {
        if(!visited[neighbour]){
            dfs(neighbour,order,visited);

        }
    }order.push_back(node);
}

std::string solve_play_on_words(const std::vector<std::string>& words){
    in_degree.clear();
    graph.clear();

    for (const auto& word: words){
        in_degree[word[0]]=0;
        in_degree[word.back()]=0;
        graph[word[0]];
        graph[word.back()];

    }

    for(std::size_t i=0; i<words.size(); ++i){
        char u= words[i][0],v= words[i].back();
        in_degree[v]++;
        graph[u].push_back(v);
    }

    int count_zero_in_degree=0;
    for(const auto& [node, degree] : in_degree){
        if(degree==0){
            count_zero_in_degree++;
        }
    }

    if(count_zero_in_degree!=2){
        return "The door cannot be opened.";
    }


    std::vector<char>order;
    std::unordered_map<char, bool>visited;
    for(const auto& [node, degree] : in_degree){
        if(degree==0 && !visited[node]){
            dfs(node, order, visited);
        }
    }

    if(order.size()!= in_degree.size()){
        return "The door cannot be opened.";

    }


    std::reverse(order.begin(), order.end());
    for(size_t i=1; i<order.size();++i){
        char u= order[i-1], v=order[i];
        if(std::find(graph[u].begin(), graph[u].end(),v)==graph[u].end()){
            return "The door cannot be opened.";
        }
    }
    return  "Ordereing is possible.";


}





std::string your_code_goes_here(std::string input) {
    // Use this function to return the solution.

    std::vector<std::string>words;
    std::istringstream iss(input);
    int num_test_cases;
    iss>>num_test_cases;
    std::ostringstream oss;
    for (int i=0; i< num_test_cases; ++i){
        int num_words;
        iss>>num_words;
        words.resize(num_words);
        for(auto& word : words){
            iss>>word;
        }
        oss<<solve_play_on_words(words)<<"\n";
    }
    return  oss.str();
}












int main() {
    std::istreambuf_iterator<char> begin(std::cin), end;
    std::string input(begin, end);

    std::string output = your_code_goes_here(input);
    std::cout << output << std::endl;
    return 0;
}
