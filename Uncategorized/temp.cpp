std::pair<long long, std::vector<std::vector<int>>> get_best(int, int, int);
        
std::pair<long long, std::vector<std::vector<int>>> get_best(int numcars, int numtrucks, int cursum) {
    int curtotalweight = 0;
    long long curbest = 0x3f3f3f3f3f3f3f3f;
    int bestcnt = 0;
    std::vector<std::vector<int>> ans;
    if (!numtrucks) {
        return {0, ans};
    }
    if (!numcars) {
        for (int i = 0; i < numtrucks; ++i) {
            std::vector<int> temp;
            ans.emplace_back(temp);
        }
        return {cursum * 1LL * numtrucks, ans};
    }
    for (int i = numcars - 1; i >= 0; --i) {
        curtotalweight += carWeights[i];
        auto temp = get_best(i, numtrucks - 1, curtotalweight);
        for (auto &j: temp.second) {
            int acc = 0;
            for (auto &k: j) {
                acc += j;
            }
            temp.first += abs(cursum - acc);
        }
        if (temp.first < curbest) {
            curbest = temp.first;
            bestcnt = numcars - i;
            ans = temp.second;
        }
    }
    std::vector<int> curtruckload;
    for (int i = 0; i < bestcnt; ++i) {
        curtruckload.emplace_back(carWeights[numcars - bestcnt + i]);
    }
    ans.emplace_back(curtruckload);
    return {curbest, ans};
}

std::vector<std::vector<int>> optimalCarsToTrucks(std::vector<int> carWeights, int numTrucks) {
    // (1 car on 1 truck), (1 car on 2 trucks), ..., (1 car on n trucks)
    // (2 cars on 1 truck), (2 cars on 2 trucks), ..., (2 cars on n trucks)
    // ...
    // (m cars on 1 truck), (m cars on 2 trucks), ..., (m cars on n trucks)
    // (m, n) = min()
    
    // recursion:
    
    std::vector<std::vector<int>> sol;
    
    int lastcartotalweight = 0;
    long long totbest = 0x3f3f3f3f3f3f3f3f;
    int lastcnt = 0;
    int totalcars = carWeights.size();
    for (int i = totalcars - 1; i >= 0; --i) {
        lastcartotalweight += carWeights[i];
        auto temp = get_best(i, numTrucks - 1, lastcartotalweight);
        if (temp.first < totbest) {
            totbest = temp.first;
            lastcnt = totalcars - i;
            sol = temp.second;
        }
    }
    std::vector<int> curtruckload;
    for (int i = 0; i < lastcnt; ++i) {
        curtruckload.emplace_back(carWeights[totalcars - lastcnt + i]);
    }
    sol.emplace_back(curtruckload);
    return sol;
    
}
