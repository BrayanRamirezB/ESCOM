public class Coche {
  private String hacer; // hacer el coche
  private int anio; // anio de manufactura del coche
  private String color; // color primario del coche
  
  public void setHacer(String hacer) {
    this.hacer = hacer;
  }
  public void setAnio(int anio) {
    this.anio = anio;
  }
  public void setColor(String color) {
    this.color = color;
  }
  public Coche hacerCopia() {
    Coche coche = new Coche();
    coche.hacer = this.hacer;
    coche.anio = this.anio;
    coche.color = this.color;
    return coche;
  } // fin hacerCopia
  public void visualizar() {
    System.out.printf("hacer= %s\nanio= %s\ncolor= %s\n",
    this.hacer, this.anio, this.color);
  } // fin visualizar
} // fin clase Coche
