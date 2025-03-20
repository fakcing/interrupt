using System;

class Rectangle {
    private double x1, y1, x2, y2;

    public Rectangle() {
        x1 = 0; y1 = 0; x2 = 1; y2 = 1;
    }

    public Rectangle(double x1, double y1, double x2, double y2) {
        this.x1 = x1; this.y1 = y1;
        this.x2 = x2; this.y2 = y2;
    }

    public Rectangle(Rectangle other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
    }

    public double GetArea() {
        return Math.Abs(x2 - x1) * Math.Abs(y2 - y1);
    }

    public double GetPerimeter() {
        return 2 * (Math.Abs(x2 - x1) + Math.Abs(y2 - y1));
    }

    public double GetX1() { return x1; }
    public double GetY1() { return y1; }
    public double GetX2() { return x2; }
    public double GetY2() { return y2; }
}

class Program {
    static void Main() {
        Rectangle rect1 = new Rectangle();
        Rectangle rect2 = new Rectangle(2, 3, 6, 7);
        Rectangle rect3 = new Rectangle(rect2);

        Console.WriteLine($"Rectangle 1: Area = {rect1.GetArea()}, Perimeter = {rect1.GetPerimeter()}");
        Console.WriteLine($"Rectangle 2: Area = {rect2.GetArea()}, Perimeter = {rect2.GetPerimeter()}");
        Console.WriteLine($"Rectangle 3 (Copy of 2): Area = {rect3.GetArea()}, Perimeter = {rect3.GetPerimeter()}");
    }
}
