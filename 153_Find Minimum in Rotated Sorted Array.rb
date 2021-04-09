
#if first val < last; then first val = smallest
#else there is an offset
    #Linear search go from end of arr to back
    #cannnot skip because we may skip past the ans?
        #or
    #Binary Search
    #what if we took the middle element, compare it to the first
    #if mid > first; then search other half
    #else search first half
        #this may be good to cut half the array out
    #repeat till found


#for all elements
    #if small < ans; then ans = small

def find_min(nums)
 
    lower = 0
    upper = nums.length-1
    
    if nums[lower] > nums[upper]
        while upper-lower > 1 #this breaks for elements of 2
            half = ((upper-lower)/2).floor
            # puts "upper: #{upper} lower: #{lower} half: #{half}"
            # for i in lower...upper+1
            #     puts " i:#{i} #{nums[i]}"
            # end
            if nums[half+lower] > nums[lower]
                lower += half
            else
                upper -= half
            end
            # puts "upper: #{upper} - lower: #{lower} = #{upper-lower}"

        end
        
        return nums[upper]
    end

    return nums[lower]
end

#find the smallest num of the array
puts "1 = #{find_min [3,4,5,1,2]}"

#basic rotation
puts "\n1 = #{find_min [1,2,3,4]}"
puts "1 = #{find_min [2,3,4,1]}"
puts "1 = #{find_min [3,4,1,2]}"
puts "1 = #{find_min [4,1,2,3]}"

#singles
puts "\n1 = #{find_min [1]}"
puts "-1 = #{find_min [-1]}"
puts "0 = #{find_min [0]}"

#negatives 
puts "\n-4 = #{find_min [-1,-2,-3,-4]}"
puts "-4 = #{find_min [-2,-3,-4,-1]}"
puts "-4 = #{find_min [-3,-4,-1,-2]}"
puts "-4 = #{find_min [-4,-1,-2,-3]}"
