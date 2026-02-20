import os
from pathlib import Path


cses_data = {
    "Introductory Problems": [
        "Weird Algorithm", "Missing Number", "Repetitions", "Increasing Array",
        "Permutations", "Number Spiral", "Two Knights", "Two Sets",
        "Bit Strings", "Trailing Zeros", "Coin Piles", "Palindrome Reorder",
        "Gray Code", "Tower of Hanoi", "Creating Strings", "Apple Division",
        "Chessboard and Queens", "Raab Game I", "Mex Grid Construction",
        "Knight Moves Grid", "Grid Coloring I", "Digit Queries",
        "String Reorder", "Grid Path Description"
    ],

    "Sorting and Searching": [
        "Distinct Numbers", "Apartments", "Ferris Wheel", "Concert Tickets",
        "Restaurant Customers", "Movie Festival", "Sum of Two Values",
        "Maximum Subarray Sum", "Stick Lengths", "Missing Coin Sum",
        "Collecting Numbers", "Collecting Numbers II", "Playlist",
        "Towers", "Traffic Lights", "Distinct Values Subarrays",
        "Distinct Values Subsequences", "Josephus Problem I", "Josephus Problem II",
        "Nested Ranges Check", "Nested Ranges Count", "Room Allocation",
        "Factory Machines", "Tasks and Deadlines", "Reading Books",
        "Sum of Three Values", "Sum of Four Values", "Nearest Smaller Values",
        "Subarray Sums I", "Subarray Sums II", "Subarray Divisibility",
        "Distinct Values Subarrays II", "Array Division", "Movie Festival II",
        "Maximum Subarray Sum II"
    ],


    "Dynamic Programming": [
        "Dice Combinations", "Minimizing Coins", "Coin Combinations I",
        "Coin Combinations II", "Removing Digits", "Grid Paths I",
        "Book Shop", "Array Description", "Counting Towers", "Edit Distance",
        "Longest Common Subsequence", "Rectangle Cutting", "Minimal Grid Path",
        "Money Sums", "Removal Game", "Two Sets II", "Mountain Range",
        "Increasing Subsequence", "Projects", "Elevator Rides",
        "Counting Tilings", "Counting Numbers", "Increasing Subsequence II"
    ],

    "Graph Algorithms": [
        "Counting Rooms", "Labyrinth", "Building Roads", "Message Route",
        "Building Teams", "Round Trip", "Monsters", "Shortest Routes I",
        "Shortest Routes II", "High Score", "Flight Discount", "Cycle Finding",
        "Flight Routes", "Round Trip II", "Course Schedule", "Longest Flight Route",
        "Game Routes", "Investigation", "Planets Queries I", "Planets Queries II",
        "Planets Cycles", "Road Reparation", "Road Construction", "Flight Routes Check",
        "Planets and Kingdoms", "Giant Pizza", "Coin Collector", "Mail Delivery",
        "De Bruijn Sequence", "Teleporters Path", "Hamiltonian Flights",
        "Knight's Tour", "Download Speed", "Police Chase", "School Dance",
        "Distinct Routes"
    ],


    "Range Queries": [
        "Static Range Sum Queries", "Static Range Minimum Queries",
        "Dynamic Range Sum Queries", "Dynamic Range Minimum Queries",
        "Range Xor Queries", "Range Update Queries", "Forest Queries",
        "Hotel Queries", "List Removals", "Salary Queries",
        "Prefix Sum Queries", "Pizzeria Queries", "Visible Buildings Queries",
        "Range Interval Queries", "Subarray Sum Queries", "Subarray Sum Queries II",
        "Distinct Values Queries", "Distinct Values Queries II",
        "Increasing Array Queries", "Movie Festival Queries", "Forest Queries II",
        "Range Updates and Sums", "Polynomial Queries",
        "Range Queries and Copies", "Missing Coin Sum Queries"
    ],

    "Tree Algorithms": [
        "Subordinates", "Tree Matching", "Tree Diameter", "Tree Distances I",
        "Tree Distances II", "Company Queries I", "Company Queries II",
        "Distance Queries", "Counting Paths", "Subtree Queries",
        "Path Queries", "Path Queries II", "Distinct Colors",
        "Finding a Centroid", "Fixed-Length Paths I", "Fixed-Length Paths II"
    ],

    "Mathematics": [
        "Josephus Queries", "Exponentiation", "Exponentiation II",
        "Counting Divisors", "Common Divisors", "Sum of Divisors",
        "Divisor Analysis", "Prime Multiples", "Counting Coprime Pairs",
        "Next Prime", "Binomial Coefficients", "Creating Strings II",
        "Distributing Apples", "Christmas Party", "Permutation Order",
        "Permutation Rounds", "Bracket Sequences I", "Bracket Sequences II",
        "Counting Necklaces", "Counting Grids", "Fibonacci Numbers",
        "Throwing Dice", "Graph Paths I", "Graph Paths II",
        "System of Linear Equations", "Sum of Four Squares",
        "Triangle Number Sums", "Dice Probability", "Moving Robots",
        "Candy Lottery", "Inversion Probability", "Stick Game",
        "Nim Game I", "Nim Game II", "Stair Game", "Grundy's Game",
        "Another Game"
    ],

    "String Algorithms": [
        "Word Combinations", "String Matching", "Finding Borders",
        "Finding Periods", "Minimal Rotation", "Longest Palindrome",
        "All Palindromes", "Required Substring", "Palindrome Queries",
        "Finding Patterns", "Counting Patterns", "Pattern Positions",
        "Distinct Substrings", "Distinct Subsequences", "Repeating Substring",
        "String Functions", "Inverse Suffix Array", "String Transform",
        "Substring Order I", "Substring Order II", "Substring Distribution"
    ],

    "Geometry": [
        "Point Location Test", "Line Segment Intersection", "Polygon Area",
        "Point in Polygon", "Polygon Lattice Points", "Minimum Euclidean Distance",
        "Convex Hull", "Maximum Manhattan Distances", "All Manhattan Distances",
        "Intersection Points", "Line Segments Trace I", "Line Segments Trace II",
        "Lines and Queries I", "Lines and Queries II", "Area of Rectangles",
        "Robot Path"
    ],
    "Advanced Techniques": [
        "Meet in the Middle", "Hamming Distance", "Corner Subgrid Check",
        "Corner Subgrid Count", "Reachable Nodes", "Reachability Queries",
        "Cut and Paste", "Substring Reversals", "Reversals and Sums",
        "Necessary Roads", "Necessary Cities", "Eulerian Subgraphs",
        "Monster Game I", "Monster Game II", "Subarray Squares",
        "Houses and Schools", "Knuth Division", "Apples and Bananas",
        "One Bit Positions", "Signal Processing", "New Roads Queries",
        "Dynamic Connectivity", "Parcel Delivery", "Task Assignment",
        "Distinct Routes II"
    ],

    "Sliding Window Problems": [
        "Sliding Window Sum", "Sliding Window Minimum", "Sliding Window Xor",
        "Sliding Window Or", "Sliding Window Distinct Values", "Sliding Window Mode",
        "Sliding Window Mex", "Sliding Window Median", "Sliding Window Cost",
        "Sliding Window Inversions", "Sliding Window Advertisement"
    ],

    "Interactive Problems": [
        "Hidden Integer", "Hidden Permutation", "K-th Highest Score",
        "Permuted Binary Strings", "Colored Chairs", "Inversion Sorting"
    ],
    "Bitwise Operations": [
        "Counting Bits", "Maximum Xor Subarray", "Maximum Xor Subset",
        "Number of Subset Xors", "K Subset Xors", "All Subarray Xors",
        "Xor Pyramid Peak", "Xor Pyramid Diagonal", "Xor Pyramid Row",
        "SOS Bit Problem", "And Subset Count"
    ],
    "Construction Problems": [
        "Inverse Inversions", "Monotone Subsequences", "Third Permutation",
        "Permutation Prime Sums", "Chess Tournament", "Distinct Sums Grid",
        "Filling Trominos", "Grid Path Construction"
    ],

    "Advanced Graph Problems": [
        "Nearest Shops", "Prüfer Code", "Tree Traversals", "Course Schedule II",
        "Acyclic Graph Edges", "Strongly Connected Edges", "Even Outdegree Edges",
        "Graph Girth", "Fixed Length Walk Queries", "Transfer Speeds Sum",
        "MST Edge Check", "MST Edge Set Check", "MST Edge Cost",
        "Network Breakdown", "Tree Coin Collecting I", "Tree Coin Collecting II",
        "Tree Isomorphism I", "Tree Isomorphism II", "Flight Route Requests",
        "Critical Cities", "Visiting Cities", "Graph Coloring", "Bus Companies",
        "Split into Two Paths", "Network Renovation", "Forbidden Cities",
        "Creating Offices", "New Flight Routes"
    ],

    "Counting Problems": [
        "Filled Subgrid Count I", "Filled Subgrid Count II", "All Letter Subgrid Count I",
        "All Letter Subgrid Count II", "Border Subgrid Count I", "Border Subgrid Count II",
        "Raab Game II", "Empty String", "Permutation Inversions", "Counting Bishops",
        "Counting Sequences", "Grid Paths II", "Counting Permutations",
        "Grid Completion", "Counting Reorders", "Tournament Graph Distribution",
        "Collecting Numbers Distribution", "Functional Graph Distribution"
    ],

    "Additional Problems I": [
        "Shortest Subsequence", "Distinct Values Sum", "Distinct Values Splits",
        "Swap Game", "Beautiful Permutation II", "Multiplication Table",
        "Bubble Sort Rounds I", "Bubble Sort Rounds II", "Nearest Campsites I",
        "Nearest Campsites II", "Advertisement", "Special Substrings",
        "Counting LCM Arrays", "Square Subsets", "Subarray Sum Constraints",
        "Water Containers Moves", "Water Containers Queries", "Stack Weights",
        "Maximum Average Subarrays", "Subsets with Fixed Average",
        "Two Array Average", "Pyramid Array", "Permutation Subsequence",
        "Bit Inversions", "Writing Numbers", "Letter Pair Move Game",
        "Maximum Building I", "Sorting Methods", "Cyclic Array", "List of Sums"
    ],

    "Additional Problems II": [
        "Bouncing Ball Steps", "Bouncing Ball Cycle", "Knight Moves Queries",
        "K Subset Sums I", "K Subset Sums II", "Increasing Array II",
        "Food Division", "Swap Round Sorting", "Binary Subsequences",
        "School Excursion", "Coin Grid", "Grid Coloring II",
        "Programmers and Artists", "Removing Digits II", "Coin Arrangement",
        "Replace with Difference", "Grid Puzzle I", "Grid Puzzle II",
        "Bit Substrings", "Reversal Sorting", "Book Shop II",
        "GCD Subsets", "Minimum Cost Pairs", "Same Sum Subsets",
        "Mex Grid Queries", "Maximum Building II", "Stick Divisions",
        "Stick Difference", "Coding Company", "Two Stacks Sorting"
    ],

}

cpp_template = """#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    return 0;
}
"""

def slugify(text):
    """Convierte 'Nombre de Problema' en 'Nombre-de-Problema'"""
    return text.replace(" ", "-")

def build_structure():
    base_path = Path(".")
    
    for category, problems in cses_data.items():
        cat_folder = base_path / slugify(category)
        cat_folder.mkdir(exist_ok=True)
        
        for prob in problems:
            # Subcarpeta del problema 
            prob_folder = cat_folder / slugify(prob)
            prob_folder.mkdir(exist_ok=True)
            
            cpp_file = prob_folder / "a.cpp"
            if not cpp_file.exists():
                cpp_file.write_text(cpp_template)
            
            in_file = prob_folder / "a.in"
            if not in_file.exists():
                in_file.touch()
        
        print(f"Categoría '{category}' creada con {len(problems)} problemas.")

if __name__ == "__main__":
    build_structure()
    print("\nEstructura generada")