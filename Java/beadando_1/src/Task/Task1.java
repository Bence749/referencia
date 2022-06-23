import java.util.Arrays;

/* Task1: slicing and merging on 1 thread, sorting slices is parralelized */
public class Task1 {

  /* Create new sorted array by merging 2 smaller sorted arrays */
  private static int[] merge(int[] arr1, int[] arr2) {
    int result[] = new int[arr1.length + arr2.length];
    int idx1 = 0, idx2 = 0, idxResult = 0;
    
    while(idx1 < arr1.length && idx2 < arr2.length)
    {
        if(arr1[idx1] < arr2[idx2])
            result[idxResult++] = arr1[idx1++];
        else
            result[idxResult++] = arr2[idx2++];
    }
    
    while(idx1 < arr1.length)
    {
        result[idxResult++] = arr1[idx1++];
    }
    
    while(idx2 < arr2.length)
    {
        result[idxResult++] = arr2[idx2++];
    }
    return result;
  }

  /* Creates an array of arrays by slicing a bigger array into smaller chunks */
  private static int[][] slice(int[] arr, int k) {
    int[][] result = new int[k][];
    for(int i = 0; i < k; i++)
    {
        int from = (i * arr.length)/k;
        int to = ((i+1)* arr.length)/k;
        result[i] = Arrays.copyOfRange(arr, from, to);
    }
    
    return result;
  }


  /* Creates a sorted version of any int array */
  public static int[] sort(int[] array) {

    /* Initialize variables */
    int threadNumber = Runtime.getRuntime().availableProcessors();
    Thread[] threadPool = new Thread[threadNumber];
    
    /* Turn initial array into array of smaller arrays */
    int[][] slicedArrays = Task1.slice(array, threadNumber);
    
    /* parralelized sort on the smaller arrays */
    for(int i = 0; i < threadNumber; i++)
    {
        int[] arrayToSort = slicedArrays[i];
        threadPool[i] = new Thread(() -> Arrays.sort(arrayToSort));
        threadPool[i].start();
    }
    
    for(Thread t : threadPool)
    {
        try
        {
            t.join();
        }
        catch(InterruptedException ie)
        {
            ie.printStackTrace();
        }
    }
    
    /* Merge sorted smaller arrays into a singular larger one */
    int[] result = new int[0];
    for(int i = 0; i < slicedArrays.length; i++)
    {
        result = Task1.merge(result, slicedArrays[i]);
    }

    /* Return fully sorted array */
    return result;
  }
}
