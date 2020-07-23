package tests;

import game.Player;
import org.junit.Assert;
import org.junit.Test;

public class Tests {
    @Test
    public void PlayerConstNullName()
    {
        assertEquals(new IllegalArgumentException("Error during Construct"), new Player(null, "192.168.12.0", 10000));
    }
}
