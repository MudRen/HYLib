// written by lmimi
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra,extrb;
    object weapon;
    extra = me->query_skill("diwangquan",1);

    if ( extra < 180) return notify_fail("������������ȭ���������죡\n");
if(me->is_busy()) me->remove_busy();

        if( me->query("neili") <= 500 )
                return notify_fail("�������������\n");
        if( me->query("jing") <= 500 )
                return notify_fail("��ľ���������\n");
                
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("��������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    weapon = me->query_temp("weapon");

      if( objectp(me->query_temp("weapon")) )
           return notify_fail("��������ʹ�ã�\n");     
target->set_temp("is_unconcious",1);
if (extra > 200) extra=200;
    me->add_temp("apply/attack",100);
    me->add_temp("apply/damage",1500);
    msg = HIM  "$N���һ��,ʹ���˺�����ĳ���������" + HIC "������ʽ" + HIM "����˫�����಻������$n�ĳ���\n" NOR;
    message_vision(msg,me,target);

if (random(3)==0)
    target->start_busy(4);

   
    msg = HIW  "\n����һʽ---�����񡹣�\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    msg = HIG  "\n  ���ڶ�ʽ---���߷ɶ�����\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   
    msg = HIY  "\n    ������ʽ---���̻��᡹��\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

    msg = BLU  "\n      ������ʽ---������������\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   
    msg = WHT  "\n        ������ʽ---���ڻ�Ծ����\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    msg = MAG  "\n          ������ʽ---��Խ��������\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  
    msg = CYN  "\n            ������ʽ---������项��\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    msg = HIC  "\n              �����һʽ---���Ĵ��ˡ���\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",-100);
    me->add_temp("apply/damage",-1500);

target->delete_temp("is_unconcious");
  me->start_busy(3);
  me->add("neili",-380);
    return 1;
}
