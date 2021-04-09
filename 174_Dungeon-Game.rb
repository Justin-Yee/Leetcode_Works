
def recursive_funct(dungeon,i,j,curr_hp = 0,min_hp =0)

    #check hp in current tile
        #if get healed or 0; then add
        #else negative
            #if beyond curr hp; drop min hp
            #else drop curr hp
    if dungeon[i][j] >= 0
        curr_hp += dungeon[i][j]
    else
        if dungeon[i][j].abs() > curr_hp
            min_hp += dungeon[i][j] + curr_hp 
            curr_hp = 0
        else
            curr_hp += dungeon[i][j]
        end
    end

    #check global board
        # If not empty; compare
            # If This square is better; place and continue
            # Else end calculating this path
        # Else place
    if $board_tracker[i][j] != nil #!$board_tracker[i][j]&.nil?
        if $board_tracker[i][j] < min_hp
            $board_tracker[i][j] = min_hp
        else 
            return
        end
    else
        $board_tracker[i][j] = min_hp
    end

    puts " Recursive: i #{i}, j: #{j}  curr: #{curr_hp} min: #{min_hp}"

    #go right if possible
    recursive_funct(dungeon,i+1,j,curr_hp,min_hp) if (i+1) < dungeon.length
    #go down if possible
    recursive_funct(dungeon,i,j+1,curr_hp,min_hp) if (j+1) < dungeon[0].length
    
    return
end

def calculate_minimum_hp(dungeon)
    $board_tracker = Array.new(dungeon.length)

    for i in 0...dungeon.length
        $board_tracker[i] = Array.new(dungeon[0].length)
    end

    # recursive_funct(dungeon,0,0)

    $board_tracker[dungeon.length-1][dungeon[0].length-1] = [ 1 - dungeon[dungeon.length - 1][dungeon[0].length - 1], 1].max

    i = dungeon.length - 1
    j = dungeon[0].length - 1
    while i >= 0
        while j >= 0

            puts "i: #{i} j: #{j}"
            $board_tracker[i][j] = [ [$board_tracker[i+1][j],$board_tracker[i][j+1]].min - dungeon[i][j], 1].max
            j-=1
        end
        i-=1
    end

    puts "board: #{dungeon}"
    puts "board_tracker: #{$board_tracker}, length: m: #{dungeon.length} n:#{dungeon[0].length}"

    return  $board_tracker[dungeon.length-1][dungeon[0].length-1].abs+1

end

#cases: does it handle multiple paths w/ = cost
#case 1: Min Initial HP = 0
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
puts "result: 3=#{calculate_minimum_hp [[1,-3,3],[0,-2,0],[-3,-3,-3]]}"
