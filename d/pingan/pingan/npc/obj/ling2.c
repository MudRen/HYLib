#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"�׻���"NOR, ({ "baihuling" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
		set("value", 400000);
            set("unit", "��");
            set("material", "paper");
            set("long", "�����ھֵ����ơ��������huwei��Ҫ����.\n");
          }

    setup();
}

void init()
{
	add_action("do_alert", "huwei");
}

int do_alert()
{
       object ob,me=this_player();
       object man;
	int strategy,leadership;
       if( !me->is_fighting() )
       return notify_fail("����û����Ҫɱ�㣡\n");
       man=new("/d/pingan/npc/baihu");
       man->move(environment(me));
       man->set("possessed", me);
       man->invocation(me, (leadership+strategy));
       me->remove_all_killer();
       destruct(this_object());
//	message_vision(HIB "\n$N����һ������Ԯ��\n" NOR, me);	
//	message_vision(HIB "\n$NӦ��������\n" NOR, soldier);
       return 1;
}
