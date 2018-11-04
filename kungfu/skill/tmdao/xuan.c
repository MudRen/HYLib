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
 	      return notify_fail("��ѣ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
 	
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
        
        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
        return notify_fail("������û��װ������������\n");
        if( (int)me->query("neili")<500)
        return notify_fail("����������̫��������ʹ�ã�\n"NOR);


          if (uptime() - me->query_temp("last_pf_time") < 2 )
          return notify_fail("���������ʤ��\n");
         //�ñ�����2��
         count = 2;
         
           
         
	if( (int)me->query("neili") < 200 )
		return notify_fail("������������ˣ�\n");

	if( (int)me->query_skill("blade") < 160 ||
	    me->query_skill_mapped("blade") != "tmdao")
		return notify_fail("��ġ������������������ң��޷�ʹ�á�ѣ������\n");
        
        if( (int)me->query_skill("tmdao") < 160 )
            return notify_fail("��ġ���ħ�����������ң��޷�ʹ�á�ѣ������\n");
	
        msg = HIW "$N��Ȼ������һ�ᣬ���λεĵ������չ��·���һƬ�׹�,ֱ��$n�����ţ�\n" NOR;
        message_vision(msg, me, target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )	
	 {  msg = HIW "$Nֻ��һ��ѣ��̵�˫��ʲô���������ˣ�$n��״��ϲ�����嵶���������ͬ�ķ�������\n" NOR;	
	    message_vision(msg, target,me);
	     extra = me->query_skill("tmdao",1) / 50;
	    if(extra>4) extra = 4 ; target->start_busy(extra + count);
	  }else{
	       msg = "����$n������$N����ͼ������һ�����˹�ȥ��\n" NOR;
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
