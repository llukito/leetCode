// leetcode number 640 (Solve the Equation)
class Solution {
public:
    string solveEquation(string equation) {
        // we first split into left and right substrings
        pair<string, string> sides = splitEquation(equation);
        string left = sides.first;
        string right = sides.second;

        // then we get x coefficient and number
        pair<int, int> leftVals = parseSide(left);
        pair<int, int> rightVals = parseSide(right);

        int leftX = leftVals.first;
        int leftSum = leftVals.second;
        int rightX = rightVals.first;
        int rightSum = rightVals.second;

        // then we move x coefficients to left and numbers to right
        int coeffX = leftX - rightX;
        int constNum = rightSum - leftSum;

        if (coeffX == 0) {
            return (constNum == 0) ? "Infinite solutions" : "No solution";
        }
        // task said solution would be integer
        return "x=" + to_string(constNum / coeffX);
    }

private:

    pair<string, string> splitEquation(string eq) {
        int pos = eq.find('=');
        return { eq.substr(0, pos), eq.substr(pos + 1) };
    }

    // Parse a side like "+3x-2+4x+5" into {sum of x-coeff, sum of constants}
    static pair<int, int> parseSide(const string& side) {
        int sumX = 0, sumC = 0;
        string term;
        for (int i = 0; i <= side.size(); i++) {
            if (i == side.size() || side[i] == '+' || side[i] == '-') {
                if (!term.empty()) {
                    parseTerm(term, sumX, sumC);
                    term.clear();
                }
                if (i < side.size()) {
                    term.push_back(side[i]);  // start next term’s sign
                }
            }
            else {
                term.push_back(side[i]);
            }
        }
        return { sumX, sumC };
    }

    // parses one term and updates sumX and sumC
    static void parseTerm(string& term, int& sumX, int& sumC) {
        bool isX = (term.find('x') != string::npos);
        int sign = (term[0] == '-') ? -1 : +1;
        // we wanna skip operators to start reading digits if present
        int i = (term[0] == '+' || term[0] == '-') ? 1 : 0;

        // extract numeric part if present
        string numStr;
        while (i < term.size() && isdigit(term[i])) {
            numStr += term[i++];
        }
        int val = numStr.empty() ? 1 : stoi(numStr);

        if (isX) {
            sumX += sign * val;
        }
        else {
            sumC += sign * val;
        }
    }
};
