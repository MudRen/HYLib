//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"��"HIW"��"HIC"��"NOR, ({"jinyin hua","hua"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","���������ٱ�ֲ����ֽ�����ɫ������ҩ���ܻ����\n");
                set("value", 30);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",1);
		        set("cure_n",0);
		
        }
        setup();
}
