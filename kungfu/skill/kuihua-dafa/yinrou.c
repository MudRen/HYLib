// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
        string *order = ({"��ԪѨ", "̴��Ѩ", "�羮Ѩ", "̫��Ѩ", "����Ѩ", "�ٻ�Ѩ","����Ѩ","ӿȪѨ","��׵Ѩ"});
int perform(object me, object target)
{
	string msg;
	int extra,ap,dp,damage;
	int i;
	object weapon,ob;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("������û��װ������������\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("pixie-jian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("kuihua-dafa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("kuihua-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kuihua-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


   if ( !wizardp(me) && (string)me->query("gender")=="����" )
        return notify_fail("��������Թ�!!\n");

        msg = HBWHT "$N��ͨ���������ѧ��ʹ����������̵ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

	extra = me->query_skill("kuihua-dafa",1) / 20;
	extra += me->query_skill("kuihua-xinfa",1) /20;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", (extra*3));
	msg = HIR  "$N��Ȼ����Ϊ�����ó�����������Ӱ���ٻ���$n������$w�û����������н���$n��$l!" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC "$N����Ӱ����˼�������������\n" NOR;
        message_vision(msg, me, target);
	if (random(2)==0) target->start_busy(3);
	for(i=0;i<extra/4;i++)
	{
	msg = HIW "$n���Գ�����Ӱ����$n���˹�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*3));

	me->start_busy(4);
        msg=YEL"\n\nֻ��$N˫Ŀһ�ͣ���������һ����ʣ���ͻȻ�ӿ죬��Ӱ���Σ�������ϣ�\n"NOR;

        msg+=YEL"����һ�������ĳ�Х��$N���б���������佣�����͵�����$nȫ��������Ŵ�Ѩ��\n\n"NOR;


        ap=me->query_skill("kuihua-dafa")+me->query_skill("strike");
        dp=target->query_skill("parry")+target->query_skill("dodge");
        if(random(ap)+30>random(dp))   
           {
              damage=(me->query_str()-target->query_str()+10);
            damage=damage*random(me->query_cor());
/* */ damage=me->query("str")+me->query_skill("unarmed",1)/10+600;
/* */ damage=damage*(20+random(20));

      if(damage<0)    damage=600;
      if(damage>9600) damage=9600;
      msg+=RED"$n����һ����"+HIY+(order[random(7)])+NOR+RED+"��λѪ���ɽ�,\n"NOR;
      switch(random(2))
      {
         case 1:
           {
               msg+=RED"$n���ۡ���һ����Ѫ�ӿ��������\n"NOR;
               target->reset_action();
 break;
           }
         default:
      msg+=RED"$n����һ��, һ����Ѫ�ӿ������,ֱ����$N,����$Nͷһ��,���ɵĶ��˹�ȥ����\n"NOR;
               target->reset_action();
      }
         switch(random(2))
     {
         case 1:
         { 
             target->receive_wound("qi",damage/2);
             target->receive_damage("qi",damage);
     if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage));
     break;
         }
      default:   
         { 
           target->receive_wound("qi",damage*2/3);
           target->receive_damage("qi",damage*5/4);
 if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage*5/4));
                      }

                  }            
           }
        else 
           {
                msg+=CYN"$p��Цһ����������μ������˿�ȥ��\n"NOR;
           }

        message_vision(msg, me, target);


  message_vision(RED"\n$N�͵�������$n��ȥ����ָһ����ϸ����˳�ȥ������$n��Ŀ��\n\n"NOR, me, target);
      
if((me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
        message_vision(HIR"\n$n⧲����������һ�����������룡\n"NOR, me, target);
        tell_object(target, HIY "��о�ϸ���������Լ���ͫ��֮�У��������ֱ�����ԣ���������֮�ǣ�\n" NOR);
                me->add("neili", -300);
                damage = extra*10;
                damage = damage*6;
               
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
               }
         else 
              {
                message_vision(HIY"\n����$n������$N����ͼ���������˿�ȥ��\n"NOR, me, target);

              }


	return 1;
}
