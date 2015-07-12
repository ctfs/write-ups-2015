class Hasher
    @@sd4_iv = 0
    @@sd4_block_size = 4
    @@sd4_alphabet = "abcdefghijklmnopqrstuvwxyz"
    def sd4(line)
        special_value = @@sd4_iv
        if line.size % @@sd4_block_size != 0
            line+="x"*(@@sd4_block_size - line.size % @@sd4_block_size)
        end
        (0...line.size).step(@@sd4_block_size) do |i|
            current_block = line[i..i+@@sd4_block_size-1].bytes
            special_value = sd4_round(special_value, current_block)
        end
        return special_value
    end
    def sd4_round(special_value, current_block)
        sum = current_block.inject(0){ |res, elem| res+=elem }
        sum += special_value
        return sum
    end
end

h = Hasher.new
my_string = "my_string"
hash = h.sd4(my_string)
print "Hash: "+hash.to_s+"\n"
