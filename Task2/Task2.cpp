#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Load the information from each brick into main memory,
    // organising it in a manner suitable for efficient searching.
    std::unordered_map<std::string, std::string> bricks;

    // northern = southern
    bricks["star"] = "square";
    bricks["circle"] = "star";
    bricks["square"] = "rectangle";
    bricks["rectangle"] = "diamond";
    bricks["diamond"] = "octagon";

    // Arbitrarily choose one of the bricks as a starting point.
    std::string starting_symbol = "circle";

    // Start constructing a result sequence elsewhere in main memory.
    std::string result = bricks[starting_symbol];

    // Repeatedly, until no matching brick is found:
    std::string next_symbol;
    while (true) {
        // Search for the brick with a northern symbol that matches
        // the back (easternmost) symbol in the result sequence.
        for (const auto& brick : bricks) {  //pass value by reference const cause cant change brick values
            //std::cout << brick.first <<"\n";
            if (brick.second == starting_symbol) {
                next_symbol = brick.first;
                break;
            }
        }

        // If we didn't find a matching brick, we're done.
        if (next_symbol.empty()) {
            break;
        }

        // Add the southern symbol name from that brick to the back of the result sequence.
        result += bricks[next_symbol];

        // Move on to the next brick.
        starting_symbol = next_symbol;





        /*

        // Repeatedly, until no matching brick is found:
        while (true) {
            // Search for the brick with a southern symbol that matches
            // the front (westernmost) symbol in the result sequence.
            next_symbol.clear();
            for (const auto& brick : bricks) {
                if (brick.first == current_symbol) {
                    next_symbol = brick.second;
                    break;
                }
            }

            // If we didn't find a matching brick, we're done.
            if (next_symbol.empty()) {
                break;
            }

            // Add the northern symbol name from that brick to the front of the result sequence.
            result = bricks[next_symbol] + result;

            // Move on to the next brick.
            current_symbol = next_symbol;
        }
        */
    }

    // Output the result sequence.
    std::cout << result << std::endl;

    return 0;
}