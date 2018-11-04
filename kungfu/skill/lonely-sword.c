// lonely-sword.c ���¾Ž�

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
        "ȴ��$n̤ǰһ������ʽбָ����ұۣ���Ҫʹ$P������ˡ�\n",
        "$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ���������������\n",
        "$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ�������������ͼ��ʹ$P���С�\n",
        "$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������\n"
        "$n�������ܣ��ٽ������ʹ�������両�ࡹ����$P��$l���뵲������С�\n",
        "$nͻȻʹ��������ɷ罣���ġ����ڤڤ������������$Pһ�ʣ���ͼͻ��$P�Ĺ��ơ�\n"
        "$nͦ��һ�����ǡ����Ƴ�ᶡ��ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣\n",
        "ֻ��$n���˷���������Ʈ�磬һʽ�����������������޶�����ס��$P��\n������\n",
        "$n���˷�����ʹ����ɽ���С�������롹��ɭɭ�����������ܣ��ܿ���$P������\n",
        });

mapping *action = ({
([      "action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ������"+(order[random(13)])+"��������Ȫ��"NOR"ֱ��$n
��$l��",
        "force" : 110,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N������$n�ӳ�"+(order[random(13)])+"��Ȫ��ܽ�ء�"NOR"��"+(order[random(13)])+"�������ϸǡ�"NOR"��"+(order[random(13)])+"��ʯ��������"NOR"��"+(order[random(13)])+"��
����������"NOR"��"+(order[random(13)])+"�����ף�ڡ�"NOR"��ɽ���񽣣�",
        "force" : 110,
        "dodge" : 60,
        "damage": 250,
        "lvl" : 7,
        "damage_type" : "����"
]),
([
        "action" : "$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ"+(order[random(13)])+"����Ůʮ�Ž���"NOR"�������
����ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼��",
        "force" : 110,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 14,
        "damage_type" : "����"
]),
([      "action" : ""+(order[random(13)])+"$N���ƺ��������裬�������������������ɽ����Ϊһ������$n����
��ȥ��",
        "force" : 120,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 21,
        "damage_type" : "����"
]),
([      "action" : ""+(order[random(13)])+"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ��
��������ɽ���ƻ���$n��$l��",
        "force" : 120,
        "dodge" : 80,
        "damage": 250,
        "lvl" : 28,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�������
��"+(order[random(13)])+"��̩ɽʮ���̡�"NOR"Ϊһ������$n��",
        "force" : 130,
        "dodge" : 100,
        "damage": 255,
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ�䣬ʹ����ɽ��"+(order[random(13)])+"��һ������㡹"NOR"������$n��$l����֪������
;��ͻȻת�򣬴��$n����֮�⣡",
        "force" : 140,
        "dodge" : 100,
        "damage": 260,
        "lvl" : 42,
        "damage_type" : "����"
]),
([      "action" : "$N����������һ������"+(order[random(13)])+"��������ɽ��"NOR"������$w����ն�䣬ֱ����$n��
$l��",
        "force" : 150,
        "dodge" : 100,
        "damage": 280,
        "lvl" : 49,
        "damage_type" : "����"
]),
([      "action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ��"+(order[random(13)])+"���ٱ�ǧ������ʮ��ʽ��"NOR"����
ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��",
        "force" : 160,
        "dodge" : 100,
        "damage": 290,
        "lvl" : 56,
        "damage_type" : "����"
]),
([      "action" : "$N��Ц����������ׯ�ϣ�$w��ӣ�����"+(order[random(13)])+"����Ħ����"NOR"Ϊһʽ������ش�
��$n��",
        "force" : 170,
        "dodge" : 100,
        "damage": 300,
        "lvl" : 63,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ"+(order[random(13)])+"��̫������"NOR"���⣬�������СС������ԲȦ�������޾�
ԴԴ�����ز���$n��",
        "force" : 280,
        "dodge" : 100,
        "damage": 320,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n��"+(order[random(13)])+"����Ħ
����"NOR"�Ľ����¶���ţ�",
        "force" : 290,
        "dodge" : 105,
        "damage": 330,
        "lvl" : 77,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$NͻȻ�鲽������ʹ�������䵱"+(order[random(13)])+"�����ѵ�ˮ��"NOR"��һ�У�",
        "force" : 200,
        "dodge" : 105,
        "damage": 360,
        "lvl" : 84,
        "damage_type" : "����"
]),
([      "action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ���������"+(order[random(13)])+"����
ħ����"NOR"��"+(order[random(13)])+"������ʽ��"NOR"��",
        "force" : 220,
        "dodge" : 100,
        "damage": 395,
        "lvl" : 91,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�˽����һ�ֹ����"+(order[random(13)])+"�������罣����"NOR"����Ȼ��$n�����Ҵ���
����",
        "force" : 240,
        "dodge" : 100,
        "damage": 320,
        "lvl" : 98,
        "damage_type" : "����"
]),
([      "action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N������
��ʵ��",
        "force" : 260,
        "dodge" : 100,
        "damage": 350,
        "lvl" : 105,
        "damage_type" : "����"
]),
([      "action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲ
ô������",
        "force" : 280,
        "dodge" : 100,
        "damage": 380,
        "lvl" : 112,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪
����Ǻã�",
        "force" : 200,
        "dodge" : 100,
        "damage": 485,
        "lvl" : 119,
        "damage_type" : "����"
]),
([      "action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ���������
��$n���ò��أ�",
        "force" : 320,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 126,
        "damage_type" : "����"
]),
([      "action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n
���Կ��彣�����ƣ�",
        "force" : 340,
        "dodge" : 105,
        "damage": 480,
        "lvl" : 133,
        "damage_type" : "����"
]),
([      "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��
ʽ��",
        "force" : 460,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 140,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����
˼�飡",
        "force" : 480,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 147,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n
��$l��",
        "force" : 500,
        "dodge" : 100,
        "damage": 520,
        "lvl" : 154,
        "damage_type" : "����"
]),
([
    "action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡",
        "force" : 600,
        "dodge" : 100,
        "damage": 665,
        "lvl" : 180,
    "damage_type" : "����"
]),
([      "action" : HIW "����$N����$w" HIW "�ƿճ�����ƽƽһ������$n��������ʽ����",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 250,
        "damage_type" : "����"
]),
([      "action" : HIW "$N�����۽������赭д������̳�һ������֮����������ʽ",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 300,
        "damage_type" : "����"
]),
([      "action" : HIW "$N��Ʈ�ݣ���̬��Ȼ������������У�����$w" HIW "�����������������"
                   "�Ž��ѵ����շ�����ľ���",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 350,
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "��ɽ��"|| myfam["master_id"] != "feng qingyang")
                return notify_fail("���¾Ž�ֻ�����������ǰ��ѧϰ��\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취�����¾Ž���\n");
        if( (int)me->query_skill("zixia-shengong",1)<100)
                return notify_fail("���¾Ž����������ϼ�񹦲�����ϰ��\n");
       if (((int)me->query_skill("huashan-sword", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��Ľ��ڻ�ɽ����̫���ˡ�\n");
       if (((int)me->query_skill("kuangfeng-jian", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("������ڿ��콣̫���ˡ�\n");
       if (((int)me->query_skill("poyu-quan", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("�������ȭ̫���ˡ�\n");
       if (((int)me->query_skill("hunyuan-zhang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��Ļ�Ԫ��̫���ˡ�\n");
       if (((int)me->query_skill("feiyan-huixiang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��ķ������̫���ˡ�\n");
       if (((int)me->query_skill("huashan-neigong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��Ľ����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("zixia-shengong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��������ڹ�̫���ˡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("���¾Ž�ֻ��ͨ��"+(order[random(13)])+"���ܾ�ʽ��"NOR"��������\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	int damage;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("lonely-sword", 1);
        if (random(me->query_skill("lonely-sword",1)) < 100 ||		             me->query_skill("force",1) < 100 )
        return 0;

	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("zixia-shengong",1);
        level2= (int) me->query_skill("zixia-shengong",1);
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "zixia-shengong")
{
if (random(2)==0)
{
	victim->start_busy(2);
}
else 	victim->receive_wound("qi", (random(damage_bonus))+200);
                  return random(2) ? HIR "$N" HIR "������ϼ�񹦣�һ��������������ɣ�,$n˫��һ��,��֪����Ǻ�!\n" NOR:
                                     HIR "$N" HIR "��������,����" + weapon->name() + HIR "���������۾�һ�㣬����ӳ�����,$n˫��һ��,��֪����Ǻ�!\n"NOR;
}
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("zixia-shengong",1);             
	if (random(3)==1 && me->query_skill("zixia-shengong",1)>300)
	{
	if( damage_bonus > 50 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)));
	return HIM"$N�����ݺ�! һ������������$n��$l�������Ѫ��!\n"NOR;
        }
}

if (me->query_skill_mapped("force") != "zixia-shengong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("sword") != "lonely-sword")
return 0;
if (me->query_skill_mapped("parry") != "lonely-sword")
return 0;

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return 0; 
        ap = (int)me->query("combat_exp");
        dpp = (int)victim->query("combat_exp");
        switch(random(5))
        {
           case 1:
              if (random(ap) > dpp/2 && random(lvl)> 180)
              {
                  me->add("neili", -20);
                  victim->receive_wound("qi", (damage_bonus) , me);
                  
                  return random(2) ? HIR "$N" HIR "һ��������������ɣ�" + weapon->name() + HIR
                                     "ʱ���������գ�ʱ��������ƣ�ȴ��֪����ͨ��"
                                     "һ��֮�о��̲������������\n" NOR:
                                     HIR "$N" HIR "����" + weapon->name() + HIR "��"
                                     "�������۾�һ�㣬һ������ӳ�����ֱ����$n" HIR 
                                     "С��������ƽ��������λ������ȴ�����ǡ���ô���\n" NOR;
             }
             break;

           case 2:
              if (random(ap) > dpp/2 && me->query("con") >= 36 && random(lvl)> 180)
              {
                  me->add("neili", -120);
                  victim->receive_wound("qi", (damage_bonus ) , me);
                  
                  return random(2) ? HIR "$N" HIR "һ��������������ɣ�" + weapon->name() + HIR
                                     "ʱ���������գ�ʱ��������ƣ�ȴ��֪����ͨ��"
                                     "һ��֮�о��̲������������\n" NOR:
                                     HIR "$N" HIR "����" + weapon->name() + HIR "��"
                                     "�������۾�һ�㣬һ������ӳ�����ֱ����$n" HIR 
                                     "С��������ƽ��������λ������ȴ�����ǡ���ô���\n" NOR;
             }
             break;

          case 3:
             message_vision(HIC "\n$N" HIC "����������е�" + weapon->name() +
                            HIC "�����дӳ��䲻��ķ�λֱָ$n" HIC "��ʽ�е�"
                            "������\n" NOR, me, victim);

             if (! me->is_busy() && random(lvl)> 180)
             {
                  weapon = me->query_temp("weapon");
                  weapon2 = victim->query_temp("weapon");
                  if (random(ap) > dpp/2 && weapon2
                      && !weapon2->query("ownmake") )
                  {
                           msg = HIW "$n" HIW "������ǰ�ۻ����ң�����"
                                 "��" + weapon2->name() + HIW "һʱ��"
                                 "Ȼ����ס�����ֶ�����\n" NOR;
                           weapon2->move(environment(me));      
                           me->add("neili", -100);                 
                  } else
                  {
                           msg = HIY "$n" HIY "�Եÿ�϶��Ϣ��һʱ��ȴ"
                                 "Ҳ����������\n" NOR;
                           me->add("neili", -10);
                  }
             }else 
             if (random(ap) > dpp/2 && random(lvl)> 180)
             {
                          msg = HIY "$n" HIY "��æ�ֵ���һʱ�䲻����æ���ң�"
                                "��Ͼ������\n" NOR;

                          me->start_busy(1);
                          victim->start_busy(2 + random(lvl / 30));
             }
             else
             {
                          msg = HIC "$N" HIC "������������е�" + weapon->name() +
                                HIC "����$n" HIC "������$n" HIC "���ص��쳣���ܣ�$N"
                                HIC "һʱ��Ȼ�޷��ҵ�������\n" NOR;
                          me->start_busy(1);
                          victim->start_busy(3);
             }
             message_combatd(msg, me, victim);
             break;
          
          case 4:
             if (random(ap) > dpp/2 && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian") &&
                 me->query("dex") >= 36
                 && random(lvl)> 180
                 )
             {
                weapon = me->query_temp("weapon");
                message_vision(HIY "\n$N" HIY "�زؽ��⣬����" + weapon->name() + HIY 
                             "��������������ٶ�֮�죬��λ֮׼�����Ƕ��¾Ž��Ѵﵽ"
                             "\n�շ�����ľ��硣\n" NOR,
                             me, victim);

                me->add("neili", -20);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 7; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(2);

                    COMBAT_D->do_attack(me, victim, weapon, 0);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
          
          default :
             if (random(ap) > dpp/2 && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian")
                 && random(lvl)> 180)
             {
                weapon = me->query_temp("weapon");
                message_vision(HIY "\n$N" HIY "�زؽ��⣬����" + weapon->name() + HIY 
                             "��������������ٶ�֮�죬��λ֮׼�����Ƕ��¾Ž��Ѵﵽ"
                             "\n�շ�����ľ��硣\n" NOR,
                             me, victim);

                me->add("neili", -20);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 7; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(2);

                    COMBAT_D->do_attack(me, victim, weapon, 0);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
       }

        if (random(me->query_skill("lonely-sword",1)) > 200 &&
        random(me->query_skill("sword",1))>180 &&
     	me->query_skill("force",1) > 250 
     	&& !victim->is_busy())
{
        me->add("neili", -50);
        victim->map_skill("dodge");

  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+2);
}
        message_vision(HIC "$nͻȻ�ٽ�һ�̣�����������£�ȴĪ�������ͻ����$N�Ĺ��ƣ����$N���ϣ�" NOR, victim,me  );
        return HIR"$n���һ������Ȼ�������ܣ�\n"NOR;
        
}
        if (random(me->query_skill("lonely-sword",1)) > 140 &&	
	 random(me->query_skill("sword",1))>140 &&
            me->query_skill("force",1) > 200 
            && !victim->is_busy())	
{
        
        me->add("neili", -30);
        victim->map_skill("parry");
  if( !victim->is_busy() )
{
        victim->start_busy(random(2)+2);
}
        message_vision(HIC "$n�ٽ��������������ش���$N��������$N��������������һ������������" NOR, victim,me);
        return HIY"$n���Կ��彣������,��Ȼ�����мܣ�\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 130 &&	
        random(me->query_skill("sword",1))>130 &&
	 me->query_skill("force",1) > 150
	 && !victim->is_busy())
{
        me->add("neili", -50);
  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+2);
}
        message_vision(HIC "$n�ὣ�ش̣��������$N��������$N���ò��������أ�����һ�μ����˳�����" NOR, victim,me );
        return HIG"$n��æ���ң����Ҳ�����\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 100 &&
        random(me->query_skill("sword",1))>100 &&
      	me->query_skill("force",1) > 120
      	&& !victim->is_busy() )	
{
if (victim->query("neili")>600)
{
        victim->add("neili", -500);
}
        message_vision(HIC "$nһת���ƣ�����ԴԴ��������$N�������ƣ�\n" NOR, victim,me );
	return HIM"$nʹ������������ѳ���Ȧ��\n"NOR;
}
        if (random(me->query_skill("lonely-sword",1)) > 80 &&	
        random(me->query_skill("sword",1))>80 &&  
	  me->query_skill("force",1) > 100 
	  && !victim->is_busy())	
{

  if( !victim->is_busy() )
{        victim->start_busy(random(2)+2);
}
        message_vision(HIC "$n�ۼ����޿ɱܣ�ֻ���ὣ�Ҵ�һͨ����Ȼ�������ϵؽ�$N�Ĺ�����ȥ��롣" NOR, victim,me );
	return HIW"$n��ʱ�����޴룬��֪����Ǻã�\n"NOR;
  } 
	
	jiali = me->query("jiali");

if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(me->query_skill("lonely-sword",1))>140 
	&& me->query("fengset")
	) {
	victim->receive_wound("qi", (random(jiali)+200));
	return HIM"$N�����ݺ�! һ������������$n��$l�������Ѫ��!\n"NOR;
}
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
j=damage;
if (me->query_skill_mapped("force") != "zixia-shengong")
return damage;
if (me->query_skill_mapped("sword") != "lonely-sword")
return damage;
if (me->query_skill_mapped("parry") != "lonely-sword")
return damage;

if (me->query("neili") < 500)
return damage;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return damage;

             if (random(ap) > dp/2 && random(2)==0)
             {
                        result = HIG "$n" HIG "�����$N" HIG "�Ĺ��ƣ�"
                                    "����ӳ�һ����������$N" HIG "��\n" NOR;
                                    if (!ob->is_busy()) ob->start_busy(3);
                    message_vision(result,ob,me);
             }
             
  if (random(ap) < dp/2  && me->query("fengset") 
  && random(2)==0)
        {
                switch (random(9))
                {
                case 0:
                        result = HIC "ȴ��$n" HIC "̤ǰһ������ʽбָ$P" HIC
                                            "�ұۣ���ʽѸ���ޱȣ�ʹ��$N" HIC "�������"
                                            "��\n" NOR;
                        break;

                case 1:
                        result = HIC "��$n" HIC "�Թ�Ϊ�أ��Խ�Ϊ�ˣ�������"
                                            "����$N" HIC "�͹����ػӳ���λ�����̩ɽ"
                                            "��" NOR + YEL "�����" NOR + HIC "��������"
                                            "\n" NOR;
                        break;

                case 2:
                        result = HIC "$n" HIC "ͻȻһ������$N" HIC "����һ��"
                                            "ȴ�����������ţ�$N" HIC "��ʱ�����޴룬��"
                                            "�Ʋ�������ͣ��������\n" NOR;
                        break;

                case 3:
                        result = HIC "����$n" HIC "�������ܣ��ٽ������ʹ��"
                                            "��" NOR + HIG "���両��" NOR + HIC "������"
                                            "$N" HIC "���󣬵����˴��С�\n" NOR;
                        break;

                case 4:
                        result = HIC "ȴ��$n" HIC "ͻȻʹ��������ɷ罣����"
                                            NOR + CYN "���ڤڤ" NOR + HIC "����������"
                                            "��$N" HIC "һ�ʣ���ʱͻ���˹��ơ�\n" NOR;
                        break;

                case 5:
                        result = HIC "$n" HIC "ͦ�����䣬��һ�С�" NOR + HIW
                                            "���Ƴ��" NOR + HIC "���ش�$N" HIC "����"
                                            "ʱ�ѽ����ƻ��⡣\n" NOR;
                        break;

                case 6:
                        result = HIC "ֻ��$n" HIC "���˷���������Ʈ�磬һʽ" 
                                            "��" NOR + HIW "��������" NOR + HIC "������"
                                            "�޶�����ס�˽�����\n" NOR;
                        break;

                case 7:
                        result = HIC "����$n" HIC "���˷�����ʹ����ɽ���С�"
                                            NOR + HIY "�������" NOR + HIC "����������"
                                            "�磬�ܿ���$N" HIC "���С�\n" NOR;
                        break;

                default:
                        result =  HIC "$n" HIC "����ͻ�䣬������������������"
                                            "��ز����ʹ��ɽ�����ġ�" NOR + HIY "������"
                                            "��" NOR + HIC "����ͼ��ʹ$N" HIC "���С�\n"
                                            NOR;
                        break;
                }
message_vision(result,ob,me);
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi"))
me->add("qi",damage/3);
if ((int)me->query("eff_qi") < (int)me->query("max_qi"))
me->add("eff_qi",damage/3);
            damage=100;
            j=100;
            return j;

        }
             
        
if ((int)me->query("qi")>1 && (int)me->query("eff_qi")>1)
{
if ((int)me->query("qi") < (int)me->query("eff_qi"))
        i = (int)me->query("eff_qi") / (int)me->query("qi") + 1;
else         i = (int)me->query("max_qi") / (int)me->query("eff_qi") + 1;
        if ( i > 5 ) i = 5;
}
else i=1;
        limbs = ob->query("limbs");
        level = me->query_skill("lonely-sword", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 100 /i 
         && me->query_skill_mapped("sword") =="lonely-sword"
         && me->query_skill_mapped("parry") =="lonely-sword"
         && me->query("fengset")
         && weapon
         && weapon->query("skill_type") == "sword"
         && me->query_skill("sword") > 300
         && random(me->query_skill("sword",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 4000
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIW"$N����ҡҡ��׹���ж����㣬֪����һ���޿ɶ�ܣ�����ͦ���̳������������۵�һ������$n���ʺ�\n"NOR;
            if ( random(level) > ob->query_skill("dodge", 1) / i){
             q = damage * i ;
             if ( q > 3500 ) q = 3500 + ( q - 3500 )/ 100;
             ob->receive_damage("qi", q);
             ob->receive_wound("qi", q/2);
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
             if ( random(me->query("combat_exp")) > ob->query("combat_exp") / i)
             p = ob->query("qi")*100/ob->query("max_qi");
             msg += damage_msg(damage, "����") + "( $n"+eff_status_msg(j)+" )\n";
             msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
             msg = replace_string(msg, "$w", "����");
             j = -(damage/2+random(damage/2));
            }
            else {
              dodge_skill = ob->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(ob, 1);
              j = -damage/4; 
            }
            message_vision(msg, me, ob);
            return j;
        }
}
