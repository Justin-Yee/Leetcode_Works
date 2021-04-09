
def max_diff(num)
   x = rand(num.digits.count)
   y1 = rand(0...9)
   y2 = rand(0..9)
   while y1 == y2
       y2 = rand(0..9)
   end

#    puts "num #{num} #{num.digits}"
#    puts "x: #{x} => #{num.digits[x]} y1: #{y1} y2: #{y2}" 

   x = num.digits[x]
   a = 0
   b = 0

   for i in 0..num.digits.count-1
       
       a *= 10
       if x == num.digits[num.digits.count-1-i]
              a += y1
       else
              a += num.digits[num.digits.count-1-i]
       end       

#    puts "a: #{a} i: #{i} => #{num.digits[num.digits.count-1-i]}"#10: #{10**i}
   end
   
   x = num.digits[rand(num.digits.count)]
   for i in 0..num.digits.count-1
       
       b *= 10
       if x == num.digits[num.digits.count-1-i]
              b += y2
       else
              b += num.digits[num.digits.count-1-i]
       end       

#    puts "b: #{b} i: #{i} => #{num.digits[num.digits.count-1-i]}"
   end

   
   ans = a-b

   if (a-b) == 0
       ans = max_diff(num)
   end

   return ans.abs()
end

puts " #{max_diff 555}"
# max_diff 12345
# max_diff 98765
# max_diff 9

