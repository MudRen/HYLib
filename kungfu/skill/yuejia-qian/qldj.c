// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp,i,basic;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("yuejia-qian",1);
        if ( extra < 50) 
                return notify_fail("���������ƽǹ�����������죡\n");
                

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������Ͻ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 1500  ) 
		return notify_fail("�������������\n");

        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        if(random(hisexp) < myexp * 10 && weapon)        
        {
        message_vision(
HIW "\n\n$Nʹ��һʽ�����Ͻ�ǹ������Ы���ס$n���еı��У�"+ 
weapon->name()+  "���ֶ��ɣ�\n\n" NOR, me,target);
        if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 1000);
        msg = HIR+ "\n\n$Nʹ��һʽ�����Ͻ�ǹ�����е�"+(me->query_temp("weapon"))->name()+"����Ы��ֱ��$n��$l��\n\n"+ NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);
        me->start_busy(2);
        }
        basic = extra/50;
        if (basic>9)
                basic=9;        
                for(i=0;i<basic;i++)
                {
                        msg = HIY"��Ц���У�$N����һ�»���ǹ����"+chinese_number(i+1)+"ǹ��\n"NOR;
                        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        me->add("neili",-10);
                }
        return 1;
}