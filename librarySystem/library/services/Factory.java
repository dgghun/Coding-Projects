
package library.services;
import java.io.*;
import java.util.*;


/**
 *
 * @author David Garcia
 */
public class Factory {
//    public IBookSvc getBookSvc(){
//        return new BookSvcSerializedIOImpl();
//    }

    public Factory() {
    }

    public IService getService(String serviceName) throws Exception {
        Class c = Class.forName(getImplName(serviceName));
        return (IService) c.newInstance();
    }

    private String getImplName(String serviceName) throws Exception {
        try{
            FileInputStream fis = new FileInputStream("config/properties.txt");
            Properties props = new Properties();
            props.load(fis);
            fis.close();
            return props.getProperty(serviceName);
        }
        catch (Exception e){
            throw e;
        }
       
            
        
    }
}
