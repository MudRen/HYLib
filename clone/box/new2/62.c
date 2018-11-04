// 回复剂

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
        set_name(HIR"十全大补丸"NOR, ({ "dabu wan", "wan" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个神奇的药丸可以使用(use id)。\n") ;

                set("unit", "个");
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
	return notify_fail("你要用什么东西?\n");

//        if(me->is_busy() )
//                return notify_fail("你正忙着哪。\n");

        if( !objectp(ob = present("dabu wan", me)) )
                return notify_fail("你没有这种东西。\n");

        message_vision(HIG"\n$n"HIG"一口吃下了$N,"HIG" $n觉的原先的忙乱全停了下来!!并增加了气血和精力和内力!!  \n"NOR,this_object(),me);
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

me->start_busy(1);
 	me->add("max_neili",800);
 	me->add("neili",8000);
    

	me->add("jing",18000);
me->add("eff_jing",18000);       

	me->add("qi",20000);
me->add("eff_qi",20000);     


message_vision(HIG"$N觉的原先的忙乱全停了下来!!并允满了气血和精力和内力!!\n"NOR, me);
        destruct(this_object());

        return 1;
}
