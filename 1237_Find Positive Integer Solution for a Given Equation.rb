# class CustomFunction:
#     def f(self, x, y):
#         Returns f(x, y) for any given positive integers x and y.
#         Note that f(x, y) is increasing with respect to both x and y.
#         i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
#     end
# end

class Customfunction

end


#IT WORKS BUT IM SURE I GOT THE THEORY WRONG
def findSolution(customfunction,z)
    pairs = Array.new

    for x in 1...1000
        for y in 1...1000
            ans = customfunction.f(x,y)
            if ans == z
                pairs << [x,y]
            end
            if ans < 0 || ans > 100
                break
            end
        end
    end
    return pairs
end

puts " #{findSolution(5)}"