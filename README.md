![image](img/G.png)

# Graph

Mini-Library for create chart.

# Requirement

- OpenCV

# Class Diagram

```mermaid
graph TB;
    
    InitDataList-->ScaledData
    ScaledData-->BarChart;
    Window-->BarChart;
    
    Window-->PieChart;
    ScaledData-->PieChart;

    Window-->LineChart;
    ScaledData-->LineChart;

    BarChart-->Chart;
    PieChart-->Chart;
    LineChart-->Chart;
    
       
```

## To Do List

- [x] Dataset input will be taken
- [ ] The dataset will be scaled for graph sizing
- [ ] Column bar will be drawn for barChart
