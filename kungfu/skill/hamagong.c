// hamagong.c ��󡹦
// By Five
#include <ansi.h>
inherit FORCE;
int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("hamagong", 1);
        return lvl * lvl * 15 * 22 / 100 / 200;
}

mapping *action = ({
([      "action" : "$N����������һ�ֳŵأ����Ӻ�ͦ��ֻ��һ����$n��$l�ĳ�",
        "dodge"  : 0,
        "force"  : 310,
        "attack" : 103,
        "parry"  : 21,
        "damage" : 58,
        "lvl"    : 0,
        "damage_type": "����" 
]), 
([      "action" : "$N˿��������ɫ��˫��΢��������ƽ�죬���������󡹦��"
                   "����������һ������$n",
        "dodge"  : 0,
        "force"  : 332,
        "attack" : 112,
        "parry"  : 37,
        "damage" : 61,
        "lvl"    : 250,
        "damage_type": "����"
]), 
([      "action" : "$N���۱�ס����������Ƭ�̣���Ծ�����۾�Ҳ����������˫"
                   "�Ʊ���$n�ķ������˳�ȥ",
        "dodge"  : 0,
        "force"  : 360,
        "attack" : 122,
        "parry"  : 53,
        "damage" : 72,
        "lvl"    : 260,
        "damage_type": "����"
]),
([      "action" : "$N�Ų�ҡҡ�ϻϣ���Ȼ˫��һ�䡢һ�ǣ����и��һ���кȣ�"
                   "������$n��Ȼ�Ƴ�",
        "dodge"  : 5,
        "force"  : 410,
        "attack" : 143,
        "parry"  : 67,
        "damage" : 81,
        "lvl"    : 270,
        "damage_type": "����"
]), 
});

mapping *reverse_action = ({
([      "action": "����$N���������������������������һ������ݺݵĳ�$n�˽�����",
	"dodge": 15,
	"parry": 20,
	"force": 300,
	"damage": 60,
	"damage_type": "����"
]),
([      "action":"����$N���Ƹ������������°�ĭ����ͷ��$n��ײ",
	"parry": 15,
	"force": 360,
	"damage": 70,
	"damage_type": "����"
]),
([      "action":"$N����ſڣ�����һ��������$n$lҧ�䣬�ֿ���׼",
	"dodge": 15,
	"force": 420,
	"damage": 80,
	"weapon": "����",
	"damage_type": "ҧ��"
]),
([      "action":"$Nһ����ĭ���£���Ю���磬����̵����ĭҲ�����˹�������",
	"dodge": 45,
	"force": 480,
	"damage": 90,
	"weapon":"��ĭ",
	"damage_type": "����"
]),
([      "action":"$N��Ȼ���죬һ����ĭ��$n������ȥ�����ƻ���$n���ܵķ�λ��ͬʱ����һ��Ũ̵�½�����",
	"dodge": 30,
	"force": 540,
	"damage": 100,
	"weapon" : "Ũ̵",
	"damage_type": "����"
]),
([      "action":"��ʱ$N��ʹ����������ϣ��Ź֣�������ף�����ʱ��������ʱ��ֱ������Ȼһ�ֳŵأ����Ӻ�ͦ��һ�ֳ��ƴ���$n$l",
	"dodge": 10,
	"force": 600,
	"damage": 110,
	"damage_type": "����"
]),
});
int valid_enable(string usage) {
        object me = this_player();
        int lvl;
        lvl = (int)this_player()->query_skill("hamagong", 1);

        if (lvl >= 300)    
                return usage == "strike" || usage == "force" || usage =="parry";
        else
                return usage == "force";
	 }
int can_not_hubo() {return 1;}

