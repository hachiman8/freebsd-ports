--- src/ztype.c.orig	2013-04-30 10:46:12.000000000 +0900
+++ src/ztype.c	2013-04-30 10:46:55.000000000 +0900
@@ -53,10 +53,10 @@
  * constant expressions, so we can't use min_long and max_long.
  * What a nuisance!
  */
-#define ALT_MIN_LONG (-1L << (arch_sizeof_long * 8 - 1))
-#define ALT_MAX_LONG (~(ALT_MIN_LONG))
-private const double min_int_real = (ALT_MIN_LONG * 1.0 - 1);
-private const double max_int_real = (ALT_MAX_LONG * 1.0 + 1);
+#define ALT_MIN_INT (-1 << 31)
+#define ALT_MAX_INT (~(ALT_MIN_INT))
+static const double min_int_real = (ALT_MIN_INT * 1.0 - 1);
+static const double max_int_real = (ALT_MAX_INT * 1.0 + 1);
 
 #define REAL_CAN_BE_INT(v)\
   ((v) > min_int_real && (v) < max_int_real)
@@ -356,14 +356,14 @@
 		return_op_typecheck(op - 2);
 	}
     } else {
-	ulong ival;
+	uint ival;
 	byte digits[sizeof(ulong) * 8];
 	byte *endp = &digits[countof(digits)];
 	byte *dp = endp;
 
 	switch (r_type(op - 2)) {
 	    case t_integer:
-		ival = (ulong) op[-2].value.intval;
+		ival = (uint) op[-2].value.intval;
 		break;
 	    case t_real:
 		{
