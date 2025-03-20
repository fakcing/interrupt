using System;

class Rectangle {
    private double x1, y1, x2, y2;

    public Rectangle(double x1, double y1, double x2, double y2) {
        this.x1 = x1; this.y1 = y1;
        this.x2 = x2; this.y2 = y2;
    }

    public double GetArea() {
        return Math.Abs(x2 - x1) * Math.Abs(y2 - y1);
    }

    public double GetPerimeter() {
        return 2 * (Math.Abs(x2 - x1) + Math.Abs(y2 - y1));
    }
}

class Program {
    static void Main() {
        Rectangle rect = new Rectangle(1, 1, 5, 4);
        Console.WriteLine("Area: " + rect.GetArea());
        Console.WriteLine("Perimeter: " + rect.GetPerimeter());
    }
}