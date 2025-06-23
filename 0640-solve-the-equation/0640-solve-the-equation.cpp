class Solution {
public:
    string solveEquation(const string& equation) {
        // 1. Split into left/right substrings
        pair<string, string> sides = splitEquation(equation);
        const string& left  = sides.first;
        const string& right = sides.second;

        // 2. Parse each side to get (x-coefficient, constant sum)
        pair<int,int> leftVals  = parseSide(left);
        pair<int,int> rightVals = parseSide(right);

        int leftX    = leftVals.first;
        int leftSum  = leftVals.second;
        int rightX   = rightVals.first;
        int rightSum = rightVals.second;

        // 3. Bring all x’s to LHS, constants to RHS
        int coeffX   = leftX - rightX;
        int constNum = rightSum - leftSum;

        // 4. Solve
        if (coeffX == 0) {
            return (constNum == 0) ? "Infinite solutions"
                                   : "No solution";
        }
        // integer division always exact in valid input
        return "x=" + to_string(constNum / coeffX);
    }

private:
    // Split "ax+b=cx+d" → {"ax+b", "cx+d"}
    static pair<string, string> splitEquation(const string& eq) {
        size_t pos = eq.find('=');
        return { eq.substr(0, pos), eq.substr(pos + 1) };
    }

    // Parse a side like "+3x-2+4x+5" into {sum of x-coeff, sum of constants}
    static pair<int,int> parseSide(const string& side) {
        int sumX = 0, sumC = 0;
        string term;
        for (size_t i = 0; i <= side.size(); ++i) {
            if (i == side.size() || side[i] == '+' || side[i] == '-') {
                if (!term.empty()) {
                    parseTerm(term, sumX, sumC);
                    term.clear();
                }
                if (i < side.size()) {
                    term.push_back(side[i]);  // start next term’s sign
                }
            } else {
                term.push_back(side[i]);
            }
        }
        return { sumX, sumC };
    }

    // Parses one term ("-2", "+3x", "x", "-x") and updates accumulators.
    static void parseTerm(const string& term, int& sumX, int& sumC) {
        bool isX = (term.find('x') != string::npos);
        int sign = (term[0] == '-') ? -1 : +1;
        // start reading digits after optional '+'/'-'
        size_t i = (term[0] == '+' || term[0] == '-') ? 1 : 0;

        // extract numeric part (might be empty for "x" or "-x")
        string numStr;
        while (i < term.size() && isdigit(term[i])) {
            numStr.push_back(term[i++]);
        }
        int val = numStr.empty() ? 1 : stoi(numStr);

        if (isX) {
            sumX += sign * val;
        } else {
            sumC += sign * val;
        }
    }
};
