#!/usr/bin/env ruby

fail 'flag?' unless File.file?('flag')

$stdout.sync = true

limit = ARGV[0].to_i
puts "Hi, I can say #{limit} bytes :P"
s = $stdin.gets.strip!

if s.size > limit || s[/[[:alnum:]]/]
  puts 'oh... I cannot say this, maybe it is too long or too weird :('
  exit
end

puts "I think size = #{s.size} is ok to me."
r = eval(s).to_s
r[64..-1] = '...' if r.size > 64
puts r
