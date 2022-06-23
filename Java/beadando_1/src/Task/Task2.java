import java.util.Arrays;

/* Task2: no slicing, no bullshit memcopy, parralelized merge */
public class Task2 {

  /* Create new sorted array by merging 2 smaller sorted arrays */
  private static void merge(int[] src, int[] dst, int idx1, int idx2, int end) {
    int idxDst = idx1, mid = idx2;
    while(idx1 < mid && idx2 < end)
    {
        if(src[idx1] < src[idx2])
            dst[idxDst++] = src[idx1++];
        else
            dst[idxDst++] = src[idx2++];
    }
    
    while(idx1 < mid)
    {
        dst[idxDst++] = src[idx1++];
    }
    
    while(idx2 < end)
    {
        dst[idxDst++] = src[idx2++];
    }
    
   }

  /* Recursive core, calls a sibling thread until max depth is reached */
  public static void kernel(int[] src, int[] dst, int start, int end, int depth) {
    /* Single thread sort if bottom has been reached */
    if(depth == 0)
    {
        Arrays.sort(src, start, end);
        for(int i = start; i < end; i++)
            dst[i] = src[i];
    } 
      
    /* Otherwise split task into two recursively */
    else
    {
        Thread siblingThread = new Thread(() -> Task2.kernel(src, dst, start + (int)Math.ceil((end - start)/2), end, depth-1));
        siblingThread.start();
        Task2.kernel(src, dst, start, start + (int)Math.ceil((end - start)/2), depth-1);
        try
        {
            siblingThread.join();
        }
        catch(InterruptedException ie)
        {
            ie.printStackTrace();
        }
        
        Task2.merge(src, dst, start, start + (int)Math.ceil((end - start)/2), end);
    }
    
  }

  /* Creates a sorted version of any int array */
  public static int[] sort(int[] array) {

    /* Initialize variables */
    int[] src = array;
    int[] dst = new int[src.length];
    Arrays.fill(dst, 0);

    /* Calculate optimal depth */
    int minSize   = 1000;
    int procNum   = Runtime.getRuntime().availableProcessors();
    int procDepth = (int) Math.ceil(Math.log(procNum) / Math.log(2));
    int arrDepth  = (int) (Math.log(array.length / minSize) / Math.log(2));
    int optDepth  = Math.max(0, Math.min(procDepth, arrDepth));

    /* Launch recursive core */
    Task2.kernel(src, dst, 0, src.length, optDepth);

    return dst;

  }
}
