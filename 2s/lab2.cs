using System;

public class Rectangle
{
    private int x1, y1, x2, y2;
    
    public Rectangle() // Конструктор за замовчуванням
    {
        x1 = y1 = 0;
        x2 = y2 = 1;
    }
    
    public Rectangle(int x1, int y1, int x2, int y2) // Конструктор з параметрами
    {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
    
    public Rectangle(Rectangle other) // Конструктор копіювання
    {
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
    }
    
    ~Rectangle() // Деструктор
    {
        Console.WriteLine("Об'єкт Rectangle знищено");
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
        
        Rectangle rect1 = new Rectangle();
        Rectangle rect2 = new Rectangle(x1, y1, x2, y2);
        Rectangle rect3 = new Rectangle(rect2);
        
        Console.WriteLine("Прямокутник 1 (за замовчуванням): " + rect1);
        Console.WriteLine("Прямокутник 2: " + rect2);
        Console.WriteLine("Прямокутник 3 (копія 2): " + rect3);
        
        Console.WriteLine($"Площа: {rect2.GetArea()}");
        Console.WriteLine($"Периметр: {rect2.GetPerimeter()}");
    }
}