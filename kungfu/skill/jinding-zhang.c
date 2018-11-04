// jinding-zhang.c ������
// Oct. 9 1997 by That
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "skill_name" : "������̩" ,
        "action" : "$N����΢�Σ�һ��"+(order[random(13)])+"��������̩��"NOR"�����������$nֻ����һ��ů��Ϯ��$l",
        "force" : 100,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "����",
        "lvl"   : 0,
]),
([      "skill_name" : "��������" ,
        "action" : "$N˫�ֱ�ã���ָ�ᵯ��һ��"+(order[random(13)])+"���������项"NOR"��������·������ʮ����ץ��$n��$l",
        "force" : 120,
        "dodge" : 10,
        "damage" : 200,
        "damage_type" : "����",
        "lvl"   : 11,
]),
([      "skill_name" : "�����" ,
        "action" : "$N����ǰ��������ٿ��������ͷ�һ��"+(order[random(13)])+"������ơ�"NOR"����ץ��$n��$l",
        "force" : 150,
        "dodge" : 15,
        "damage" : 250,
        "damage_type" : "����",
        "lvl"   : 22,
]),
([      "skill_name" : "������ɳ" ,
        "action" : "$N����Ȧת�����$n�����֣������Ƴ������������Ļ���һ��"+(order[random(13)])+"��������ɳ��"NOR"���͵ػ���$n���°�",
        "force" : 200,
        "dodge" : 25,
        "damage" : 300,
        "damage_type" : "����",
        "lvl"   : 33,
]),
([      "skill_name" : "�׶�����" ,
        "action" : "$N�������ף�һ�����ȣ���$nһ㶼䣬����һ��"+(order[random(13)])+"���׶�������"NOR"��ֱ��$n��$l",
        "force" : 200,
        "dodge" : 10,
        "damage" : 220,
        "damage_type" : "����",
        "lvl"   : 44,
]),
([      "skill_name" : "�𶥷��" ,
        "action" : "$N˫��ƽ����ȭ����¶΢Ц��$n��㱼俴��$N����Ϊ�������$N���������һ��"+(order[random(13)])+"���𶥷�⡹"NOR"��֪��������ʵ���Ʒ��Ѿ�Ϯ��",
        "force" : 300,
        "dodge" : 15,
        "damage" : 250,
        "damage_type" : "����",
        "lvl"   : 55,
]),
([      "skill_name" : "���Ľ�ħ" ,
        "action" : "$Nһ������ׯ�ϣ�ʹ��"+(order[random(13)])+"�����Ľ�ħ��"NOR"��������磬����$nƯ�Ʋ���",
        "force" : 230,
        "parry" : 20,
        "dodge" : 20,
        "damage" : 360,
        "damage_type" : "����",
        "lvl"   : 66,
]),
([      "skill_name" : "����˻�" ,
        "action" : "$Nȫ�����ߣ�˫�ۼ��裬��Ϊ�����Ӱ��һ��"+(order[random(13)])+"������˻ġ�"NOR"����ǵ�Ϯ��$nȫ�������Ѩ",
        "force" : 300,
        "parry" : 5,
        "dodge" : 300,
        "damage" : 300,
        "damage_type" : "����",
        "lvl"   : 77,
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 10)
                return notify_fail("����ټ�ׯ�ķ���򲻹��������������ơ�\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("�������̫�����޷��������ơ�\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i-1]["lvl"])
                return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, jiali,p;
        int level   = (int) me->query_skill("jinding-zhang",1);
  string msg; 
        mapping px_info;
	object victim, ob;

	// lasting effects of piaoxue
        ob = me->select_opponent();
p=level+100;
        if (random(me->query_skill("jinding-zhang",1)) > 200
        && me->query_skill("linji-zhuang",1) > 200 &&
        me->query("neili") > 200 && ob)
{
	me->add("neili", -30);
  msg = HIY "\n$P���ƺ��ͣ�����һβ�����ޱȣ�Ѹ�����׵�С��һ�㣬����$n����ǰ��\n";
  msg += "$n��Ȼ��Ȼ�ķ��������ͶԷ�����������һ�������������ɾ޴���ھ�����δײ��\n";
  msg += "����δ��֮�ʣ�$P������ȴ��Ȼ��Ӱ���ٵ���ʧ�ˡ�\n\n"NOR;
if (random(me->query_skill("jinding-zhang",1)) > ob->query_skill("parry",1)/2)
	    if (ob->query("neili") > p) {
		msg += HIR "\n$n����͸$P��������ʵ��ֻ�ô����������ȫ������������\n"NOR;
		ob->receive_damage("qi", p);
		ob->add("neili", -p);
	    } else {
		msg +=HIR "\n$nһ�������᲻��������$P�Ʒ�ɨ�У��������ģ��������¡�\n"NOR;
		ob->receive_damage("qi", p);
	    }
else
{
if (random(me->query_skill("jinding-zhang",1)) < ob->query_skill("parry",1)/6)
{
    msg += HIB"$n��Ц�����������֮��˭�˲�֪��Ʈѩ�����ƣ�Ҳ����˼�����ֳ�\n";
    msg += HIB"$n���²������˵�վ��һ��׮���������ӣ���$P�ľ�������жȥ��\n";
    msg += HIR"$N���һ������࣬���ĵĿ��Ŵ󿪣��Ǳ����м��ţ�\n" NOR;
    me->start_busy(2);
}
else       msg += HIG"$n�����������ؿڣ��������$P��һ�ƣ�Ц����Ʈѩ�����ƺô����ͷ����ʹ��Ҳ������ˡ�\n" NOR;
}
  message_vision(msg+"\n", me, ob);

}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if (me->query_skill("jinding-zhang", 1) < 100)
                me->receive_damage("qi", 10);
        else
        me->receive_damage("qi", 20);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/"+ action;
}
int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N �������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩��������϶��Ҿ����������֮���ʱ����!��\n"NOR;
msg += "$N��ɫһ��,�ָ���Щ������\n",  
           message_vision(msg, me, ob);
           return j;
} 
}