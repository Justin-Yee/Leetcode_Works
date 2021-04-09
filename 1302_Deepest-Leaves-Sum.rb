

class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val = 0, left = nil, right = nil)
        @val = val
        @left = left
        @right = right
    end
end

def deepest_leaves_sum(root)
    queue = Queue.new 
    if root.val != nil
    queue << root
    end
    tot_val = 0
    while !queue.empty?
        tot_val = 0
        size = queue.size
        for i in 0...size
            temp = queue.pop
            tot_val += temp.val

            if temp.left != nil
                queue << temp.left
            end
            if temp.right != nil
                queue << temp.right
            end
        end
    end

    return tot_val
end


root = TreeNode.new(3, TreeNode.new(3,nil,nil), TreeNode.new(2,nil,nil))

puts "5 = #{deepest_leaves_sum(root)}"