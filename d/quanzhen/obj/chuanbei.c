//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"����"NOR, ({"chuanbei"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","�������������ݱ�ֲ���������Σ��油�������������˶�����Ч��\n");
                set("value", 400);
				set("yaocai", 1);
        		set("cure_s",10);
		        set("cure_d",0);
		        set("cure_n",0);
		
        }
        setup();
}
