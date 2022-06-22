class Prisma {
  double ancho;
  double alto;
  double profundidad;
  Prisma(double an, double al, double p) {
    this.ancho = an;
    this.alto = al;
    this.profundidad = p;
  }
  double volumen() {
    return ancho * alto * profundidad;
  }
}

class PrismaDemo1 {
  public static void main(String[] args) {
    Prisma miPrisma1 = new Prisma(10,20,15);
    Prisma miPrisma2 = new Prisma(3,6,8);
    double vol;
    vol = miPrisma1.volumen();
    System.out.println("El volumen es " + vol);
    vol = miPrisma2.volumen();
    System.out.println("El volumen es " + vol);
  }
}
