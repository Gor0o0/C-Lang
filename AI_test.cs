using System;
using System.Globalization;

class Program
{
    static void Main()
    {
        Console.Write("Введите первое число: ");
        if (!TryReadDouble(out double a))
        {
            Console.WriteLine("Ошибка: не удалось прочитать число.");
            return;
        }

        Console.Write("Введите операцию (+, -, *, /): ");
        string? op = Console.ReadLine()?.Trim();
        if (string.IsNullOrEmpty(op) || op.Length != 1 || "+-*/".IndexOf(op[0]) < 0)
        {
            Console.WriteLine("Ошибка: неизвестная операция.");
            return;
        }

        Console.Write("Введите второе число: ");
        if (!TryReadDouble(out double b))
        {
            Console.WriteLine("Ошибка: не удалось прочитать число.");
            return;
        }

        double result;
        switch (op[0])
        {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    Console.WriteLine("Ошибка: деление на ноль.");
                    return;
                }
                result = a / b;
                break;
            default:
                Console.WriteLine("Ошибка: неизвестная операция.");
                return;
        }

        Console.WriteLine($"Результат: {result.ToString(CultureInfo.InvariantCulture)}");
    }

    static bool TryReadDouble(out double value)
    {
        string? s = Console.ReadLine();
        if (s == null)
        {
            value = 0;
            return false;
        }

        s = s.Trim().Replace(',', '.');
        return double.TryParse(s, NumberStyles.Float, CultureInfo.InvariantCulture, out value);
    }
}
