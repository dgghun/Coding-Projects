/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package library.presentation;
import library.domain.*;
import library.business.*;
import java.awt.*;
import java.util.List;
import java.awt.event.*;
import java.io.FileInputStream;
import java.util.ArrayList;
import javax.swing.*;



/**
 * public class
 * @author MY dell
 */
public class UI extends JFrame{
    private JFrame frame;
    private JPanel panel_1, panel_2, panelContainer;
    private CardLayout cardLay;
    private final int TEXT_FIELD_LENGTH = 30;
    private final int TEXT_AREA_ROWS = 5;
    private JLabel isbnHeaderLabel, authorHeaderLabel, isbnNoteLabel, authorNoteLabel, authorLabel, isbnLabel;
    private JTextField isbnField;
    private JTextArea authorTextArea;
    private JScrollPane authorInputPane;
    private JButton isbnResetButton, authorResetButton, isbnExitButton, authorExitButton, addAuthorButton, addBookButton, nextButton;
    private int isbn;
    private List<String> authorList;
    private final String ENTER_ISBN_MESSAGE = "Enter an ISBN number";    // used for isbnNext button action listener
    private final String ENTER_AUTHOR_MESSAGE = "Enter authors separated by new lines.";      // used for addAuthor button action listener
    private final String AUTHOR_NOTE1 = "Enter authors seprated by new lines. Click Add Authors when done. Reset to start over.";
    private final String AUTHOR_NOTE2 = "Click Add book to submit. Reset to start over.";
    private BookMgr bookMgr;
    
    
    public UI(String title) {
        
        // initialize panels, frame, cardLayout, isbn/author variables & BookMgr
        frame = new JFrame();
        panel_1 = new JPanel();
        panel_2 = new JPanel();
        panelContainer = new JPanel();
        cardLay = new CardLayout();                         // cardLayout for panel 1 & 2
        isbn = 0;
        authorList = new ArrayList<>();
        bookMgr = new BookMgr();
         
        
        //intialize labels
        isbnHeaderLabel = new JLabel(" ENTER ISBN");
        authorHeaderLabel = new JLabel(" ENTER AUTHORS");
        authorNoteLabel = new JLabel(AUTHOR_NOTE1);
        isbnNoteLabel = new JLabel("Click Next when done to enter Authors. Reset to start over.");
        authorLabel = new JLabel("Author:");
        authorHeaderLabel.setFont(new Font("", Font.BOLD, 30));
        isbnLabel = new JLabel("ISBN:");
        isbnHeaderLabel.setFont(new Font("", Font.BOLD, 30));
        
        //intialize text fields
        isbnField = new JTextField(TEXT_FIELD_LENGTH);
        authorTextArea = new JTextArea(TEXT_AREA_ROWS, TEXT_FIELD_LENGTH);
        authorTextArea.setLineWrap(true);
        authorInputPane = new JScrollPane();
        authorInputPane.setViewportView(authorTextArea);
       
        
        
        
        // intialize buttons
        isbnResetButton = new JButton("RESET");
        authorResetButton = new JButton("RESET");
        isbnExitButton = new JButton("EXIT");
        authorExitButton = new JButton("EXIT");
        addAuthorButton = new JButton("Add Authors");
        addBookButton = new JButton("ADD BOOK");
        nextButton = new JButton("NEXT");
        addBookButton.setVisible(false);                    // hide until an author is entered
       
        
        // set layouts and add to container for card layout
        panel_1.setLayout(new GridBagLayout());
        panel_2.setLayout(new GridBagLayout());
        panelContainer.setLayout(cardLay);                  // set panel to cardlayout
        panelContainer.add(panel_1, "1");
        panelContainer.add(panel_2, "2");
        cardLay.show(panelContainer, "1");
        
        frame.setTitle(title);                              // set frame title
        GridBagConstraints gbc = new GridBagConstraints();  // used for gbc.fill constraints 
        gbc.insets = new Insets(15, 5 , 15, 5);             // creates gaps between components
        
        
        /********* PANEL_1 *********************************************************************/
         gbc.fill = GridBagConstraints.CENTER;               // resizes compoments horizontally
         
        // headerLabel label - LEVEL 0
        gbc.gridwidth = 4;
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel_1.add(isbnHeaderLabel, gbc);
        
        //noteLabel label - LEVEL 1
        gbc.gridwidth = 1;
        gbc.gridx = 1;
        gbc.gridy = 1;
        panel_1.add(isbnNoteLabel, gbc);
        
        // isbn label & text field - LEVEL 2
        gbc.gridx = 0;
        gbc.gridy = 2;
        panel_1.add(isbnLabel, gbc);
        gbc.gridx = 1;
        panel_1.add(isbnField, gbc);
          
        gbc.fill = GridBagConstraints.HORIZONTAL;           // resizes compoments horizontally

        // RESET button  - LEVEL 3      
        gbc.gridx = 0;
        gbc.gridy = 3;
        panel_1.add(isbnResetButton, gbc);
        
        // NEXT button - LEVEL 3
        gbc.gridx = 1;
        gbc.gridy = 3;
        panel_1.add(nextButton, gbc);
     
        // EXIT button - LEVEL 3
        gbc.gridx = 2;
        gbc.gridy = 3;
        panel_1.add(isbnExitButton, gbc);

        
        /********* PANEL_2 ***************************************************************/
         gbc.fill = GridBagConstraints.CENTER;           // resizes compoments horizontally
         
        // headerLabel label - LEVEL 0
        gbc.gridwidth = 4;
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel_2.add(authorHeaderLabel, gbc);
        
        //noteLabel label - LEVEL 1
        gbc.gridwidth = 1;
        gbc.gridx = 1;
        gbc.gridy = 1;
        panel_2.add(authorNoteLabel, gbc);
  
        // textArea - LEVEL 2
        gbc.gridx = 1;
        gbc.gridy = 2;
        panel_2.add(authorInputPane, gbc);
        
       
        // AddAuthor button  - LEVEL 3 
        gbc.fill = GridBagConstraints.HORIZONTAL;           // resizes compoments horizontally
        gbc.gridx = 1;
        gbc.gridy = 3;
        panel_2.add(addAuthorButton, gbc);
        
        
        // RESET button - LEVEL 4   
        gbc.gridx = 0;
        gbc.gridy = 3;
        panel_2.add(authorResetButton, gbc);
        
        // SUBMIT button - LEVEL 4
        gbc.gridx = 1;
        gbc.gridy = 3;
        panel_2.add(addBookButton, gbc);
     
        // EXIT button - LEVEL 4
        gbc.gridx = 2;
        gbc.gridy = 3;
        panel_2.add(authorExitButton, gbc);
        
        
        /**
         * ACTION LISTENERS
         */ 
        class ButtonListner implements ActionListener {
            
            // Resets GUI panels to enter a new book
            public void resetForm(){
                isbnField.setText("");
                authorTextArea.setText("");
                isbn = 0;
                authorList.clear();
                authorNoteLabel.setText(AUTHOR_NOTE1);
                addBookButton.setVisible(false);
                addAuthorButton.setVisible(true);
                authorTextArea.setEditable(true);
                authorHeaderLabel.setVisible(true);
                authorTextArea.setBackground(Color.white);
                cardLay.show(panelContainer, "1");
                isbnField.requestFocusInWindow();  
                }
            
            @Override
            public void actionPerformed(ActionEvent ae){
                if (ae.getSource() == isbnResetButton || ae.getSource() == authorResetButton)    //ISBN/AUTHOR resetButton action
                {
                    resetForm();
                }
                else if (ae.getSource() == nextButton)                                           // ISBN nextButton action
                {   
                    // if text field is empty or equals enterIsbn message
                    // or if parsing the text field string fails
                    // or if a negative numbers is inputed throw an exception
                    // else set isbn and go to author panel.
                    try
                    {
                        if(isbnField.getText().trim().isEmpty() || isbnField.getText().equals(ENTER_ISBN_MESSAGE) )
                            throw new Exception(ENTER_ISBN_MESSAGE);
                        isbn = Integer.parseInt(isbnField.getText());               // posible NumberFormatException
                        cardLay.show(panelContainer, "2");
                        authorTextArea.setText(ENTER_AUTHOR_MESSAGE);
                        authorTextArea.requestFocusInWindow();
                        authorTextArea.selectAll();
                        
                    }
                    catch(NumberFormatException e)
                    {
                        
                        isbnField.setText("INVALID INPUT: Enter numbers only.");
                        isbnField.requestFocusInWindow();
                        isbnField.selectAll();
                            
                    }
                    catch(Exception e)
                    {
                        isbnField.setText(e.getMessage());
                        isbnField.requestFocusInWindow();
                        isbnField.selectAll();
                    }       
                }
                else if(ae.getSource() == addAuthorButton)                                       // AUTHOR addAuthor action 
                {
                    if(authorTextArea.getText().trim().isEmpty() || authorTextArea.getText().equals(ENTER_AUTHOR_MESSAGE))
                    {
                        authorTextArea.setText(ENTER_AUTHOR_MESSAGE);
                        authorTextArea.requestFocus();
                        authorTextArea.selectAll();
                    }
                    else
                    {   
                        StringBuilder authors = new StringBuilder();
                        // get all authors in text area and format them
                        for(String line : authorTextArea.getText().trim().split("\\n"))
                        {         
                            if(!line.trim().isEmpty())
                            {
                                authorList.add(line.trim());
                                authors.append("(" + line.trim() + "), ");
                            }
                        }
                        authors.delete(authors.length()-2, authors.length());
                        authorTextArea.setText(" ISBN: " + isbn + "\n\n AUTHORS:\n " + authors.toString());                            // display authors reformatted
                        authorTextArea.setBackground(Color.LIGHT_GRAY);
                        authorTextArea.setEditable(false);
                        authorTextArea.setCaretPosition(0);
                        authorNoteLabel.setText(AUTHOR_NOTE2);
                        authorHeaderLabel.setVisible(false);
                        addBookButton.setVisible(true);                                         
                        addAuthorButton.setVisible(false);
                        frame.setSize(frame.getWidth() + 15, frame.getHeight() + 5);
                    }
                }
                else if(ae.getSource() == addBookButton)                                       // AUTHOR addBook action
                {
                    // package book
                    Book newBook = new Book(authorList, isbn);
                    System.out.println("BOOK STATE - " + newBook.toString());                                     // print book state toString()
                    
                    // Validate and store book in file
                    if(newBook.validate())
                        try 
                        {
                            bookMgr.storeBook(newBook);
                            System.out.println("Book was stored.");
                        } 
                        catch (Exception e) 
                        {
                            System.err.println(e);
                            System.err.println("Book was not stored.");
                        }
                    else
                        JOptionPane.showMessageDialog(null, "Invalid book!", title, JOptionPane.ERROR_MESSAGE);
              
                    resetForm(); 
                }
                else if (ae.getSource() == isbnExitButton || ae.getSource() == authorExitButton) // ISBN & AUTHOR exit buttons action
                    System.exit(0);
            }
        }// END of ButtonListener
        
        // register action listeners for buttons
        isbnResetButton.addActionListener(new ButtonListner());
        authorResetButton.addActionListener(new ButtonListner());
        isbnExitButton.addActionListener(new ButtonListner());
        authorExitButton.addActionListener(new ButtonListner());
        nextButton.addActionListener(new ButtonListner());
        addAuthorButton.addActionListener(new ButtonListner());
        addBookButton.addActionListener(new ButtonListner());
        
        
        frame.add(panelContainer);
        frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationByPlatform(true);
        frame.setVisible(true);
     
    }// END of UI constuctor
   
    
    /**
     * MAIN PROGRAM
     * @param args 
     */
//    public static void main(String[] args) {
//        JFrame frame = new UI ("Library System");  
//    }// END of Main
} // END of UI class
