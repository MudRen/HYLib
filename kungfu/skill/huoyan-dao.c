//
// huoyan-dao.c ���浶
// Designed by secret(����)
//
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N��ü��Ŀ������һ������ȫ��ǽ�һ���죬һ�С��޼᲻�ݡ���������$n����һ�ƣ�����������$n��ȫ��",
        "skill_name" : "�޼᲻��",
        "force" : 250,
        "lvl" : 5,
        "dodge" : 5,
        "damage" : 200,
        "parry" : 0,
        "weapon" : random(2) ?"���ε���" : "���浶��", 
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����з�ʬ��������$n�������ұ��������㲻մ�أ�˫�ƴ���˷���һ���Ƶش���$n��һ�ƽ��������������ѱ䡣",
        "skill_name" : "���з�ʬ",
        "force" : 280,
        "lvl" : 35,
        "dodge" : 7,
        "damage" : 200,
        "parry" : 0,
        "weapon" : random(2) ?"���ε���" : "���浶��", 
        "damage_type" : "����",
]),
([      "action" : "$N�������У���$n˫���������ţ�����һ������Ʈ��$n���������ʹ��һ�С������ɢ��������$n�ĺ��ԡ�",
        "skill_name" : "�����ɢ",
        "force" : 300,
        "lvl" : 65,
        "damage" : 200,
        "dodge" : 15,
        "parry" : 5,
        "weapon" : random(2) ?"���ε���" : "���浶��", 
        "damage_type" : "����",
]),
([      "action" : "$N��ǰһ�󲽣�˫��һ��ʹ��һ�С�������������˫��һǰһ������$n��$l���Ʒ�����֮����",
        "skill_name" : "��������",
        "damage" : 260,
        "force" : 360,
        "lvl" : 95,
        "dodge" : 10,
        "parry" : 3,
        "weapon" : random(2) ?"���ε���" : "���浶��", 
        "damage_type" : "����",
]),
([      "action" : "$N˫�ƻӶ�֮�ʾ�����һ�����ˣ�һ�С�������ʯ����˫�Ʒ��������������д������˽�������$n��$l��",
        "skill_name" : "������ʯ",
        "force" : 420,
        "lvl" : 125,
        "dodge" : 10,
        "parry" : 0,
                "damage" : 400,
        "weapon" : random(2) ?"���ε���" : "���浶��", 
        "damage_type" : "����",
]),
([      "action" : "$N��¶��Ц��һ�С���Ű���ҡ���˫��������һ�㷢����$n���Ʒ�Ƶ�һ�����ϣ�ü������$N��������˿��ý��ڡ�",
        "skill_name" : "��Ű����",
        "force" : 460,
        "lvl" : 155,
        "dodge" : 20,
        "parry" : 5,
                "damage" : 400,
        "weapon" : random(2) ?"���ε���" : "���浶��", 
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"����ľȡ��"NOR"������ת��˫����ǰƽƽ����$n",
        "skill_name" : "��ľȡ��",
        "force" : 100,
        "lvl" : 0,
        "damage" : 160,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"��ף�ڻ��桹"NOR"�������絶��бб����$n��$l",
        "skill_name" : "ף�ڻ���",
        "force" : 150,
        "lvl" : 10,
        "damage" : 180,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"������ޱߡ�"NOR"��˫��һ�ģ�һ�����������й���$n��$l",
        "skill_name" : "����ޱ�",
        "force" : 200,
        "lvl" : 20,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"�������ֻء�"NOR"��˫�ֺ�ʮ����ͷ����$n",
        "skill_name" : "�����ֻ�",
        "force" : 250,
        "lvl" : 30,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"��˫�����桹"NOR"��˫��һ�������������湥��$n��$l",
        "skill_name" : "˫������",
        "force" : 300,
        "lvl" : 40,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"����ɽ�𺣡�"NOR"��˫������б�ģ���ʱ��ǧ������������˷�����$n",
        "skill_name" : "��ɽ��",
        "force" : 350,
        "lvl" : 60,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"���׷��ȡ�"NOR"����ۻ��գ�����������ֱ��$n��$l",
        "skill_name" : "�׷���",
        "force" : 400,
        "lvl" : 80,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"������������"NOR"��˫��΢��������ǰ�죬һ���ھ�����ɽ�����㹥��$n",
        "skill_name" : "��������",
        "force" : 500,
        "lvl" : 100,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$N��Ϣת�����˾���˫�ۣ�ȫ��ǽ�һ���죬����һʽ"+(order[random(13)])+"��ʾ������"NOR"��$n��������$nȫ�������ڳ��ȵ��Ʒ���",
        "skill_name" : "ʾ����",
        "force" : 300,
        "lvl" : 15,
        "damage" : 300,
        "dodge" : 15,
        "damage_type" : "����",
]),
([      "action" : "$N�����Ц��һ��"+(order[random(13)])+"��ʼ�ľ���"NOR"�����浶�ھ����ڼ�������ӿ����$P˫���籦���ʮ����ǰ������$n����һ��",
        "skill_name" : "ʼ�ľ�",
        "force" : 350,
        "lvl" : 25,
        "damage" : 300,
        "dodge" : 10, 
        "damage_type" : "����",
]),
([      "action" : "$N˫�ƺ�ʮ���ִ򿪣�����"+(order[random(13)])+"���ֱ�����"NOR"�Ի��浶���Ϲ����۳�һ�������ʢ���Ļ��������ת��������$n����",
        "skill_name" : "�ֱ���",
        "force" : 400,
        "lvl" : 55,
        "dodge" : 5,
        "damage" : 300,
        "weapon" : "��������",
        "damage_type" : "����",
]),
([      "action" : "$N�������࣬˫�ƴ�Բ��ʹ�������ȵĵ�����ۣ�����"+(order[random(13)])+"���Ʒ�ִ��"NOR"����һֻ�޴�����ƣ������$n��ץ����",
        "skill_name" : "�Ʒ�ִ",
        "force" : 340,
        "lvl" : 75,
        "damage" : 380,
        "dodge" : 1,
        "damage_type" : "����",
]),
([      "action" : "$N����һ������Ȼʹ����ħ���ϵ�"+(order[random(13)])+"������Բ��"NOR"��������쫷��Χ��$P������������$nһ��������$P��������",
        "skill_name" : "����Բ",
        "force" : 450,
        "lvl" : 125,
        "damage" : 400,
        "dodge" : 10,
        "damage_type" : "����",
]),
([      "action" : "$N�����ħ�澭��˫��������������$n����������֮�£����絶�и�����"+(order[random(13)])+"�����泣��"NOR"�����ƺ�Ҫ��$p��������",
        "skill_name" : "���泣",
        "force" : 380,
        "lvl" : 145,
        "damage" : 400,
        "dodge" : 15, 
        "weapon" : "���ε���",
        "damage_type" : "����",
]),
([      "action" : "$N�ֱ��࣬������������"+(order[random(13)])+"�����淨��"NOR"�����ĳ�������е������᲻ɢ�����������Ƶ�����ȴ��ɽ�������ӿ��$n",
        "skill_name" : "���淨",
        "force" : 450,
        "lvl" : 160,
        "damage" : 400,
        "dodge" : 15, 
        "damage_type" : "����",
]),
([      "action" : "$N�������ƣ�һʽ"+(order[random(13)])+"�������š�"NOR"��������ת������ȫ�������޷��Զ���$P����΢�㣬��������һ����ն��$n$l",
        "skill_name" : "������",
        "force" : 500,
        "lvl" : 180,
        "damage" : 400,
        "dodge" : 55, 
        "weapon" : "��������",
        "damage_type" : "����",
]),

});


