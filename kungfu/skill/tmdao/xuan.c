// xuan.c
// modify by xiha@wmkj

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
int get_current_day_phase();
static mapping *day_phase = NATURE_D->query_day_phase(); 

int perform(object me, object target)
{
	object weapon, ob;
	string msg; 
	int phase = get_current_day_phase(); 
	int extra,count = 0;
 
	
	 if( !target ) target = offensive_target(me);
         if( !target || !target->is_character() || !me->is_fighting(target) )
 	      return notify_fail("「眩刀」只能对战斗中的对手使用。\n");
        
 	
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
        
        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
        return notify_fail("你手中没有装备刀类武器！\n");
        if( (int)me->query("neili")<500)
        return notify_fail("你现在内力太弱，不能使用！\n"NOR);


          if (uptime() - me->query_temp("last_pf_time") < 2 )
          return notify_fail("出奇才能至胜。\n");
         //用冰刀加2招
         count = 2;
         
           
         
	if( (int)me->query("neili") < 200 )
		return notify_fail("你的内力不够了！\n");

	if( (int)me->query_skill("blade") < 160 ||
	    me->query_skill_mapped("blade") != "tmdao")
		return notify_fail("你的「基本刀法」还不到家，无法使用「眩刀」！\n");
        
        if( (int)me->query_skill("tmdao") < 160 )
            return notify_fail("你的「天魔刀」还不到家，无法使用「眩刀」！\n");
	
        msg = HIW "$N猛然将刀身一横，明晃晃的刀身在日光下反射一片白光,直射$n的面门！\n" NOR;
        message_vision(msg, me, target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )	
	 {  msg = HIW "$N只觉一道眩光刺得双眼什么都看不见了，$n见状大喜连续五刀，从五个不同的方向砍来！\n" NOR;	
	    message_vision(msg, target,me);
	     extra = me->query_skill("tmdao",1) / 50;
	    if(extra>4) extra = 4 ; target->start_busy(extra + count);
	  }else{
	       msg = "可是$n看破了$N的企图，往旁一闪躲了过去。\n" NOR;
	       message_vision(msg, me, target);
                me->set_temp("last_pf_time",uptime());
               me->start_busy(1+random(3));
	       return 1;
           }
	me->set_temp("action_flag", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("action_flag");
	me->add("neili", -250);
	me->start_busy(2);
        me->set_temp("last_pf_time",uptime());
	return 1;
}



int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time()*60);
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
        if (t>=day_phase[i]["length"])
            t -= (int)day_phase[i]["length"];
        else
            break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}
