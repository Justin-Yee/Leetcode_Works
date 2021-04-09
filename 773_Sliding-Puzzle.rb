# I got stuck :(

#https://leetcode.com/problems/sliding-puzzle/discuss/113613/C%2B%2B-9-lines-DFS-and-BFS
#https://leetcode.com/problems/sliding-puzzle/discuss/374126/Picture-shows-how-does-the-BFS-work
#https://leetcode.com/problems/sliding-puzzle/discuss/146652/Java-8ms-BFS-with-algorithm-explained

def sliding_puzzle(board)
    target = "123450"
    start = ""

    # board.each do |x| 
    #     x.each do |y|
    #         start += y.to_s
    #     end
    # end
    board.each { |x| x.each { |y| start +=y.to_s}}

    puts start
 
    dir = [ [ 1, 3 ], [ 0, 2, 4 ],
    [ 1, 5 ], [ 0, 4 ], [ 1, 3, 5 ], [ 2, 4 ] ]

    queue= Queue.new
    visited = Hash.new

    queue << start
    visited [:start]
    res = 0
    while !queue.empty?

        size = queue.size
        for i in 0...size

            if(!queue.empty?)
                cur = queue.pop 
            end
            if (cur == target)
                return res
            end

            zero = cur.index('0')
            dir[zero].each do |x|
                nxt = cur
                nxt[zero], nxt[x] = nxt[x], nxt[zero]
                if visited.has_value?(nxt)
                    continue
                end
                # visited.push(nxt)
                visited = {:next => 1}
                queue << nxt
            end

        end
        res += 1
    end

    return -1
end

# The board has 6^1 + 5^1 + 4^1 ... because every spot is unique
# manually solving / brute force will take to long
    #apparenty manual solving w/ breath first is the answer ;/
    #i guess that is the simplest way due to no known other method


# lets think of this like a tree?
    #this will require 6 trees so prob dont think of it as a tree?
#


puts "output: 1= #{sliding_puzzle [[1,2,3],[4,0,5]]}"
puts "output: 5= #{sliding_puzzle [[4,1,2],[5,0,3]]}"
puts "output: -1= #{sliding_puzzle [[1,2,3],[5,4,0]]}"

