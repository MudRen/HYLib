// xi.c
// ���Ǵ� ��.c    By poopoo
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int exert(object me, object target)
{

        int sp, dp;
        int my_max, tg_max;
        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("tmdafa",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

        if ( !target ) target = offensive_target(me);

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");
        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("��Ҫ��ȡ˭��������\n");
        if (target->query("race") != "����")
                return notify_fail("����ˣ��ⲻ���ˣ�\n");

        my_max = me->query("max_neili");
        tg_max = target->query("qi");

        if ( me->query_temp("sucked") )
                return notify_fail("�������˹�֮�У�\n");

        if( !me->is_fighting() || !target->is_fighting())

        if( (int)me->query_skill("tmdafa",1) < 100 )
                return notify_fail("�����ħ�󷨹���������������ȡ�Է����������\n");
	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");

        if( (int)me->query("neili") < 100 )
                return notify_fail("�����������������ʹ�����Ǵ󷨡�\n");
	if( (int)me->query("neili") > 20000 )
		return notify_fail("���������̫�࣬������ȡ�ˡ�\n");
	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�����Ǵ󷨣�\n");
        if ( !wizardp(this_player()) && (me->query("family/family_name") != "�������"))
                return notify_fail("�㲻��������̵��ӣ�����ʹ�����Ǵ󷨡�\n");
        if ( !wizardp(this_player()) && (me->query("family/master_name") != "������"))
                return notify_fail("ֻ���ν����״����Ӳ���ʹ�����Ǵ󷨡�\n");

	if( (int)target->query("max_neili") < 100 )
		return notify_fail( target->name() +
			"��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

        if( (int)target->query("max_neili") < (int)me->query("max_neili")/10 )
		return notify_fail( target->name() +
			"���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");
			
      if( target->query_temp("no_kill") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");

        if(target==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

       if(me->is_busy())
        return notify_fail("��������æ��\n");
     message_vision(
        HIR "$N����һ�ۣ��������Ĵ󷨣�ȫ��ǽڷ���һ�󱬶�������죬�ƺ�Ҫɱ���ˡ�\n" NOR, me);

        message_combatd(
                HIB "$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,
                me, target );
        if ( living(target) )
        {
                if( !target->is_killing(me) ) target->kill_ob(me);
        }
        me->set_temp("sucked", 1);              
        if (( random(sp) > random(dp) ) || !living(target) )
        {
                tell_object(target, HIB "��ֻ���춥���ѣ�ȫ�������Զ���������ѩ����ʧ����Ӱ���٣�\n" NOR);
                tell_object(me, HIR "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);
        if( (int)me->query_skill("force") < (int)me->query("max_neili") /18 )
{
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/5) );
                call_out("del_sucked", 10, me);
                return notify_fail("����ڹ�̫���ˣ��Ѿ������������ˡ�\n");
}
        if( (int)target->query("qi") < 50 )
{
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/5) );
                call_out("del_sucked", 10, me);
                return notify_fail( target->name() +
                        "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");
}
        if( (int)target->query("qi") < (int)me->query("max_neili")/18 )
{
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/5) );
                call_out("del_sucked", 10, me);
                return notify_fail( target->name() +
                        "���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");
}
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/6) );
                call_out("del_sucked", 10, me);
                me->add("max_neili",  1*(1+(me->query_skill("tmdafa", 1)-90)/6) );
 if ( target->query("max_neili") <1) target->set("max_neili",0);
                me->start_busy(7);
                target->start_busy(random(7));
                me->add("neili", -10);
                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_combatd(HIY "����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��\n" NOR, me, target);
                me->start_busy(7);
                call_out("del_sucked", 20, me);
        }
        return 1;
}
void del_sucked(object me)
{
if (!me) return;
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}
