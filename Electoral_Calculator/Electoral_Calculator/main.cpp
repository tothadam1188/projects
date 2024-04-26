#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "matplotlibcpp.h" // or any other charting library

using namespace std;
namespace plt = matplotlibcpp;

// Function to implement D'Hondt algorithm
vector<pair<string, int>> calculateDHondt(const map<string, int>& votes, int seats) {
    vector<pair<string, int>> results;

    // Copy votes to a vector of pairs (party, votes)
    vector<pair<string, int>> voteList(votes.begin(), votes.end());

    // Sort the parties by their vote count in descending order
    sort(voteList.begin(), voteList.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });

    // Allocate seats using D'Hondt method
    for (int i = 0; i < seats; ++i) {
        results.push_back(make_pair(voteList[0].first, voteList[0].second / (i + 1)));
        ++voteList[0].second; // Increase vote count for the party that got the seat
        // Re-sort the parties based on updated vote count
        sort(voteList.begin(), voteList.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
            });
    }

    return results;
}

int main() {
    // Parse data from Google Forms (for simplicity, data is hardcoded here)
    map<string, int> votes = {
        {"Party A", 500},
        {"Party B", 300},
        {"Party C", 200},
        // Add more parties as needed
    };

    int totalSeats = 10; // Total number of seats to allocate

    // Calculate results using D'Hondt method
    vector<pair<string, int>> results = calculateDHondt(votes, totalSeats);

    // Display results
    for (const auto& result : results) {
        cout << result.first << ": " << result.second << " seats\n";
    }

    // Generate column chart
    vector<string> parties;
    vector<int> seats;
    for (const auto& result : results) {
        parties.push_back(result.first);
        seats.push_back(result.second);
    }

    plt::bar(parties, seats);
    plt::show();

    return 0;
}