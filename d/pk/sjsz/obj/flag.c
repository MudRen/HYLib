//Cracked by Kafei
// FLAG

#include <ansi.h>
inherit ITEM;

string long_desc() {
    string msg;

    msg = "\n" +
HIR"    ��"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + RED"~~~~~~~~~~~~~~~~~~~~"NOR + "\n" +
HIB"    ||"NOR + RED"                  /"NOR + "\n" +
HIB"    ||"NOR + HIY"    ��������"NOR + RED"     ("NOR + "\n" +
HIB"    ||"NOR + RED"                  \\"NOR + "\n" +
HIB"    ||"NOR + RED"~~~~~~~~~~~~~~~~~~~~"NOR  + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ��"NOR + "\n";

    return msg;
}

void create() {
    set_name("���ִ���", ({ "flag" }) );
    set_weight(200);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", (: long_desc :));
        set("unit", "��");
        set("value", 100000);
    }
    set("bwdhpk",1);setup();
}
