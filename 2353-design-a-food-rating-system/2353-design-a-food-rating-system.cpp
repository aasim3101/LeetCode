struct CuisineFoods {
    int rating;
    string name;
    CuisineFoods(const int& _rating, const string& _name){
        rating = _rating;
        name = _name;
    }
    bool operator < (const CuisineFoods& otherFood) const {
        if(rating != otherFood.rating){
            return rating > otherFood.rating;
        }
        return name < otherFood.name;
    }
};
class FoodRatings {
    map<string,set<CuisineFoods> > foodPerCuisine;
    map<string,pair<string,int> > foodsCuisineAndRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++){
            string food=foods[i],cuisine=cuisines[i];
            int rating=ratings[i];
            foodPerCuisine[cuisine].insert(CuisineFoods(rating, food));
            foodsCuisineAndRating[food]={cuisine,rating};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto curr=foodsCuisineAndRating[food];
        auto currCuisine=curr.first;
        auto currRating=curr.second;
        foodPerCuisine[currCuisine].erase(CuisineFoods(currRating, food));
        foodPerCuisine[currCuisine].insert(CuisineFoods(newRating, food));
        foodsCuisineAndRating[food]={currCuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return foodPerCuisine[cuisine].begin()->name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */