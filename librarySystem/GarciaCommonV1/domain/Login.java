
package common.domain;
import java.io.Serializable;

import java.util.Objects;

/**
 *
 * @author david
 */
public class Login implements Serializable{
    
    // Properties
    private String userName;
    private String userPassword;
    
    /**
     * Default constructor
     */
    public Login() {
        userName = new String();
        userPassword = new String();
    }
    
    /**
     * 
     * @param userName
     * @param userPassword 
     */
    public Login(String userName, String userPassword) {
        this.userName = userName;
        this.userPassword = userPassword;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public void setUserPassword(String userPassword) {
        this.userPassword = userPassword;
    }

    public String getUserName() {
        return userName;
    }

    public String getUserPassword() {
        return userPassword;
    }

    @Override
    public String toString() {
        return "Login{" + "userName=" + userName + ", userPassword=" + userPassword + '}';
    }   

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Login other = (Login) obj;
        if (!Objects.equals(this.userName, other.userName)) {
            return false;
        }
        if (!Objects.equals(this.userPassword, other.userPassword)) {
            return false;
        }
        return true;
    }
    
    
}
