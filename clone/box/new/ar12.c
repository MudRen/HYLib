#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"ĵ������"NOR, ({"pifen12"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("long", "һ��ĵ�����磮\n");
                set("material", "steel");
                set("value", 3500);
                set("armor_prop/armor", 79);
set("armor_prop/damage", 19);
set("armor_prop/attack", 18);
        }
        setup();
}


