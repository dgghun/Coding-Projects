
package library.services;
import java.sql.*;
import javax.sql.*;
import javax.xml.bind.ParseConversionEvent;
import library.domain.*;


/**
 *
 * @author david
 */
public class BookSvcJDBCImpl implements IBookSvc {

    private String connString = "jdbc:mysql://localhost/garcialibrary?user=root&password=admin";
    public Connection conn;
    public Statement stmt;
    
    
    private Connection getConnection() throws Exception {
        return DriverManager.getConnection(connString);
    }

    @Override
    public Book add(Book book) throws Exception {
        try {
            conn = getConnection();
            stmt = conn.createStatement();
            
            // get list from book and store it in a string
            StringBuilder authors = new StringBuilder();
            for(String temp : book.getAuthors())
                authors.append(temp + ", ");
            authors.delete(authors.length()-2, authors.length());
            
            String sql = "INSERT INTO book (isbn, authors) " 
                    + "VALUES ('" 
                    + book.getIsbn() 
                    + "', '"
                    + authors
                    + "')";
            stmt.executeUpdate(sql);
        } catch (Exception e) {
            throw e;
        } finally {
            if (conn != null) {
                stmt.close();
                conn.close();
            }
            
            return book;
        }
    } // END if addBook()
}// END of BookSvcJDBCImpl
