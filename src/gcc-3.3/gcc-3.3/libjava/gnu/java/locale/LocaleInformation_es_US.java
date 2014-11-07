// This file was automatically generated by localedef.

package gnu.java.locale;

import java.util.ListResourceBundle;

public class LocaleInformation_es_US extends ListResourceBundle
{
  static final String decimalSeparator = LocaleInformation_en_US.decimalSeparator;
  static final String groupingSeparator = LocaleInformation_en_US.groupingSeparator;
  static final String numberFormat = LocaleInformation_en_US.numberFormat;
  static final String percentFormat = LocaleInformation_en_US.percentFormat;
  static final String[] weekdays = { null, "domingo", "lunes", "martes", "mi\u00E9rcoles", "jueves", "viernes", "s\u00E1bado" };

  static final String[] shortWeekdays = { null, "dom", "lun", "mar", "mi\u00E9", "jue", "vie", "s\u00E1b" };

  static final String[] shortMonths = { "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic", null };

  static final String[] months = { "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre", null };

  static final String[] ampms = { "", "" };

  static final String shortDateFormat = "dd/MM/yy";
  static final String defaultTimeFormat = "";
  static final String currencySymbol = "$";
  static final String intlCurrencySymbol = "USD";
  static final String currencyFormat = "$#,###,##0.00;-$#,###,##0.00";

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
