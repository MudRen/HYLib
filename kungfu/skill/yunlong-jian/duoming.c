// yaoyuan@sjfy 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 int perform(object me, object target) 
{ 
       string msg; 
       int extra,i,lmt,duosword,urkee; 
       object weapon; 
             urkee=me->query("eff_jing"); 
weapon = me->query_temp("weapon"); 
       extra = me->query_skill("yunlong-jian",1); 
            duosword = (int)me->query_skill("yunlong-jian", 1); 
       if ( extra < 200) return notify_fail("��������������������죡\n"); 
       if( !target ) target = offensive_target(me); 
       if( !target 
      ||      !target->is_character() 
       ||      !me->is_fighting(target) ) 
               return notify_fail("�۶�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
//if (!wizardp(me))
//                return notify_fail("�����书��������!\n");
        if( (int)me->query("neili") < 900 )
                return notify_fail("�������������\n");
	
	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("��������񹦲����ߡ�\n");

 if(!objectp(weapon = me->query_temp("weapon"))) return 1; 
msg = HIR  "$N���赭д���ӳ����⣬һ˲�����ʹ������ʮ��ʽ�����е�"+ weapon->name()+  "�������� 
�������Ǻ�ˮ�����$n�̳�,��ؼ��ݷ������ɱ����\n\n" NOR; 
      message_vision(msg,me,target); 
           me->add_temp("apply/attack",extra/3); 
           me->add_temp("apply/damage",extra); 
//lmt=13;
       lmt = random(13)+1; 
       for(i=1;i<=lmt;i++) 
       { 
if(!objectp(weapon = me->query_temp("weapon")) ) continue; 
       msg = HIR "------>>>>>>��"+chinese_number(i)+"��<<<<<<------" NOR; 
        COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg); 
       } 
       msg = CYN "\n\n$N�ĵ�"+chinese_number(i-1)+"���̳������еı仯���������������ˮ�ѵ���ͷ���� 
��Ҳ���ˣ�������\n"NOR; 
      message_vision(msg,me,target); 
           me->add_temp("apply/attack",-extra/3); 
           me->add_temp("apply/damage",-extra); 
 me->add("neili", -(lmt*50+50));
if (duosword >300 &&
me->query("neili") > 500
&& lmt < 13
&& (int)me->query_skill("yunlong-shengong", 1)>250 )
{
	weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra*5);
	msg = HIW  "������$N���е�"+ weapon->name()+  "�ٴγ��ʣ��ͻ���һ���⻪����$n��һ�����εĹ⻪�����á��Ի͡�������\n" + HIG"�⻪����������á��߸����ϣ�����Ʈ����$nֻ��������⻪�ݷ�����Լ�ü��
�䣬ȴ�ֲ���ȷ������������ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "������ȷʵ����������޴����ڡ����Ǿ���$n��ȷ��������ʱ������Ȼ�ֲ���
�ˡ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT"���漣���Ȼ���֣����漣���Ȼ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "���еĶ����ͱ仯��������һɲ�Ǽ���ɣ���ֹ�����������ǣ�ȴ���������磬ȴ�ֱ�
���Ǻ�������ӽ��漣����Ϊ�߶���仯������������$N�������ġ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",extra/3);
       	me->add_temp("apply/damage",-extra*5);
me->add("neili",-400);
}
if( duosword > 250 && lmt == 13 ) 
           { 
               msg = CYN  "��Ȼ����ȴ�����ڱ䣬$N��Ȼһ���ӳ��������߼ʣ������·���"; 
msg +=  HIR "\nȻ��$N�ʹ̳��˶����������ĵ�ʮ�Ľ�------------------------\n" NOR;       
           me->add_temp("apply/attack",extra); 
           me->add_temp("apply/damage",extra*3); 
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
           me->add_temp("apply/attack",-extra); 
           me->add_temp("apply/damage",-extra*3); 
message_vision( RED "$N�Ľ�����ɱ�������أ��������쵺���ܲ�����һ���̳�����Ȼ��ͽ��������ƶ������ˣ��ֳ������⡣\n" NOR ,me,target); 
if(target->is_busy()) 
                        { 
               return notify_fail(target->name()+"��Ϊ��Ľ���������\n"); 
                        } 
             else 
            { 
       message_vision(HIW"���$N��ʧɫ,Ϊ����������\n"NOR,target); 
       target->start_busy(random(5)+1); 
       } 
	message_vision( YEL "\n��һ���̳������еı仯������ѵ���������ѵ��˾�ͷ����ˮ�����ھ���������ȫ�ݽߣ�$N����Ҳ�ѽ��ˡ�\n\n" NOR ,me,target); 
         me->set_temp("can_shiwu",1);   
              } 


if( duosword > 300 && me->query_temp("can_shiwu")) 
           { 
                msg = HIW "\n���Ǿ�����ʱ��$N���еĽ���Ȼ�������������,��������Ȼȫ����ֹ�����Ծ�ֹ��\n"; 
                 msg +="û�б仯��û������!��һ�������ģ�ֻ����!ֻ�С���������������һ�е��սᣬ����\n"; 
                 msg +="�������ս�!��ˮǬ�ݣ��仯��������սᣬ��������!����ǡ������������������ľ���!\n"; 
                 msg +="���������������һ��!��һ����Ȼ�Ѿ��ǵ�ʮ�彣��\n\n" NOR; 
                                    message_vision(msg, me, target); 
          if( random(2) && !wizardp(me) ) 
       { 
       msg = HIB "���е����������������ѱ�$N��һ����ȥ,$n���Ϻ�Ȼ¶���ֿ־�֮���ı��顣"; 
msg +=  "\n$N���۾����ȻҲ¶���ֿ־�֮���ı��飬����Զ��$n���־塣"; 
msg +=  "\nȻ��$N���������κ��˶��벻�����κ��˶��޷�������¡�$N��Ȼ��ת�˽��棬�����$N�Լ����ʺ�\n\n"NOR; 
  message_vision(msg, me, target); 
me->delete_temp("can_shiwu"); 
               me->unconcious(); 
                      return 1; 
       } 
       else 
          { 
               msg = HIB "���е����������������ѱ�$N��һ����ȥ,$n���Ϻ�Ȼ¶���ֿ־�֮���ı��顣"NOR; 
msg +=  RED"\n��ž����һ����$N���е�"+ weapon->name()+  "����!\n\n"NOR; 
            message_vision(msg, me, target); 
me->delete_temp("can_shiwu"); 
if (target->query("qi") > 30000)
{
target->add("qi",-25000);
target->add("eff_qi",-25000);
}else target->unconcious();
//         weapon->unequip(); 
//         destruct(weapon); 
              return 1;   
              } 
               }               
           me->start_busy(lmt/2+1); 
             return 1; 
} 


 