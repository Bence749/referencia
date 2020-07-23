package auto;

import auto.utils.Color;

public class Auto {
    private String plate;
    private Color color;
    private int maxSpeed;
    private static int counter = 0;
    
    public Auto(String plate, Color color, int maxSpeed)
    {
        this.plate = plate;
        this.color = color;
        this.maxSpeed = maxSpeed;
        counter++;
    }
    public Auto()
    {
        this.plate = "AAA-000";
        this.color = color.BLUE;
        this.maxSpeed = 120;
        counter++;
    }
    public static boolean faster(Auto x, Auto y)
    {
        return x.maxSpeed > y.maxSpeed;
    }
}
