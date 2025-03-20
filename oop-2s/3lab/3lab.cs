using System;

class Vector {
    private double x, y;

    public Vector() {
        x = 0; y = 0;
    }

    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Vector(Vector other) {
        x = other.x;
        y = other.y;
    }

    public double Length() {
        return Math.Sqrt(x * x + y * y);
    }

    public double GetX() { return x; }
    public double GetY() { return y; }

    public static Vector operator *(Vector v, double scalar) {
        return new Vector(v.x * scalar, v.y * scalar);
    }

    public static Vector operator -(Vector v1, Vector v2) {
        return new Vector(v1.x - v2.x, v1.y - v2.y);
    }

    public void Print() {
        Console.WriteLine($"Vector({x}, {y}) Length: {Length()}");
    }
}

class Program {
    static void Main() {
        Vector V1 = new Vector();
        Vector V2 = new Vector(3, 4);
        Vector V3 = new Vector(V2);

        V3 = V3 * 2;
        V1 = V3 - V2;

        Console.Write("V1: "); V1.Print();
        Console.Write("V2: "); V2.Print();
        Console.Write("V3: "); V3.Print();
    }
}
