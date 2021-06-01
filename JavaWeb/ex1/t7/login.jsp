<%@ page contentType="text/html;charset=UTF-8" %>

<%
	String userName = request.getParameter("userName");
	String userPwd = request.getParameter("userPwd");
	String userType = request.getParameter("userType");
	if ("18093133".equals(userName) && "123456".equals(userPwd) && "admin".equals(userType)
		|| "user".equals(userName) && "test".equals(userPwd) && "simple".equals(userType)) {
			session.setAttribute("userName", userName);
			session.setAttribute("userPwd", userPwd);
			session.setAttribute("userType", userType);
			response.sendRedirect("main.jsp");
	}	
	else {
		response.sendRedirect("login.html");	
	}
%>