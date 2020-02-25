
def gennumbin n
  res = n % 2

  checkbin n
  return res
end

def checkbin n
  res = n % 2 
  if res == 0
     return 1
  end
  if res != 0
     return 0
  end  
end
