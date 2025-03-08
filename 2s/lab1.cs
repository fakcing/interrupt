using System;

class Rectangle
{
    private int x1, y1, x2, y2;
    
    public Rectangle(int x1, int y1, int x2, int y2)
    {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
    
    public int GetWidth() => Math.Abs(x2 - x1);
    public int GetHeight() => Math.Abs(y2 - y1);
    public int GetArea() => GetWidth() * GetHeight();
    public int GetPerimeter() => 2 * (GetWidth() + GetHeight());
    
    public override string ToString()
    {
        return $"Вершини: ({x1}, {y1}), ({x2}, {y2})";
    }
}

class Program
{
    static void Main()
    {
        Console.Write("Введіть координати x1, y1, x2, y2: ");
        string[] input = Console.ReadLine().Split();
        
        int x1 = int.Parse(input[0]);
        int y1 = int.Parse(input[1]);
        int x2 = int.Parse(input[2]);
        int y2 = int.Parse(input[3]);
        
        Rectangle rect = new Rectangle(x1, y1, x2, y2);
        
        Console.WriteLine(rect);
        Console.WriteLine($"Площа: {rect.GetArea()}");
        Console.WriteLine($"Периметр: {rect.GetPerimeter()}");
    }
}