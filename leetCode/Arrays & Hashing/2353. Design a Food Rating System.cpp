class FoodRatings {
    unordered_map<string,int> foodRatings;
    unordered_map<string,string> foodCuisines;
    unordered_map<string,multiset<pair<int,string>>> foodGroups;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size = foods.size();

        for(int i = 0 ; i < size ; ++i)
        {
            foodRatings[foods[i]] = ratings[i];
            foodCuisines[foods[i]] = cuisines[i];
            foodGroups[cuisines[i]].insert(make_pair(ratings[i] , foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisines[food];

        // Find the target element in the group
        auto it1 = foodGroups[cuisine].lower_bound(make_pair(foodRatings[food] , food));

        // Erase the older rating and insert the new one
        foodGroups[cuisine].erase(it1);
        foodGroups[cuisine].insert(make_pair(newRating , food)); 

        // Update the rating  
        foodRatings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        int maxVal = (*foodGroups[cuisine].rbegin()).first;

        // Return the lexicographically smallest name
        return (*foodGroups[cuisine].lower_bound(make_pair(maxVal , ""))).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
