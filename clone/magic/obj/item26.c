// ��ɫ�㹽

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
        set_name(BLU"�ҽ�֮��ʵ"NOR, ({ "mp itemf", "26item" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ħ��Ũ��Һ����ʹ��(use id)����˵���Իָ�����\n") ;
set("treasure",1);
                set("unit", "��");
                set("value", 110000);
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

        if( !objectp(ob = present("mp itemf", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(BLU"\n$n"BLU"һ�ڳ�����$N"BLU"  $n����ȫ���������!  \n"NOR,this_object(),me);
        me->start_busy(1) ;
me->add("neili",1700);

	if((int)me->query("neili") < (int)me->query("max_neili")+(int)me->query("max_neili")/2)
        {
        me->add("neili",me->query("max_neili")/3);
if (me->query("neili") > me->query("max_neili")+1750)
me->set("neili",me->query("max_neili")+1750);
message_vision(BLU"$N�ķ����ָ��˲���!!\n"NOR, me);
        }


        destruct(this_object());

        return 1;
}
