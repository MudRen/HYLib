// ��ɢ
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
});
int perform(object me, object target)
{
	string msg;
       int damage;
int rlevel,i,p;
int level;
object weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʼʱ��������һ�ѽ���\n");
     

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("wudu-goufa", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("qianzhu-wandushou", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("wudu-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wudu-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");
if (random(3)==0) target->start_busy(3);

        msg = HBWHT "$N��ͨ�嶾����ѧ��ʹ�����嶾�̵ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

rlevel=(int) me->query_skill("wudu-shengong", 1)/10;
if (!rlevel) rlevel=10;
p=rlevel/4;
if (p> 8) p=8;
	for(i=0;i<p;i++)
	{
	me->add_temp("apply/attack", (rlevel*2));	
	me->add_temp("apply/damage", (rlevel*4));
        msg = HIB "$N�����嶾��,ͷ���������ڣ�һ�����˳�����\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(rlevel*2));	
	me->add_temp("apply/damage", -(rlevel*4));
}
me->start_busy(4);
	msg = HIR "$Nһ����Ц�����������һָ��$n��ü�ĵ�ȥ��\n";
	message_vision(msg, me, target);
	       target->apply_condition("chilian_poison",
		        (int)target->query_condition("chilian_poison") + 50 );
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 50 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 50 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 50 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 50 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 50 );


	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {
		msg = HIR"ֻ��һ�ƺ�����$N��ָ��͸����ֻһ����û��$n��ü�ģ�\n" NOR;
	       message_vision(msg, me, target);
             if(target->query_skill("hunyuan-yiqi",1)>me->query_skill("qianzhu-wandushou",1)*12/10&&random(2)==0){             
		msg = RED"$N��Ȼ����ָ����һ�����εľ��������ţ�������ֻ��\n
$nһ����ȣ�$N��ʱ��һ�����ݰ㱻����Զ����\n" NOR;
	       message_vision(msg, me, target);
		msg = RED"$Pֻ����һ����ɽ�ľ���˳ָ���͹�������ֻ����ȫ������ܡ�\n��Ȼ�ؿ�һʹ�����ɡ��ۡ���һ���³�һ�ں�Ѫ��\n" NOR;
	       message_vision(msg, me);
              damage=(int)me->query_skill("qianzhu-wandushou",1)
                     +(int)me->query_skill("wudu-shengong",1);
              if(damage < 50 ) damage = 50;
		target->receive_wound( "qi",damage);

              }    
              else{
		msg = HIR"$n����һ���Һ�ˤ���ڵأ�������ʹ���������һ�ţ�\n" NOR;
	       message_vision(msg, me, target);
              damage=(int)me->query_skill("wudu-goufa",1)
                    +(int)me->query_skill("qianzhu-wandushou",1)
                    +(int)me->query_skill("wudu-shengong",1);
              if(damage > 5900 ) damage = 5900;
		target->receive_wound( "qi",damage);
             }
	} 
       else {
		msg = HIG "����$n����׼����һ����¿����������������һ�С�\n" NOR;
	       message_vision(msg, me, target);
	}

	msg = HIM "ֻ��$N�ӻ��У��ó�һ�����֪����ʲô������ҩ�ۣ�һ������$n������!\n";

	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {
		msg += HIR"$nû�з�����ȫ�����±�����һ�����ţ�\n" NOR;
            target->receive_damage( "qi",damage*5);
            target->receive_wound( "qi",damage);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);

            target->start_busy(1 + random(3));
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "$p������������һ�𣬽�$N�����Ķ���ж��������!\n" NOR;
		message_combatd(msg, me, target);
	}
	return 1;
}
