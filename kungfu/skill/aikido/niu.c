
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
string* buwei = ({
        "�����ⲿ",
        "����",
        "���ֹؽ�",
        "����",
        "�粿�ؽ�",
        "����ҪѨ",
        "ϥ�ؽ�",
        "����"
});
int perform(object me, object target)
{
        object weapon;
        string msg;
       int extra;
        int i, attack_time;
        string bw;
        
        
        bw = buwei[random(sizeof(buwei))];

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������.��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������.�ܱ�����֡�\n");
       if( (int)me->query("max_neili") < 200 )
      return notify_fail("�������������\n");
	extra = me->query_skill("aikido",1)/10;
	if(extra <= 3 ) return notify_fail("��ģۺ������ݲ���������\n");
     if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("���ɱ���ķ���򲻹���\n");
               
	if( (int)me->query("neili") < 200  ) 
		return notify_fail("�������������\n");

        msg = HIG "$N˫üһ�һ�����ö�Ȼ��ץס��$n��"+bw+"Ȼ���"+bw+"������һŤ��!\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR " ���$p��$PŤ�Ĳҽв�ֹ�������˵Ĳ��壡\n" NOR;
if (userp(target))
                target->add("qi",-target->query("qi")/10);
else            target->add("qi",-extra*20);
        } else {
                msg += HIC"����$p������$P����ͼ��������$P�����á�\n"NOR NOR;
        }
        message_combatd(msg, me, target);
                me->start_busy(2);
	me->add("neili", - 100);
        if(!target->is_fighting(me)) target->fight_ob(me);

        return 1;
}

