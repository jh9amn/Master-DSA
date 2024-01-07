import java.applet.*;
import java.awt.*;

public class B extends Applet{
    public void init(){
        setBackground(Color.red);
        setForeground(Color.blue);
    }
    public void paint(Graphics g){
        g.drawString("Hello",70,50);
    }
}
