package student.first;

import java.util.concurrent.atomic.AtomicBoolean;

public class Peasant extends Unit {

    private static final int HARVEST_WAIT_TIME = 100;
    private static final int HARVEST_AMOUNT = 10;

    private AtomicBoolean isHarvesting = new AtomicBoolean(false);
    private AtomicBoolean isBuilding = new AtomicBoolean(false);

    private Peasant(Base owner) {
        super(owner, UnitType.PEASANT);
    }

    public static Peasant createPeasant(Base owner){
        return new Peasant(owner);
    }

    /**
     * Starts gathering gold.
     */
    public void startMining(){
        // TODO Set isHarvesting to true
        // TODO Start harvesting on a new thread
        // TODO Harvesting: Sleep for HARVEST_WAIT_TIME, then add the resource - HARVEST_AMOUNT
        if(!(isBuilding.get()))
        {
            isHarvesting.set(true);
            Thread mining = new Thread(() -> {
                while(isHarvesting.get())
                {
                    sleepForMsec(HARVEST_WAIT_TIME);
                    getOwner().getResources().addGold(HARVEST_AMOUNT);
                }
            });
            System.out.println("Peasant starting mining");
            mining.start();
        }
    }

    /**
     * Starts gathering wood.
     */
    public void startCuttingWood(){
        // TODO Set isHarvesting to true
        // TODO Start harvesting on a new thread
        // TODO Harvesting: Sleep for HARVEST_WAIT_TIME, then add the resource - HARVEST_AMOUNT
        
        if(!(isBuilding.get()))
        {
            isHarvesting.set(true);
            Thread cuttingWood = new Thread(() -> {
                while(isHarvesting.get())
                {
                    sleepForMsec(HARVEST_WAIT_TIME);
                    getOwner().getResources().addWood(HARVEST_AMOUNT);
                }
            });

            System.out.println("Peasant starting cutting wood");
            cuttingWood.start();
        }
    }

    /**
     * Peasant should stop all harvesting once this is invoked
     */
    public void stopHarvesting(){
        this.isHarvesting.set(false);
    }

    /**
     * Tries to build a certain type of building.
     * Can only build if there are enough gold and wood for the building
     * to be built.
     *
     * @param buildingType Type of the building
     * @return true, if the building process has started
     *         false, if there are insufficient resources
     */
    public boolean tryBuilding(UnitType buildingType){
        // TODO Start building on a separate thread if there are enough resources
        // TODO Use the Resources class' canBuild method to determine
        // TODO Use the startBuilding method if the process can be started
        if(super.getOwner().getResources().canBuild(buildingType.goldCost, buildingType.woodCost))
        {
            Thread building = new Thread( () -> { startBuilding(buildingType); } );
            building.start();
            return true;
        }
        
        return false;
    }

    /**
     * Start building a certain type of building.
     * Keep in mind that a peasant can only build one building at one time.
     *
     * @param buildingType Type of the building
     */
    private void startBuilding(UnitType buildingType){
        // TODO Ensure that only one building can be built at a time - use isBuilding atomic boolean
        // TODO Building steps: Remove cost, build the building, wait the wait time
        // TODO Use Building's createBuilding method to create the building
        if(isHarvesting.get() == true) isHarvesting.set(false);
        if(isBuilding.get() == false)
        {
            isBuilding.set(true);
            super.getOwner().getResources().removeCost(buildingType.goldCost, buildingType.woodCost);
            super.getOwner().getBuildings().add(Building.createBuilding(buildingType, super.getOwner()));
            sleepForMsec(buildingType.buildTime);
            isBuilding.set(false);
        }
    }

    /**
     * Determines if a peasant is free or not.
     * This means that the peasant is neither harvesting, nor building.
     *
     * @return Whether he is free
     */
    public boolean isFree(){
        return !isHarvesting.get() && !isBuilding.get();
    }


}
