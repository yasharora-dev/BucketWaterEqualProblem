//
//  main.cpp
//  BucketWaterEqualProblem
//
//  Created by Yash Arora on 09/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

/*
 
 There are n buckets of water with some amount of water.
 Solve by ensuring each bucket has equal water
 you can remove a bucket altogether completely or remove water from the bucket
 minimize water wastage to get equal water in all buckets
 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int computeCost(vector<int> &buckets, int water)
{
    int cost=0;
    int size = buckets.size();
    for(int i=0;i<size;i++)
    {
        if(water > buckets[i])
            cost+=buckets[i];
        else
            cost+=buckets[i]-water;
    }
    
    return cost;
}


void MinCostMakeWaterEqual(vector<int> &buckets, int &waterLeftInBuckets, int &wastage)
{
    int size = buckets.size();
    
    sort(buckets.begin(),buckets.end());
    vector<int> Table;
    
    for(int i=0;i<size;i++)
    {
        Table.push_back(computeCost(buckets, buckets[i]));
    }
    
    //int minCostLevelIndex = findMinCostIndex(Table);
    int minCost = *min_element(Table.begin(), Table.end());
    int minCostLevelIndex = (std::find(Table.begin(),Table.end(),minCost) - Table.begin());
    
    waterLeftInBuckets = buckets[minCostLevelIndex];
    wastage = minCost;
}

void Test1()
{
    vector<int> buckets {7,10,30,41,50,90,1};
    int waterLeftInBuckets=0;
    int wastage=0;
    
    MinCostMakeWaterEqual(buckets,waterLeftInBuckets,wastage);
    cout<<"Water left in all buckets: "<<waterLeftInBuckets<<endl;
    cout<<"Water wastage: "<<wastage<<endl;
}

void Test2()
{
    vector<int> buckets {4,7,8,12,15,20};
    int waterLeftInBuckets=0;
    int wastage=0;
    
    MinCostMakeWaterEqual(buckets,waterLeftInBuckets,wastage);
    cout<<"Water left in all buckets: "<<waterLeftInBuckets<<endl;
    cout<<"Water wastage: "<<wastage<<endl;
}

void Test3()
{
    vector<int> buckets {4,7,8,12,15,100};
    int waterLeftInBuckets=0;
    int wastage=0;
    
    MinCostMakeWaterEqual(buckets,waterLeftInBuckets,wastage);
    cout<<"Water left in all buckets: "<<waterLeftInBuckets<<endl;
    cout<<"Water wastage: "<<wastage<<endl;
}
int main(int argc, const char * argv[]) {
    Test1();
    Test2();
    Test3();
    return 0;
}
