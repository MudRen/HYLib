// suo.c  ������
// by star
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	 object ob,weapon,myweapon;
        string msg, string1;
        int skill,myskill;
	int extra;

	if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("�������꡹ֻ����ս����ʹ�á�\n");

       if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("�������꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

 	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������꡹��ʼʱ��������һ�ѽ���\n");
     
	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

        if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("����嶾����Ϊ��������\n");

	if( (int)me->query_skill("sword",1) < 50 ||
	    me->query_skill_mapped("sword") != "wudu-goufa")
		return notify_fail("����嶾�����������ң��޷�ʹ�ý����꣡\n");

	if( (int)me->query_skill("wudu-goufa",1) < 50 )
		return notify_fail("����嶾�����������ң��޷�ʹ�ý����꣡\n");
 	if (!objectp(weapon = target->query_temp("weapon"))
 	&&(int)me->query_skill("wudu-goufa",1) >150 )
{
 weapon = me->query_temp("weapon");
	extra = me->query_skill("wudu-goufa",1) / 3;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
         msg = HIY "��Ы���룡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "���߲���\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "���ű䣡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "������! \n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "�������ţ�\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "������צ��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
            me->add("neili",-200);
            me->start_busy(3);
return notify_fail(HIR"�Է����в�û�б�������ֻ��ֹͣ�˹���\n"NOR);
}
 	if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("�Է����в�û�б�����\n");

       weapon=target->query_temp("weapon");
       myweapon=me->query_temp("weapon");
	extra = me->query_skill("wudu-goufa",1) / 3;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
         msg = HIY "��Ы���룡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "���߲���\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "���ű䣡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "������! \n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "�������ţ�\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "������צ��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
//message_vision(msg, me,target);
 	message_vision(HIR "\n$N���һ�У�����"+myweapon->query("name")+"����һ���������Ѵ���$n��"+weapon ->query("name")+HIR"�ϣ�\n" NOR,me,target);
       skill = target->query_skill("parry",1);             // 32
       myskill = me->query_skill("wudu-goufa",1);
       if(random(myskill) < random(skill/2)||me->query("max_neili") <random(target->query("max_neili"))){
	     msg = HIY "����$n����׼������æ����������\n" NOR;
            message_vision(msg, me,target);
            me->start_busy(3);
            me->add("neili",-200);
            return 1; 
       }
 
	msg = HIR "ֻ��$N˳��һ�ʣ��ͺ�һ���������֣���$nֻ���û���һ���ʹ��\n����"+weapon->query("name")+HIR"���һ�����ڵ��ϣ�\n" NOR;
       message_vision(msg,me,target);
	msg = "$N����һЦ���������ˣ����н��ƣ�\n" NOR;
       message_vision(msg, me,ob);
	me->clean_up_enemy();
	ob = me->select_opponent();
       weapon->move(environment(me));
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
               target->apply_condition("snake_poison",
                        (int)target->query_condition("snake_poison") + 50 );
               target->apply_condition("wugong_poison",
                        (int)target->query_condition("wugong_poison") + 50 );
               target->apply_condition("zhizhu_poison",
                        (int)target->query_condition("zhizhu_poison") + 50 );
               target->apply_condition("xiezi_poison",
                        (int)target->query_condition("xiezi_poison") + 50 );
               target->apply_condition("chanchu_poison",
                        (int)target->query_condition("chanchu_poison") + 50 );
	msg = HIY"$Nʹ�����嶾�󷨣�$nֻ�����˴�һ���飬�ƺ��ж��ˡ�\n" NOR;
       message_vision(msg, me,ob);
}
	me->add("neili", -300);
	me->start_busy(3);
	return 1;
}