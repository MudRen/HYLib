//heijian-jindao
#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

string  *sword = ({
"$N�ҽ���ǰһ������ϥ����$w��ǰ�����Ϸ�����һ�С��������ա�������$n��$l",
"$Nһ�С�槼�Ц����˫����㣬��ǰ����Ծ�䣬����$w������ǰ���£�Ʈ�ݵص���$n��$l",
"$N�������ȣ�ת��沽�������ҽŸ�����һ�С���ʽ�ֽ𡹣�$w�й�ֱ��������$n��$l",
"$N�ҽź�һ����һת������$w��󷴻���һ�С�������ء���Ĩ��$n��$l",
"$N�鲽������һ�С�������衹������$w���������һ��������$n��ȫ���Ѩ",
"$N��ǰ����һ�������ֽ���������$wʹ��һʽ�������롹������ֱ��$n��$l",
"$Nһ�С�����ҽ�����$w���϶��»���һ�������⣬ƽƽ����$n��$l��ȥ",
"$N�е�������������$w���������ش�ȥ�����ǽ��Ⲣ��ֱ����ȴ����$n��ǰ��תȦ��",
"$N���ֿ켫��$n��Ծ�˱ܣ�$w���ɵ�ԲȦ����ָ��$n��ǰ����ȦԽ��Խ��",
"$N����š���������鱧��һ�С���Ʒ��̨����$w�й�ֱ��������ƽ�͵ش���$n��$l"
});

