struct pair_hash
{
  // unordered_map<pair<int, int>, int, pair_hash> mp;
  size_t operator()(const pair<int, int> &p) const noexcept
  {
    // A common way: combine hashes of the two elements
    // Use bit shifts / XOR to reduce collisions
    return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
  }
};

class MovieRentingSystem {
    unordered_map<int, set<pair<int,int>>> unrentedMovies; // [movie , (price , shop)]
    unordered_map<pair<int,int> , int , pair_hash> checkPrice; // [(shop , movie) , price]
    set<tuple<int,int,int>> rentedMovies; // [price , shop , movie]
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &v : entries) {
            unrentedMovies[v[1]].insert(make_pair(v[2] , v[0]));
            checkPrice[make_pair(v[0] , v[1])] = v[2];
        }
    }
    
    vector<int> search(int movie) {
        auto &st = unrentedMovies[movie];
        vector<int> ans;
        int counter = 0;

        for(auto &it : st)
        {
            if(counter == 5)
             break;

            ans.push_back(it.second);
            counter++;
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = checkPrice[make_pair(shop , movie)];
        unrentedMovies[movie].erase(make_pair(price , shop));
        rentedMovies.insert(make_tuple(price , shop , movie));
    }
    
    void drop(int shop, int movie) {
        int price = checkPrice[make_pair(shop , movie)];
        unrentedMovies[movie].insert(make_pair(price , shop));
        rentedMovies.erase(make_tuple(price , shop , movie));
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int counter = 0;

        for(auto &it : rentedMovies)
        {
            if(counter == 5)
             break;

            vector<int> v = {get<1>(it) , get<2>(it)};
            ans.push_back(v);
            counter++;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
