// �ظ���

#include <ansi.h>
inherit ITEM;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void create()
{
        set_name(HIB"��ҹ�ݼ�"NOR, ({ "heal itemf", "16item" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ҹ�ݼ�����ʹ��(use id)��\n") ;
set("treasure",1);
                set("unit", "��");
                set("value", 95000);
                set("zhen", 1);
        }
        setup();
}

void init()
{
        add_action("do_shot","use");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;

        me = this_player();

 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô����?\n");

        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");


        if( me->query("combat_exp")< 500000)
        return notify_fail("��ľ���̫���ò��ˣ�\n");

        if( !objectp(ob = present("heal itemf", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(HIB"\n$n"HIB"һ�ں�����$N"HIB"  $n����ȫ���������!  \n"NOR,this_object(),me);
me->add("qi",1800);
me->add("eff_qi",1800);
        me->start_busy(1) ;
	if((int)me->query("qi") < (int)me->query("max_qi")+(int)me->query("max_qi")/2)
        {
        me->add("qi",me->query("eff_qi")/3);
        me->add("eff_qi",me->query("eff_qi")/4);
if (me->query("qi") > me->query("max_qi")+1750)
me->set("qi",me->query("max_qi")+1750);
if (me->query("eff_qi") > me->query("max_qi"))
me->set("eff_qi",me->query("max_qi"));
message_vision(HIB"$N���ϵ��˺��˲���!!\n"NOR, me);
        }


        destruct(this_object());

        return 1;
}
