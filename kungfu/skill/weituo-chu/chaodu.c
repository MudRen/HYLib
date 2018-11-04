#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, club, i,ap,pp;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("�����ȼ��֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "club" )
                return notify_fail("�������޹����������á����ȼ��֡�����\n");

        if( me->query_temp("sl_chaodu") )
               return notify_fail("�����ȼ��֡��������ܼ���̫��������Υ��ͣ����ɶ��ã�\n");



        if((int)me->query_skill("weituo-chu", 1) < 300 )
               return notify_fail("�㡸Τ���ơ���Ϊ����������δ�����򡸳��ȼ��֡���\n");

	if((int)me->query_str()-(int)me->query_temp("apply/strength")<50)
	       return notify_fail("��������������޷��ó������ȼ��֡�\n");

	if((int)me->query("con")+(int)me->query_skill("force",1)/10<50)
	       return notify_fail("��ĸ��ǲ������޷����ܡ����ȼ��֡��Ľ�մ�����\n");

        if((int)me->query_skill("buddhism",1) < 200)
               return notify_fail("��������Ϊ����������δ�����򡸳��ȼ��֡���\n");


        if( me->query_skill("yijinjing", 1) < 300 )
                return notify_fail("����ڹ���Ϊ���δ����ʩչֻ���˼�����\n");

        if( me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("�����õ��ڹ��롸���ȼ��֡��ķ���㣣�\n");

        if (me->query_skill_mapped("club") != "weituo-chu"
         )
                return notify_fail("�������޷�ʹ�á����ȼ��֡����й�����\n");

        if( me->query("max_neili") < 5000 )
                return notify_fail("���������Ϊ���㣬����������ʩչ�����ȼ��֡���\n");

        if( me->query("neili") <= 2000 )
                return notify_fail("�����������������������ʩչ�����ȼ��֡���\n");

        if( me->query("jing") <= 500 )
                return notify_fail("��ľ������ޣ�������ʩչ�����ȼ��֡���\n");

        if (random(2)==0) target->start_busy(2);
        message_vision(BLU"\nͻȻ$N��¶��⣺�����ȼ��֡������α��ǣ���ͬΤ����������һ�㣬��ȭͻ������"+weapon->name()+BLU"���У����塱��һ����"+weapon->name()+"����ķ�����ǧ�����Ƿ���$n��\n" NOR, me,target);
        weapon->move(environment(me));
        weapon->set("name", weapon->query("name")+"����Ƭ");
        weapon->unequip();
        weapon->set("value", 0);
        weapon->set("weapon_prop", 0);
        damage = (int)me->query_skill("club") + (int)me->query_skill("buddhism",1);
        club = me->query_skill("club")/3;
        i = 10+random(me->query_skill("buddhism",1)/20);
        damage = damage*i;
        if(me->is_killer(target->query("id")))
       		damage = damage *2/3;
        if(!target->is_killer(me->query("id")))
       		damage = damage *2/3;
        if (wizardp(me))
           	write(sprintf("damage = %d\n",damage));
        ap = COMBAT_D->skill_power(me,"club",SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(me,"parry",SKILL_USAGE_DEFENSE);
        if(target->is_busy())
        	pp /= 2;
        if(me->query("real_yjj"))
        	{
        		damage *=2;
        		ap *= 2;
        		pp /= 2;
        	}
	me->set_temp("sl_chaodu",1);
	if(random(ap+pp)>pp)
	{
          	me->add("neili", -500);
          	me->add("jing", -200);
          	target->receive_damage("qi",damage);
          	target->receive_wound("qi",damage/2);
            	message_vision(HIY"\n$n���������ô���ͰԵ�����ʽ,�мܲ�������ȭ�����У��߹ǵ����������ѣ�\n" NOR, me,target);
            	COMBAT_D->report_status(target);
if (random(6)==0 && target->query("int") > 30 && target->query("qi") < 800)
{
           	message_vision(HIY"\n$n����һƬ���Σ�һƬ�հף�\n" NOR, me,target);
target->add("int",-1);
}
else if (random(6)==0 && target->query("str") > 30 && target->query("qi") < 800)
{
           	message_vision(HIY"\n$nȫ��һ����ľ������һ�ɣ�\n" NOR, me,target);
target->add("str",-1);
}

            	me->start_busy(1+random(2));
            	call_out("remove_effect2", club*2/3, me);
       }
       else {
          	message_vision(HIY"\n$n�ۼ�$N�����׺ݣ������мܣ��������ػ��У����������ɣ������������һ����\n" NOR, me,target);
          	me->add("neili", -500);
          	me->add("jing", -100);
          	me->start_busy(1+random(2));
          	call_out("remove_effect2", club*2/3, me);
       }
       return 1;
}

void remove_effect2(object me)
{
        if (!me) return;
        me->delete_temp("sl_chaodu");
        tell_object(me, HIG"\n�㾭��һ��ʱ���������ԣ��ֿ�����ʹ�á����ȼ��֡��ˡ�\n"NOR);
}

int help(object me)
{
        write(
@HELP
���ȼ���
       �Ƿ����񹦣�����Τ���ơ������⹥���������б������飬����ǧ��Ƭ��Ƭ�������֡�
       ���ǡ�Τ���ơ����ռ���ʽ��
HELP
        );
        return 1;
}
