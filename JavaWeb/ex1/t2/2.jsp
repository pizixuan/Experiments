<%@ page contentType="text/html;charset=UTF-8" %>
<%
       String str_2 = "<h1> JSP: </h1> <br>";
       for (int i = 1; i <= 7; ++i) {
              str_2 += "<font size='" + i + "'" + ">" + "你好,JSP!" + "</font>";
       }
       out.print(str_2);
%> 



<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>1-7号字体</title>
</head>
<body>
    <br>
    <h1>
    HTML:
    </h1>
    <div id="app">
      
    </div> 
</body>
<script>
    var str = "";
    for (var i = 1; i <= 7; ++i) {
        str += "<font size='" + i + "'" + ">" + "你好,JSP!" + "</font>";
    }

    var app = document.getElementById("app");
    app.innerHTML = str;
</script>
</html>