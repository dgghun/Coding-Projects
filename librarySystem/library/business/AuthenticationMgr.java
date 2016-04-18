
package library.business;
import library.services.*;
import common.domain.Login;


/**
 *
 * @author david
 */
public class AuthenticationMgr {
   
    public boolean authenticate(Login login) throws Exception{
        Factory factory = new Factory();
        IAuthenticationSvc authenticationSvc = (IAuthenticationSvc)factory.getService("IAuthenticationSvc");
        return authenticationSvc.authenticate(login);
    }
    
}
