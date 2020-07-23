package game.vehicles;

import game.utils.VehicleException;

public class Vehicle {
    protected static int id = 0;
    private double curSpeed;
    
    
    public double getSpeed() { return curSpeed; }

    protected final void accelerateCurrentSpeed( double x ) throws VehicleException
    {
        if( curSpeed + x < 0 )
            throw new game.utils.VehicleException();
        curSpeed += x;
    }
    
    public void accelerate( double x ) throws VehicleException {};
}
