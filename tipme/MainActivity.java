package app.android.tipme;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        hideTips();	// Hide all tip values on create
    }
	
	// TextView variables to get a handle on the views
    TextView goodTip;
    TextView goodTipT;
    TextView fairTip ;
    TextView fairTipT;
    TextView badTip;
    TextView badTipT;
    DecimalFormat decimalFormat = new DecimalFormat("0.00");    // formats 2 decimal places
    Double totalNum = 0.0;	// Running total of amount entered by user


    /**
     * This action event handles button input.
     * @param view
     */
    public void onClick1(View view){
		// Get textView IDs
        TextView textView2 = (TextView) findViewById(R.id.TVbillAmount); 
        goodTip = (TextView) findViewById(R.id.TVgoodTipAmount);
        fairTip = (TextView) findViewById(R.id.TVfairTipAmount);
        badTip = (TextView) findViewById(R.id.TVbadTipAmount);
		
        Button button = (Button) view;             			// cast what button was clicked
        String numClicked = button.getText().toString();   	// get string of button clicked


        if(view.getId() == R.id.buttonClear)    // if the clear button is clicked
        {
            textView2.setText(getResources().getString(R.string.zeros));
            totalNum = 0.0;
            hideTips();
        }
        else if(view.getId() == R.id.buttonGetTip){ // If the Get tip button is clicked
            // If total is greater than zero calculate tip
            if(totalNum > 0.0) {
                CalcTip tip = new CalcTip();
				
                String good = decimalFormat.format(tip.CalcTip(totalNum, 20));
                String goodTotal = (good + " = $ " + decimalFormat.format(Double.parseDouble(good) + totalNum));
                String fair = decimalFormat.format(tip.CalcTip(totalNum, 15));
                String fairTotal = (fair + " = $ " + decimalFormat.format(Double.parseDouble(fair) + totalNum));
                String bad = decimalFormat.format(tip.CalcTip(totalNum, 5));
                String badTotal = (bad + " = $ " + decimalFormat.format(Double.parseDouble(bad) + totalNum));
				
				//Set tip amounts
                goodTip.setText(goodTotal);
                fairTip.setText(fairTotal);
                badTip.setText(badTotal);
                totalNum = 0.0;
                showTips();
            }
        }
        else if(decimalFormat.format(totalNum).length() >= 7){ //if limit has been reached
          //To do: play error sound.
        }
        else { // if a number is pressed, multiply total to push decimal over.
            totalNum *= 10;     
            Double tempNum = Double.parseDouble(numClicked) / 100;  // puts input at end
            totalNum += tempNum;
            textView2.setText(decimalFormat.format(totalNum));
            hideTips();
        }
    }// END of onClick1()

	 /**
     * This hides all tip amounts 
     *
     */
    public  void hideTips(){
        goodTip = (TextView) findViewById(R.id.TVgoodTipAmount);
        goodTipT = (TextView) findViewById(R.id.TVgoodTip);
        fairTip = (TextView) findViewById(R.id.TVfairTipAmount);
        fairTipT = (TextView) findViewById(R.id.TVfairTip);
        badTip = (TextView) findViewById(R.id.TVbadTipAmount);
        badTipT = (TextView) findViewById(R.id.TVbadTip);
        goodTipT.setVisibility(View.INVISIBLE);
        fairTipT.setVisibility(View.INVISIBLE);
        badTipT.setVisibility(View.INVISIBLE);
        goodTip.setVisibility(View.INVISIBLE);
        fairTip.setVisibility(View.INVISIBLE);
        badTip.setVisibility(View.INVISIBLE);
    }
	
	 /**
     * This shows all tip amounts 
     *
     */
    public void showTips(){
        goodTip = (TextView) findViewById(R.id.TVgoodTipAmount);
        goodTipT = (TextView) findViewById(R.id.TVgoodTip);
        fairTip = (TextView) findViewById(R.id.TVfairTipAmount);
        fairTipT = (TextView) findViewById(R.id.TVfairTip);
        badTip = (TextView) findViewById(R.id.TVbadTipAmount);
        badTipT = (TextView) findViewById(R.id.TVbadTip);
        goodTipT.setVisibility(View.VISIBLE);
        fairTipT.setVisibility(View.VISIBLE);
        badTipT.setVisibility(View.VISIBLE);
        goodTip.setVisibility(View.VISIBLE);
        fairTip.setVisibility(View.VISIBLE);
        badTip.setVisibility(View.VISIBLE);
    }

}// END of MainActivity
