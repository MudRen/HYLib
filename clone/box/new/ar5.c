#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"��ѩ����"NOR, ({"pifen5"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("long", "һ����ѩ���磮\n");
                set("material", "steel");
                set("value", 2800);
                set("armor_prop/armor", 62);
set("armor_prop/damage", 15);
set("armor_prop/attack", 15);
        }
        setup();
}

