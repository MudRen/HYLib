#include <ansi.h>

#include <combat.h>

inherit F_SSERVER; 
int perform(object me, object target,object weapon)
{       int damage,myexp,yourexp,cpexp,lvl,sword;
        string msg;
	int res_kee,res_gin,res_sen,max_exp;
	int no_busy,x;
	
	no_busy = 0;  

		lvl = me->query_skill("chixin-jian",1);
		sword = me->query_skill("sword",1);
        if(lvl < 300)
                return notify_fail("��ĳ����鳤��δ�ܴﵽ���޽����ľ��磡\n");
        if(sword < 280)
                return notify_fail("��Ļ�������δ�ܴﵽ���޽����ľ��磡\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("��ı̲��񹦻��̫ǳ��\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("��İ�Ӱ������̫ǳ��\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("���������Ѩ�ֻ��̫ǳ��\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("�����Ӣ�񽣻��̫ǳ��\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("�����Ӣ���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ���̫ǳ��\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("�������ɨҶ�Ȼ��̫ǳ��\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("������｣�����̫ǳ��\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("����������Ի��̫ǳ��\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������л��̫ǳ��\n");                
       if ((int)me->query_skill("canglang-bian", 1) < 120)
                return notify_fail("��Ĳ��˱޷����̫ǳ��\n");   

        x=(lvl-170)/2;
        if(x==0) x=1;
        if(x>=50) x=50;
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���޽���ֻ����ս����ʹ�á�\n"); 

        if (me->query_skill("bibo-shengong", 1) < 250)  
                return notify_fail("��ı���������Ϊ������\n");  

         if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");                       

        if (me->query("neili") < 600)
                return notify_fail("��������������޷�ʹ�ã�\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ���������\n"); 
        if((int)me->query("neili") < 100 )
                return notify_fail("�������������\n");

		me->receive_damage("jing", 100);
        	me->add("neili",-100);

        if(target->query("no_busy"))
		no_busy=target->query("no_busy");
        if ( me->query_temp("weapon"))
        {
        	 //return notify_fail ("���޽��ķ���������ֲ���ʹ����\n");
                weapon = me->query_temp("weapon");
                //if(weapon->query("equipped") == "wielded") 
                msg = HIC "\n$N"+HIC"����һ���������������ۼ�ת����ָΪ�������ƴ�����\n" NOR;
		msg += HIW "ֻ�����콣�⡣һ˿˿����˺�ѿ�����ֱ��$nҪ������Ȼ����������ʽ�ġ��޽��ķ�����\n\n"NOR;
        	message_vision(msg, me, target);
                 //weapon->unequip();
                 	//return 2;
        }
        else
        {
        msg = HIC "\n$N"+HIC"˫�ֲ�ָΪ����ָ���ֱ����������һ���������������£����ƴ�����\n" NOR;
		msg += HIW "ֻ�����콣�⡣һ˿˿����˺�ѿ�����ֱ��$nҪ������Ȼ����������ʽ�ġ��޽��ķ�����\n\n"NOR;
        message_vision(msg, me, target);
                 	//return 2;
        }
        
		if ( me->query_skill("force") < random( (target->query_skill("force")))/2) {
			message_vision(HIY"����$N������λ���ܹ��������ν�����ֱ��$n�����ţ�\n"NOR, target,me);
			me->start_busy(2);
			return 1;
		}

        damage = sword + lvl;
        damage = damage + random(damage);
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=random(myexp/2);
		if(yourexp<10000000) yourexp = yourexp*2/3;
             if (yourexp*2 < myexp) {
             	message_vision(HIR "�����Ľ����ᴩ$N�����壬��â������Ѫ���������ڷ�Բʮ��֮�ڡ�\n" NOR, target);
                     target->receive_damage("qi", damage*3);
                     target->receive_damage("jing",damage);

                     target->receive_wound("qi", damage*3);
                     target->receive_wound("jing",damage);

                     COMBAT_D->win_lose_check(me,target,1);
                }
                else
                {        if( target->query_busy() ) {

                message_vision(HIR "�����Ľ����ᴩ$N�����壬��â������Ѫ���������ڷ�Բʮ��֮�ڡ�\n" NOR, target);
				if(random((int)me->query_skill("magic")) > 50) {
                     target->receive_damage("qi", damage*3);
                     target->receive_damage("jing",damage);

                     target->receive_wound("qi", damage*3);
                     target->receive_wound("jing",damage);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
				}
				else message_vision(HIY "����$N"HIY"һ�������ڿ������㿪����һ����\n" NOR, target);
		} else if (yourexp > cpexp) {
			if(random(4)==0) target->delete("no_busy");
            message_vision(HIG"����ʮ��·����ʮ��·����������$N��ȫ��Ѩ���ϣ�$N��ʱ�������á�\n"NOR, target); 
			target->receive_damage("qi", damage);
            target->start_busy(6);
           // target->set("no_busy",no_busy);
		}
		else {
			message_vision(HIY"����һ���þ���$N��Ϣ���ܿ��ƣ���ǰ¶�����ţ�\n"NOR, me);
		}
	}		
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 2000);
               msg=HIW"��غ���£���"+WHT"$N"+WHT"����һ��Ʋ������Ҳ��������յ�����������ֱָ$n��"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIW"���º���������"+WHT"$N"+WHT"�Ųȵؼ�λ�����־�һָһ���������������һ�佣������$n��"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIW"��ʱ�����򣭣�"+WHT"$N"+WHT"һ���ӳ�,���ƻ�����ƽƽ���棬�������飬���ƽ�����ʵ��"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIG"\n������伪�ף���"+HIM"ɭɭ��Ӱ������裬���ۺ��ְ˷����ߣ�����Ѹ�׿�к���ִ�$n"+HIM"����Ҫ����\n"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -2000);

      message_vision(HIR+"\n\n$N"+HIR"���б���ֹ�ŵĳ������������߽�������������һƬ��Ļ����ʱ���������Ž���\n"NOR,me);
        
        
        if (random(target->query("combat_exp"))<max_exp) {
                message_vision(BLU"$N"+BLU"��ʧɫ��ֻ��������Ӱ��ɽ����Х��ӿ�������������˷���������ֱ���ڸ���\n",target);
                                     target->receive_damage("qi", damage*2);
                                     target->receive_wound("qi", damage);
                     target->receive_wound("jing",damage/2);
        }
   
        message_vision(HIR"\n\n$N"+HIR"ͻȻ����������Ӱ�����ۺ��ְ˷����ߣ�����һ��֮�����������Ž���\n"NOR,me);
        
        max_exp=me->query("combat_exp");
                
        if (random(target->query("combat_exp"))<max_exp) {
                message_vision(BLU"$N"+BLU"��ʧɫ��ֻ����Ӱɽ����Х���������˷�����ֱ���ڸ���\n"NOR,target);
                                     target->receive_damage("qi", damage*2);
                                     target->receive_wound("qi", damage);
                     target->receive_wound("jing",damage/2);
        } else {
                message_vision(YEL"$N"+YEL"���Ų�æ�����λζ������ǽ���֮���š�\n"NOR,target);
                me->start_busy(2);
                return 1;
        }           
        me->add("neili",-580);
        me->start_busy(5);
        return 1;
}      
