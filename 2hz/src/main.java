import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import auto.Auto;
import auto.utils.Color;

public class main {
    public static void main()
    {
        try
        {
            File input = new File("input.txt");
            Scanner reader = new Scanner(input);
            ArrayList<Auto> cars = new ArrayList();
            while( reader.hasNextLine() )
            {
                String[] line = reader.nextLine().split(" ");
                cars.add(new Auto(line[0], Color.valueOf(line[1]), Integer.parseInt(line[2])));
            }
        }
        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
        }
    }
}
