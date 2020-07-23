package game.vehicles;

import game.utils.VehicleException;

public class Car extends game.vehicles.Vehicle implements Comparable<Car>{
    private final int maxSpeed;
    private final int price;
    
    public Car(int maxSpeed, int price)
    {
        this.maxSpeed = maxSpeed;
        this.price = price;
        id++;
    }
    
    public String toString() 
    {
        StringBuilder str = new StringBuilder();
        str.append(id + maxSpeed + price);
        return str.toString();
    }
    
    @Override
    public void accelerate( double amount ) throws VehicleException
    {
        if( maxSpeed >= super.getSpeed() + amount )
            super.accelerateCurrentSpeed(amount);
    }

    public int compareTo(Car x) {
        if( maxSpeed == x.maxSpeed )
            if( price < x.price )
                return 1;
        if( maxSpeed < x.maxSpeed )
            return 1;
        return 0;
        
    }
    
    
}
