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
	int damage;
             urkee=me->query("eff_jing"); 
weapon = me->query_temp("weapon"); 
       extra = me->query_skill("yunlong-jian",1); 
            duosword = (int)me->query_skill("yunlong-jian", 1); 
        if( !target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("yunlong-jian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

       if( !wizardp(me) &&(int)me->query_skill("yunlong-zhua", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("yunlong-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "yunlong-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ������ѧ��ʹ���������ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
me->start_busy(4);
        message_vision(msg, me, target);   


 if(!objectp(weapon = me->query_temp("weapon"))) return 1; 
msg = HIR  "$N���赭д���ӳ����⣬һ˲�����ʹ������ʮ��ʽ�����е�"+ weapon->name()+  "�������� 
�������Ǻ�ˮ�����$n�̳�,��ؼ��ݷ������ɱ����\n\n" NOR; 
      message_vision(msg,me,target); 
           me->add_temp("apply/attack",extra/3); 
           me->add_temp("apply/damage",extra); 
//lmt=13;
       lmt = 13; 
if (random(3)==0) target->start_busy(3);       
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
          if( random(10)==0) 
       { 
               msg = HIB "���е����������������ѱ�$N��һ����ȥ,$n���Ϻ�Ȼ¶���ֿ־�֮���ı��顣"NOR; 
msg +=  RED"\n��ž����һ����$N���е�"+ weapon->name()+  "����!\n\n"NOR; 
            message_vision(msg, me, target); 
me->delete_temp("can_shiwu"); 
            target->unconcious(); 
//         weapon->unequip(); 
//         destruct(weapon); 
              return 1;   
       } 
       else 
          { 
me->delete_temp("can_shiwu"); 
    weapon->unequip(); 
    msg = RED "\n$N����ͻȻ�������⽣�Ŀ���,ͻȻ��������!! **��Ѫ��ץ**��һץץ�����Ʋ��ɵ���\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 ) {  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(
		target->query_temp("weapon"))->move(environment(target));
		target->start_busy(3);
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{

		target->start_busy(random(4)+1);
		
		damage = (int)me->query_skill("yunlong-shengong", 1);
		
		damage = damage*5 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }
       return 1; 

              } 
               }               
me->start_busy(4);
//           me->start_busy(lmt/2+1); 
             return 1; 
} 


 