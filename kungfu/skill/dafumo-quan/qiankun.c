#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int neili, qi;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ǭ��һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("dafumo-quan", 1) < 300 )
                return notify_fail("��Ĵ��ħȭ������죬�޷�ʹ�á�Ǭ��һ������\n");
        if( (int)me->query_skill("jiuyin-zhengong", 1) < 200 )
                return notify_fail("��ľ����湦������죬�޷�ʹ�á�Ǭ��һ������\n");

        if ( (int)me->query("max_neili") < 4000)
                return notify_fail("��������������޷�ʹ�á�Ǭ��һ������\n");
        if ( (int)me->query("neili") < 6000)
                return notify_fail("��������������޷�ʹ�á�Ǭ��һ������\n");
        if (target->query("jiuyin/qiankun"))
                return notify_fail("���Ѿ��������ˣ����Ĺ����ɡ�\n");

        msg = HIY"$NͻȻ�۾�һ��������һ������ʹ��ȫ���������ȭ��$n��ȥ��\n";
        me->start_perform(6,"��Ǭ��һ����");
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg += HIR"$n��������������С����$nֻ����һ��ǿ���ľ������������Լ���������\n";
                msg += HIR"$nֻ���õ������絶����̴�С�����Ѩ��Ϣ��Ҳ�޷�˳��ͨ�У�\n"NOR;
	        neili = target->query("max_neili");
	        qi = target->query("max_qi");
                target->start_busy(random(4)+1);
                target->set("jiuyin/qiankun",1);
// set for condition
                target->set("qiankun/qi",qi);
                target->set("qiankun/neili",neili);
                target->set("max_qi",qi/2);
		if (target->query("eff_qi")>qi/2)
			target->set("eff_qi",qi/2);
                if (target->query("qi")>target->query("eff_qi")) 
                       target->set("qi",target->query("eff_qi"));
                target->set("max_neili",neili/2);
                if (target->query("neili")>target->query("max_neili"))
                       target->set("neili",target->query("max_neili"));
                target->apply_condition("qiankun_wound",(int)me->query_skill("force")/50);
		me->add("neili", -1000);
        } 
        else {
                msg += HIG"$n���������ң���æ����һ�ԡ�\n" NOR;
		me->add("neili", -300);
        }
        message_vision(msg, me, target);
        me->start_busy(2+random(3));
}else
{
        if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	) {
                msg += HIR"$n��������������С����$nֻ����һ��ǿ���ľ������������Լ���������\n";
                msg += HIR"$nֻ���õ������絶����̴�С�����Ѩ��Ϣ��Ҳ�޷�˳��ͨ�У�\n"NOR;
	        neili = target->query("max_neili");
	        qi = target->query("max_qi");
                target->start_busy(random(4)+1);
                target->set("jiuyin/qiankun",1);
// set for condition
                target->set("qiankun/qi",qi);
                target->set("qiankun/neili",neili);
                target->set("max_qi",qi/2);
		if (target->query("eff_qi")>qi/2)
			target->set("eff_qi",qi/2);
                if (target->query("qi")>target->query("eff_qi")) 
                       target->set("qi",target->query("eff_qi"));
                target->set("max_neili",neili/2);
                if (target->query("neili")>target->query("max_neili"))
                       target->set("neili",target->query("max_neili"));
                target->apply_condition("qiankun_wound",(int)me->query_skill("force")/50);
		me->add("neili", -1000);
        } 
        else {
                msg += HIG"$n���������ң���æ����һ�ԡ�\n" NOR;
		me->add("neili", -400);
        }
        message_vision(msg, me, target);
        me->start_busy(2+random(3));
}
        return 1;
}
