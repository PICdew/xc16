------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUNTIME COMPONENTS                          --
--                                                                          --
--                         G N A T . S I G N A L S                          --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--             Copyright (C) 2003 Free Software Foundation, Inc.            --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNAT;  see file COPYING.  If not, write --
-- to  the Free Software Foundation,  59 Temple Place - Suite 330,  Boston, --
-- MA 02111-1307, USA.                                                      --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

with System.Interrupts;

package body GNAT.Signals is

   package SI renames System.Interrupts;

   ------------------
   -- Block_Signal --
   ------------------

   procedure Block_Signal (Signal : Ada.Interrupts.Interrupt_ID) is
   begin
      SI.Block_Interrupt (SI.Interrupt_ID (Signal));
   end Block_Signal;

   ----------------
   -- Is_Blocked --
   ----------------

   function Is_Blocked
     (Signal : Ada.Interrupts.Interrupt_ID)
      return Boolean
   is
   begin
      return SI.Is_Blocked (SI.Interrupt_ID (Signal));
   end Is_Blocked;

   --------------------
   -- Unblock_Signal --
   --------------------

   procedure Unblock_Signal (Signal : Ada.Interrupts.Interrupt_ID) is
   begin
      SI.Unblock_Interrupt (SI.Interrupt_ID (Signal));
   end Unblock_Signal;

end GNAT.Signals;

