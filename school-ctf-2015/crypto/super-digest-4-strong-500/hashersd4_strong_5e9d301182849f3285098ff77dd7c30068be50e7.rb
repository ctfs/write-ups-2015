class Hasher
    @@sd4_strong_iv = 0xdeadbeef
    @@sd4_block_size = 4
    @@sd4_strong_alphabet = "abcdefghijklmnopqrstuvwxyz_"
    def sd4_round(special_value, current_block)
        sum = 0
        0.upto(current_block.size()-1) do |i|
            sum = sum + current_block[i]
        end
        sum += special_value
        return sum
    end
    def sd4_strong(line)
        special_value = @@sd4_strong_iv
        if line.size % @@sd4_block_size != 0
            line+="x"*(@@sd4_block_size-line.size % @@sd4_block_size)
            print "line: ", line, "\n"
        end
        (0...line.size).step(@@sd4_block_size) do |i|
            current_block = line[i..i+@@sd4_block_size-1].bytes
            special_value += sd4_round(special_value, current_block)
        end
        return special_value
    end
end

h = Hasher.new
my_line = "1234567887654321"
print "Hash: ",h.sd4_strong(my_line),"\n"
