//Cracked by Roath
// weapon: /d/zhongnan/obj/yaochu.c
// sdong 08/06/98

#include <weapon.h>

inherit HAMMER;

void create()
{
		  set_name("ҩ��", ({ "yao chu", "chu" }) );
		  set_weight(1000);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
					 set("unit", "��");
					 set("long", "����һ��ȫ��̵���������ר�Ų�ҩ�õ�ҩ����\n");
                set("value", 50);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(5);
		  setup();
}

init()
{
	object me = this_player();
	 if ( me->query("id",1)!="qiu chuji" && !wizardp(me)) {
		set("no_drop",  "��ô���õĶ�����ô�������ء�\n");
		set("no_steal", "���������͵������\n");
		}
}
