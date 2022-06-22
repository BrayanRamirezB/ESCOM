class Coche4 {
  private String hacer; // hacer coche
  private int anio; // anio de manufactura del coche
  private String color; // color primario coche

  public Coche4(String h, int a, String c) {
    hacer = h;
    anio = a;
    color = c;
  } // fin constructor
  public Coche4(int a) {
    anio = a;
    color = "Son de color amarillo";
  } // fin constructor
  public String getHacer() {
    return hacer;
  } // fin getHacer
  public int getAnio() {
    return anio;
  } // fin getAnio
  public String getColor() {
    return color;
  } // fin getColor
} // fin clase Coche4

public class Coche4Driver {
  public static void main(String[] args) {
    Coche4 allexCar = new Coche4("Porsche", 2006, "beige"); 
    Coche4 ramirezCar = new Coche4("Saturn", 2002, "rojo");
    System.out.println(allexCar.getHacer() + " " + allexCar.getAnio() + " " + allexCar.getColor());
    System.out.println(ramirezCar.getHacer() + " " + ramirezCar.getAnio() + " " + ramirezCar.getColor());
    Coche4 carroCar = new Coche4(2006);
    System.out.println(carroCar.getColor());
  } // end main
} // end class Car4Driver
