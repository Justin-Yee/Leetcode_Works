

def set_zeroes(matrix)
    m = matrix.size
    n = matrix[0].size
    puts " m:#{m} n:#{n}"
    for i in 0...m
        for j in 0...n
            if matrix[i][j] == 0
                matrix[i][j] = nil
            end
            puts " i:#{i} j:#{j}"
        end
    end

    for i in 0...m
        for j in 0...n
            if matrix[i][j] == nil
                #convert entire row/col to 0
                for x in 0...m
                    unless matrix[x][j] == nil
                        matrix[x][j] = 0 
                    end
                end
                for y in 0...n
                    unless matrix[i][y] == nil
                        matrix[i][y] = 0
                    end
                end
                matrix[i][j] = 0
            end
        end
    end
    
    return matrix
end

puts "[[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]\n#{set_zeroes([[0,1,2,0],[3,4,5,2],[1,3,1,5]])}"