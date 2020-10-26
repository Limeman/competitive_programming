#! /usr/bin/python3
import sys
import re

def simplify(line):
    exp = line.split()
    i = len(exp) - 1
    while i - 2 >= 0:
        # If the current index matches an evaluateable expression
        if re.search("[0-9]", exp[i]) != None and re.search("[0-9]", exp[i - 1]) != None\
                                              and exp[i - 2] in "*-+":
            # Evaluate the expression
            tmp = str(eval(exp[i - 1] + exp[i - 2] + exp[i]))
            # Save the calculated value
            exp[i] = tmp
            # Remove the other parts of the expression
            exp = exp[:i - 2] + exp[i:]
            i = len(exp) - 1
        else:
            i -= 1
    return " ".join(exp)

def main():
    case_counter = 1
    for line in sys.stdin.readlines():
        print("Case " + str(case_counter) + ": " + simplify(line[:-1]))
        case_counter += 1

if __name__ == "__main__":
    main()