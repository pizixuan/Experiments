<%@ page contentType="text/html;charset=UTF-8" %>
<%@ page import="java.text.DecimalFormat"%>
<%
// 计算公式：每月还款金额=(贷款本金/还款月数)+(本金—已归还本金累计额)×每月利率
    String e_str = "<table border='1px'>";
    double allMoney = 600000;
    double year = 1;
    double ratio = (0.0486/12);
    double allPayed = 0;
    e_str += "<tr align='center'>";
    e_str += "<td> 应还金额 </td>";
    for (int i = 1; i <= 12; i++) {
        e_str += "<td> 第" + i + "个月</td>";
    }        
    e_str += "</tr align='center'>";
    for (int i = 1; i <= 20; i++) {
        e_str += "<tr> <td> 第" + i + "年</td>";
        for (int j = 1; j <= 12; j++) {
            double pay = (allMoney / 240) + (allMoney - allPayed) * ratio;
            allPayed += 2500;
            e_str += "<td >" + (new DecimalFormat("0.00").format(pay)) + "</td>";
        } 
        e_str += "</tr>";
   }
    e_str += "</tr>";
    e_str += "</table>";
    out.print(e_str);
%>