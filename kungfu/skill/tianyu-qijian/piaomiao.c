// ��翽�
 
#include <ansi.h>
#include <combat.h> 
#include <skill.h>

inherit F_SSERVER;

int perform(object me, object target)
{
         string name,dodge_skill,msg;
         int i, j, p;
 
         object weapon = me->query_temp("weapon");
        
         if( !target ) target = offensive_target(me);
 
         if( !target || !me->is_fighting(target) )
                 return notify_fail("��翽�ֻ����ս���жԶ���ʹ�á�\n");
         if(!weapon || weapon->query("skill_type") != "sword")
                 return notify_fail("�����ʹ����������ʹ�á���翽�����\n");   

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("tianyu-qijian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("zhemei-shou", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bahuang-gong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ���չ���ѧ��ʹ�������չ��ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
 
         me->set_temp("xtj_haichao", 1);
         message_vision(MAG"\n$N"+weapon->name()+MAG"΢΢�ζ��������������۷�ʱ��˫ü��������ǰ�磬һ�ɳ��ǵĽ�����������ӿ��ȥ��\n"NOR,me,target);
         i = me->query_skill("tianyu-qijian", 1)/2;
         j = me->query_skill("sword", 1)/2;
         me->add_temp("apply/strength", i);
         me->add_temp("apply/attack", j);
         me->add_temp("apply/damage", j); 
           if (random(3)==0) target->start_busy(3);
           msg = HIC "$w"HIC"��$N�þ���ָ���£����������������ƿ�֮����������������ɳ��۵ĺ�Х������ʹ���ĺ���������ƣ�" NOR;  
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg); 
           msg = HIC "$N�ӽ����裬һʱ�����ݺᣬ�����ྲ�ද����ʱ������ƽ�羵�Ĵ󺣣���ʱ����ŭ�����Σ��仯Ī�⣡" NOR;             
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);      
           msg = HIC "$Nÿһ��̬���������ۣ�ÿһ�����������ֳ��������ܵļ��ޣ����ľ��ּ��ң��γɾ��������������ƣ�" NOR; 
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);	

         me->add_temp("apply/strength", -i);
         me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -j);
	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 ){
         message_vision(HIW"\nͻȻ�������һ�����죬һ�����绮��ҹ������"+weapon->name()+HIW"�ϣ�$NЮ�׵�֮������$n���˹�ȥ��\n"NOR,me,target);
	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 ){
		message_vision(HIR"���$n����������$N�������ţ�" + weapon->name() + HIR"�ϵ�"HIC"�羢"HIR"�˻�����$n���ڡ�\n"NOR,me,target);
              p = 2+random(4);
              	target->receive_damage("qi", i*5);
		target->receive_wound("qi", i*4);
		target->apply_condition("ss_poison", 5+(me->query_str()/10)); }
	else {
         dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);	
		}
		}
weapon->unequip();
if (random(2)==0) target->start_busy(3);
msg = YEL "$N΢΢һЦ��������$n���ᵯ����������Ҫ��ȥ÷�������¶�飡" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 1,msg);                                             message_vision(HIW"                                          ���� ÷��"NOR, me, target); 
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
msg = YEL "$N˫�ּ��ӣ�����ҡ�ڣ��ó�����÷������ѩ�Ƶ���$n������" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 2,msg);                                           message_vision(HIW"                                          ���� ѩ��"NOR, me, target); 
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
msg = YEL "$nͻȻ�ŵ�һ���������޵���ζ����Գ����֮��$N��˫������$p�ؿ�������" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3,msg);                                             message_vision(HIW"                                          ��ɢ���㡿\n"NOR, me, target); 
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
msg = HIR "$N˫�ֻó�������Ӱ���������÷������$n������һƬ÷��֮�У�"NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 4,msg);
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
me->start_busy(4);
       return 1;
 }

 