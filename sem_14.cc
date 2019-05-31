#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

typedef unordered_multimap<int, bitset<10>> m_map;
//ypedef m_map::iterator m_map_iter;

inline bitset<10> get_digits(int number)
{
	bitset<10> bset;
	while(number != 0)
	{
		int rem = number%10;
		number = number/10;
		bset[rem] = 1;
	}
	return bset;
}

void compute(vector<int> input_set)
{
    vector<int> sum_set = input_set;
    vector<m_map> digit_set;
    

    //for(int i=0; i<input_.set.size();i++)
    //{
        bitset<10> temp = get_digits(input_set[0]);
        m_map t_map;
        t_map.insert(pair<int, bitset<10>>(input_set[0],temp));
        digit_set.emplace_back(t_map);
    //}
    //int count = 0;
    for(int i=1; i<input_set.size();i++)
    {
                 
        bitset<10> temp = get_digits(input_set[i]);
        m_map t_map;
        t_map.reserve(65536);
        t_map.insert(pair<int, bitset<10>>(input_set[i],temp));
        digit_set.push_back(t_map);
        
        for(int j=0; j<i; j++)
        {
            //compare_and_set(digit_set[i],digit_set[j], sum_set[i]);
            bool inserted = false;
            for(auto it : digit_set[i])
            {
                for (auto it1 : digit_set[j])
                {
                    //if(is_set_different(it->second,it1->second))
                    if((it.second & it1.second) == 0)
                    {
                        int sum = it.first + it1.first;
                        sum_set.emplace_back(sum);
                            bitset<10> temp;
                            temp = (it.second | it1.second);
                            digit_set[i].emplace(pair<int, bitset<10>>(sum,temp));
                            //count++;

                    }
                   
                }

            }
            
        }
        
    }
    //cout << "insert count " << count << endl;
    std::vector<int>::iterator result;
    result = std::max_element (sum_set.begin(),sum_set.end());
    cout << *result << endl;
}

int main()
{ 

	int num_tests = 0;
    cin >> num_tests;
	vector<vector<int>> test_set;
	

	for(int i=0; i<num_tests; i++)
    {
		int num_boxes;
		cin >> num_boxes;
		vector<int> input_set;
		for(int j=0; j<num_boxes; j++)
		{
			int number;
			cin >> number;
			input_set.emplace_back(number);
		}
		test_set.emplace_back(input_set);
    }
    
    for(int i=0; i<num_tests; i++)
    {
        //vector<int> input_set = test_set[i];
        
        //sort(input_set.begin(),input_set.end());
        compute(test_set[i]);
	}
    return 0;
}
