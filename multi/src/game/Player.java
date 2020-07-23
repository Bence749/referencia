package game;

import game.vehicles.Car;
import java.util.ArrayList;

public class Player {
    private String name;
    private String IP;
    private int money = 0;
    private ArrayList<Car> cars;
    
    public Player(String name, String ip, int money)
    {
        if("".equals(name) && "".equals(ip) && ip.contains(" ") && Integer.parseInt(ip) <= 0 && money < 0)
            throw new IllegalArgumentException("Error during Construct");
        this.name = name;
        this.IP = ip;
        this.money = money;
    }

    public boolean equals( Player x )
    {
        return x.name.equals(this.name) && x.money == this.money && this.cars.equals(x.cars);
    }
}
