// This file was automatically generated by localedef.

package gnu.java.locale;

import java.util.ListResourceBundle;

public class LocaleInformation_ko_KR extends ListResourceBundle
{
  static final String decimalSeparator = ".";
  static final String groupingSeparator = ",";
  static final String numberFormat = "#,###,##0.###";
  static final String percentFormat = "#,###,##0%";
  static final String[] weekdays = { null, "\uC77C\uC694\uC77C", "\uC6D4\uC694\uC77C", "\uD654\uC694\uC77C", "\uC218\uC694\uC77C", "\uBAA9\uC694\uC77C", "\uAE08\uC694\uC77C", "\uD1A0\uC694\uC77C" };

  static final String[] shortWeekdays = { null, "\uC77C", "\uC6D4", "\uD654", "\uC218", "\uBAA9", "\uAE08", "\uD1A0" };

  static final String[] shortMonths = { " 1\uC6D4", " 2\uC6D4", " 3\uC6D4", " 4\uC6D4", " 5\uC6D4", " 6\uC6D4", " 7\uC6D4", " 8\uC6D4", " 9\uC6D4", "10\uC6D4", "11\uC6D4", "12\uC6D4", null };

  static final String[] months = { "\uC77C\uC6D4", "\uC774\uC6D4", "\uC0BC\uC6D4", "\uC0AC\uC6D4", "\uC624\uC6D4", "\uC720\uC6D4", "\uCE60\uC6D4", "\uD314\uC6D4", "\uAD6C\uC6D4", "\uC2DC\uC6D4", "\uC2ED\uC77C\uC6D4", "\uC2ED\uC774\uC6D4", null };

  static final String[] ampms = { "\uC624\uC804", "\uC624\uD6C4" };

  static final String shortDateFormat = "yyyy MM dd";
  static final String defaultTimeFormat = "a hh m s";
  static final String currencySymbol = "\uFFE6";
  static final String intlCurrencySymbol = "KRW";
  static final String currencyFormat = "$#,###,##0.;$-#,###,##0.";

  private static final Object[][] contents =
  {
    { "weekdays", weekdays },
    { "shortWeekdays", shortWeekdays },
    { "shortMonths", shortMonths },
    { "months", months },
    { "ampms", ampms },
    { "shortDateFormat", shortDateFormat },
    { "defaultTimeFormat", defaultTimeFormat },
    { "currencySymbol", currencySymbol },
    { "intlCurrencySymbol", intlCurrencySymbol },
    { "currencyFormat", currencyFormat },
    { "decimalSeparator", decimalSeparator },
    { "groupingSeparator", groupingSeparator },
    { "numberFormat", numberFormat },
    { "percentFormat", percentFormat },
  };

  public Object[][] getContents () { return contents; }
}
