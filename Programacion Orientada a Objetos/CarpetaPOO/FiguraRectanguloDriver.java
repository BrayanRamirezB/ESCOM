class FiguraRectangular {
  double ancho;
  double alto;
  double largo;
  
  FiguraRectangular(FiguraRectangular obj) {
    ancho = obj.ancho;
    alto = obj.alto;
    largo = obj.largo;
  }
  
  FiguraRectangular() {
    ancho = -1;
    alto = -1;
    largo = -1;
  }
  
  FiguraRectangular(double an, double al, double lar) {
    ancho = an;
    alto = an;
    largo = lar;
  }
  
  FiguraRectangular(double lado) {
    ancho = alto = largo = lado;
  }
  
  double volumen() {
    return ancho * alto * largo;
  }
}

class FiguraRectanguloDriver {
  public static void main(String args[]) {
    FiguraRectangular rec1 = new FiguraRectangular(10, 20, 15);
    FiguraRectangular rec2 = new FiguraRectangular();
    FiguraRectangular cubo = new FiguraRectangular(7);
    
    FiguraRectangular recParecido = new FiguraRectangular(rec1);
    
    double vol;
    
    vol = rec1.volumen();
    System.out.println("El volumen de rec1 es " + vol);
    
    vol = rec2.volumen();
    System.out.println("El volumen de rec2 es " + vol);
    
    vol = cubo.volumen();
    System.out.println("El volumen de cubo es " + vol);
    
    vol = recParecido.volumen();
    System.out.println("El volumen del recParecido es " + vol);
    
  }
}
