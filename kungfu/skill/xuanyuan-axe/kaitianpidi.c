 // tie@fengyun
#include <ansi.h>
#include <combat.h>
//inherit NPC;
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,a;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");

        extra = me->query_skill("xuanyuan-axe",1);
        if ( extra < 30) return notify_fail("�����ԯ�������������죡\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۿ���ٵأ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");
    
    extra=extra/3;
if (extra> 200) extra=200;    
        me->add_temp("apply/damage", extra);
a=extra/4;
if (a> 12) a=12;
        msg = HIY  "$N"+HIY"�߸ߵؾ������е�"+ weapon->name()+ HIY"��ȫ��֮��������$n"+HIY"��Ȼ���£�" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	for(i=0;i<a;i++)
	{
       msg = HIC "����ٵص�"+(i+1)+"ʽ $N�߾�"+ weapon->name()+ HIC"��$n"+HIC"��Ȼ���£�\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili",-40);
	}
        me->add_temp("apply/damage", -extra);
       me->start_busy(3);
        return 1;
}
