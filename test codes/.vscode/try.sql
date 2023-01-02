DECLARE
r number:=10;
area number;

BEGIN

area :=22/7 *r*r;

dbms_output.put_line('The area of the circle is '|| area);

End;