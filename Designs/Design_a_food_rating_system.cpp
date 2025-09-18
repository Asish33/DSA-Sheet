class FoodRatings {
public:
    struct Compare {
        bool operator()(const pair<string, int>& a,
                        const pair<string, int>& b) const {
            if (a.second == b.second)
                return a.first < b.first;  // lexicographically smaller food first
            return a.second > b.second;    // larger rating first
        }
    };

    unordered_map<string, set<pair<string, int>, Compare>> cuisineSets;
    unordered_map<string, string> foodCuisine;  
    unordered_map<string, int> foodRating;     

    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            cuisineSets[cuisine].insert({food, rating});
            foodCuisine[food] = cuisine;
            foodRating[food] = rating;
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];

        cuisineSets[cuisine].erase({food, oldRating});
        cuisineSets[cuisine].insert({food, newRating});
        foodRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        return cuisineSets[cuisine].begin()->first;
    }
};
