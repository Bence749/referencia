import basics.Matrix;

public class main
{
    public static void main(String[] args)
    {
        Matrix n = new Matrix();
        n.identityMatrix(3);
        
        Matrix m = new Matrix();
        float in[][] = {{2, 3, 2}, {3, 2, 1}, {5, 3, 5}};
        m.createMatrix(in);
        Matrix k = Matrix.sumMatrix(n, m);
        Matrix l = new Matrix();
        l.createNullMatrix(2, 3);
        System.out.println(Matrix.asString(n));
        System.out.println(Matrix.asString(m));
        System.out.println(Matrix.asString(k));
        System.out.println(Matrix.asString(l));
        System.out.println(Matrix.asString(k.transposeMatrix()));
    }
}