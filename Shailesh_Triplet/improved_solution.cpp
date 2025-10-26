#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to check if a triplet {a, b, c} is valid for the *real* problem
// A+B+C = 2N, A^B^C = N
bool check(long long n, long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    if (a == b || a == c || b == c) return false;
    
    if ((a + b + c) == (2 * n) && (a ^ b ^ c) == n) {
        vector<long long> result = {a, b, c};
        sort(result.begin(), result.end());
        cout << result[0] << " " << result[1] << " " << result[2] << "\n";
        return true;
    }
    return false;
}

// Tries to find a solution for A+B+C = 2N, A^B^C = N
void solve(long long n) {
    
    // N must be even for most solutions
    if (n % 2 != 0) {
        cout << "-1\n";
        return;
    }

    // N must be positive
    if (n <= 0) {
         cout << "-1\n";
         return;
    }

    // --- Hypothesis 1 (From Samples N=20, N=52) ---
    // Try A = N+2
    long long s_new1 = n - 2;
    long long xor_new1 = n ^ (n + 2);
    long long and_new_times_2_1 = s_new1 - xor_new1;

    if (and_new_times_2_1 >= 0 && and_new_times_2_1 % 2 == 0) {
        long long and_new1 = and_new_times_2_1 / 2;
        if ((and_new1 & xor_new1) == 0) {
            long long a = n + 2;
            long long b = xor_new1 + and_new1;
            long long c = and_new1;
            if (check(n, a, b, c)) return;
        }
    }

    // --- Hypothesis 2 (Try A = N/2) ---
    // Check if 3N/2 is integer (N must be even)
    if (n % 2 == 0) {
        long long s_new2 = (3 * n) / 2;
        long long xor_new2 = n ^ (n / 2);
        long long and_new_times_2_2 = s_new2 - xor_new2;

        if (and_new_times_2_2 >= 0 && and_new_times_2_2 % 2 == 0) {
            long long and_new2 = and_new_times_2_2 / 2;
            if ((and_new2 & xor_new2) == 0) {
                long long a = n / 2;
                long long b = xor_new2 + and_new2;
                long long c = and_new2;
                if (check(n, a, b, c)) return;
            }
        }
    }
    
    // --- NEW Hypothesis 3 (Try C = 2) ---
    // A+B = 2N - 2
    // A^B = N ^ 2
    long long s_new3 = 2 * n - 2;
    long long xor_new3 = n ^ 2;
    long long and_new_times_2_3 = s_new3 - xor_new3;

    if (and_new_times_2_3 >= 0 && and_new_times_2_3 % 2 == 0) {
        long long and_new3 = and_new_times_2_3 / 2;
        if ((and_new3 & xor_new3) == 0) {
            long long a = xor_new3 + and_new3;
            long long b = and_new3;
            long long c = 2;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 4 (Try C = 4) ---
    // A+B = 2N - 4
    // A^B = N ^ 4
    long long s_new4 = 2 * n - 4;
    long long xor_new4 = n ^ 4;
    long long and_new_times_2_4 = s_new4 - xor_new4;

    if (and_new_times_2_4 >= 0 && and_new_times_2_4 % 2 == 0) {
        long long and_new4 = and_new_times_2_4 / 2;
        if ((and_new4 & xor_new4) == 0) {
            long long a = xor_new4 + and_new4;
            long long b = and_new4;
            long long c = 4;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 5 (Try A = N+4) ---
    // A+B = 2N - (N+4) = N - 4
    // A^B = N ^ (N+4)
    long long s_new5 = n - 4;
    long long xor_new5 = n ^ (n + 4);
    long long and_new_times_2_5 = s_new5 - xor_new5;

    if (and_new_times_2_5 >= 0 && and_new_times_2_5 % 2 == 0) {
        long long and_new5 = and_new_times_2_5 / 2;
        if ((and_new5 & xor_new5) == 0) {
            long long a = n + 4;
            long long b = xor_new5 + and_new5;
            long long c = and_new5;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 6 (Try C = N/2 + 2) ---
    if (n % 2 == 0) {
        long long c6 = (n / 2) + 2;
        long long s_new6 = 2 * n - c6;
        long long xor_new6 = n ^ c6;
        long long and_new_times_2_6 = s_new6 - xor_new6;

        if (and_new_times_2_6 >= 0 && and_new_times_2_6 % 2 == 0) {
            long long and_new6 = and_new_times_2_6 / 2;
            if ((and_new6 & xor_new6) == 0) {
                long long a = xor_new6 + and_new6;
                long long b = and_new6;
                if (check(n, a, b, c6)) return;
            }
        }
    }
    
    // --- NEW Hypothesis 7 (Try C = 8) ---
    long long s_new7 = 2 * n - 8;
    long long xor_new7 = n ^ 8;
    long long and_new_times_2_7 = s_new7 - xor_new7;

    if (and_new_times_2_7 >= 0 && and_new_times_2_7 % 2 == 0) {
        long long and_new7 = and_new_times_2_7 / 2;
        if ((and_new7 & xor_new7) == 0) {
            long long a = xor_new7 + and_new7;
            long long b = and_new7;
            long long c = 8;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 8 (Try A = Highest bit of N) ---
    if (n > 0) {
        long long h = 1LL << (63 - __builtin_clzll(n));
        long long s_new8 = 2 * n - h;
        long long xor_new8 = n ^ h;
        long long and_new_times_2_8 = s_new8 - xor_new8;

        if (and_new_times_2_8 >= 0 && and_new_times_2_8 % 2 == 0) {
            long long and_new8 = and_new_times_2_8 / 2;
            if ((and_new8 & xor_new8) == 0) {
                long long a = h;
                long long b = xor_new8 + and_new8;
                long long c = and_new8;
                if (check(n, a, b, c)) return;
            }
        }
    }

    // --- NEW Hypothesis 9 (Try C = 1) ---
    // A+B = 2N - 1
    // A^B = N ^ 1
    long long s_new9 = 2 * n - 1;
    long long xor_new9 = n ^ 1;
    long long and_new_times_2_9 = s_new9 - xor_new9;

    if (and_new_times_2_9 >= 0 && and_new_times_2_9 % 2 == 0) {
        long long and_new9 = and_new_times_2_9 / 2;
        if ((and_new9 & xor_new9) == 0) {
            long long a = xor_new9 + and_new9;
            long long b = and_new9;
            long long c = 1;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 10 (Try C = 16) ---
    long long s_new10 = 2 * n - 16;
    long long xor_new10 = n ^ 16;
    long long and_new_times_2_10 = s_new10 - xor_new10;

    if (and_new_times_2_10 >= 0 && and_new_times_2_10 % 2 == 0) {
        long long and_new10 = and_new_times_2_10 / 2;
        if ((and_new10 & xor_new10) == 0) {
            long long a = xor_new10 + and_new10;
            long long b = and_new10;
            long long c = 16;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 11 (Try A = N-2) ---
    if (n - 2 > 0) {
        long long s_new11 = n + 2;
        long long xor_new11 = n ^ (n - 2);
        long long and_new_times_2_11 = s_new11 - xor_new11;

        if (and_new_times_2_11 >= 0 && and_new_times_2_11 % 2 == 0) {
            long long and_new11 = and_new_times_2_11 / 2;
            if ((and_new11 & xor_new11) == 0) {
                long long a = n - 2;
                long long b = xor_new11 + and_new11;
                long long c = and_new11;
                if (check(n, a, b, c)) return;
            }
        }
    }

    // --- NEW Hypothesis 12 (Try A = N-4) ---
    if (n - 4 > 0) {
        long long s_new12 = n + 4;
        long long xor_new12 = n ^ (n - 4);
        long long and_new_times_2_12 = s_new12 - xor_new12;

        if (and_new_times_2_12 >= 0 && and_new_times_2_12 % 2 == 0) {
            long long and_new12 = and_new_times_2_12 / 2;
            if ((and_new12 & xor_new12) == 0) {
                long long a = n - 4;
                long long b = xor_new12 + and_new12;
                long long c = and_new12;
                if (check(n, a, b, c)) return;
            }
        }
    }

    // --- NEW Hypothesis 13 (Try C = 32) ---
    long long s_new13 = 2 * n - 32;
    long long xor_new13 = n ^ 32;
    long long and_new_times_2_13 = s_new13 - xor_new13;

    if (and_new_times_2_13 >= 0 && and_new_times_2_13 % 2 == 0) {
        long long and_new13 = and_new_times_2_13 / 2;
        if ((and_new13 & xor_new13) == 0) {
            long long a = xor_new13 + and_new13;
            long long b = and_new13;
            long long c = 32;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 14 (Try A = N+8) ---
    long long s_new14 = n - 8;
    long long xor_new14 = n ^ (n + 8);
    long long and_new_times_2_14 = s_new14 - xor_new14;

    if (and_new_times_2_14 >= 0 && and_new_times_2_14 % 2 == 0) {
        long long and_new14 = and_new_times_2_14 / 2;
        if ((and_new14 & xor_new14) == 0) {
            long long a = n + 8;
            long long b = xor_new14 + and_new14;
            long long c = and_new14;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 15 (Try A = N-8) ---
    if (n - 8 > 0) {
        long long s_new15 = n + 8;
        long long xor_new15 = n ^ (n - 8);
        long long and_new_times_2_15 = s_new15 - xor_new15;

        if (and_new_times_2_15 >= 0 && and_new_times_2_15 % 2 == 0) {
            long long and_new15 = and_new_times_2_15 / 2;
            if ((and_new15 & xor_new15) == 0) {
                long long a = n - 8;
                long long b = xor_new15 + and_new15;
                long long c = and_new15;
                if (check(n, a, b, c)) return;
            }
        }
    }

    // --- NEW Hypothesis 16 (Try C = N/2 - 2) ---
    if (n % 2 == 0 && (n / 2) - 2 > 0) {
        long long c16 = (n / 2) - 2;
        long long s_new16 = 2 * n - c16;
        long long xor_new16 = n ^ c16;
        long long and_new_times_2_16 = s_new16 - xor_new16;

        if (and_new_times_2_16 >= 0 && and_new_times_2_16 % 2 == 0) {
            long long and_new16 = and_new_times_2_16 / 2;
            if ((and_new16 & xor_new16) == 0) {
                long long a = xor_new16 + and_new16;
                long long b = and_new16;
                if (check(n, a, b, c16)) return;
            }
        }
    }

    // --- NEW Hypothesis 17 (Try C = 64) ---
    long long s_new17 = 2 * n - 64;
    long long xor_new17 = n ^ 64;
    long long and_new_times_2_17 = s_new17 - xor_new17;

    if (and_new_times_2_17 >= 0 && and_new_times_2_17 % 2 == 0) {
        long long and_new17 = and_new_times_2_17 / 2;
        if ((and_new17 & xor_new17) == 0) {
            long long a = xor_new17 + and_new17;
            long long b = and_new17;
            long long c = 64;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 18 (Try A = N+16) ---
    long long s_new18 = n - 16;
    long long xor_new18 = n ^ (n + 16);
    long long and_new_times_2_18 = s_new18 - xor_new18;

    if (and_new_times_2_18 >= 0 && and_new_times_2_18 % 2 == 0) {
        long long and_new18 = and_new_times_2_18 / 2;
        if ((and_new18 & xor_new18) == 0) {
            long long a = n + 16;
            long long b = xor_new18 + and_new18;
            long long c = and_new18;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 19 (Try A = N-16) ---
    if (n - 16 > 0) {
        long long s_new19 = n + 16;
        long long xor_new19 = n ^ (n - 16);
        long long and_new_times_2_19 = s_new19 - xor_new19;

        if (and_new_times_2_19 >= 0 && and_new_times_2_19 % 2 == 0) {
            long long and_new19 = and_new_times_2_19 / 2;
            if ((and_new19 & xor_new19) == 0) {
                long long a = n - 16;
                long long b = xor_new19 + and_new19;
                long long c = and_new19;
                if (check(n, a, b, c)) return;
            }
        }
    }

    // --- NEW Hypothesis 20 (Try C = N/2 + 4) ---
    if (n % 2 == 0) {
        long long c20 = (n / 2) + 4;
        long long s_new20 = 2 * n - c20;
        long long xor_new20 = n ^ c20;
        long long and_new_times_2_20 = s_new20 - xor_new20;

        if (and_new_times_2_20 >= 0 && and_new_times_2_20 % 2 == 0) {
            long long and_new20 = and_new_times_2_20 / 2;
            if ((and_new20 & xor_new20) == 0) {
                long long a = xor_new20 + and_new20;
                long long b = and_new20;
                if (check(n, a, b, c20)) return;
            }
        }
    }

    // --- NEW Hypothesis 21 (Try C = N/2 - 4) ---
    if (n % 2 == 0 && (n / 2) - 4 > 0) {
        long long c21 = (n / 2) - 4;
        long long s_new21 = 2 * n - c21;
        long long xor_new21 = n ^ c21;
        long long and_new_times_2_21 = s_new21 - xor_new21;

        if (and_new_times_2_21 >= 0 && and_new_times_2_21 % 2 == 0) {
            long long and_new21 = and_new_times_2_21 / 2;
            if ((and_new21 & xor_new21) == 0) {
                long long a = xor_new21 + and_new21;
                long long b = and_new21;
                if (check(n, a, b, c21)) return;
            }
        }
    }

    // --- NEW Hypothesis 22 (Try A = N/2 + 4) ---
    if (n % 2 == 0) {
        long long a22 = (n / 2) + 4;
        long long s_new22 = 2 * n - a22;
        long long xor_new22 = n ^ a22;
        long long and_new_times_2_22 = s_new22 - xor_new22;

        if (and_new_times_2_22 >= 0 && and_new_times_2_22 % 2 == 0) {
            long long and_new22 = and_new_times_2_22 / 2;
            if ((and_new22 & xor_new22) == 0) {
                long long b = xor_new22 + and_new22;
                long long c = and_new22;
                if (check(n, a22, b, c)) return;
            }
        }
    }

    // --- NEW Hypothesis 23 (Try A = N/2 - 4) ---
    if (n % 2 == 0 && (n / 2) - 4 > 0) {
        long long a23 = (n / 2) - 4;
        long long s_new23 = 2 * n - a23;
        long long xor_new23 = n ^ a23;
        long long and_new_times_2_23 = s_new23 - xor_new23;

        if (and_new_times_2_23 >= 0 && and_new_times_2_23 % 2 == 0) {
            long long and_new23 = and_new_times_2_23 / 2;
            if ((and_new23 & xor_new23) == 0) {
                long long b = xor_new23 + and_new23;
                long long c = and_new23;
                if (check(n, a23, b, c)) return;
            }
        }
    }

    // --- NEW Hypothesis 24 (Try C = N+1) ---
    long long s_new24 = n - 1;
    long long xor_new24 = n ^ (n + 1);
    long long and_new_times_2_24 = s_new24 - xor_new24;

    if (and_new_times_2_24 >= 0 && and_new_times_2_24 % 2 == 0) {
        long long and_new24 = and_new_times_2_24 / 2;
        if ((and_new24 & xor_new24) == 0) {
            long long a = xor_new24 + and_new24;
            long long b = and_new24;
            long long c = n + 1;
            if (check(n, a, b, c)) return;
        }
    }

    // --- NEW Hypothesis 25 (Try C = N-1) ---
    if (n - 1 > 0) {
        long long s_new25 = n + 1;
        long long xor_new25 = n ^ (n - 1);
        long long and_new_times_2_25 = s_new25 - xor_new25;

        if (and_new_times_2_25 >= 0 && and_new_times_2_25 % 2 == 0) {
            long long and_new25 = and_new_times_2_25 / 2;
            if ((and_new25 & xor_new25) == 0) {
                long long a = xor_new25 + and_new25;
                long long b = and_new25;
                long long c = n - 1;
                if (check(n, a, b, c)) return;
            }
        }
    }


    // If no hypothesis worked, fail.
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}


