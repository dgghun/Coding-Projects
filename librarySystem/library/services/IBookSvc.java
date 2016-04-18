
package library.services;
import library.domain.*;

/**
 *
 * @author David Garcia
 */
public interface IBookSvc extends IService{
    
    public Book add(Book book) throws Exception;
   
}