string  *blade = ({
"$N��ɫ��ɱ���е�����˸���������������ϡ�һƬ�̹ǵĵ��罫$n����Χס����һֻ�ֽ�����������!",
"$Nһ�С�Ǭ����ת��������$w�ڿ����������±��ǵ�����ͻȻ��ɽ����»�����$n��$l",
"$N���浶���������Ծ��һ�С���ӥ���¡���ֱ��$n�Ҽ磬��ͽ���涵�˸���Բ����һֻ�ֽ���ȴ����$n��$l",
"$N������$w����һ����һ�ֽ���Ȧת�黮���漴����һ���ԡ��ͻ���ɽ��֮������$n",
"$N�Ӷ�$w���Խ�������̳���ͻȻ��;�ῳֱ��ʹ��������һ�С���ɳ��ʯ��$wһ���������$n",
"$N����΢��$w������������˹�ȥ������$n��$l����Ѫ�ų���",
"$N����ͻȻ���ȣ����ֻ��˸�ԲȦ�������Ե�����ס���ƣ�һ�С�����ɽ�ӡ���$n��ѹ��ȥ"
});
void weapon_attack(object me, object victim);
int valid_enable(string usage) { return (usage == "sword") ||(usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("sword", 1) < 20)
		return notify_fail("��Ļ����������̫ǳ��\n");
	if ((int)me->query("jing") < 80)
		return notify_fail("�����������ѧ�ڽ��𵶡�\n");
	me->receive_damage("jing", 10);

	return 1;
}
mapping query_action(object me, object weapon)
{
        object target;
        int i, level, n;
        string msg,str;
        level = me->query_skill("heijian-jindao",1);
	if (objectp(weapon)) {
	if (me->query_temp("heijian-jindao/luanren",1)&&!me->query_temp("heijian-jindao/doublt_attack",1)&& objectp(target = me->select_opponent())) {
		me->set_temp("heijian-jindao/doublt_attack",1);
		weapon_attack(me,target);
		me->delete_temp("heijian-jindao/doublt_attack");
	}
      if (me->query_temp("heijian-jindao/nizhuan",1)) {
        if(weapon->query("skill_type") == "blade" ) {
          	str = HIB+sword[random(sizeof(sword))]+NOR;
     		str = replace_string(str, "$w", weapon->name()+HIB);       
                return ([
                        "action": str+"!\n$N����$w������ϴ������ȫ�ߵĽ�������·��",
                        "damage": level*3/2+100,
                        "damage_type": "����",
                        "dodge": random(level/10)*2-20,
                        "parry": random(level/10)*2-10,
                        "force": level*2/3,
                ]);  }
        if(weapon->query("skill_type") == "sword" ) {
          	str = HIY+blade[random(sizeof(blade))]+NOR;
     		str = replace_string(str, "$w", weapon->name()+HIY);       
                return ([
                        "action": str+"!\n$N����$wӲ��������Ȼʹ�������յĵ���",
                        "damage": level*2/3+100,
                        "damage_type": "����",
                        "dodge": random(level/10)*2+20,
                        "parry": random(level/10)*2+10,
                        "force": level*3/2,
                ]);  }
	} else {
        if(weapon->query("skill_type") == "sword" ) {
          	str = sword[random(sizeof(sword))];
                return ([
                        "action": "$N����$w������ϴ�����ޱȡ�\n"+str,
                        "damage": level+100,
                        "damage_type": "����",
                        "dodge": random(level/20)-20,
                        "parry": random(level/20)-10,
                        "force": level/3,
                ]);  }
        if(weapon->query("skill_type") == "blade" ) {
          	str = blade[random(sizeof(blade))];
                return ([
                        "action": "$N����$wӲ�������Ҿ��ס�\n"+str,
                        "damage": level/3+100,
                        "damage_type": "����",
                        "dodge": random(level/20)+20,
                        "parry": random(level/20)+10,
                        "force": level,
                ]);  }
  }
}
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ʹ�õ��������ԡ�\n");
       if(weapon->query("skill_type") !="sword"&&weapon->query("skill_type") !="blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("heijian-jindao",1) < 200)
		return notify_fail("����Ҫ��һ������������!��\n");
	if ((int)me->query("neili") < 180)
		return notify_fail("��������������ڽ��𵶡�\n");

	if ((int)me->query("jing") < 80)
		return notify_fail("��������������ڽ��𵶡�\n");
	me->receive_damage("jing", 50);
	me->add("neili", -50);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
       	if ( me->query("max_neili") > 1200 && me->query("neili") > 1000 && random(10) >= 7
		&&!me->query_temp("heijian-jindao/nizhuan",1)
		&&!me->query_temp("heijian-jindao/luanren",1)
		&&!me->query_temp("heijian-jindao/doublt_attack",1)
       	&& random(me->query_int()) > 10 
       	&& !me->is_busy()
       	&& random(me->query("combat_exp")) > victim->query("combat_exp")/3){
			weapon_attack(me,victim);
		}

}
/*
int ob_hit(object ob, object me, int damage)
{
       	          
}
*/
void weapon_attack(object me, object victim)
{
	object weapon,weapon2;
	object *inv;
	int i,damage,level,j;
	string msg;
	if (!me || !victim || !me->is_fighting(victim))
		return;
	if (me->is_busy())
	return;
	weapon = me->query_temp("weapon");
	level=me->query_skill("heijian-jindao",1);
       inv = all_inventory(me);
	i = 1;
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }

	if(me->query_temp("heijian-jindao/doublt_attack") && !me->query_temp("heijian-jindao/doublt_attack1")
	&& objectp(weapon2)
	&& !me->is_busy()
	) {
		me->set_temp("heijian-jindao/doublt_attack1", 1);
              weapon->unequip();
              weapon2->wield();
		COMBAT_D->do_attack(me, victim, weapon2, i);
		COMBAT_D->do_attack(me, victim, weapon2, i);
              weapon2->unequip();
              weapon->wield();
		me->delete_temp("heijian-jindao/doublt_attack1");
	} else if (!me->query_temp("heijian-jindao/doublt_attack1")){
		
		switch(i) {
			case 1: msg = "$N"+weapon->name() + HIG"һ������ת�䣬";break;
			case 2: msg = "$N"+weapon->name() + HIG"����ͻȻ��ɵ������漴̽��"+weapon2->name()+HIG"ʹ��һ�н�����";damage = level*2;break;
			case 3: msg = "$N"+weapon->name() + HIG"����ͻȻ��ɽ��У��漴̽��"+weapon2->name()+HIG"ʹ��һ�е�����";damage = level+random(level);break;
			default: msg = "$N"+weapon->name() + HIG"һ������ת�䣬";damage = level;break;
		}
		message_vision(HIG+msg+ "���ǡ����������з����˵������ޱȣ�\n"HIR"$n������Ӧ�������ô��ֲ����������ˡ�\n"NOR,me,victim);
 		if (!victim->is_busy()) victim->start_busy(4-i+random(2)+1);
      if (i>1&&weapon2
      && !me->is_busy()) {
         	victim->receive_damage("qi", damage , me);
              victim->receive_wound("qi", damage , me);
              j = (int)victim->query("eff_qi") * 100 / (int)victim->query("max_qi");
              msg = damage_msg(damage, "����") + "( $n"+eff_status_msg(j)+" )\n";
        	msg = replace_string(msg, "$l", "�ؿ�");
        	msg = replace_string(msg, "$w", weapon2->name());
		message_vision(msg,me,victim);
	}
	}
}
string perform_action_file(string action)
{
        return __DIR__"heijian-jindao/" + action;
}
