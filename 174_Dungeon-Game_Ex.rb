# from https://leetcode.com/problems/dungeon-game/discuss/52805/Best-solution-I-have-found-with-explanations
def calculate_minimum_hp(dungeon)
    $board_tracker = Array.new(dungeon.length)

    for i in 0...dungeon.length
        $board_tracker[i] = Array.new(dungeon[0].length)
    end

    # recursive_funct(dungeon,0,0)

    # $board_tracker[dungeon.length-1][dungeon[0].length-1] = [ 1 - dungeon[dungeon.length - 1][dungeon[0].length - 1], 1].max

    i = dungeon.length - 1
    while i >= 0
        j = dungeon[0].length - 1
        while j >= 0
            if i == dungeon.length - 1 && j == dungeon[0].length - 1
                $board_tracker[i][j] = [ 1 - dungeon[i][j], 1].max
            elsif i == dungeon.length - 1
                $board_tracker[i][j] = [1,$board_tracker[i][j+1] - dungeon[i][j] ].max
            
            elsif j == dungeon[0].length - 1
                $board_tracker[i][j] = [1,$board_tracker[i+1][j] - dungeon[i][j] ].max

            else
            $board_tracker[i][j] = [ [$board_tracker[i+1][j],$board_tracker[i][j+1]].min - dungeon[i][j], 1].max
            end
            j-=1
        end
        i-=1
    end
        
    # puts "board: #{dungeon}"
    # puts "board_tracker: #{$board_tracker}, length: m: #{dungeon.length} n:#{dungeon[0].length}"

    # return  $board_tracker[dungeon.length-1][dungeon[0].length-1].abs+1
    return  $board_tracker[0][0].abs
end

#cases: does it handle multiple paths w/ = cost
#case 1: Min Initial HP = 0
puts "result: 1 = #{calculate_minimum_hp [[0]]}"
# puts "result: 1 = #{calculate_minimum_hp [[0,0,0],[0,0,0],[0,0,0]]}"
# puts "result: 1 = #{calculate_minimum_hp [[1,1,1],[1,1,1],[1,1,1]]}"
# puts "result: 1 = #{calculate_minimum_hp [[0,0,0,0],[0,0,0,0],[0,0,0,0]]}"

# #case 2: Min Initial HP < 0 no matter what path
# puts "result: 2=#{calculate_minimum_hp [[0,0,0],[0,0,-1],[0,-1,0]]}"
# puts "result: 1=#{calculate_minimum_hp [[1,1,1],[1,1,1],[1,1,1]]}"
# puts "result: 7=#{calculate_minimum_hp [[1,1,1],[1,1,1],[1,1,-10]]}"

# #case 3: all paths are equally bad
# puts "result: 6=#{calculate_minimum_hp [[-1,-1,-1],[-1,-1,-1],[-1,-1,-1]]}"

# #case 4: does it handle single good path
# puts "result: 9=#{calculate_minimum_hp [[-1,-2,-3],[-1,-2,-3],[-1,-2,-3]]}"
# puts "result: 7=#{calculate_minimum_hp [[-2,-3,3],[-5,-10,1],[10,30,-5]]}"
# puts "result: 3=#{calculate_minimum_hp [[1,-3,3],[0,-2,0],[-3,-3,-3]]}"
