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
        set_name(HIR"������"NOR, ({ "shennen wan", "wan" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������ҩ�����ʹ��(use id)��\n") ;

                set("unit", "��");
                set("value", 50000);
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

//        if(me->is_busy() )
//                return notify_fail("����æ���ġ�\n");

        if( !objectp(ob = present("shennen wan", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(HIY"\n$n"HIY"һ�ڳ�����$N,"HIY" $n����Ǳ�ܺ;���Ӷ���!  \n"NOR,this_object(),me);
me->add("qi",500);
me->add("eff_qi",500);
        
	if((int)me->query("qi") < (int)me->query("max_qi")+(int)me->query("max_qi")/3)
        {
        me->add("qi",me->query("eff_qi")/6);
        me->add("eff_qi",me->query("eff_qi")/6);
if (me->query("qi") > me->query("max_qi")+200)
me->set("qi",me->query("max_qi")+200);
if (me->query("eff_qi") > me->query("max_qi"))
me->set("eff_qi",me->query("max_qi"));
        }

	me->add("combat_exp", 100000+random(88888));
	me->add("potential",50000+random(88888));        
	me->add("max_neili",500);

message_vision(HIY"$N����Ǳ�ܺ;���Ӷ���!!\n"NOR, me);
        destruct(this_object());

        return 1;
}
