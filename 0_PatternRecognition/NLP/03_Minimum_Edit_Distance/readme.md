#Minimum Edit Distance
- How similar are two strings?
    - spell correction
    - computational biology
    - edit distance
        - the minimum edit distance between two strings
            - insertion
            - deletion
            - substitution
        - ex.  alignment in computational biology
- How to find the Min Edit Distance?
    1. Dynamic Programming
        - D(n,m) means the edit distance between X[1...n] and Y[1..m]
    1. Backtrace for computing Alignments
        - every time we enter a cell, remember where we came from
        - "An optimal alignment is composed of optimal subalignments"
- Weighted Minimum Edit Distance
    - reasons
        - spell correction: some letters are more likely to be mistyped than others
        - biology: certain kinds of insertion or deletion are more likely


