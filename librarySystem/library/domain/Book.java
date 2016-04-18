/*
 * Author: David Garcia
 * Last Revised: 11/8/15
 */

package library.domain;
import java.io.Serializable;
import java.util.*;


// Book Class
public class Book implements Serializable{
    
    // Properties
    private List<String> authors;
    private int isbn;
    
    
    /**
     * Default constructor
     */
    public Book()
    {
        authors = new ArrayList<>();
        isbn = 0;
    }
    
    /**
     * Constructor with parameters
     * @param authors
     * @param isbn 
     */
    public Book(List<String> authors, int isbn)
    {
        this.authors = new ArrayList<>(authors);
        this.isbn = isbn;
    }
    

    /**
     * Get authors list
     * @return List of authors 
     */
    public List<String> getAuthors()
    {
        return authors;
    }
    
    /**
     * Gets ISBN number
     * @return isbn number
     */
    public int getIsbn()
    {
        return isbn;
    }
    
    /**
     * Sets authors list
     * @param authors 
     */
    public void setAuthors(List<String> authors)
    {
        this.authors = authors;
    }
    
    /**
     * Sets ISBN number
     * @param isbn 
     */
    public void setIsbn(int isbn)
    {
        this.isbn = isbn;
    }
    
    /**
     * Adds an author to book
     * @param author 
     */
    public void addAuthor(String author)
    {
        this.authors.add(author);
    }
    
    //Overriden toString() method
    @Override
    public String toString()
    {
        String bookInfo  = "ISBN: " + Integer.toString(isbn) + " AUTHORS: ";
        for(int i = 0; i < this.authors.size(); i++)
        {
            if(i == this.authors.size() - 1)
                bookInfo += this.authors.get(i);
            else
                bookInfo += this.authors.get(i) + ", ";
        }
        
        return bookInfo;
    }
    
    // Overriden Object’s equals() method
    @Override
    public boolean equals(Object obj)
    {
        if(this == obj) return true;                        //If obj is compared to self, return true
        if(!(obj instanceof Book)) return false;            //If obj is not instance of Book, return false
        Book book = (Book)obj;                              //Typecast to compare data members
        if(!this.authors.equals(book.authors)) return false;  //If "this" doesn't equal "book.author" data member, return false (string comparison)
        return                                              
                this.isbn == book.isbn;                     //Compare "this" integer with isbn data member & return accordingly (int comparison)
    }
    
    
    /**
     * Validate author & isbn data members
     * @return false if any author is null, empty or contains an empty string (all white spaces)
     */
    public boolean validate()
    {
        if(authors == null || authors.isEmpty()) return false;
        if(isbn <= 0) return false;
        return true;
        
    }
    
} // END of Book Class
