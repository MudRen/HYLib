// wenshu
#include <ansi.h>
inherit ITEM;
string target;

void create()
{
	set_name(WHT "��������" NOR, ({ "wenshu", "wen",}));
	set("weight", 100);
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "��");
		set("long", WHT"����һ���������飬������һ�����񣬵�����һ��С�֡�\n" NOR);
//		set("value", 50000);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
                set("no_steal",1);
        	}
	setup();
}
 
 
#include "/quest/guanfu/wenshu1.h"
