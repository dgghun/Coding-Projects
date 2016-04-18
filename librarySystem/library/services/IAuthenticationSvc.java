
package library.services;
import common.domain.Login;


/**
 *
 * @author david
 */
public interface IAuthenticationSvc extends IService{
    
    public boolean authenticate(Login login) throws Exception;
    
}
