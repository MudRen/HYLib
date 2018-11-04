// 暗黑核融术卷轴

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


int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

         msg = HIY"$N"HIY"对着$n"HIY"扔出了一个 烟雾弹！\n"NOR;
        msg += HIY"$n"HIY"大吃一惊，不知所措!!\n"NOR;
if (userp(target))
{
target->start_busy(12);
}
else
{
target->start_busy(12);
}
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);


if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);

	return 1;
	
}

void create()
{
        set_name(HIY"超级连环烟舞弹"NOR, ({ "yanwu dan", "dan" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个可以使用的武器。可以使用(use)\n") ;

                set("unit", "个");
                set("value", 150000);
                set("zhen", 3);
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
        int damagic;
        string msg;
        object weapon;
	object	env;
	object	*inv;        
	int	i;
        me = this_player();

 	if (!id(arg))
	return notify_fail("你无法使用这个!\n");
	
        if( !arg ) return notify_fail("你想对谁使用？\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("只能对战斗中的对手使用。\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");




if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("对方比你弱小，没必要使用！\n");
	
        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");


        if( !objectp(ob = present("yanwu dan", me)) )
                return notify_fail("你没有这种东西。\n");

if (target->is_busy())
return notify_fail("现在正是用攻击敌人的时候啊！\n");
                me->start_busy(3);
              message_vision(HIY"\n$n"HIY"突然对着所有的敌人扔出了一个 烟雾弹 !!  \n"NOR,this_object(),me);

	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
 
        destruct(this_object());
        return 1;
}
