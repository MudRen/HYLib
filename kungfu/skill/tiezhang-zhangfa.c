// tiezhang-zhangfa ���ư� �����Ʒ�
// by zqb
//update by cool 981010
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N����һ������һ��"+(order[random(13)])+"���ƴ����¡�"NOR"���Բ����������򣬵�ʱ��$n��������б��",
        "dodge": 5,
        "force": 200,
        "damage": 300,
        "parry": 40,
        "lvl": 0,
        "damage_type": "����"
]),
([      "action": "$Nʹһ��"+(order[random(13)])+"����ˮ������"NOR"�����ƶ�Ȼ�����쳤���ұۣ��ɿ��һ��������ն��$n��$l",
        "dodge": 10,
        "force": 260,
        "damage": 330,
        "parry": 35,
        "lvl": 0,
        "damage_type": "����"
]),
([      "action": "$NͻȻʹһʽ"+(order[random(13)])+"�����ƻ��衹"NOR"��˫��������һ��һ����裬����һ����ת�����ˡ� ",
        "dodge": 15,
        "damage": 300,
        "force": 300,
        "parry": 30,
        "lvl": 10,
        "damage_type": "����"
]),
([      "action": "$Nһ��"+(order[random(13)])+"������Ǭ����"NOR"���͵ز���������ұ��������¼���������Ĵ������ָ��Ȧ�͵�$n��$l",
        "dodge": 20,
        "damage": 330,
        "force": 280,
        "parry": 25,
        "lvl": 20,
        "damage_type": "����"
]),
([      "action": "$Nһ��"+(order[random(13)])+"�����ո��¡�"NOR"������һ��һ�գ�һ����˿��������һ��֮�䣬һ�������ޱȵ������Ŷ�Ȼ������",
        "dodge": 25,
        "damage": 360,
        "force": 320,
        "parry": 20,
        "lvl": 30,
        "damage_type": "����"
]),
([      "action": "$N���б���һʽ"+(order[random(13)])+"������Ϊ����"NOR"��˫�ƺ���г�����Ե�ŵݳ������غ�Х֮��������",
        "dodge": 20,
        "force": 350,
        "parry": 15,
        "damage": 370,
        "lvl": 40,
        "damage_type": "����"
]),
([      "action": "$Nһ��"+(order[random(13)])+"�����޵�����"NOR"�����ƴ�Ȧ����������СȦ�������������������һ��֮�£�����$n��$l",
        "dodge": 25,
        "force": 400,
        "parry": 10,
        "damage": 380,
        "lvl": 50,
        "damage_type": "����"
]),
([      "action": "$Nһ��"+(order[random(13)])+"����ָ��ɽ��"NOR"����һ�����������������ţ���һ��ȴ��Ѹ���ޱȵ�һ�Ƽ��ա�",
        "dodge": 30,
        "force": 450,
        "parry": 5,
        "damage": 390,
        "lvl": 60,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���һ�������м��ɶ�������$nֱ�˶��£������б������ء���һ���̶���Х��",
        "force": 540,
        "parry": 10,
        "dodge": 40,
        "damage": 400,
                 "lvl": 100,
        "damage_type": "����"
                ]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="unarmed"; }
int valid_combine(string combo) { return combo=="liumang-quan"; }

mapping query_action(object me, object weapon)
{
                  int i,level,lev;

        if (random(me->query_skill("strike", 1)) > 100 
            && random(me->query_skill("tiezhang-zhangfa", 1)) > 200 
            && me->query_skill("force") > 100
            && me->query("neili") > 30 
            && !me->is_busy()) {
                me->add("neili", -20);
                return ([
                  "action": HIR"$NͻȻ���һ�������м��ɶ�������$nֱ�˶��£������б������ء���һ���̶���Х��"NOR,
                  "force": 650,
                  "parry": 10,
                  "dodge": 40,
                  "damage": 630,
                  "damage_type": "����"
                ]);
        }
        level = (int) me->query_skill("tiezhang-zhangfa",1);
                lev   = (int) me->query_skill("guiyuan-tunafa",1);
        
        if (me->query_temp("tzzf") && me->query("jiali") < 50 )
        me->set("jiali",50);
        
          for(i = sizeof(action); i > 0; i--) {
                                 if(level > action[i-1]["lvl"]) {
                               if (me->query_temp("tzzf")) {                
                    return ([  
                    "action" : WHT+action[NewRandom(i, 20, level/5)]["action"]+NOR,
                    "force" : action[NewRandom(i, 20, level/5)]["force"]+random(30),
                    "dodge":action[NewRandom(i, 20, level/5)]["dodge"],
                    "damage": level/4+random(lev/4),
                    "lvl" : action[NewRandom(i, 20, level/5)]["lvl"],
                    "weapon" : "�Ƶ�",
                    "damage_type" : random(2)?"����":"����",
                    ]);
               } else return action[NewRandom(i, 20, level/5)];
                           }
                           }
}


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʒ�������֡�\n");
        if ((int)me->query_skill("guiyuan-tunafa", 1) < 10)
                return notify_fail("��Ĺ�Ԫ���ŷ���򲻹����޷��������Ʒ���\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ�������޷��������Ʒ�");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("��ı����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("��ı����Ṧ̫���ˡ�\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("���ͨ��������̫���ˡ�\n");
        return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("������������������Ʒ���\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("��ı����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("��ı����Ṧ̫���ˡ�\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("���ͨ��������̫���ˡ�\n");
        if (me->query_skill("tiezhang-zhangfa", 1) < 50)
                me->receive_damage("jing", 20);
        else
                me->receive_damage("jing", 30);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tiezhang-zhangfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lev,damage, i;
        object weap;
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N����һ������������һƬ��Ҷ���Ʈ��,$nͷһ�裬��֪����!\n"NOR;

victim->start_busy(3);

                return msg;
}
        weap = victim->query_temp("weapon");
        lev =me->query("tiezhang-zhangfa");
	if( damage_bonus < 20 ) return 0;
	if( damage_bonus/2+20  > victim->query_str() ) {
if(me->query_skill("guiyuan-tunafa", 1) > 10 && random(2) == 1)
{
		victim->receive_wound("qi", (damage_bonus ) +10 );
		return HIW "��! "+ victim->name()+"���Ʒ�ɨ�У��ڽ����³�Ѫ˿....\n" NOR;
}
        if( (me->query("neili") > 1000)&& (victim->query_temp("weapon"))
                                            && (me->query_temp("tzzf"))
                         && (random(me->query_str()) > victim->query_str()/2) )
                 {      
                                      if (!weap->query("ownmake"))
                        {
                        message_vision(HIW "$N�����絶��������ʮ���£�ֻ����"+(order[random(13)])+"��ž��"NOR"��һ����$n���е�" + weap->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, me, victim );
                        weap->move(environment(me));
                        weap->set("name", "�ϵ���"+weap->query("name"));
                        weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        } else {
                        message_vision(HIW "$N�����絶��������ʮ���£�ֻ����"+(order[random(13)])+"������"NOR"��һ����$n���е�" + weap->name()
                                + "��㱻�������䵽���ϣ�\n" NOR, me,victim );
                        victim->start_busy(3);
                                                }
                                                victim->reset_action();
                        me->add("neili", -100);
                        return 1;
                 }

	}
 
       
}

