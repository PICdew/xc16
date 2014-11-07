// This file was automatically generated by localedef.

package gnu.java.locale;

import java.util.ListResourceBundle;

public class LocaleInformation_es_PA extends ListResourceBundle
{
  static final String decimalSeparator = ".";
  static final String groupingSeparator = "";
  static final String numberFormat = "#.###";
  static final String percentFormat = "#%";
  static final String[] weekdays = { null, "domingo", "lunes", "martes", "mi\u00E9rcoles", "jueves", "viernes", "s\u00E1bado" };

  static final String[] shortWeekdays = { null, "dom", "lun", "mar", "mi\u00E9", "jue", "vie", "s\u00E1b" };

  static final String[] shortMonths = { "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic", null };

  static final String[] months = { "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre", null };

  static final String[] ampms = { "", "" };

  static final String shortDateFormat = "dd/MM/yy";
  static final String defaultTimeFormat = "";
  static final String currencySymbol = "B/";
  static final String intlCurrencySymbol = "PAB";
  static final String currencyFormat = "$ #,###,##0.00;-$ #,###,##0.00";

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
