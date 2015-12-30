#!/usr/bin/env ruby

require 'openssl'
require 'timeout'
require 'securerandom'
require 'digest'

$stdout.sync = true
$stdin.binmode

begin
  Timeout::timeout(30) do
    puts "To prove that you're a robot, answer the following question:"
    prefix = SecureRandom.random_bytes(4)
    print "What string has length 8, begins with #{prefix.bytes.map{|x| '%02x' % x}.join(' ')}, and has SHA1 with first 24 bits zero? "
    s = $stdin.read(8)
    if s.size != 8 || s[0...4] != prefix
      puts 'Cheater!'
      exit
    end
    sha = Digest::SHA1.digest(s)
    if sha[0...3] != "\0\0\0".b
      puts 'Wrong!'
      exit
    end

    p = 195589859419604305972182309315916027436941011486827038011731627454673222943892428912238183097741291556130905026403820602489277325267966860236965344971798765628107804393049178848883490619438682809554522593445569865108465536075671326806730534242861732627383004696136244305728794347161769919436748766859796527723

    flag = IO.read('/home/pow/flag').strip
    fail unless flag.size == 50

    flag = flag.unpack('H*')[0].to_i(16)

    loop do
      x = gets
      break if x.nil?
      x = x.to_i
      if x <= 0 || x >= p
        puts 'Bad input :('
        exit 1
      end

      puts x.to_bn.mod_exp(flag, p).to_i
    end
  end
rescue Timeout::Error
  puts 'zzz too slow...'
end
