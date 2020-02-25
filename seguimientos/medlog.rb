#!/usr/bin/ruby

require './functions'

# main

m = gets.chop.to_i
until $stdin.eof
  n = gets.chop.to_i
  puts "#{medlog n,m}"
end