int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

void skill_improved(object me)
{
   int skill = me->query_skill("huoyan-dao", 1);
   if(skill >= 200 && !me->query("hyd_add")){
   	 me->set("hyd_add", 1);   
   	 tell_object(me, HIW"\n��Ȼ����е�������ϢԽתԽ�죬˲ʱ�书���Ѿ���������һ���µľ��磡\n������������ˣ�\n��ĸ��������ˣ�\n"NOR);
         me->add("max_neili", skill+random(skill));
         me->add("con", 1);
         }
}


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");

	else if ((int)me->query("max_neili") < 300)	//  ���浶Ҫ�кܸߵ���������ѧ
		return notify_fail("�������������\n");

	if ((int)me->query_skill("longxiang", 1) >= 60 ||
	    (int)me->query_skill("xiaowuxiang", 1) >= 60)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 60)
		return notify_fail("���������������̫ǳ��\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 60)
		return notify_fail("���С���๦���̫ǳ��\n");
        if ((int)me->query_skill("dashou-yin", 1) < 80)
		return notify_fail("������ڴ���ӡ�����̫ǳ��\n");
        if ((int)me->query_skill("yujiamu-quan", 1) < 80)
		return notify_fail("��Ľ�����ĸȭ���̫ǳ��\n");
}


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
		  level   = (int) me->query_skill("huoyan-dao",1);
        if ( random(level)>200
        && random(10)>5){
		return ([
		"action": HIR "$N˫�Ƽе���ʮ������"+HIR"��ʱ����һ�Ż��潫�Լ���Χ��$N����һ����ţ�һ��ֱ����$n��" NOR,
                "force" : 800,
                "dodge" : 10,
                "damage": 800,
		"damage_type": "����"]);
        }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");
	if ((int)me->query("qi") < 140)
		return notify_fail("������������������˻��浶��\n");
        if ((int)me->query_skill("dashou-yin", 1) < 80)
		return notify_fail("������ڴ���ӡ�����̫ǳ��\n");
        if ((int)me->query_skill("yujiamu-quan", 1) < 80)
		return notify_fail("��Ľ�����ĸȭ���̫ǳ��\n");
	me->receive_damage("qi", 50);
	return 1;
}


