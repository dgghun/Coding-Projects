
package library.services;
import java.io.*;
import library.domain.*;

/**
 *
 * @author David Garcia
 */
public class BookSvcSerializedIOImpl implements IBookSvc{
    private String file = System.getProperty("user.home") + "\\Desktop\\BookFile.ser";
    
    @Override // IBookSvc
    public Book add(Book book) throws Exception {
        FileOutputStream fos = new FileOutputStream(file);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(book);
        oos.flush();
        oos.close();
        
        return book;
    } 
    
}
