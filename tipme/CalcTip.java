package app.android.tipme;

/**
 * This class calculates a tip based on percent and value.
 */
public class CalcTip {

    public Double CalcTip(Double billAmount, Integer percent) {

        Double tip = billAmount * (percent.doubleValue() / 100);
        return tip;
    }

}
