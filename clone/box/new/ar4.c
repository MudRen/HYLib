#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"Ʈѩ����"NOR, ({"pifen4"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("long", "һ��Ʈѩ���磮\n");
                set("material", "steel");
                set("value", 2700);
                set("armor_prop/armor", 61);
set("armor_prop/damage", 15);
set("armor_prop/attack", 14);
        }
        setup();
}


