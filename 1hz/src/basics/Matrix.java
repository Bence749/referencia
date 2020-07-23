package basics;

import java.lang.StringBuilder;

public class Matrix {
    float[][] matrix;
    public Matrix createNullMatrix(int x, int y)
    {
        this.matrix = new float[x][y];
        return this;
    }
    public Matrix createMatrix(float[][] x)
    {
        this.matrix = x;
        return this;
    }
    public Matrix identityMatrix(int x)
    {
        this.matrix = new float[x][x];
        for(int i = 0; i < x; i++)
            for(int j = 0; j < x; j++)
                this.matrix[i][j] = (i == j) ? 1 : 0;
        return this;
    }
    public Matrix transposeMatrix()
    {
        Matrix out = new Matrix();
        out.matrix = new float [this.matrix[0].length][this.matrix[1].length];
        for(int i = 0; i < this.matrix.length; i++)
            for(int j = 0; j < this.matrix[1].length; j++)
                out.matrix[i][j] = this.matrix[j][i];
        return out;
    }
    public static Matrix sumMatrix(Matrix n, Matrix k)
    {
        Matrix out = new Matrix();
        out.createNullMatrix(n.matrix[0].length, n.matrix[1].length);
        for(int i = 0; i < out.matrix.length; i++)
            for(int j = 0; j < out.matrix[1].length; j++)
                out.matrix[i][j] = n.matrix[i][j] + k.matrix[i][j];
        return out;
    }
    public Matrix subtractionMatrix(Matrix n, Matrix k)
    {
        Matrix out;
        out = n;
        for(int i = 0; i < out.matrix.length; i++)
            for(int j = 0; j < out.matrix.length; i++)
                out.matrix[i][j] -= k.matrix[i][j];
        return out;
    }
    public static String asString(Matrix n)
    {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n.matrix.length; i++)
        {
            for(int j = 0; j < n.matrix[1].length; j++)
                sb.append(n.matrix[i][j]).append(' ');
            sb.append('\n');
        }
        String out = sb.toString();
        return out;
    }
}
