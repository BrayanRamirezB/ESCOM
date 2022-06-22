import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class K extends JPanel{
 JFrame jf;
 float x, y, dir;
 int level = 1;
 public K(){
    jf = new JFrame("K");
    addMouseListener(new MouseAdapter(){
        public void mousePressed(MouseEvent evt){
            level++;
            repaint();
        }
    });
    jf.add(this);
    jf.setVisible(true);
 }
 public void paintComponent(Graphics g){
    int length = getWidth()/2;
    y = (float)(getHeight()/2 + Math.sin(Math.toRadians(30))*length/2);
    x = this.getWidth()/4;
    g.setColor(Color.white);
    g.fillRect(0, 0, getWidth(), this.getHeight());
    g.setColor(Color.black);
    dir = 0;
    dK(g, length, level);
    dir -= 120;
    drawKoch(g, length, level);
    dir -= 120;
    drawKoch(g, length, level);
 }
 public void dK(Graphics g, double len, int n){
    if (n==0){
        double dirRad = Math.toRadians(dir);
        double xInc = len * Math.cos(dirRad); // x increment
        double yInc = len * Math.sin(dirRad); // y increment
        float x1 = x + (float)xInc;
        float y1 = y + (float)yInc;
        g.drawLine((int)x,(int)y,(int)x1,(int)y1);
        x = x1;
        y = y1;
    }else{
        dK(g, len/=3, --n);
        dir += 60;
        dK(g, len, n);
        dir -= 120;
        dK(g, len, n);
        dir += 60;
        dK(g, len, n);
    }
 }
  public static void main(String [] args){
     new K();
 }
}