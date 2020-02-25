
class Pato
  def graznar
    puts "Cuack"
  end
end

class Vaca
  def mujir
    puts "Muuu"
  end

  def graznar
    puts "Muuu-Cuack"
  end
end

def utilizarPato pato
  pato.graznar
end
