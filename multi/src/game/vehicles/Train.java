package game.vehicles;

import game.utils.VehicleException;

public class Train extends game.vehicles.Vehicle {

    @Override
    public void accelerate( double amount ) throws VehicleException
    {
        super.accelerateCurrentSpeed( (amount < 0) ? amount / 10 : amount );
    }
}
