#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"��ϼ����"NOR, ({"pifen9"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("long", "һ����ϼ���磮\n");
                set("material", "steel");
                set("value", 3200);
                set("armor_prop/armor", 66);
set("armor_prop/damage", 17);
set("armor_prop/attack", 17);
        }
        setup();
}


