<%@ page contentType="text/html;charset=UTF-8" %>
    <form method=POST action=6.3.jsp>
        请输入要计算图形的相应数据:<br/>
<%
    String graphical = request.getParameter("graphical");
    if (graphical.equals("triangle")) {
        String str = "底:<input type='text' name='data_1'> 高:<input type='text' name='data_2'> <input name='graphical' type='hidden' value='triangle'>";
        out.print(str);
    }
    else if (graphical.equals("rectangle")) {
        String str = "长或宽:<input type='text' name='data_1'> 长或宽:<input type='text' name='data_2'> <input name='graphical' type='hidden' value='rectangle'>";
        out.print(str);
    }
    else if (graphical.equals("circular")) {
        String str = "圆形 半径:<input type='text' name='data_1'> <input name='graphical' type='hidden' value='circular'>";
        out.print(str);
    }
    else if (graphical.equals("trapezoid")) {
        String str = "梯形 上底:<input type='text' name='data_1'> 下底:<input type='text' name='data_2'> 高:<input type='text' name='data_3'> <input name='graphical' type='hidden' value='trapezoid'>";
        out.print(str);
    }
%>
        <input type="submit" value="提交">
    </form>