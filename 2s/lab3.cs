using System;

public class Vector
{
    private int x, y;
    
    public Vector()
    {
        x = 0;
        y = 0;
    }
    
    public Vector(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
    
    public Vector(Vector other)
    {
        x = other.x;
        y = other.y;
    }
    
    public double GetLength() => Math.Sqrt(x * x + y * y);
    
    public override string ToString()
    {
        return $"({x}, {y})";
    }
    
    public static Vector operator *(Vector v, int scalar)
    {
        return new Vector(v.x * scalar, v.y * scalar);
    }
    
    public static Vector operator -(Vector v1, Vector v2)
    {
        return new Vector(v1.x - v2.x, v1.y - v2.y);
    }
}

class Program
{
    static void Main()
    {
        Vector V1 = new Vector();
        Vector V2 = new Vector(3, 4);
        Vector V3 = new Vector(V2);
        
        V3 = V3 * 2;
        V1 = V3 - V2;
        
        Console.WriteLine("V1: " + V1);
        Console.WriteLine("V2: " + V2);
        Console.WriteLine("V3: " + V3);
    }
}
