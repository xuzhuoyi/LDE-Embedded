// QChartGallery.js ---
//
// Author: Julien Wintz
// Created: Thu Feb 13 23:43:13 2014 (+0100)
// Version:
// Last-Updated:
//           By:
//     Update #: 13
//

// Change Log:
//
//

// /////////////////////////////////////////////////////////////////
// Line Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartLineData = {
      labels: ["January","February","March","April","May","June","July"],
    datasets: [{
               fillColor: "rgba(220,220,220,0.5)",
             strokeColor: "rgba(220,220,220,1)",
              pointColor: "rgba(220,220,220,1)",
        pointStrokeColor: "#ffffff",
                    data: [65,59,90,81,56,55,40]
    }, {
               fillColor: "rgba(151,187,205,0.5)",
             strokeColor: "rgba(151,187,205,1)",
              pointColor: "rgba(151,187,205,1)",
        pointStrokeColor: "#ffffff",
                    data: [28,48,40,19,96,27,100]
    }]
}

// /////////////////////////////////////////////////////////////////
// Polar Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartPolarData = [{
    value: 30,
    color: "#D97041"
 }, {
    value: 90,
    color: "#C7604C"
 }, {
    value: 24,
    color: "#21323D"
 }, {
    value: 58,
    color: "#9D9B7F"
 }, {
    value: 82,
    color: "#7D4F6D"
 }, {
    value: 8,
    color: "#584A5E"
}]

// /////////////////////////////////////////////////////////////////
// Radar Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartRadarData = {
      labels: ["Eating","Drinking","Sleeping","Designing","Coding","Partying","Running"],
    datasets: [{
               fillColor: "rgba(220,220,220,0.5)",
             strokeColor: "rgba(220,220,220,1)",
              pointColor: "rgba(220,220,220,1)",
        pointStrokeColor: "#fff",
                    data: [65,59,90,81,56,55,40]
    }, {
               fillColor: "rgba(151,187,205,0.5)",
             strokeColor: "rgba(151,187,205,1)",
              pointColor: "rgba(151,187,205,1)",
        pointStrokeColor: "#fff",
                    data: [28,48,40,19,96,27,100]
    }]
}

// /////////////////////////////////////////////////////////////////
// Pie Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartPieData = [{
    value: 30,
    color: "#F38630"
 }, {
    value: 50,
    color: "#E0E4CC"
 }, {
    value: 100,
    color: "#69D2E7"
}]

// /////////////////////////////////////////////////////////////////
// Doughnut Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartDoughnutData = [{
    value: 30,
    color: "#F7464A"
 }, {
    value: 50,
    color: "#E2EAE9"
 }, {
    value: 100,
    color: "#D4CCC5"
 }, {
    value: 40,
    color: "#949FB1"
 }, {
    value: 120,
    color: "#4D5360"
}]

// /////////////////////////////////////////////////////////////////
// Bar Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartBarData = {
      labels: ["January","February","March","April","May","June","July"],
    datasets: [{
          fillColor: "rgba(255,255,153,0.5)",
        strokeColor: "rgba(153,102,153,1)",
               data: [65,59,90,81,56,55,40]
    }, {
          fillColor: "rgba(255,204,204,0.5)",
        strokeColor: "rgba(204,153,153,1)",
               data: [28,48,40,19,96,27,100]
    }]
}

function GetHeader(src) {
//权限只读(只读=1，只写=2 ，追加=8 等权限)
var ForReading=1;
var fso=new ActiveXObject("Scripting.FileSystemObject");
var f=new fso.OpenTextFile(src,ForReading);
return(new f.ReadAll());
}

function GetData() {
    var arr=new GetHeader("tmdata").split("\r\n");
    for(var i=0;i<arr.length;i++){
    alert("第"+(i+1)+"行数据为:"+arr[i]);
    }
}
