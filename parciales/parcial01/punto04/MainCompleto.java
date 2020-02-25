public class Main {

    public static boolean evaluar(Relacion raiz) {
	boolean ret = false;
	if (raiz == null){
	    ret = false;
	}
	else if (raiz instanceof Verdadero){
	    Verdadero v = (Verdadero) raiz;
	    ret = v.obtValor();
	}
	else if (raiz instanceof Falso){
	    Falso f = (Falso) raiz;
	    ret = f.obtValor();
	}
	else{
	    Binario ub = (Binario) raiz;
	    switch(ub.obtOper()){
	    case MAYORIGUALQUE:
		if (evaluar(ub.obtIzq())==false && evaluar(ub.obtDer())==true){
		    ret = false;
		}
		else{
		    ret = true;
		}
		break;
	    case MENORIGUALQUE:
		if (evaluar(ub.obtIzq())==true && evaluar(ub.obtDer())==false){
		    ret = false;
		}
		else{
		    ret = true;
		}
		break;
	    }
        }
	return ret;
    }

    public static void main(String []args) {

	Relacion exprs[] = { new Binario(Operador.MENORIGUALQUE,
					 new Falso(),
					 new Verdadero()),
			     new Binario(Operador.MAYORIGUALQUE,
					 new Falso(),
					 new Verdadero()),
			     new Binario(Operador.MENORIGUALQUE,
					 new Verdadero(),
					 new Verdadero()),
			     new Binario(Operador.MAYORIGUALQUE,
					 new Verdadero(),
					 new Falso())
	};

	for (Relacion expr : exprs) {
	    System.out.println("Valor: " + evaluar(expr));
	}
    }
}
