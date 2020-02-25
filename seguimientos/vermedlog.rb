#!/usr/bin/ruby

require './functions'

# main

m = gets.chop.to_i
until $stdin.eof
  ns,s = gets.split
  n = ns.to_i
  puts "#{ok? n,m,s}"
end
