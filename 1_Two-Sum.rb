
    # vector<int> twoSum(vector<int>& nums, int target) {
    #     vector<int> ans;
        
    #     for(int i = 0; i < nums.size(); i++){
    #         for(int j = i+1; j < nums.size(); j++){
    #             if( nums[i] + nums[j] == target){
    #                 ans.push_back(i); ans.push_back(j);
    #                 return ans;
    #             }
    #         }
    #     }
    #     return ans;
    # }

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    puts "two sums"
    for i in 0...nums.length
        for j in i+1...nums.length
            if nums[i] + nums[j] == target
                ans = [i, j]
                return ans
            end
        end
    end
    
end

def sample (*test)
    puts "The number of parameters is #{test.length}"
    for i in 0...test.length
       puts "The parameters are #{test[i]}"
    end
end

 puts two_sum [2,7,11,15], 9