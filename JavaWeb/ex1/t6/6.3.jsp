<%@ page contentType="text/html;charset=UTF-8" %>
<%@ page import="java.text.DecimalFormat"%>
<%
    String graphical = request.getParameter("graphical");
    if (graphical.equals("triangle")) {
        double data_1 = Float.parseFloat(request.getParameter("data_1"));
        double data_2 = Float.parseFloat(request.getParameter("data_2"));
        double res = data_1 * data_2 / 2;
        out.print("结果为" + (new DecimalFormat("0.00").format(res)));
    }
    else if (graphical.equals("rectangle")) {
        double data_1 = Float.parseFloat(request.getParameter("data_1"));
        double data_2 = Float.parseFloat(request.getParameter("data_2"));
        double res = data_1 * data_2;
        out.print("结果为" + (new DecimalFormat("0.00").format(res)));
    }
    else if (graphical.equals("circular")) {
        double data_1 = Float.parseFloat(request.getParameter("data_1"));
        double res = data_1 * data_1 * Math.PI;
        out.print("结果为" + (new DecimalFormat("0.00").format(res)));
    }
    else if (graphical.equals("trapezoid")) {
        double data_1 = Float.parseFloat(request.getParameter("data_1"));
        double data_2 = Float.parseFloat(request.getParameter("data_2"));
        double data_3 = Float.parseFloat(request.getParameter("data_3"));
        double res = (data_1 + data_2) * data_3 / 2;
        out.print("结果为" + (new DecimalFormat("0.00").format(res)));
    }
%>