string perform_action_file(string action)
{
	return __DIR__"huoyan-dao/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int j, skill, neili, neili1;
       object wp1,weapon;
        int p;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("longxiang",1);
        skill = me->query_skill("longxiang", 1);
if ( level2<= 0) level2= (int) me->query_skill("xiaowuxiang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIM"$N ���������𡸽�����ħ�䡹��������ӿ������һ��һ��ļ�ǿ��$n����һ�ң�������Ȼ�᲻������\n"NOR;
ob->set_temp("apply/attack", 0);
ob->set_temp("apply/defense", 0);
if (random(2)==0)
{
msg += HIM"$N"+HIM+"Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ! $n����һ�����³�һ����Ѫ!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           message_vision(msg, me, ob);
           return j;
}      
        skill = me->query_skill("huoyan-dao", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

      if(me->query("jiali") && random(skill) > 180
         && me->query("combat_exp") > ob->query("combat_exp")/3
         && me->query_skill_mapped("parry") == "huoyan-dao"
         && me->query_skill("longxiang", 1) > 150
         && neili > 1000 
         && skill > 150 
         && living(me)
         && !me->query_temp("weapon")
         && !ob->query("env/invisibility")) 
         {           
         msg = HIR"ֻ����$N��ǰ�������죬�����浶�����ƴ�ʢ��"NOR;            
           if(neili >= neili1+random(neili1)+damage*2){
              msg += HIR"��$n��ʽ�ϵ��������ƽ�������\n"NOR, 
              j = -5000;
              }
           else if(neili >= neili1+damage){
              msg += RED"$P�����ﴦ����ס��һЩ$n������������\n"NOR, 
              j = -(damage/2+random(damage/2));               
              }
           else{
              msg += HIR"$Pչ�����浶������ס��һЩ$n�Ĺ�����\n"NOR, 
              j = -damage/3; 
              }        
           if(wizardp(me)) tell_object(me, "Target damage = "+damage+" ��\n");   
           message_vision(msg, me, ob);
           return j;
       }          
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 
             me->set_temp("xiuluo", 1);
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("huoyan-dao",1)) > 100 ) 
{
	  victim->receive_wound("qi", damage_bonus/2);
        return HIM "$n���Ʒ�ɨ�У��о��˿�����������\n" NOR;
}
}
