// rating is subtracted from 1e8 because we need highest rating but set sorts in ascending order, 
// therefore subtracting frating from 1e8 will make the highest rating as lowest

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_rating_food;
    set<pair<int, string>> rating_food;
    unordered_map<string, int> food_rating;
    unordered_map<string, string> food_cuisine;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i<foods.size(); i++) {
            cuisine_rating_food[cuisines[i]].insert({1e8-ratings[i], foods[i]});
            rating_food.insert({1e8-ratings[i], foods[i]});
            food_rating[foods[i]] = 1e8-ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        
        auto pr = make_pair(food_rating[food], food);
        
        auto itr = rating_food.find({pr});
        rating_food.erase(itr);
        rating_food.insert({1e8-newRating, food});
        
        food_rating[food] = 1e8-newRating;
        string c = food_cuisine[food];
        
        auto itr2 = cuisine_rating_food[c].find(pr);
        cuisine_rating_food[c].erase(itr2);
        cuisine_rating_food[c].insert({1e8-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisine_rating_food[cuisine].begin()).second;
    }
};
