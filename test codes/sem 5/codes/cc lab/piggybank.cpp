int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int e, f, n;
        cin >> e >> f >> n;
        int w = f - e;
        vector<int> p(n), c(n);
        for (int j = 0; j < n; j++) {
            cin >> p[j] >> c[j];
        }

        vector<int> dp(w+1, -1);
        dp[0] = 0;

        for (int j = 0; j < n; j++) {
            for (int k = c[j]; k <= w; k++) {
                if (dp[k-c[j]] != -1) {
                    if (dp[k] == -1 || dp[k] > dp[k-c[j]] + p[j]) {
                        dp[k] = dp[k-c[j]] + p[j];
                    }
                }
            }
        }

        if (dp[w] == -1) {
            cout << "This is impossible.\n";
        } else {
            cout << "The minimum amount of money in the piggy-bank is " << dp[w] << ".\n";
        }
    }

    return 0;