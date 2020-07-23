package main;

import game.Player;
import game.vehicles.Car;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static Player loadPlayerFromFile(String playerName)
    {
        File input = new File("users/" + playerName + ".txt");

        String[] data;
        try (BufferedReader bf = new BufferedReader(new FileReader(input))){
            String line = bf.readLine();
            data = line.split(" ");

            return new Player(playerName, data[1], Integer.parseInt(data[2]));
        } catch (IOException e) {
            System.out.println("IO error occured: " + e.getMessage());
        }

        return null;
    }
    
    public static void main(String[] args) {
        Player Daniel = loadPlayerFromFile("Daniel");
        Player Peter = loadPlayerFromFile("Peter");
        Player Richard = loadPlayerFromFile("Richard");
        Player Tamas = loadPlayerFromFile("Tamas");
        Player Zorror = loadPlayerFromFile("Zorror");
        
        Car audi = new Car(230, 8000000);
        Car alfaromeo = new Car(260, 12000000);
        Car opel = new Car(260, 10000000);
        Car ferrari = new Car(400, 50000000);
        Car suzuki = new Car(180, 4000000);
        
        
   }
}
