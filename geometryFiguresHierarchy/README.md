Спроектирована и реализована иерархию классов, содержащая не менее 4 классов. В каждом классе определены поля и методы, необходимые для демонстрации.
Представленная схема описывает реализованную иерархию:


```mermaid
classDiagram
      
      Shape <|-- Polygon
      Shape <|-- Circle
      Shape <|-- Ellipse
      
      Polygon <|-- Triangle
      Polygon <|-- Quadrangle
      
   
      class Point{
          string pointName
          double x, y
          double radiusVectorLen()
          operator+()
          operator-()
          operator*()
          operator=()
          operator<<()
          operator>>()
 
      }
      class Segment{
          Point point1, point2
          double segmentLen()
          double getTangent()
          double getAngle()
      }
      class Shape{
          string shapeName
          bool isPolygon()
      }
      class Triangle{
          vector points
      }
      class Quadrangle{
          vector points
      }
      class Polygon{
          vector points
          double area()
          double perimeter()
          void displayInfo()
          operator+=()
          operator=()
      }
      class Circle{
          double r
          double area()
          double perimeter()
          void displayInfo()
      }
      class Ellipse{
          double a, b
          double area()
          double perimeter()
          void displayInfo()
      }
```