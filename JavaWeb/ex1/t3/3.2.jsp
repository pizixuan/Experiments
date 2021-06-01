<%@ page contentType="text/html;charset=UTF-8" %>
<%
    int l = Integer.parseInt(request.getParameter("line"));
    int r = Integer.parseInt(request.getParameter("row"));
    String c2_str = "<table border='1px' width='400' height='200'>";
    for (int i = 0; i < l; ++i) {
        c2_str += "<tr>";
        for (int j = 0; j < r; ++j)
            c2_str += "<td >" + "</td>";
        c2_str += "</tr>";
    }
    c2_str += "</table>";
    out.print(c2_str);
%>