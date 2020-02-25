
def ok? n, m, s
    ast = "*"
    mod = (n % m) + 1
    res = ast * mod
    
    puts res == s
end