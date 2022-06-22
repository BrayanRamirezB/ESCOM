class Fraccion {
  private int numerador;
  private int denominador;
  private double cociente;

  public Fraccion(int n) {
    this(n, 1);
  }

  public Fraccion(int n, int d) {
    numerador = n;
    denominador = d;
    cociente = (double) numerador / denominador;
  }

  public void printIt() {
    System.out.println(numerador + " / " +
      denominador + " = " + cociente);
  } // fin printIt
} // fin clase Fraccion

public class FraccionDriver {
  public static void main(String[] args) {
    Fraccion a = new Fraccion(3, 4); 
    Fraccion b = new Fraccion(3);

    Fraccion c = new Fraccion(4, 5); 
    Fraccion d = new Fraccion(6);

    a.printIt();
    b.printIt();

    c.printIt();
    d.printIt();
  } // fin main
} // fin clase FraccionDriver
