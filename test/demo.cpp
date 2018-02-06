#include <memory>
#include <iostream>
#include "mysqlppc.h"

int main(int argc,char *argv[])
{
	try
	{
		mysqlppc::Connection conn("localhost",3306,"root","","test");

		std::auto_ptr<mysqlppc::Statement> stmt(conn.prepare("select * from student where name=?"));

		//stmt->bindIntParam(0,1);
		stmt->bindStrParam(0,"yang");
		stmt->execute(); 

		std::auto_ptr<mysqlppc::ResultSet> resultSet(stmt->getResultSet());
		while(resultSet->next())
		{
			std::cout<<" id:"<<resultSet->getInt("id");
			std::cout<<" name:"<<resultSet->getString("name");
			std::cout<<" regtime:"<<resultSet->getString("regtime");
			std::cout<<" salary:"<<resultSet->getFloat("salary");
			std::cout<<std::endl;

			resultSet->getInt(8);
		}
	}
	catch(mysqlppc::MysqlException &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	return 0;
}
