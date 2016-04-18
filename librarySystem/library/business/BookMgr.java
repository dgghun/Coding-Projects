
package library.business;
import library.domain.*;
import library.services.*;

/**
 *
 * @author david
 */
public class BookMgr {
    
    public Book storeBook(Book book) throws Exception{
        Factory factory = new Factory();
        IBookSvc bookSvc = (IBookSvc)factory.getService("IBookSvc");
        return bookSvc.add(book);
    }
}
