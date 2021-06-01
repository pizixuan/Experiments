<%@page contentType="text/html;charset=UTF-8"%>
<%
		int res = 0;
		for(int i = 1; i <= 100; ++i) {
			res += i;	
		}
		out.println("1~100的和为" + res);
%>