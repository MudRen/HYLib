//sunarrow ����֮��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"������֮����ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-light",1)< 750)
	return notify_fail("��Ĺ���ħ��̫���ˣ�\n");

	msg = HIY "$N"HIY"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
        msg += HIY"$N"HIY"� �ȴ󺣸���������ˣ� ����ո���������Զ���� \n"NOR;
        msg += HIY"$N"HIY"� ߵ�ݹ����Ӣ�飬����������������Բ׶!!\n"NOR;
        msg += HIY"$N"HIY"� ΰ�����֮���ǰ�����������â�����밵!\n"NOR;
        msg += HIY"$N"HIY"� �췣֮ʱ�Ѿ�������������ʥ����ͷ�ƽ����������ɣ���������!\n"NOR;
       msg += HIY"���޾�����������У�һ����̫��������"HIR"����֮��"HIY"��$n"HIY"��ȥ��\n"NOR;
	if((int)me->query("qi") < (int)me->query("max_qi")+(int)me->query("max_qi")/3)
        {
msg += HIY"����֮����ʹ$N"HIY"���帴ԭ��\n"NOR;
        me->add("qi",me->query("eff_qi")/3);
        me->add("eff_qi",me->query("eff_qi")/3);
if (me->query("qi") > me->query("max_qi")+1800)
me->set("qi",me->query("max_qi")+1800);
if (me->query("eff_qi") > me->query("max_qi"))
me->set("eff_qi",me->query("max_qi"));
        }
	if((int)me->query("jing") < (int)me->query("max_jing")+(int)me->query("max_jing")/3)
        {
msg += HIY"����֮����ʹ$N"HIY"�ľ���һ��\n"NOR;
        me->add("jing",me->query("eff_jing")/3);
        me->add("eff_jing",me->query("eff_jing")/3);
if (me->query("jing") > me->query("max_jing")+1800)
me->set("jing",me->query("max_jing")+1800);
if (me->query("eff_jing") > me->query("max_jing"))
me->set("eff_jing",me->query("max_jing"));

         }
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-light", 1);
//�Թ�����Ŀ��������
       if ((int)target->query("magicgift")==6)
{
damagic=3000+damage;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);

damagic=2000+damage;
                target->receive_wound("qi", damagic);
}
//�԰�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==5)
{
damagic=6900+damage*6;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
damagic=6900+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=2000+damage*3;
target->receive_damage("qi", 2000+damage*3);
target->receive_wound("qi", 2000+damage*2);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
target->start_busy(1);
msg += HIY"                                               \n"NOR;
msg += HIR"������������������������������������������������������\n"NOR;
msg += HIR"                 ��� ���      ���  ���         \n"NOR;
msg += HIR"        ��      ��������     ����֮��!!!!         \n"NOR;
msg += HIR"        ����������������������������������������������    \n"NOR;
msg += HIR"         ��     ��������  ��������              \n"NOR;
msg += HIR"                 ��� ���      ���  ���            \n"NOR;        
msg += HIR"������������������������������������������������������\n"NOR;
msg += HIY"                                               \n"NOR;
        msg += HIY"�췣֮ʱ�Ѿ�������!!$n���⵽�˹�����о�!!\n"NOR;
        msg += HIY"$nȫ��ʥ��������!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
damagic=1500+damage*2;
                target->receive_damage("qi", damagic);
damagic=1500+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
msg += HIY"                                               \n"NOR;
msg += HIR"������������������������������������������������������\n"NOR;
msg += HIR"                 ��� ���      ���  ���         \n"NOR;
msg += HIR"        ��      ��������     ����֮��!!!!         \n"NOR;
msg += HIR"        ����������������������������������������������    \n"NOR;
msg += HIR"        ��     ��������  ��������              \n"NOR;
msg += HIR"                 ��� ���      ���  ���            \n"NOR;        
msg += HIR"������������������������������������������������������\n"NOR;
msg += HIY"                                               \n"NOR;
        msg += HIY"�췣֮ʱ�Ѿ�������!!$n���⵽�˹�����о�!!\n"NOR;
        msg += HIY"$pʹ��ȫ�����ֿ�ʥ�⣬�����Ǹ�ʥ�������ˡ�\n"NOR;
		message_combatd(msg, me, target);
        }

if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);                

                me->start_busy(4);
                me->add("neili", -2000);
        return 1;
}