int valid_learn(object me)
{
	int i = (int)me->query_skill("hamagong", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( me->query("gender") == "����" && i > 49)
		return notify_fail("���޸����ԣ���������������������ĸ�󡹦��\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ��󡹦��\n");

	if(i<=300)
	{
		if (i > 10 && -(int)me->query("shen") < t * 5) 
			return notify_fail("ѧ��󡹦��Ҫ�ĺ���������������������ò���ѽ��\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("ѧ��󡹦��Ҫ�ĺ���������������������ò���ѽ��\n");
	}

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	||  me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��󡹦����\n");
	return 1;
}

int practice_skill(object me)
{
        object ob;

        if ((int)me->query("jing") < 180)
                return notify_fail("��ľ��񲻹��ã�û����ϰ�ˡ�\n");

        if ((int)me->query("qi") < 130)
                return notify_fail("������ʵ����̫ƣ���ˡ�\n");



        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���򲻹���\n");

        if ((int)me->query_skill("lingshe-zhangfa",1) < 280)
                return notify_fail("��������ȷ��������ң��޷�ʹ�ã�\n");

        if ((int)me->query_skill("xiyu-tiezheng",1) < 180)
                return notify_fail("��������������������ң��޷�ʹ�ã�\n");

        if ((int)me->query_skill("shentuo-zhang",1) < 180)
                return notify_fail("�������ѩɽ�ƻ������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("chanchu-bufa",1) < 180)
                return notify_fail("�����ܲ����������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("hamashengong",1) < 180)
                return notify_fail("��ĸ���񹦻������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("lingshe-quan",1) < 180)
                return notify_fail("�������ȭ�������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("qixian-wuxingjian",1) < 180)
                return notify_fail("����������ν��������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("shexing-diaoshou",1) < 180)
                return notify_fail("������ε��ֻ������ң��޷�ʹ�ã�\n");
        me->receive_damage("jing", 145);
        me->receive_damage("qi", 120);
        return 1;

}


string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
	int i, level;
	string *power_msg = 
	({
		HIR"$N���������������󡹦��˫��ƽ�ƣ�������ü�����������к���������֮�����з缲��Ѹ���;���ʵ�Ƿ�ͬС��"NOR,
		WHT"$N�������ŭ�𣬶�������������˫�����������δ�����Ʒ��ѽ����³�������һ�ɾ���ֱ��$n���ţ��Ƶ���ǿ�ޱ�"NOR,
		HIR"$N��ɫ���������������鼡��΢΢ǣ�����������������һ����У�˫��ͦ����һ�ɾ������ֱײ�ĳ�$n�ƽ�����"NOR,
		WHT"$N�׵����ӣ����й������Ľ���������˫���Ƴ����Ը�󡹦��$n�͹���$n������$P��������֮�£�ֻ���û�����������������"NOR,
	});
	string *reverse_msg = 
	({
		HIM"����$N�������أ��������ף������������Լ�������ץһ�ѣ������������Լ����Ϻ���һ�ţ�ÿһ�ƴ򽫳�������;����ر䣬ʵ��֪�򽫺δ�"NOR,
		HIM"$N��Ȼ���������������Լ��������⣬��һ����˫�־ݵأ�����$n�����ط���һ������Ȼ�����Ծ��˫����$n��������"NOR,
		HIM"ͻȻ֮�䣬$N������������ȫȻ���أ����й����ޱȣ�����󡹦��ת���ã�������֮��������֮����������׽��"NOR,
		HIM"$Nȫ������˳���棬����������Ȼ���˴�������Ǵ��д��ţ����ֵֹ�������$n����ѽ�"NOR,
	});

	level   = (int) me->query_skill("hamagong",1);

	if (me->query_skill_mapped("force") == "hamagong" ) {
		if ( !me->query_temp("hmg_dzjm") && me->query_temp("powerup") && random(me->query_skill("force",1)) > 180 && me->query("neili") > 1000 )
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 20,
			"parry": 20,
			"force": 650+random(100),
			"damage": 220,
			"damage_type": random(2)?"����":"����"
			]);
		else if ( me->query_temp("hmg_dzjm") && random(me->query_skill("force",1)) > 180  && random(me->query_skill("strike",1)) > 180 && me->query("neili") > 1000 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 100,
			"parry": 100,
			"force": 630+random(100),
			"damage": 220+random(20),
			"damage_type": "����",
			]);
	}
	else if ( me->query_temp("hmg_dzjm") )
		return reverse_action[random(sizeof(reverse_action))];
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);
	
 return HIR "$N��ת����������һ�䣬һ�ڶ�������$n�³�!$nͷһ�裬��֪���� ��\n";
}
	if( damage_bonus < 100 ) return 0;



if (me->query_temp("hmg_dzjm") && random(4)>2 )
{
        victim->receive_damage("qi", damage_bonus/2);
        victim->receive_wound("qi", damage_bonus/2);
 return HIR "$N��ת��������$n�ſ�һҧ!$n�˿�һ������Ѫ�����\n";
}
	if( damage_bonus/2 > victim->query_str() && random(3)==0 ) {
if(me->query_skill("hamagong", 1)>150)
{
if (me->query_skill_mapped("force") == "hamagong"
&& !me->query_temp("weapon"))
{
		victim->receive_wound("qi", (damage_bonus ) / 2 );
		return HIM " "+ victim->name()+"��Ϣδ�����־�һ�ɾ����������,�³���һ�����Ѫ��\n" NOR;
}
}
	}
        lvl = me->query_skill("hamagong", 1);

        if (damage_bonus < 50
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_skill_mapped("force") != "hamagong"
)
                return 0;

        if (damage_bonus / 6 > victim->query_con() && random(2)==0)
        {
                me->add("neili", -30);
                victim->receive_wound("qi", (damage_bonus - 90) / 3+20);
                return WHT "$n" WHT "Ӳ����$N" WHT "һ�ƣ���ʱȫ"
                       "��һ���������������һ����Ѫ��\n" NOR;
        }
}

string exert_function_file(string func)
{
        return __DIR__"hamagong/exert/" + func;
}

string perform_action_file(string action)
{
	return __DIR__"hamagong/perform/" + action;
}
mapping curing_msg(object me)
{
        return ([
"apply_short" :me->name()+"��ͷ֧�ڵ��ϣ�˫�Ų�£��������ա�",
"start_self" :HIW"�㵹ת���壬��ͷ֧�أ�˫�Ų�£��������գ������󡹦��ת�ķ����ˡ�\n"NOR,
"on_self" :HIM"�㵹����Ϣ���������ߣ��о����ƴ�����ɫ��\n"NOR,
"start_other" :HIM""+me->name()+"��ɫ������ͷ�½��ϵ����ţ���������ɢ����һ�ɺ�����\n"NOR,
"finish_self" :HIW"��е�ȫ������ͨ�����裬�ֽ�һ�����͵�Ծ��\n"NOR,
"finish_other" :me->name()+"����һ���ֽ�һ����ͻȻԾ�𣬺���Ҳ��֮����ɢȥ��\n",
"unfinish_self" :"��������ת�������ˣ�ͻȻ�е������Ҵܣ��ų�һ���亹��ֻ��ͣ��������\n",
"unfinish_other":me->name()+"��Ȼ����˫�ۣ�����վ�𣬵���ɫ����������\n",
"halt_self" :"�㽫���ߵ�����ѹ�ص��˫���ŵأ�վ��������\n",
"halt_other" :me->name() +"�������������ڣ�վ�������������ƺ����Ϻ��˲��١�\n",
        ]);
}
