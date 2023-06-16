#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> checkScores(const std::vector<std::vector<int>>& testCases) {
    std::vector<std::string> results;
    
    for (const auto& scores : testCases) {
        int numStudents = scores.size();
        
        int highestScore = *std::max_element(scores.begin(), scores.end());
        int count = std::count(scores.begin(), scores.end(), highestScore);
        
        if (count > 1) {
            results.push_back("fight:(");
        } else {
            results.push_back("peace:)");
        }
    }
    
    return results;
}

int main() {
    int T;
    std::cin >> T;
    
    std::vector<std::vector<int>> testCases;
    
    for (int i = 0; i < T; i++) {
        int numStudents;
        std::cin >> numStudents;
        
        std::vector<int> scores(numStudents);
        for (int j = 0; j < numStudents; j++) {
            std::cin >> scores[j];
        }
        
        testCases.push_back(scores);
    }
    
    std::vector<std::string> results = checkScores(testCases);
    
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}
