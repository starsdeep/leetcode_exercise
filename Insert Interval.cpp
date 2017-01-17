#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  		vector<Interval> answer;
  		auto partial_order = [](const Interval& a, const Interval& b){
  			return a.end < b.start;
  		};
  		auto less = lower_bound(intervals.begin(), intervals.end(), newInterval, partial_order);
  		auto greater = upper_bound(intervals.begin(), intervals.end(), newInterval, partial_order);
  		answer.insert(answer.end(), intervals.begin(), less);
  		answer.push_back(merge(less, greater, newInterval));
  		answer.insert(answer.end(), greater, intervals.end());
  		return answer;
    }

    Interval merge(vector<Interval>::iterator& first, vector<Interval>::iterator& larst, Interval& newInterval ){
    	Interval answer(newInterval);
    	if(first<larst){
    		answer.start = min(answer.start, (*first).start);
    		answer.end = max(answer.end, (*(larst-1)).end);
    	}
    	return answer;

    }
};

int main(){

}