// juemie ���Ǿ�
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int extra;
        int count;
                int damage;
int finger, skill, jiali, my_rate, your_rate, neili_cost, jingli_cost;
 	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("ֻ����ս����ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʼʱ��������һ�ѽ���\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("jinding-zhang", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("huifeng-jian", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("linji-zhuang", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ��������ѧ��ʹ���˶����ɵľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);
	extra = me->query_skill("huifeng-jian",1) / 15;
	extra += me->query_skill("linji-zhuang",1) /15;
 
        msg = YEL "$Nʹ���ط������������һ�������塹��һ���������������е�"+ weapon->name()+  "����㹥����һ����" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", extra*2);
        me->add_temp("apply/damage", extra*4);
        msg = HIY "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n����磡" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = HIW "��һ������"+HIR+"����$n����$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
        message_vision(msg, me, target);
  if( !target->is_busy() )
{
        target->start_busy(2);
}
        }
        msg =  HIW "$N���һ����"+ weapon->name()+ GRN"����$n���Ҽ磡" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������,$nֻ����ȫ��һ��ʹ��\n"NOR;   
                message_vision(msg, me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra);
        }
        msg = CYN "$N��Хһ�����۹��������֣�ʹ����������߾���--�𽣣���$n����ǰ��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������Ѩ,$nֻ����ȫ�������᲻�����ˣ�\n"NOR;   
        message_vision(msg, me, target);
        target->add("neili",-extra*4);
        target->add("eff_neili",-extra*4);
        }
        me->add_temp("apply/attack", - extra*2);
        me->add_temp("apply/damage", - extra*4);
        me->start_busy(4);

        msg = YEL "$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥���ƽ�$n��\n"NOR;
        msg += YEL"$n�������콣�⣬�����Ծ��ֻ��һɲ�����콣Ӱ��Ϊһ��ֱ��$nǰ�أ�"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("combat_exp"))+5000 > target->query("combat_exp")/2) {  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(
		target->query_temp("weapon"))->move(environment(target));
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
          message_vision(HIW "��$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݣ�����ǧ�������裬����ͷ�����
������$n����֮�£���ʱ����ɢ�ң��޴��мܣ�\n" NOR, 
                         me, target);
	}
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp"))+8000 > target->query("combat_exp")/4 )
	{
		
		damage = (int)me->query_skill("huifeng-jian", 1);
		
		damage = damage*6 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫ��һ�����У��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n���һ�����У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����һ������,$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬һ������,$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	message_vision(msg, me, target);
            message_vision(HIW "��$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݶ�������ǧ�������裬����ͷ�����
������$n���Ѽӱ���������Ըй���ƵƵ�մ졣\n" NOR, 
me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra/2);
        target->add("qi",-extra);
        target->add("eff_qi",-extra/2);
	}
	message_vision(msg, me, target);

        }
 msg = HIY "\n$NͻȻ��ȫ������з����������ĵ���΢����֮���������������δ������������$n�ؿڻ�ȥ��\n\n"NOR;
  msg += HIG"��һ���Ƕ����ɵľ�ѧ��������������ա����⡰������ա����Ʒ���ֻһ�У�������\n";
  msg += HIG"һ��Ҳ�������仯����ʽƽƽ������һ�ɲ��䣬����������֮�����������Զ����ɾ���\n";
  msg += HIG"�ڹ���Ϊ������һ�Ƽȳ�����������ɽ����һ��Ϯ�������˵��޿ɵ������޿ɱܡ�\n\n";

// because hy2 can not jiajin, so update jiajin to jiali (by xbd)
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        if(damage > 8100) damage = 8100;
                        if(damage < 500) damage = 500;
//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);

                msg += HIR"��������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n������ˤ����������۵�һ�������һ����Ѫ��\n"NOR;
                }else if ( damage < 1000) {
                        msg += YEL"$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ\n"NOR;
                }else if ( damage < 2000) {
                        msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;
                }else if ( damage < 3000) {
                        msg += RED"ֻ��һ�����죬$n������Ѫ���磬ȫ��������ѡ�\n"NOR;
                }else {
                        msg += RED"ֻ��һ�����죬$nȫ��������ѣ���������ɽ�������һ�������Ӵ�������ء�\n"NOR;
                }
                msg += NOR;
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
                                &&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        damage = damage / 2+600;
                        if(damage > 9000) damage = 9000;
                        if(damage < 350) damage = 350;

//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);

                        msg += HIY"$p�ۿ���һ���������ڣ�֪�����ڶԸ�����æ�����ֿ�����������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n������ˤ����������۵�һ�������һ����Ѫ��\n"NOR;
                }else if ( damage < 1000) {
                        msg += RED"$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ\n"NOR;
                }
                else msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
          random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        damage = damage / 3;
                        if(damage > 6000) damage = 6000;
                        if(damage < 550) damage = 550;

//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);

                        msg += HIM"$p�ۿ���һ���������ڣ���æʹ�������������Ծ�����ɣ��������������̲ض�ü�ڼ��ϳ��ڹ���\n";
                        msg += "��Բ���ɶ��������𺳣�$pֻ���ú���һ���ѱ�������������.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n������ˤ����������۵�һ�������һ����Ѫ��\n"NOR;
                }else if ( damage < 1000) {
                        msg += RED"$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ��\n"NOR;
                }
                else msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
  }
  else {
         msg += HIC"$n�ۿ���һ���������ڣ�ʹ��������������Ծ�����ɣ�\n\n"NOR;
         msg += HIW"$N��һ������ʹ����ȫ����˿��������ء�û�뵽ȫ���ô��������������ң�����΢΢������\n" NOR;
         neili_cost = jiali*3;
//         jingli_cost = me->query("jiajin")*2;
         if(neili_cost > me->query("neili")) 
                neili_cost = me->query("neili");
         if(jingli_cost > me->query("jingli"))
                jingli_cost = me->query("jingli")-1;

         message_vision(msg+"\n", me, target);
         return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
        return 1;
}

