class Solution {
public:
    int countCollisions(string directions) {
        int n =directions.size();
        int left=0;
        int right =n-1; //collisions are unavoidable.

        while(left < n  && directions[left] == 'L'){
            left++; //no collision is possible
        }

        while(right>= left  && directions[right] == 'R'){
            right--; //no collision is possible
        }
cout << left << " and " << right << endl;

        // stack<char> st;
        int coll = 0;
        for(int i= left; i<=right;i++){
            if(directions[i] != 'S'){
                coll++;  // CAR not stationary will collide.
            }
        }
        // for(char c: directions){
        //     st.push(c);
        //     char top = st.top();
        //     st.pop();
        //     // if(c == 'L' && top == 'L' || c == 'R' && top == 'L' || c == 'L' && top == 'L' || ){
        //     if(c == top){
        //         continue;
        //     }
        //     else if ( c == 'S' && top == 'L' || c=='S' & top == 'R'){
        //         coll+=1;
        //     }
        //     else coll+=2;

        // }
         return coll;
    }
};