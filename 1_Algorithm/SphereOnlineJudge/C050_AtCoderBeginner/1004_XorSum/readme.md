http://abc050.contest.atcoder.jp/tasks/arc066_b
- u = a xor b = a+b-2(a and b) <= a+b = v
- 规定a_i < b_i，避免重复计数
- dp[][][][] 用增量法， 位数依次增加，确定在最低几位的数
