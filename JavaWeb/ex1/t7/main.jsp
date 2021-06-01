<%@page contentType="text/html;charset=UTF-8"%>
<%
	String userName = (String)session.getAttribute("userName");
	String userPwd = (String)session.getAttribute("userPwd");
	String userType = (String)session.getAttribute("userType");
	if (userName == null) {
		out.print("错误");
		response.sendRedirect("login.html");
	} else {
		if ("admin".equals(userType)) {
			out.print("欢迎您，管理员：");
			out.print(userName);
		} else if ("simple".equals(userType)) {
			out.print("欢迎您，用户：");
			out.print(userName);
		}
	}
%>