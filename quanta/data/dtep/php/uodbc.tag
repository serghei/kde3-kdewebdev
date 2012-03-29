<!DOCTYPE tags>
<tags>
	<tag name="odbc_autocommit" type="function" returnType="bool" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="OnOff" type="bool" status="optional"></attr>
	</tag>
	<tag name="odbc_binmode" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="mode" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_close_all" type="function" returnType="void" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
	</tag>
	<tag name="odbc_close" type="function" returnType="void" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_columnprivileges" type="function" returnType="int" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="required"></attr>
		<attr name="owner" type="string" status="required"></attr>
		<attr name="table_name" type="string" status="required"></attr>
		<attr name="column_name" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_columns" type="function" returnType="resource" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="optional"></attr>
		<attr name="schema" type="string" status="optional"></attr>
		<attr name="table_name" type="string" status="optional"></attr>
		<attr name="column_name" type="string" status="optional"></attr>
	</tag>
	<tag name="odbc_commit" type="function" returnType="bool" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_connect" type="function" returnType="resource" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="dsn" type="string" status="required"></attr>
		<attr name="user" type="string" status="required"></attr>
		<attr name="password" type="string" status="required"></attr>
		<attr name="cursor_type" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_cursor" type="function" returnType="string" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_data_source" type="function" returnType="resource" version="PHP 4 &gt;= 4.3.0, PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="fetch_type" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_do" type="function" returnType="resource" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="conn_id" type="resource" status="required"></attr>
		<attr name="query" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_error" type="function" returnType="string" version="PHP 4 &gt;= 4.0.5, PHP 5">
		<attr name="connection_id" type="resource" status="optional"></attr>
	</tag>
	<tag name="odbc_errormsg" type="function" returnType="string" version="PHP 4 &gt;= 4.0.5, PHP 5">
		<attr name="connection_id" type="resource" status="optional"></attr>
	</tag>
	<tag name="odbc_exec" type="function" returnType="resource" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="query_string" type="string" status="required"></attr>
		<attr name="flags" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_execute" type="function" returnType="bool" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="parameters_array" type="array" status="optional"></attr>
	</tag>
	<tag name="odbc_fetch_array" type="function" returnType="array" version="PHP 4 &gt;= 4.0.2, PHP 5">
		<attr name="result" type="resource" status="required"></attr>
		<attr name="rownumber" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_fetch_into" type="function" returnType="resource" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="&amp;result_array" type="array" status="required"></attr>
		<attr name="rownumber" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_fetch_object" type="function" returnType="object" version="PHP 4 &gt;= 4.0.2, PHP 5">
		<attr name="result" type="resource" status="required"></attr>
		<attr name="rownumber" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_fetch_row" type="function" returnType="bool" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="row_number" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_field_len" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="field_number" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_field_name" type="function" returnType="string" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="field_number" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_field_num" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="field_name" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_field_precision" type="function" returnType="string" version="PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="field_number" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_field_scale" type="function" returnType="string" version="PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="field_number" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_field_type" type="function" returnType="string" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="field_number" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_foreignkeys" type="function" returnType="resource" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="pk_qualifier" type="string" status="required"></attr>
		<attr name="pk_owner" type="string" status="required"></attr>
		<attr name="pk_table" type="string" status="required"></attr>
		<attr name="fk_qualifier" type="string" status="required"></attr>
		<attr name="fk_owner" type="string" status="required"></attr>
		<attr name="fk_table" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_free_result" type="function" returnType="bool" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_gettypeinfo" type="function" returnType="int" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="data_type" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_longreadlen" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="length" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_next_result" type="function" returnType="bool" version="PHP 4 &gt;= 4.0.5, PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_num_fields" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_num_rows" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_pconnect" type="function" returnType="resource" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="dsn" type="string" status="required"></attr>
		<attr name="user" type="string" status="required"></attr>
		<attr name="password" type="string" status="required"></attr>
		<attr name="cursor_type" type="int" status="optional"></attr>
	</tag>
	<tag name="odbc_prepare" type="function" returnType="resource" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="query_string" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_primarykeys" type="function" returnType="resource" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="required"></attr>
		<attr name="owner" type="string" status="required"></attr>
		<attr name="table" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_procedurecolumns" type="function" returnType="resource" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="optional"></attr>
		<attr name="owner" type="string" status="required"></attr>
		<attr name="proc" type="string" status="required"></attr>
		<attr name="column" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_procedures" type="function" returnType="resource" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="optional"></attr>
		<attr name="owner" type="string" status="required"></attr>
		<attr name="name" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_result_all" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="format" type="string" status="optional"></attr>
	</tag>
	<tag name="odbc_result" type="function" returnType="string" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="result_id" type="resource" status="required"></attr>
		<attr name="field" type="mixed" status="required"></attr>
	</tag>
	<tag name="odbc_rollback" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
	</tag>
	<tag name="odbc_setoption" type="function" returnType="int" version="PHP 3&gt;= 3.0.6, PHP 4 , PHP 5">
		<attr name="id" type="resource" status="required"></attr>
		<attr name="function" type="int" status="required"></attr>
		<attr name="option" type="int" status="required"></attr>
		<attr name="param" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_specialcolumns" type="function" returnType="resource" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="type" type="int" status="required"></attr>
		<attr name="qualifier" type="string" status="required"></attr>
		<attr name="owner" type="string" status="required"></attr>
		<attr name="table" type="string" status="required"></attr>
		<attr name="scope" type="int" status="required"></attr>
		<attr name="nullable" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_statistics" type="function" returnType="resource" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="required"></attr>
		<attr name="owner" type="string" status="required"></attr>
		<attr name="table_name" type="string" status="required"></attr>
		<attr name="unique" type="int" status="required"></attr>
		<attr name="accuracy" type="int" status="required"></attr>
	</tag>
	<tag name="odbc_tableprivileges" type="function" returnType="int" version="PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="required"></attr>
		<attr name="owner" type="string" status="required"></attr>
		<attr name="name" type="string" status="required"></attr>
	</tag>
	<tag name="odbc_tables" type="function" returnType="int" version="PHP 3&gt;= 3.0.17, PHP 4 , PHP 5">
		<attr name="connection_id" type="resource" status="required"></attr>
		<attr name="qualifier" type="string" status="optional"></attr>
		<attr name="owner" type="string" status="optional"></attr>
		<attr name="name" type="string" status="optional"></attr>
		<attr name="types" type="string" status="optional"></attr>
	</tag>
</tags>