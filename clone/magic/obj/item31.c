// ����ҩ�� 

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
        set_name(HIC"����ҩ��"NOR, ({ "jing itema", "3item" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ҩ�ۿ���ʹ��(use id)����˵���Իָ�����\n") ;
                set("unit", "��");

                set("value", 80000);
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


        if( !objectp(ob = present("jing itema", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(HIC"\n$n"HIC"һ�ڳ�����$N"HIC"  $n����ȫ���������!  \n"NOR,this_object(),me);
        me->start_busy(1) ;
me->add("jing",500);

	if((int)me->query("jing") < (int)me->query("max_jing")+(int)me->query("max_jing")/3)
        {
        me->add("jing",me->query("eff_jing")/6);
        me->add("eff_jing",me->query("eff_jing")/6);
if (me->query("jing") > me->query("max_jing")+200)
me->set("jing",me->query("max_jing")+200);
if (me->query("eff_jing") > me->query("max_jing"))
me->set("eff_jing",me->query("max_jing"));
message_vision(HIG"$N���ϵľ����˲���!!\n"NOR, me);
         }


        destruct(this_object());

        return 1;
}