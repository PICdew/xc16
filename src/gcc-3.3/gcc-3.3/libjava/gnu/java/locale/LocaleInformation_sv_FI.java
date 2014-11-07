// This file was automatically generated by localedef.

package gnu.java.locale;

import java.util.ListResourceBundle;

public class LocaleInformation_sv_FI extends ListResourceBundle
{
  static final String decimalSeparator = LocaleInformation_fi_FI.decimalSeparator;
  static final String groupingSeparator = LocaleInformation_fi_FI.groupingSeparator;
  static final String numberFormat = LocaleInformation_fi_FI.numberFormat;
  static final String percentFormat = LocaleInformation_fi_FI.percentFormat;
  static final String[] weekdays = { null, "s\u00F6ndag", "m\u00E5ndag", "tisdag", "onsdag", "torsdag", "fredag", "l\u00F6rdag" };

  static final String[] shortWeekdays = { null, "s\u00F6n", "m\u00E5n", "tis", "ons", "tor", "fre", "l\u00F6r" };

  static final String[] shortMonths = { "jan", "feb", "mar", "apr", "maj", "jun", "jul", "aug", "sep", "okt", "nov", "dec", null };

  static final String[] months = { "januari", "februari", "mars", "april", "maj", "juni", "juli", "augusti", "september", "oktober", "november", "december", null };

  static final String[] ampms = { "", "" };

  static final String shortDateFormat = "yyyy-MM-dd";
  static final String defaultTimeFormat = "";
  static final String currencySymbol = LocaleInformation_fi_FI.currencySymbol;
  static final String intlCurrencySymbol = LocaleInformation_fi_FI.intlCurrencySymbol;
  static final String currencyFormat = LocaleInformation_fi_FI.currencyFormat;

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