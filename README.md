﻿![image](img/G.png)

# Graph

Mini-Library for create chart.

# Requirement

- OpenCV

# Class Diagram

```mermaid
graph TB;
    

    InitDataList-->BarChart;
    Window-->BarChart;
    
    Window-->PieChart;
    InitDataList-->PieChart;

    Window-->LineChart;
    InitDataList-->LineChart;

    BarChart-->Chart;
    PieChart-->Chart;
    LineChart-->Chart;
    
       
```

## To Do List

- [x] Dataset input will be taken
- [x] The dataset will be scaled for BarChart
- [x] Column bar will be drawn for BarChart
- [x] Column bar will be drawn for BarChart
- [ ] New class will be created => PieChart
