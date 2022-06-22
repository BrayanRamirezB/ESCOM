class Prueba {
  int a, b;
  
  Prueba(int i, int j) {
    a = i;
    b = j;
  }
  
  boolean esIgual(Prueba o) {
    if(o.a == a && o.b == b)
      return true;
    else
      return false;
  }
}

class PaseObjetosDriver {
  public static void main(String args[]) { 
    Prueba obj1 = new Prueba(100, 22);
    Prueba obj2 = new Prueba(100, 22);
    Prueba obj3 = new Prueba(10, 2);
  
    System.out.println("obj1 == obj2:" + obj1.esIgual(obj2));
  
    System.out.println("obj1 == obj3:" + obj1.esIgual(obj3));
  }
}
    
