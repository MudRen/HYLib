#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"嫺�����"NOR, ({"pifen11"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("long", "һ��嫺����磮\n");
                set("material", "steel");
                set("value", 3400);
                set("armor_prop/armor", 78);
set("armor_prop/damage", 18);
set("armor_prop/attack", 18);
        }
        setup();
}


