<%@ page contentType="text/html;charset=UTF-8" %>
<%
    String d_str = "<table border='1px' width='400' height='200'>";

    for (int i = 1; i <= 10; i++) {
        d_str += "<tr align='center'>";
        int res = 1;
        for (int j = i; j > 0; --j) {
            res *= j;
        }
        d_str += "<td >" + i + "的阶乘</td>";
        d_str += "<td >" + res + "</td>";
    }
    d_str += "</tr>";
    d_str += "</table>";
    out.print(d_str);
%>