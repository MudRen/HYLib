// perform dodge.shenxingbaibian

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
     string msg;
        int extra,i,j,lmt;
        object weapon;
extra = me->query_skill("diwangquan",1);
  weapon = me->query_temp("weapon");
if ( extra < 100) return notify_fail("�����������ȭ���������죡\n");

 if( !target ) target = offensive_target(me);
  if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ΰٱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                        if(me->is_busy()) return notify_fail("������û�գ���\n");

        if( me->query("neili") <= 500 )
                return notify_fail("�������������\n");
        if( me->query("jing") <= 500 )
                return notify_fail("��ľ���������\n");
                
i = random(10);
if(me->query_skill_mapped("force") == "shenlong-xinfa")
{
switch(i)

{case 0:
case 1:

{
message_vision(HIW"$N��������������������$n���ߣ�ͻȻʹ��ΤС���ľ�����" + HIC "���аٱ�" + HIW "����\n"NOR,me,target);
        if(random((int)target->query("combat_exp")) < 10*(int)me->query("combat_exp"))

        {
        message_vision(HIW"���$N��Ū��ͷ���ۻ�,��֪���룡\n"NOR,target);
        target->start_busy(3);

        }
        else{
        message_vision(HIY"$NǱ������,���о���,��û���ܵ��Ի�\n"NOR,target);
        target->start_busy(2);
        me->start_busy(1);
        }

        break;}
case 2:
case 3:
case 4:
case 5:
case 6:


{

        msg = RED "$Nƴ��ȫ����ʹ�����ΰٱ�����������һʽ��" + HIC "һ�Ŷ�Ǭ��" NOR + RED"����\n" ;
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
{msg += HIR "ֻ��$nһ���ҽ�,��������һ̯����һ����̱����ȥ��\n" NOR;
target->receive_damage("qi",(int) me->query("max_qi"));
              target->start_busy(1+random(1));}
else {msg += CYN "$n��æ�͵ش��,��Ȼ�����������һ��,ȴҲ�Ǳ�����,�亹ֱð��\n" NOR;
target->start_busy(1+random(1));}
me->start_busy(1);
message_vision(msg, me, target);
break;}
case 7:
case 8:
case 9:
{msg = HIM  "$NͻȻ���ȼ�ɨ��������´�Ƭɳʯ������һ��Ϊ����ǰ��л����������У�" NOR;
message_vision(msg,me,target);
target->set_temp("is_unconcious",1);

lmt = random(6)+3;
for(j=1;j<=lmt;j++)
        {
        msg =  HIM "��"+chinese_number(j)+"�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }

 target->delete_temp("is_unconcious");
me->start_busy(1);
target->start_busy(1+random(1));
break;}}}

else
{
switch(i)

{case 0:
case 1:

{
message_vision(HIW"$N��������������������$n���ߣ�ͻȻʹ��ΤС���ľ�����" + HIC "���аٱ�" + HIW "����\n"NOR,me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))

        {
        message_vision(HIW"���$N��Ū��ͷ���ۻ�,��֪���룡\n"NOR,target);
        target->start_busy(3);
        }
        else{
        message_vision(HIY"$NǱ������,���о���,��û���ܵ��Ի�\n"NOR,target);}
        me->start_busy(1);
        break;}
case 2:
case 3:
case 4:
case 5:
case 6:


{

        msg = RED "$Nƴ��ȫ����ʹ�����ΰٱ�����������һʽ��" + HIC "һ�Ŷ�Ǭ��" NOR + RED"����\n" ;
if( random(me->query("combat_exp")) > (int)target->query("combat_exp") )
{msg += HIR "ֻ��$nһ���ҽ�,��������һ̯����һ����̱����ȥ��\n" NOR;
target->receive_damage("qi",(int) me->query("max_qi"));
}
else {msg += CYN "$n��æ�͵ش��,��Ȼ�����������һ��,ȴҲ�Ǳ�����,�亹ֱð��\n" NOR;
}
me->start_busy(1);
message_vision(msg, me, target);
break;}
case 7:
case 8:
case 9:
{msg = HIM  "$NͻȻ���ȼ�ɨ��������´�Ƭɳʯ������һ��Ϊ����ǰ��л����������У�" NOR;
message_vision(msg,me,target);
lmt = random(2)+1;
for(j=1;j<=lmt;j++)
        {
        msg =  HIM "��"+chinese_number(j)+"�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }

me->start_busy(1);
break;}}
}
  me->start_busy(3);
  me->add("neili",-180);

return 1;
}

